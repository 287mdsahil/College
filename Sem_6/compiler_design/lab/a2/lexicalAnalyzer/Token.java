package lexicalAnalyzer;

import java.util.*;
import java.io.*;

public class Token{
	static String[] codes = {
		"Keyword",
		"arith_op",
		"rel_op",
		"assign_op",
		"special_symbols",
		"inum",
		"num",
		"id"
	};

	private static List<String> keywords 	= getTokenFromFile("keywords");
	private static List<String> arith_ops 	= getTokenFromFile("arith_op");
	private static List<String> rel_ops 	= getTokenFromFile("rel_op");
	private static List<String> assign_ops 	= getTokenFromFile("assign_op");
	private static List<String> specialSym 	= getTokenFromFile("specialSymbols");

	int id;
	String idcode;
	String lexeme;
	int row;
	int col;
	
	public static List<String> getTokenFromFile(String filename) {
		File file = new File("lexicalAnalyzer/Dict/" + filename);
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

	public boolean inumDfa(String lexeme) {
		//States:
		//0 start state
		//1 state when input is numeric
		//2 null state
		//state 1 is accepting state
		
		int state = 0;
		
		for(char c : lexeme.toCharArray()) {
			if(Character.isDigit(c) && (state == 0 || state == 1))
				state = 1;
			else {
				state = 2;
				break;
			}
		}

		if(state == 1)
			return true;
		else
			return false;
	}
	
	public boolean numDfa(String lexeme) {
		//States:
		//0 start state
		//1 state when input is numeric and . has not been encountered
		//2 state when input is numeric and . has been encountered
		//3 rejecting state
		//state 1 and 2 are accepting states
		
		int state = 0;
		
		for(char c : lexeme.toCharArray()) {
			if(Character.isDigit(c)) {
				if(state == 0 || state == 1)
					state = 1;
				else if(state == 2)
					state = 2;
			} else if(c == '.') {
				if(state == 0 || state == 1)
					state = 2;
				else {
					state = 3;
					break;
				}
			} else {
				state = 3;
				break;
			}
		}

		if(state == 1 || state == 2)
			return true;
		else
			return false;
	}

	public boolean idDfa(String lexeme) {
		//States:
		//0 start state
		//1 state when _ or alphabet is encountered after start state
		//	or when _ or alpha numeric encountered not after start state
		//2 rejecting state
		
		int state = 0;
		
		for(char c : lexeme.toCharArray()) {
			if(Character.isAlphabetic(c) || c == '_') {
				if(state == 0)
					state = 1;
				else if(state == 1)
					state = 1;
			}
			else if (Character.isDigit(c)) {
				if(state == 1)
					state = 1;
				else if(state == 0) {
					state = 2;
					break;
				}
			}
		}

		if(state == 1)
			return true;
		else
			return false;
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
		else if(specialSym.indexOf(lexeme)!=-1)
			idcode = codes[4];
		else if(inumDfa(lexeme))
			idcode = codes[5];
		else if(numDfa(lexeme))
			idcode = codes[6];
		else if(idDfa(lexeme))
			idcode = codes[7];
		
		System.out.println(lexeme + "\t:\t" + idcode);
	}

	public Token(String l, int r, int c) {
		lexeme = l;
		row = r;
		col = c;
		identify();
	}
}
