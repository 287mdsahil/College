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
				//if(bufferStatus==0)
					//notifyAll();
			}
		}

		protected void onePersitent() {
			while(true) {
				if(bufferStatus == 0) {
					try {
						String msg = "000111";
						System.out.println("Sending broadcast message");
						sendMsg(msg,BROADCAST_ADDRESS);
						bufferStatus = 100;
					} catch (Exception e) {
						e.printStackTrace();
						System.exit(0);
					}
				} else if(bufferStatus>0 && bufferStatus<100) {
					System.out.print("");
				}
			}
		}


		protected void nonPersitent() {
			Random rand = new Random();
			while(true) {
				try {
					if(bufferStatus == 0) {
						String msg = "000111";
						System.out.println("Sending broadcast message");
						sendMsg(msg,BROADCAST_ADDRESS);
					} else if(bufferStatus>0) {
						System.out.print("");
						int n = rand.nextInt(2000) + 500;
						Thread.sleep(n);
					}
				} catch (Exception e) {
					e.printStackTrace();
					System.exit(0);
				}
			}
		}
		
		
		protected void pPersitent() {
			Random rand = new Random();
			while(true) {
				try {
					if(bufferStatus == 0) {
						String msg = "000111";
						System.out.println("Sending broadcast message");
						sendMsg(msg,BROADCAST_ADDRESS);
						bufferStatus = 100;
					} else if(bufferStatus>0) {
						System.out.print("");
						int n = 500;
						Thread.sleep(n);
					}
				} catch (Exception e) {
					e.printStackTrace();
					System.exit(0);
				}
			}
		}

		public void run(String mac_addr) {
			super.run(mac_addr);
			//onePersitent();
			//nonPersitent();
			pPersitent();
		}


	}

	public static void main(String args[]) {
		new ClientWrapper().run(args[0]);
	}
}
