package dllp;

import java.net.Socket;
import java.net.UnknownHostException;
import java.util.*;
import java.io.*;
import java.lang.Runnable;

public class Client {

	public static final String DHCPLITE_REQUEST 	= "00000000";
	public static final String DHCPLITE_GRANTED 	= "00000001";
	public static final String DHCPLITE_REJECTED 	= "00000010";
	public static final String DATA_TRANSFER 	= "10000000";
	
	protected static PrintWriter out;
	protected static BufferedReader in;
	protected static String addr;
	protected static Socket soc;

	private static class Sender implements Runnable {
		public Sender() {
			super();
		}
		public void run() {
			/* start listening to server */
			try{
				while(!soc.isClosed()) {
					Scanner s = new Scanner(System.in);
					System.out.print("Enter message:");
					String m = s.nextLine();
					System.out.print("Enter destination address:");
					String da = s.nextLine();
					s.close();
					out.println(DATA_TRANSFER
							+ da
							+ addr
							+ m
						);
					
				}
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
		}
	}

	private static class Listener implements Runnable {
		public Listener() {
			super();
		}
		public void run() {
			/* start listening to server */
			try{
				while(!soc.isClosed()) {
					if(in.ready()) {
						String msg = in.readLine();
						System.out.println(msg);
					}
				}
			} catch (IOException e) {
				e.printStackTrace();
				System.exit(0);
			}
		}
	}

	private static boolean dhcpLite() {
		try {
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter the addr: ");
			addr = sc.nextLine();
			out.println(DHCPLITE_REQUEST + addr);
			String msg = in.readLine();
			if(msg.substring(0,8).equals(DHCPLITE_GRANTED)) {
				System.out.println("Connected Established");
				return true;
			} else if(msg.substring(0,8).equals(DHCPLITE_REJECTED)) {
				System.out.println("Connection denied by server dns!");
				return false;
			} else {
				System.out.println("Unexpected error occurred!");
				return false;
			}
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(0);
		}

		return false;
	}

	public static void run() {
		try {
			soc = new Socket("localhost",8888);
			System.out.println("Client started with local address:" +
					soc.getLocalSocketAddress().toString()
					);
			out = new PrintWriter(soc.getOutputStream(), true);
			in = new BufferedReader(
				new InputStreamReader(
					soc.getInputStream()
					)
				);

			if(!dhcpLite())
				return;
			new Thread(new Listener()).start();
			new Thread(new Sender()).start();

		} catch (UnknownHostException e) {
			e.printStackTrace();
			System.exit(0);
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(0);
		}
	}

	public static void main(String[] args) {
		run();
	}
}
