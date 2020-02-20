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
	protected static String mac_addr;
	protected static Socket soc;

	private static boolean dhcpLite(String mac) {
		/**Function to establish dhcpLite connection
		 * It registers the mac accress of the client on the server dns
		 * boolean dhcpLite(String mac_address)
		 * If the mac address arguement is null
		 * the client asks the user to enter a mac_address
		 * */
		try {
			if(mac == null || mac.isEmpty()) {
				Scanner sc = new Scanner(System.in);
				System.out.print("Enter the mac address: ");
				mac_addr = sc.nextLine();
				while(mac_addr.length() != 8) {
					System.out.print("Please enter a valid mac address: ");
					mac_addr = sc.nextLine();
				}
				sc.close();
			} else {
				mac_addr = mac;
				if(mac_addr.length() != 8) {
					System.out.println("Invalid mac address for client");
					System.exit(0);
				}
			}

			out.println(DHCPLITE_REQUEST + mac_addr);
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

	// Function for sending messages to other clients
	protected static void sendMsg(String msg, String destination_mac) {
		String message = DATA_TRANSFER + destination_mac + mac_addr + msg;
		out.println(message);
	}

	public static void run(String mac) {
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

			if(!dhcpLite(mac))
				return;			

		} catch (UnknownHostException e) {
			e.printStackTrace();
			System.exit(0);
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(0);
		}
	}

	public static void main(String[] args) {
		run(null);
	}
}
