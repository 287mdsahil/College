package errorChecker;

public class CRC implements Checker{
	
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

	private String divide(int mBitSize, int rBitSize, String div, String s) {
		String r_new = div;
		String r = s.substring(0,rBitSize + 1);
		String ddiv = div;
		String r0 = "";
		for(int i=0;i<r.length();i++)
			r0 += '0';
		for(int i = 0; i < mBitSize ; i++) {
			r_new = "";
			
			if(r.charAt(0) == '0')
				ddiv = r0;
			else
				ddiv = div;
				
			for(int j = 0; j < rBitSize + 1; j++) {
				r_new += xor(r.charAt(j),ddiv.charAt(j));
				//System.out.println(r_new.charAt(j) + ","  + r.charAt(j) + "," + ddiv.charAt(j));
			}

			//System.out.println(r_new);
			r = r_new;
			if(s.length() > i+rBitSize + 1)
				r = r.substring(1,rBitSize+1) +  s.charAt(i+rBitSize+1);
		}
		return r_new;
	}

	public String generator(String input) {

		// Applying zero padding to make frames evenly sized
		String paddingDummy = "";
		for(int i=0;i<mBitSize;i++)
			paddingDummy += '0';
		int l = (mBitSize - input.length() % mBitSize) % mBitSize;
		input = input + paddingDummy.substring(0,l);
			
		String output = "";
		
		// Iterate per frames
		// Adding redundant bits to each frame
		while( input.length() != 0 ) {
			String s = input.substring(0,mBitSize);
			s = s + paddingDummy.substring(0,rBitSize);
			String r0 = paddingDummy.substring(0,div.length()); 
			String r = div;
			String r_new = "";
			input = input.substring(mBitSize,input.length());
			r_new = divide(mBitSize,rBitSize,div,s);
			r_new = r_new.substring(1,r_new.length());
			output += s.substring(0,s.length() - r_new.length()) + r_new;
		}
		return output;
	}

	public boolean check(String input) {	
		String r = div;
		String r_new = "";
		String correct = "";	
		for(int i=0;i<r.length();i++)
			correct += '0';
		while( input.length()!= 0 ) {
			String s = input.substring(0,frameSize);
			//input = input.substring(frameSize,input.length());

			r = divide(mBitSize,rBitSize,div,s);
			
				
			if(!r.equals(correct)) {
				System.out.println("r:"+r);
				return false;
			}

			break;
		}
		return true;
	}
}
