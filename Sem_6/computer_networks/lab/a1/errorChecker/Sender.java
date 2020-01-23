package errorChecker;

import java.util.*;
import java.io.*;

public class Sender {
	private static String readInput() {
		String inputFilename = "input";
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

	private static void writeOutput(String output) {
		System.out.println("Output : " + output);
		try {
			FileWriter fw = new FileWriter("senderFile",false);
			PrintWriter outf = new PrintWriter(fw);
			outf.println(output);
			outf.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.out.println(e);
			System.exit(0);
		}
	}
		
	public static void main(String args[]) {
		String inputString = readInput();
		System.out.println("Input : " + inputString);
		LRC vrc = new LRC(8);
		String outputString = vrc.generator(inputString);
		writeOutput(outputString);
	}
}
