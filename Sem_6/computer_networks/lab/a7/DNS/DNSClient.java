import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class DNSClient {
  public static void main(String args[]) throws Exception {
    String url = args[0];
    DatagramSocket ds = new DatagramSocket();

    byte[] data = url.getBytes();
    DatagramPacket dp = new DatagramPacket(data, data.length, InetAddress.getLocalHost(), 8888);

    ds.send(dp);

    byte[] data2 = new byte[1024];
    DatagramPacket dp1 = new DatagramPacket(data2, data2.length);
    ds.receive(dp1);

    String ipaddr = new String(dp1.getData());
    System.out.println(ipaddr);
  }
}
