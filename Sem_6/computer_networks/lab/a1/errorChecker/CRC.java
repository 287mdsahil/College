package errorChecker;

public class CRC {
	
	int frameSize;
	int rBitSize;
	int mBitSize;
	String div;


	CRC (int fs, String d) {
		frameSize = fs;
		div = d;
		rBitSize = d.length() - 1;
		mBitSize = frameSize - rBitSize;
		if(mBitSize <= 0) {
			System.out.println("CRC error: frame size must be larger than redundant bits");
			System.exit(0);
		}
	}

	private char xor(char a, char b) {
		if(a == '1' && b == '1') {
			return '0';
		} else if(a == '0' && b == '0') {
			return '0';
		}
		return '1';
	}

	String generator(String input) {

		// Applying zero padding to make frames evenly sized
		System.out.println(div);
		String paddingDummy = "";
		for(int i=0;i<mBitSize;i++)
			paddingDummy += '0';
		input = input + paddingDummy.substring((input.length() % mBitSize));

		
		String output = "";
		
		// Iterate per frames
		// Adding redundant bits to each frame
		while( input.length() != 0 ) {
			String s = input.substring(0,mBitSize);
			s = s + paddingDummy.substring(0,rBitSize);
			String r = div;
			String r_new = "";
			input = input.substring(mBitSize,input.length());
			for(int i = 0; i < mBitSize - 1; i++) {
				r_new = "";
				for(int j = 0; j < rBitSize + 1; j++) {
					r_new += xor(r.charAt(i),s.charAt(i+j));
				}
				r = r_new;
				r = r.substring(1,r.length()) + s.charAt(i+rBitSize);
			}
			r_new = r_new.substring(1,r_new.length());
			//debug
			System.out.println("String:" + s);
			System.out.println("Rcode:" + r_new);
			System.out.println(s.substring(0,s.length() - r_new.length()) + r_new);
			output += s.substring(0,s.length() - r_new.length()) + r_new;
		}
		check(output);	
		return output;
	}

	boolean check(String input) {
		/*while( input.length() != 0 ) {
			String s = input.substring(0,frameSize);
			String r = div;
			String r_new = "";
			input = input.substring(frameSize,input.length());
			for(int i = 0; i < mBitSize - 1; i++) {
				r_new = "";
				for(int j = 0; j < rBitSize + 1; j++) {
					r_new += xor(r.charAt(i),s.charAt(i+j));
				}
				r = r_new;
				r = r.substring(1,r.length()) + s.charAt(i+rBitSize);
			}
			System.out.println("String:" + s);
			System.out.println("Rcode:" + r_new);
			output += s + r_new;
		}*/
		return true;
	}
}
