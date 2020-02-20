package dllp;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

/*Frame format:
 * 1 byte premble
 * 1 bytes destination address
 * 1 bytes source address
 * 1 - 10 bytes of data
 *
 *
 * If the premble is set to 00000000 then it is for dhcpLite request
 * If the premble is set to 00000001 then it is for dhcpLite granted
 * If the premble is set to 00000010 then it is for dhcpLite rejected
 * If the premble is set to 10000000 then it is for data transfer
 */

public class Server {

	public static final String DHCPLITE_REQUEST 	= "00000000";
	public static final String DHCPLITE_GRANTED 	= "00000001";
	public static final String DHCPLITE_REJECTED 	= "00000010";
	public static final String DATA_TRANSFER 	= "10000000";

	private static Map<String, ClientHandler> dns = new HashMap<String, ClientHandler>();

	private static class ClientHandler implements Runnable {
		private Socket soc;
		public PrintWriter out;
		public BufferedReader in;

		public ClientHandler(Socket s) {
			soc = s;
			try {
				out = new PrintWriter(soc.getOutputStream(), true);
				in = new BufferedReader(
					new InputStreamReader(
						soc.getInputStream()
						)
					);
			} catch (IOException e) {
				e.printStackTrace();
				System.exit(0);
			}
		}

		public void dataTranser(String msg) {
			String destination = msg.substring(8,16);
			dns.get(destination).out.println(msg);
			System.out.println("Message passed from: "
						+ msg.substring(16,24)
						+ " to:"
						+ destination
					);
		}

		public void dhcpLite(String msg) {
			try {
				String addr = msg.substring(8,16);
				if(dns.containsKey(addr)) {
					out.println(DHCPLITE_REJECTED);
					soc.close();
				} else {
					dns.put(addr,this);
					out.println(DHCPLITE_GRANTED);
					System.out.println("Connection established with:" 
							+ addr 
							+ " at socket:" 	
							+ soc.getRemoteSocketAddress().toString());
				}
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
		}

		public void run() {
			System.out.println("Attempting to connect:" 	
					+ soc.getRemoteSocketAddress().toString());

			/* starts listeining to client indefinitely */ 
			try {
				while(!soc.isClosed()) {
					if(in.ready()) {
						String msg = in.readLine();
						System.out.println("Received:" + msg);
						if(msg.substring(0,8).equals(DHCPLITE_REQUEST))
							dhcpLite(msg);
						else if(msg.substring(0,8).equals(DATA_TRANSFER))
							dataTranser(msg);
						else
							System.out.println(msg.substring(0,8));
					}
				}
			} catch (IOException e) {
				e.printStackTrace();
				System.exit(0);
			}
		}
	}

	public static int PORT = 8888;
	public static void run() {
		try {
			ServerSocket serversocket = new ServerSocket(PORT);
			System.out.println("Starting server");	
			while(true) {
				Socket soc = serversocket.accept();
				new Thread(new ClientHandler(soc)).start();
			}
			//serversocket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}


	public static void main(String[] args) {
		run();
	}
}
