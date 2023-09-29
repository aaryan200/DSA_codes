class StickyBitConsensus implements MultiValConsensus {
	int numBits; // number of bits in value
	int numThr; // number of threads
	StickyBit[] s;
	MRSWRegister[] arr;
	StickyBitConsensus(int m, int n) {
		numBits = log(m);
		numThr = n;
		s = new StickyBit [numBits];
		arr = new MRSWRegister [numThr];
		for (int i=0;i<numThr;i++) {
			arr[i] = -1; // Initialize to -1
		}
	}
	int decide ( int value ) {
		int v = value;
		arr[threadID] = value;
		for (int i = 0; i < numBits ; i ++) {
			b = bit i of v ;
			s [i]. write (b) ;
			if ( s [i]. read () != b ) {
				for (int j = 0; j < numThr; j ++) {
					if ( (arr[j] != -1) && (bits(arr[j])[0...i] match with s[0...i]) ) {
						// Copy the value of the thread which has written a different value in s[i]
						v = arr[j];
					}
				}
			}
		}
		return booleanArrayToInt (s);
	}
}
