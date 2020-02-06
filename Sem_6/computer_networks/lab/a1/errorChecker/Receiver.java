package errorChecker;

import java.util.*;
import java.io.*;



public class Receiver {

	private static String readInput(String inputFilename) {
		String inputString = "";
		File inputFile = new File(inputFilename);
		try {
			Scanner inputScanner = new Scanner(inputFile);
			if(inputScanner.hasNextLine()) {
				inputString = inputScanner.nextLine();
			inputScanner.close();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.out.println(e);
			System.exit(0);
		}
		return inputString;
	}

	public static void receive(String method, String outputFile) {
		
		Checker checker;
		if(method.toUpperCase().equals("CHECKSUM")) 
			checker = new CheckSum(8);
		else if(method.toUpperCase().equals("VRC"))
			checker = new VRC(8);
		else if(method.toUpperCase().equals("LRC"))
			checker = new LRC(8);
		else 	
			checker = new CRC(7,"1101");

		String receivedString = readInput(outputFile);
		System.out.println("Received input:\t" + receivedString);
		
		if(checker.check(receivedString))
			System.out.println("True");
		else 
			System.out.println("False");
	}
}
