package lexicalAnalyzer;
import java.util.*;
import java.io.*;

public class WordTokenizer {
	public TokenList getTokens(String filename)  {
		File file = new File(filename);
		TokenList tl = new TokenList();

		try {
			Scanner fout = new Scanner(file);
			int row = 0;
			while(fout.hasNext()) {
				String[] words = fout.nextLine().split(" ");
				int col = 0;
				for(String w : words) {
					tl.append(w, row, col);
					col++;
				}
				row++;
			}
		} catch (FileNotFoundException e) {
			System.out.println(filename + " file not found");
			System.exit(0);
		}
		return tl;
	}
}
