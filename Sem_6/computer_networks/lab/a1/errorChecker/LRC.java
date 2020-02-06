package errorChecker;

public class LRC implements Checker{
	
	int frameSize;

	LRC (int p) {
		frameSize = p;
	}

	public String generator(String input) {
		String paddingDummy = "";
		for(int i=0;i<frameSize;i++)
			paddingDummy += '0';
		int l = (frameSize - input.length() % frameSize) % frameSize;
		input = input + paddingDummy.substring(0,l);
		String output = "";
		int parityBits[] = new int[frameSize];
		for(int i=0;i<frameSize;i++)
			parityBits[i]=0;
		
		while(input.length()!=0) {
			int limit = frameSize;
			String frame = input.substring(0,limit);
			System.out.println(frame);
			output += frame;
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
		
		System.out.println(parityFrame);	
		output += parityFrame;
		return output;
	}


	public boolean check(String input) {
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

