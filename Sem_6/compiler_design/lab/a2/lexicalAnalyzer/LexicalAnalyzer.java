package lexicalAnalyzer;

import java.io.*;
import java.util.*;

public class LexicalAnalyzer {

	private static ArrayList<String> lines = new ArrayList<String>();
	// An array of strings to hold lines in the input file


	private static void readFile(String filename) {
		// Function to read the input file
		File file = new File(filename);
		try {
			Scanner fin = new Scanner(file);
			while(fin.hasNext()) {
				lines.add(fin.nextLine());
			}
			fin.close();
		} catch(FileNotFoundException e) {
			System.out.println("Error:" + e.getMessage());
			e.printStackTrace();
		}	
	}

	public static void run(String filename) {
		System.out.println("lexical analyzer");
		readFile(filename);	
	}
}
