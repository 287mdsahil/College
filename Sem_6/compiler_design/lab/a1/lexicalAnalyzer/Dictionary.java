package lexicalAnalyzer;

import java.util.*;
import java.io.*;

public class Dictionary {

	Map<String, Integer> dict;

	public Dictionary() {
		dict = new HashMap<String, Integer>();
		generate();
	}

	private void  generate() {
		
		// int 0 for adjectives
		File file = new File("lexicalAnalyzer/Dict/adjectives");
		try {
			Scanner fout = new Scanner(file);
			while(fout.hasNext()) {
				dict.put(fout.next(),0);
			}
		} catch (FileNotFoundException e) {
			System.out.println("adjectives file not found");
			System.exit(0);
		}

		// int 1 for articles
		file = new File("lexicalAnalyzer/Dict/articles");
		try {
			Scanner fout = new Scanner(file);
			while(fout.hasNext()) {
				dict.put(fout.next(),1);
			}
		} catch (FileNotFoundException e) {
			System.out.println("articles file not found");
			System.exit(0);
		}
	
		// int 2 for conjunctions
		file = new File("lexicalAnalyzer/Dict/conjunctions");
		try {
			Scanner fout = new Scanner(file);
			while(fout.hasNext()) {
				dict.put(fout.next(),2);
			}
		} catch (FileNotFoundException e) {
			System.out.println("conjunctions file not found");
			System.exit(0);
		}

		// int 3 for prepositions
		file = new File("lexicalAnalyzer/Dict/prepositions");
		try {
			Scanner fout = new Scanner(file);
			while(fout.hasNext()) {
				dict.put(fout.next(),3);
			}
		} catch (FileNotFoundException e) {
			System.out.println("prepositions file not found");
			System.exit(0);
		}

		
		// int 4 for verbs
		file = new File("lexicalAnalyzer/Dict/verbs");
		try {
			Scanner fout = new Scanner(file);
			while(fout.hasNext()) {
				dict.put(fout.next(),4);
			}
		} catch (FileNotFoundException e) {
			System.out.println("verbs file not found");
			System.exit(0);
		}
	}
		
	public int getType(String s) {
		try {
			return dict.get(s);
		} catch (NullPointerException e) {
			return -1;
		}
	}
}
