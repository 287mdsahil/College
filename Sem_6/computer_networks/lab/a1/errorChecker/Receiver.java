package errorChecker;

import java.util.*;
import java.io.*;



public class Receiver {

	private static String readInput() {
		String inputFilename = "senderFile";
		String inputString = "";
		File inputFile = new File(inputFilename);
		try {
			Scanner inputScanner = new Scanner(inputFile);
			if(inputScanner.hasNextLine()) {
				inputString = inputScanner.nextLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.out.println(e);
			System.exit(0);
		}
		return inputString;
	}

	public static void main(String args[]) {
		LRC lrc = new LRC(8);
		String receivedString = readInput();
		
		if(lrc.check(receivedString))
			System.out.println("True");
		else 
			System.out.println("False");
	}
}
