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
			int id = st.get(i).getId();
			String s = new String();
			if(id == 0) s = "adjectives";
			else if(id == 1) s = "articles";
			else if(id == 2) s = "conjucntions";
			else if(id == 3) s = "prepositions";
			else if(id == 4) s = "verbs";
			System.out.print(s + "\n");
		}
		System.out.println("---------------------");
	}
	
	private static void printFileSymtab(Symtab st) {
		try {
			FileWriter fw = new FileWriter("SymtabOutput", false);
			PrintWriter outf = new PrintWriter(fw);
			for(int i=0; i<st.size(); i++) {
				outf.print(st.get(i).getString() + "\t");
				outf.print("(" + st.get(i).getRow() + "," + st.get(i).getCol()  + ")\t");
				int id = st.get(i).getId();
				String s = new String();
				if(id == 0) s = "adjectives";
				else if(id == 1) s = "articles";
				else if(id == 2) s = "conjucntions";
				else if(id == 3) s = "prepositions";
				else if(id == 4) s = "verbs";
				outf.print(s + "\n");
			}
			outf.close();
		} catch (IOException e) {
			System.out.println("IOException:" + e.getMessage());
			e.printStackTrace();
			System.exit(0);
		}
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
		printFileSymtab(st);
	}
}
