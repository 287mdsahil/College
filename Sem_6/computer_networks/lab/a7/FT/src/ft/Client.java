package ft;

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class Client {
  private int port;
  private String host;
  private Socket soc;
  private int wordSize;
  public static final int CLIENT_ERROR = 501;

  public Client(String host, int port) {
    this.port = port;
    this.host = host;
    this.wordSize = 2048;
  }

  public void receiveFile(String filename) {
    try {
      soc = new Socket(this.host, this.port);
    } catch (IOException e) {
      System.err.println("Failed to create connection");
      e.printStackTrace();
      System.exit(CLIENT_ERROR);
    }
    System.out.println("Connection established with " + host + ":" + Integer.toString(port));
    System.out.println("Waiting for server to send...");
    byte[] word = new byte[wordSize];

    try {
      FileOutputStream fos = new FileOutputStream(filename);
      BufferedOutputStream bos = new BufferedOutputStream(fos);
      InputStream is = soc.getInputStream();

      int bytesRead = 0;
      while ((bytesRead = is.read(word)) != -1) bos.write(word, 0, bytesRead);
      bos.flush();
      soc.close();
      System.out.println("File transered successfully!");
    } catch (IOException e) {
      System.err.println("Failed to receive data");
      e.printStackTrace();
      System.exit(CLIENT_ERROR);
    }
  }

  public static void main(String args[]) {
    Client client = new Client("localhost", 8888);
    client.receiveFile("data.bin");
  }
}
