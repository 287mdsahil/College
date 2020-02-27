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

public class SRReceiverClientClass extends ClientClass {
	/**Send and Wait data link layer protocol implementation */
	
	protected static final String SENDER_MAC_ADDR 		= "10101010";
	protected static final String RECEIVER_MAC_ADDR 	= "10101011";
	protected static final String MESSAGE_HEADER 		= "00000000";
	protected static final String AWK_HEADER 		= "10000000";	
	protected static final String NAK_HEADER 		= "11000000";
	
	protected String MSG;
	protected int rn = 0;
	protected int sw = 4;
	protected Boolean marked[];
	protected boolean nakSent = false;
	protected boolean ackNeeded = false;

	public SRReceiverClientClass() {
		super();
	}
	

	public void run() {
		super.run(RECEIVER_MAC_ADDR);
		System.out.println("Receiver is listening...");
		marked = new Boolean[sw*2];
		for(int i=0;i<sw*2;i++)
			marked[i] = false;
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

	
	protected boolean checkInWindow(int ackNo) {
		int r = rn;
		for(int i=0;i<sw;i++) {
			if(r==ackNo) return true;	
			r = (r + 1)%(sw * 2);
		}
		return false;
	}


	protected void sendAck(int r,String source_mac) {
		System.out.println("Sending Awk-" 
				+ Integer.parseInt(makeSequenceString(r),2)
				+ " to:" + source_mac);
		super.sendMsg(AWK_HEADER + makeSequenceString(rn) ,SENDER_MAC_ADDR);
	}

	protected void sendNak(int r, String source_mac) {
		System.out.println("Sending Nak-" 
				+ Integer.parseInt(makeSequenceString(r),2)
				+ " to:" + source_mac);
		super.sendMsg(NAK_HEADER + makeSequenceString(rn) ,SENDER_MAC_ADDR);
	}

	@Override
	protected void receiveMsg(String msg) {
		String dest_mac = msg.substring(0,8);
		String source_mac = msg.substring(8,16);
		String info = msg.substring(16,24);
		if(!info.equals(MESSAGE_HEADER)) {
			if(!nakSent) {
				sendNak(rn,source_mac);
				nakSent = true;
			}
		} else {

			int seqNO = Integer.parseInt(msg.substring(24,32),2);
			if(seqNO == rn) {
				rn = (rn + 1)%(sw * 2);
				sendAck(rn,dest_mac);
			}
			else if(seqNO != rn && !nakSent) {
				sendNak(rn,source_mac);
				nakSent = true;
				if(checkInWindow(seqNO) && !marked[seqNO]) {
					//storeframe[seqNO];
					marked[seqNO] = true;
					while(marked[rn]) {
						marked[rn] = false;
						System.out.println("Message-"
								+ rn
								+ " received: " 
								+ msg.substring(32) 
								+ " from client: " 
								+ source_mac);
						rn = (rn+1)%(sw*2);
						ackNeeded = true;
					}

					if (ackNeeded) {
						sendAck(rn,source_mac);
						ackNeeded = false;
						nakSent = false;
					}
				}
			}	
		}
	}
		/*
		if(info.equals(MESSAGE_HEADER)) {
			if(seqNO == rn) {
				System.out.println("Message-" 
						+ rn
						+ " received: " 
						+ msg.substring(24) 
						+ " from client: " 
						+ source_mac);
				rn = (rn + 1)%(sw * 2);
				System.out.println("Sending Awk-" 
						+ Integer.parseInt(makeSequenceString(rn),2)
						+ " to:" + source_mac);
				super.sendMsg(AWK_HEADER + makeSequenceString(rn) ,SENDER_MAC_ADDR);
			}
		}
		*/
}
