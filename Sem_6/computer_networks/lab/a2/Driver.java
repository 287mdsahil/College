import java.util.*;
import java.io.*;
import java.util.concurrent.TimeUnit;

public class Driver {
	public static void main(String args[]) throws Exception {
		Runtime r = Runtime.getRuntime();
		Process p = r.exec("cal 2020");
		BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));
		String line;
		while((line = br.readLine())!=null)
			System.out.println(line);
		p.waitFor(10,TimeUnit.SECONDS);
		p.destroy();
	}
}
