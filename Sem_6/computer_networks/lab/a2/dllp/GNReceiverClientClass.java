package dllp;

/**Data format:
 * 1 byte: Info
 * 1 byte: Sequence number
 * 1 - 7 bytes: data
 *
 * Info byte structrue:
 * 00000000: message
 * 10000000: ack 
 * 11111111: invalid frame
 *
 * */

public class GNReceiverClientClass extends ClientClass {
	/**Send and Wait data link layer protocol implementation */
	
	protected static final String SENDER_MAC_ADDR 		= "10101010";
	protected static final String RECEIVER_MAC_ADDR 	= "10101011";
	protected static final String MESSAGE_HEADER 		= "00000000";
	protected static final String AWK_HEADER 		= "10000000";
	
	protected String MSG;
	protected int rn = 0;
	protected int sw = 3;

	public GNReceiverClientClass() {
		super();
	}
	

	public void run() {
		super.run(RECEIVER_MAC_ADDR);
		System.out.println("Receiver is listening...");
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

	@Override
	protected void receiveMsg(String msg) {
		String dest_mac = msg.substring(0,8);
		String source_mac = msg.substring(8,16);
		String info = msg.substring(16,24);
		if(info.equals(MESSAGE_HEADER)) {
			int seqNO = Integer.parseInt(msg.substring(24,32),2);
			if(seqNO == rn) {
				System.out.println("Message-" 
						+ rn
						+ " received: " 
						+ msg.substring(24) 
						+ " From client: " 
						+ source_mac);
				rn = (rn + 1)%(sw + 1);
				System.out.println("Sending Awk-" 
						+ Integer.parseInt(makeSequenceString(rn),2)
						+ " to:" + source_mac);
				super.sendMsg(AWK_HEADER + makeSequenceString(rn) ,SENDER_MAC_ADDR);
			}
		}
	}
}
