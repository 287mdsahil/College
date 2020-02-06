package errorChecker;

public class VRC implements Checker{
	
	int frameSize;

	VRC (int p) {
		frameSize = p;
	}

	public String generator(String input) {
		String output = "";
		String paddingDummy = "";
		for(int i=0;i<frameSize;i++)
			paddingDummy += '0';

		int l = (frameSize - input.length() % frameSize) % frameSize;
		input = input + paddingDummy.substring(0,l);

		while(input.length() != 0) {
			int limit = frameSize;
			String frame = input.substring(0,limit);
			input = input.substring(limit,input.length());
			int parity = 0;
			
			for(int i = 0; i < limit ; i++) {
				if(frame.charAt(i)=='1')
					parity++;
			}
			
			if(parity % 2 == 0) {
				frame = frame + "0";
			} else {
				frame = frame + "1";
			}
			
			output = output + frame;
			System.out.println(frame);

		}
		return output;
	}

	public boolean check(String input) {
		if(input.length() % (frameSize + 1) != 0)
			return false;

		while(input.length() != 0) {	
			int limit = frameSize + 1;
			String frame = input.substring(0,limit);
			input = input.substring(limit,input.length());
			int parity = 0;
			
			for(int i = 0; i < limit - 1 ; i++) {
				if(frame.charAt(i) == '1')
					parity++;
			}
			
			if(parity % 2 == 0 && frame.charAt(limit - 1) != '0') {
				return false;
			} else if(parity % 2 == 1 && frame.charAt(limit- 1) != '1') {
				return false;
			}
		}
		return true;
	}
}

