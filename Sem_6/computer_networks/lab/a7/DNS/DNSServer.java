import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

public class DNSServer {
  private static Map<String, String> records;

  private static void fillRecords() {
    records = new HashMap<String, String>();
    records.put("google.com", "123.123.8.8");
    records.put("amazon.com", "124.123.8.8");
    records.put("sahil.com", "8.8.8.8");

    //for(String x : records.keySet())
    //  System.out.println(x+" "+records.get(x));
  }

  public static void main(String args[]) throws Exception {
    fillRecords();
    DatagramSocket ds = new DatagramSocket(8888);

    byte[] data = new byte[1024];

    while (true) {
      DatagramPacket dp = new DatagramPacket(data, data.length);
      ds.receive(dp);

      String url = new String(dp.getData()).trim();

      System.out.println("Request for:" + url + " => " +records.get(new String(url)));

      String ipaddr = records.get(url);
      if (ipaddr == null) ipaddr = "DNS entry not found";
      byte[] data1 = ipaddr.getBytes();
      DatagramPacket dp1 =
          new DatagramPacket(data1, data1.length, InetAddress.getLocalHost(), dp.getPort());
      ds.send(dp1);
    }
    // ds.close();
  }
}
