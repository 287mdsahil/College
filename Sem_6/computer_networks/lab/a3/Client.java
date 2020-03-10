import java.util.Random;

public class Client {
	public static class ClientWrapper extends ClientClass {
		public ClientWrapper() {
			super();
		}

		protected void receiveMsg(String msg) {
			//do nothing for now
		}	

		protected void bufferUpdate(String buffer) {
		int newbufferStatus = Integer.parseInt(buffer,2);
		if(newbufferStatus != bufferStatus) {
				bufferStatus = newbufferStatus;
			}
		}

        protected String makeSequenceString (int n) {
	    	String sq = Integer.toBinaryString(n);
		    if(sq.length() > 8)
				sq = sq.substring(sq.length() - 8);
			else if(sq.length() < 8)
				while(sq.length()!=8)
					sq = "0" + sq;
			return sq;
		}

		protected void onePersitent() {
			int count = 0;
			while(true) {
				if(bufferStatus == 0) {
					try {
						String msg = makeSequenceString(count);
						System.out.println("Sending broadcast message:" + count);
						sendMsg(msg,BROADCAST_ADDRESS);
						count++;
						bufferStatus = 100;
						Thread.sleep(1000);
					} catch (Exception e) {
						e.printStackTrace();
						System.exit(0);
					}
				} else if(bufferStatus > 0) {
					System.out.print("");
				}

				if(count==100)
					break;
			}
		}


		protected void nonPersitent() {
			Random rand = new Random();
			int count = 0;
			while(true) {
				try {
					if(bufferStatus == 0) {
						String msg = makeSequenceString(count);
						System.out.println("Sending broadcast message:" + count);
						sendMsg(msg,BROADCAST_ADDRESS);
						count++;
						bufferStatus = 100;
					} else if(bufferStatus>0) {
						System.out.print("");
						int n = rand.nextInt(2000) + 500;
						Thread.sleep(n);
					}
				} catch (Exception e) {
					e.printStackTrace();
					System.exit(0);
				}

				if(count==100)
					break;
			}
		}
		
		
		protected void pPersitent() {
			Random rand = new Random();
			int count = 0;
			while(true) {
				try {
					if(bufferStatus == 0) {
						String msg = makeSequenceString(count);
						System.out.println("Sending broadcast message:" + count);
						sendMsg(msg,BROADCAST_ADDRESS);
						count++;
						bufferStatus = 100;
					} else if(bufferStatus>0) {
						System.out.print("");
						int n = 1000;
						Thread.sleep(n);
					}
				} catch (Exception e) {
					e.printStackTrace();
					System.exit(0);
				}

				if(count==100)
					break;
			}
		}

		public void run(String mac_addr) {
			super.run(mac_addr);
			onePersitent();
			//nonPersitent();
			//pPersitent();
		}


	}

	public static void main(String args[]) {
		new ClientWrapper().run(args[0]);
	}
}
