public
class AbortableMCSLock implements Lock
{
	AtomicReference<QNode> tail;
	ThreadLocal<QNode> myNode;
public
	AbortableMCSLock()
	{
		tail = new AtomicReference<QNode>(null);
		myNode = new ThreadLocal<QNode>() {
		protected QNode initialValue() {
				return new QNode();
			}
		}
	}
public
	boolean lock(long time, TimeUnit unit)
	{
		long startTime = System.currentTimeMillis();
		long patience = TimeUnit.MILLISECONDS.convert(time, unit);
		QNode qnode = myNode.get();
		QNode myPred = tail.getAndSet(qnode);

		if (myPred == null) return true;

		qnode.locked = true;
		myPred.next = qnode;
		qnode.pred = myPred;

		while (System.currentTimeMillis() - startTime < patience)
		{
			if (!qnode.locked)
				return true;
		}

		// Abandoning lock
		qnode.pred.next = qnode.next;
		if (qnode.next != null)
			qnode.next.pred = qnode.pred;
		// If the node at the end of queue is abandoned, update tail
		tail.compareAndSet(qnode, myPred)
		return false;
	}
public
	void unlock() {
		QNode qnode = myNode.get();
		if (qnode.next == null) {
			if (tail.compareAndSet(qnode, null))
				return;
			// wait until successor fills in its next field
			while (qnode.next == null) {}
		}
		qnode.next.locked = false;
		qnode.next = null;
	}
	class QNode
	{
		volatile boolean locked = false;
		volatile QNode next = null;
		volatile QNode pred = null;
	}
}