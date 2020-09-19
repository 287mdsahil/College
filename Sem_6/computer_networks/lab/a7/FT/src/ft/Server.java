package ft;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
  private int port;
  private ServerSocket sc;
  private Socket soc;
  private int wordSize;
  public static final int SERVER_ERROR = 500;

  public Server(int port) {
    this.port = port;
    wordSize = 2048;
    try {
      sc = new ServerSocket(this.port);
      System.out.println(
          "Server successfully started on address: "
              + InetAddress.getLocalHost().getHostAddress()
              + ":"
              + Integer.toString(this.port));
    } catch (Exception e) {
      System.err.println("Failed to open server port!");
      e.printStackTrace();
      System.exit(SERVER_ERROR);
    }
  }

  public void sendFile(String filename) {
    System.out.println("Waiting for client...");
    try {
      soc = sc.accept();
    } catch (IOException e) {
      System.err.println("Failed to open server port!");
      e.printStackTrace();
      System.exit(SERVER_ERROR);
    }
    System.out.println("Connection established");
    try {
      File file = new File(filename);
      System.out.println("Sending file...");
      FileInputStream fis = new FileInputStream(file);
      BufferedInputStream bis = new BufferedInputStream(fis);
      OutputStream os = soc.getOutputStream();

      long fileSize = file.length();
      System.out.println("File size:" + Long.toString(fileSize));
      long current = 0;
      while (current < fileSize) {
        long size = this.wordSize;
        if (fileSize - current < size) size = fileSize - current;
        current = current + size;
        byte[] word = new byte[(int) size];
        bis.read(word, 0, (int) size);
        os.write(word);
        System.out.print("\rSending file ... " + (current * 100) / fileSize + "% complete!");
      }

      os.flush();
      bis.close();
      soc.close();
      sc.close();
      System.out.println("\nFile sent successfully");

    } catch (IOException e) {
      System.err.println("Failed to sendFile!");
      e.printStackTrace();
      System.exit(SERVER_ERROR);
    }
  }

  public static void main(String args[]) {
    Server server = new Server(8888);
    String filename = "./test.jpg";
    server.sendFile(filename);
  }
}
