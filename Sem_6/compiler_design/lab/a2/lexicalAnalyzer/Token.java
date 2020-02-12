package lexicalAnalyzer;

import java.util.*;
import java.io.*;

public class Token{
	static String[] codes = {
		"Keyword",
		"arith_op",
		"rel_op",
		"assign_op",
		"id",
		"inum",
		"num"
	};

	private static List<String> keywords = getKeywords();
	private static List<String> arith_ops = getArithOp();
	private static List<String> rel_ops = getRelOp();
	private static List<String> assign_ops = getAssignOp();

	int id;
	String idcode;
	String lexeme;
	int row;
	int col;

	public static List<String> getKeywords() {
		File file = new File("lexicalAnalyzer/Dict/keywords");
		List<String> kds = new ArrayList<String>();
		try {
			Scanner fin = new Scanner(file);
			while(fin.hasNext()) {
				kds.add(fin.nextLine());
			}
			fin.close();
		} catch(FileNotFoundException e) {
			System.out.println("Error:" + e.getMessage());
			e.printStackTrace();
			System.exit(0);
		}
		return kds;
	}

	public static List<String> getArithOp() {
		File file = new File("lexicalAnalyzer/Dict/arith_op");
		List<String> aps = new ArrayList<String>();
		try {
			Scanner fin = new Scanner(file);
			while(fin.hasNext()) {
				aps.add(fin.nextLine());
			}
			fin.close();
		} catch(FileNotFoundException e) {
			System.out.println("Error:" + e.getMessage());
			e.printStackTrace();
			System.exit(0);
		}
		return aps;
	}
	
	public static List<String> getRelOp() {
		File file = new File("lexicalAnalyzer/Dict/rel_op");
		List<String> aps = new ArrayList<String>();
		try {
			Scanner fin = new Scanner(file);
			while(fin.hasNext()) {
				aps.add(fin.nextLine());
			}
			fin.close();
		} catch(FileNotFoundException e) {
			System.out.println("Error:" + e.getMessage());
			e.printStackTrace();
			System.exit(0);
		}
		return aps;
	}
	
	public static List<String> getAssignOp() {
		File file = new File("lexicalAnalyzer/Dict/assign_op");
		List<String> aps = new ArrayList<String>();
		try {
			Scanner fin = new Scanner(file);
			while(fin.hasNext()) {
				aps.add(fin.nextLine());
			}
			fin.close();
		} catch(FileNotFoundException e) {
			System.out.println("Error:" + e.getMessage());
			e.printStackTrace();
			System.exit(0);
		}
		return aps;
	}

	public void identify() {	
		if(keywords.indexOf(lexeme)!=-1)
			idcode = codes[0];
		else if(arith_ops.indexOf(lexeme)!=-1)
			idcode = codes[1];
		else if(rel_ops.indexOf(lexeme)!=-1)
			idcode = codes[2];
		else if(assign_ops.indexOf(lexeme)!=-1)
			idcode = codes[3];
		
		System.out.println(lexeme + ":" + idcode);
	}

	public Token(String l, int r, int c) {
		lexeme = l;
		row = r;
		col = c;
		identify();
	}
}
