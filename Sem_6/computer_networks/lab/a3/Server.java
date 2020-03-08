import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

/**Frame format:
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

	public static final String DHCPLITE_REQUEST 		= "00000000";
	public static final String DHCPLITE_GRANTED 		= "00000001";
	public static final String DHCPLITE_REJECTED 		= "00000010";
	public static final String DATA_TRANSFER 			= "10000000";
	public static final String BUFFER_STATUS_MESSAGE 	= "11100000";
	public static final String BROADCAST_ADDRESS 		= "11111111";
	public static final double ERROR_P 		= 0.3;

	private static Map<String, ClientHandler> dns = new HashMap<String, ClientHandler>();
	protected static String buffer;
	
	private static class ChannelBroadcaster implements Runnable {

        protected String makeSequenceString (int n) {
	    	String sq = Integer.toBinaryString(n);
		    if(sq.length() > 8)
				sq = sq.substring(sq.length() - 8);
			else if(sq.length() < 8)
				while(sq.length()!=8)
					sq = "0" + sq;
			return sq;
		}


		public void run() {
			while(true) {
				String msg = BUFFER_STATUS_MESSAGE;
				for(ClientHandler client : dns.values()) {
					msg += makeSequenceString(buffer.length());
					client.out.println(msg);
				}
			}	
		}
	}

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
			/**Function for data tranfer between clients 
			 * void dataTranser(String message_to_be_send)
			 * */
			String destination = msg.substring(8,16);
			String source = msg.substring(16,24);
			if(destination.equals(BROADCAST_ADDRESS)) {
				System.out.println("Broadcast message received");
				//Broadcast()
				
			} else {
			double p = Math.random();
				if(p>ERROR_P) {
					dns.get(destination).out.println(msg);
					System.out.println("Message passed from:"
							+ source
							+ " to:"
							+ destination);
				} else {
					System.out.println("Error while passing message from:"
							+ source
							+ " to:"
							+ destination);
				}
			}
		}

		public void dhcpLite(String msg) {
			/**Function mac address registration on server
			 * void dhcpLite(String dhcp_message_received_from_server)
			 * */
			try {
				String mac_addr = msg.substring(8,16);
				if(dns.containsKey(mac_addr)) {
					out.println(DHCPLITE_REJECTED);
					soc.close();
				} else {
					dns.put(mac_addr,this);
					out.println(DHCPLITE_GRANTED);
					System.out.println("Connection established with:" 
							+ mac_addr 
							+ " at socket:" 	
							+ soc.getRemoteSocketAddress().toString());
				}
			} catch (StringIndexOutOfBoundsException e) {
				System.out.println("Socket:"
						+ soc.getRemoteSocketAddress()
						+ " Requested an invalid mac_address registration");
				out.println(DHCPLITE_REJECTED);
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
		}

		public void run() {
			System.out.println("Attempting to connect:" 	
					+ soc.getRemoteSocketAddress().toString());

			/** starts listeining to client indefinitely */ 
			try {
				while(!soc.isClosed()) {
					if(in.ready()) {
						String msg = in.readLine();
						//System.out.println("Received:" + msg);
						if(msg.substring(0,8).equals(DHCPLITE_REQUEST))
							dhcpLite(msg);
						else if(msg.substring(0,8).equals(DATA_TRANSFER)) {
							//System.out.println("Data:" + msg);
							//dataTranser(msg);
							buffer = msg;
						}
						else
							System.out.println("Unknown premble:" + msg.substring(0,8));
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

		buffer = new String("");
		ChannelBroadcaster cb = new ChannelBroadcaster();
		Thread cdThread = new Thread(cb);
		cdThread.start();

		try {
			ServerSocket serversocket = new ServerSocket(PORT);
			System.out.println("Server Started!");	
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
