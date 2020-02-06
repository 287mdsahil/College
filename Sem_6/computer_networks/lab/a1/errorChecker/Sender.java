package errorChecker;

import java.util.*;
import java.io.*;

public class Sender {
	private static String readInput(String inputFilename) {
		String inputString = "";
		File inputFile = new File(inputFilename);
		try {
			Scanner inputScanner = new Scanner(inputFile);
			if(inputScanner.hasNextLine()) {
				inputString = inputScanner.nextLine();
			}
			inputScanner.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.out.println(e);
			System.exit(0);
		}
		return inputString;
	}

	private static void writeOutput(String output,String outputFile) {
		try {
			FileWriter fw = new FileWriter(outputFile,false);
			PrintWriter outf = new PrintWriter(fw);
			outf.println(output);
			outf.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.out.println(e);
			System.exit(0);
		}
	}
		
	public static void send(String method, String inputFile, String outputFile) {
		String inputString = readInput(inputFile);
		System.out.println("Input :\t\t" + inputString);
		
		Checker checker;
		if(method.toUpperCase().equals("CHECKSUM")) 
			checker = new CheckSum(8);
		else if(method.toUpperCase().equals("VRC"))
			checker = new VRC(8);
		else if(method.toUpperCase().equals("LRC"))
			checker = new LRC(8);
		else 	
			checker = new CRC(7,"1101");

		String outputString = checker.generator(inputString);
		
		System.out.println("Output :\t" + outputString);

		writeOutput(outputString,outputFile);
	}
}
