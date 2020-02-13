package lexicalAnalyzer;

import java.io.*;
import java.util.*;

public class LexicalAnalyzer {

	private static ArrayList<String> lines = new ArrayList<String>();
	// An array of strings to hold lines in the input file
	
	private static List<Token> tokens = new ArrayList<Token>();
	
	private static String getDelimitersRegex() {
		// Function to read the input file
		File file = new File("lexicalAnalyzer/Dict/delimiters");
		String delimiters = "( )|(\t)|(\n)|(\r)";
		try {
			Scanner fin = new Scanner(file);
			while(fin.hasNext()) {
				String s = fin.nextLine();
				delimiters += "|((?<=" + s + ")";
				delimiters += "|(?=" + s + "))";
				
			}
			fin.close();
		} catch(FileNotFoundException e) {
			System.out.println("Error:" + e.getMessage());
			e.printStackTrace();
			System.exit(0);
		}
		return delimiters;
	}

	private static void tokenize() {
		// Function to generater tokens
		for(int r = 0; r < lines.size(); r++) {
			String line = lines.get(r);
			String wordarr[] = line.split(getDelimitersRegex());
			List<String> words = new ArrayList<String>(
					Arrays.asList(wordarr));
			words.removeAll(Arrays.asList("",null));
			for(int c = 0; c < words.size(); c++) {
				String word = words.get(c);
				tokens.add(new Token(word,r,c));
			}
		}
	}

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
			System.exit(0);
		}	
	}

	private static void printSymTab() {
		System.out.println("_____________________________________________________________");
		System.out.println("Id"
				+ "\t" + "Position"
				+ "\t" + "Lexeme" 
				+ "\t\t" + "Token-type"
				);
		System.out.println("_____________________________________________________________");
		for(Token token : tokens) {
			System.out.println(token.id 
				+ "\t" + "(" + token.row + "," + token.col + ")"
				+ "\t\t" + token.lexeme 
				+ "\t\t" + token.idcode
				);
		}		
		System.out.println("_____________________________________________________________");
	}

	public static void run(String filename) {
		readFile(filename);
		tokenize();
		printSymTab();	
	}
}
