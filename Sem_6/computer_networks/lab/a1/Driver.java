import errorChecker.*;
import java.util.Random;
import java.util.*;
import java.io.*;


public class Driver{

	private static final double  error_percentage = 1;

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
	
	
	public static void error(String outputFile) {
		String message = readInput(outputFile);
		
		Random rand = new Random();
		double p = rand.nextFloat();

		//inflicting error
		if(p<error_percentage){
			System.out.println("\nInflicting error");
			System.out.print("Errors at:");
			int n = rand.nextInt(message.length()/2)+1;
			n = 2;
			for(int i=0;i<n;i++) {
				int ind = rand.nextInt(message.length());
				System.out.print(ind + ",");
				char s[] = message.toCharArray();
				if(s[ind] == '0') s[ind] = '1';
				else s[ind] = '0';
				message = new String(s);
			}
			System.out.println("\n");
		}

		writeOutput(message,outputFile);
	}



	public static void main(String args[]) {
		String inputFile = "input";
		String outputFile = "output";
		String method = "vrc";
		System.out.println("Sender:------");
		Sender.send(method,inputFile,outputFile);

		//error(outputFile);

		System.out.println("Receiver:------");
		Receiver.receive(method,outputFile);
	}
}
