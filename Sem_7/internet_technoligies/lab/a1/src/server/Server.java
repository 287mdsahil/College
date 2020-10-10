package server;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
  private ServerSocket m_serverSocket;
  private static final int PORT = 8888;

  public void run() {
    try {
      m_serverSocket = new ServerSocket(PORT);
      System.out.println("Server started at :" + InetAddress.getLocalHost().getHostAddress());
      while(true) {
        Socket soc = m_serverSocket.accept();
        new Thread(new GuestClientHandler(soc)).start();
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
