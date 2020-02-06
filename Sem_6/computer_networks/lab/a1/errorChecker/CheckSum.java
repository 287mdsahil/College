package errorChecker;

import java.util.*;

public class CheckSum implements Checker {

	private int framesize;

	private String addBinaryString(String s1, String s2){
		if(s1.length()!=framesize || s2.length()!=framesize){
			System.out.println("checksum addition bit size error");
			System.exit(0);
		}
		
		int n1 = Integer.parseInt(s1,2);
		int n2 = Integer.parseInt(s2,2);

		int sum = n1 + n2;
		String result = Integer.toBinaryString(sum);

		if(result.length()<framesize) {
			int d = framesize - result.length();
			String padding = "";
			for(int i=0;i<d;i++) padding += '0';
			result = padding + result;
		}
		
		// One's complement addition ( we add the carry)
		if(result.length()>framesize){
			String carry = result.substring(0,result.length() - framesize);
			result = result.substring(result.length() - framesize, result.length());
			n1 = Integer.parseInt(result,2);
			n2 = Integer.parseInt(carry,2);
			result = Integer.toBinaryString(n1 + n2);
		}


		if(result.length()<framesize) {
			int d = framesize - result.length();
			String padding = "";
			for(int i=0;i<d;i++) padding += '0';
			result = padding + result;
		}
		
		//debug
		//System.out.println(s1);
		//System.out.println("+");
		//System.out.println(s2);
		//System.out.println("------------");
		//System.out.println(result);
		//System.out.println("===================\n");

		return result;
	}

	public CheckSum(int f) {
		framesize = f;
	}

	public String generator(String input) {
		String paddingDummy = "";
		String checksum = "";
		for(int i=0;i<framesize;i++) {
			paddingDummy += '0';
			checksum += '0';
		}

		int l = (framesize - input.length() % framesize) % framesize;
		input = input + paddingDummy.substring(0,l);
	
		String output = "";
		while(input.length()!= 0) {
			String frame = input.substring(0,framesize);
			input = input.substring(framesize,input.length());
			output = output + frame;
			checksum = addBinaryString(checksum,frame);
		}

		checksum = Integer.toBinaryString(~(Integer.parseInt(checksum,2)));
		checksum = checksum.substring(checksum.length()-framesize,checksum.length());
		System.out.println("Checksum:" + checksum);
		return output + checksum;
	}

	public boolean check(String input) {
		String checksum = "";
		for(int i=0;i<framesize;i++) 
			checksum += '0';
		String correct = new String(checksum);

		while(!input.isEmpty()) {
			String frame = input.substring(0,framesize);
			input = input.substring(framesize,input.length());
			checksum = addBinaryString(checksum,frame);
		}
		
		checksum = Integer.toBinaryString(~(Integer.parseInt(checksum,2)));
		checksum = checksum.substring(checksum.length()-framesize,checksum.length());
		System.out.println("Checksum:" + checksum);

		if(checksum.equals(correct))
			return true;
		else
			return false;
	}
}
