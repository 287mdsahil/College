import java.util.*;

public class Symtab {
	public class Sym {
		int row;
		int col;
		int id;
		String token;
		
		public Sym(String s, int r, int c, int i) {
			token = s;
			row = r;
			col = c;
			id = i;
		}

		public String getToken() { return token; }
		public int getId() { return id; }
		public int getRow() { return row; }
		public int getCol() { return col; }
	}

	 ArrayList<Sym> sl;

	public Symtab() {
		sl = new ArrayList<Sym>();
	}

	public void insert(String s, int r, int c, int i) {
		sl.add(new Sym(s,r,c,i));
	}

	public void remove(int i) {
		sl.remove(i);
	}

	public Sym get(int i) {
		return sl.get(i);
	}
}
