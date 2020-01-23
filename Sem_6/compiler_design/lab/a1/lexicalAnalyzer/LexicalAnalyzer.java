package lexicalAnalyzer;

import java.io.*;
import java.util.*;

public class LexicalAnalyzer {
	public static void main(String args[]) {
		String filename = "input";
		WordTokenizer wt = new WordTokenizer();
		TokenList tl = wt.getTokens(filename);
		for(int i = 0; i < tl.getSize(); i++)
			System.out.println(tl.get(i).getString() + "(" + tl.get(i).getRow() + "," + tl.get(i).getCol() + ")" );

		Dictionary dict = new Dictionary();
		System.out.println(dict.getType("an"));
		System.out.println(dict.getType("at"));
	}
}
