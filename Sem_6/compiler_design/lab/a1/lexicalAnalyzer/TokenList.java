package lexicalAnalyzer;

import java.util.*;

public class TokenList {

	public class Token {
		String string;
		int row;
		int col;

		public Token(String s, int r, int c) {
			string = s;
			row = r;
			col = c;
		}

		public String getString() { return string; }
		public int getRow() { return row; }
		public int getCol() { return col; }
	}

	private ArrayList<Token> tokens;

	public TokenList() {
		tokens = new ArrayList<Token>();
	}

	public int getSize() {
		return tokens.size();
	}

	public Token get(int index) {
		return tokens.get(index);
	}

	public void append(String s, int row, int col) {
		tokens.add(new Token(s,row,col));
	}

	public void remove(int index) {
		tokens.remove(index);
	}

}
