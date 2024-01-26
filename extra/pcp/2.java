class Bathroom{

    static final int ANYONE = 0, MALE = 1, FEMALE = 2;
    SimpleLock lock;
    Condition cv;
    int num_males, num_females;
    int num_male_waiting, num_female_waiting;
    int chance;
    /*
     * If chance == ANYONE, then anyone can enter
     * If chance == MALE, then male can enter
     * If chance == FEMALE, then female can enter
    */

    public Bathroom(){
        num_males = num_females = 0;
        num_male_waiting = num_female_waiting = 0;
        chance = ANYONE;
        lock = new SimpleLock();
        cv = lock.newCondition();
    }

    public void enterMale(){
        lock.acquire();

        num_male_waiting++;

        while (num_females > 0 or chance == FEMALE) cv.await();
        num_male_waiting--;

        num_males++;
        lock.release();
    }

    public void leaveMale(){
        lock.acquire();
        num_males--;

        if (num_female_waiting) {
            chance = FEMALE;
        }
        else {
            chance = ANYONE;
        }
        lock.release();

        cv.signalAll();
    }

    public void enterFemale(){
        lock.acquire();

        num_female_waiting++;

        while (num_males > 0 or chance == MALE) cv.await();
        num_female_waiting--;

        num_females++;
        lock.release();
    }

    public void leaveFemale(){
        lock.acquire();
        num_females--;

        if (num_male_waiting)
            chance = MALE;
        else
            chance = ANYONE;

        lock.release();

        cv.signalAll();

    }
    
    public void use_bathroom(int gender){
        if (gender == MALE){
            enterMale();
            // Use bathroom
            leaveMale();
        }
        else if (gender == FEMALE) {
            enterFemale();
            // Use bathroom
            leaveFemale();
        }
    }
};