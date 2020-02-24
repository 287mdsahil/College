package dllp;

public class SAWReceiverClientClass extends ClientClass {
	/**Send and Wait data link layer protocol implementation */
	
	protected static final String SENDER_MAC_ADDR 		= "10101010";
	protected static final String RECEIVER_MAC_ADDR 	= "10101011";
	protected static final String MESSAGE_HEADER 		= "00000000";
	protected static final String AWK_HEADER 		= "10000000";
	
	protected String MSG;

	public SAWReceiverClientClass() {
		super();
	}
	

	public void run() {
		super.run(RECEIVER_MAC_ADDR);
		System.out.println("Receiver is listening...");
	}

	@Override
	protected void receiveMsg(String msg) {
		String dest_mac = msg.substring(0,8);
		String source_mac = msg.substring(8,16);
		String info = msg.substring(16,24);
		if(info.equals(MESSAGE_HEADER)) {
			System.out.println("Message received: " + msg.substring(24) + " From client: " + source_mac);
			System.out.println("Sending Awk to:" + source_mac);
			super.sendMsg(AWK_HEADER,SENDER_MAC_ADDR);
		}
	}
}
