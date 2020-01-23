package lexicalAnalyzer;

import java.io.*;
import java.util.*;

public class LexicalAnalyzer {

	private static void printSymtab(Symtab st) {
		System.out.println("---------------------");
		System.out.println("Token\tPos\tType");
		System.out.println("---------------------");
		for(int i=0; i<st.size(); i++) {
			System.out.print(st.get(i).getString() + "\t");
			System.out.print("(" + st.get(i).getRow() + "," + st.get(i).getCol()  + ")\t");
			System.out.print(st.get(i).getId() + "\n");
		}
		System.out.println("---------------------");
	}

	private static Symtab generateSymtab(TokenList tl, Dictionary dict){
		Symtab st = new Symtab();
		for(int i = 0; i<tl.getSize(); i++) {
			String s = tl.get(i).getString();
			int r = tl.get(i).getRow();
			int c = tl.get(i).getCol();
			int id = dict.getType(s);
			if(id != -1) {
				st.insert(s,r,c,id);
			}
		}
		return st;
	}
	public static void run(String filename) {
		WordTokenizer wt = new WordTokenizer();
		TokenList tl = wt.getTokens(filename);
		
		//for(int i = 0; i < tl.getSize(); i++)
			//System.out.println(tl.get(i).getString() + "(" + tl.get(i).getRow() + "," + tl.get(i).getCol() + ")" );
		
		Dictionary dict = new Dictionary();
		Symtab st = generateSymtab(tl,dict);

		printSymtab(st);
	}
}
