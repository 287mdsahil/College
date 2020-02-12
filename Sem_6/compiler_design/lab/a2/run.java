import java.util.*;
import lexicalAnalyzer.*;

public class run {
	public static void main(String[] args) {
		String filename = new String();
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the filename: ");
		filename = sc.nextLine();
		LexicalAnalyzer.run(filename);
		sc.close();
	}
}
