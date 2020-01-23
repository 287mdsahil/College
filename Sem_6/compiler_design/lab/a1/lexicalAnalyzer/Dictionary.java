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
		
		// int 0 for artiles
		File file = new File("lexicalAnalyzer/Dict/articles");
		try {
			Scanner fout = new Scanner(file);
			while(fout.hasNext()) {
				dict.put(fout.next(),0);
			}
		} catch (FileNotFoundException e) {
			System.out.println("articles file not found");
			System.exit(0);
		}

		// int 1 for perpositons
		file = new File("lexicalAnalyzer/Dict/prepositions");
		try {
			Scanner fout = new Scanner(file);
			while(fout.hasNext()) {
				dict.put(fout.next(),1);
			}
		} catch (FileNotFoundException e) {
			System.out.println("prepositions file not found");
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
