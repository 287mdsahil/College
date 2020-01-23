package errorChecker;

public class LRC {
	
	int frameSize;

	LRC (int p) {
		frameSize = p;
	}

	String generator(String input) {
		String output = input;
		String paddingDummy = "00000000";
		input = input + paddingDummy.substring((input.length() % frameSize));
		int parityBits[] = new int[frameSize];
		for(int i=0;i<frameSize;i++)
			parityBits[i]=0;
		
		while(input.length() != 0) {
			int limit = frameSize;
			String frame = input.substring(0,limit);
			input = input.substring(limit,input.length());
			int parity = 0;
	
			for(int i = 0; i < limit ; i++) {
				if(frame.charAt(i)=='1')
					parityBits[i]++;
			}
		}
			
		String parityFrame = "";
		for(int i=0;i<frameSize;i++) {
			if(parityBits[i]%2 == 0)
				parityFrame += '0';
			else
				parityFrame += '1';
		}
		output += parityFrame;

		System.out.println(output.length());
		return output;
	}


	boolean check(String input) {
		if(input.length() % (frameSize) != 0){
			System.out.println("Incorrect size: " + input.length());
			return false;
		}

		int parityBits[] = new int[frameSize];
		for(int i=0;i<frameSize;i++)
			parityBits[i]=0;

		for(int i=0;i<input.length() - frameSize;i++) {
			if(input.charAt(i) == '1')
				parityBits[i%frameSize]++;
		}

		String parityFrame = input.substring(input.length() - frameSize, input.length());
			
		for(int i=0;i<frameSize;i++) {
			if(parityBits[i] % 2 == 0 && parityFrame.charAt(i) != '0') {
				return false;
			} else if(parityBits[i] % 2 == 1 && parityFrame.charAt(i) != '1') {
				return false;
			}
		}
		return true;
	}

}

