package client;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {
  private Socket m_soc;
  private PrintWriter m_out;
  private BufferedReader m_in;
  private Thread m_listenerThread;

  private class Listener implements Runnable {
    public void run() {
      try {
        while (m_soc.isConnected()) {
          if (m_in.ready()) {
            String msg = m_in.readLine();
            System.out.println(msg);
          }
        }
      } catch (IOException e) {
        e.printStackTrace();
        System.exit(0);
      }
    }
  }

  private void runSender() {
    Scanner sc = new Scanner(System.in);
    while (true) {
      String msg = sc.nextLine();
      m_out.println(msg);
    }
  }

  public void run() {
    m_listenerThread = new Thread(new Listener());
    m_listenerThread.start();
    runSender();
  }

  public Client(String hostname, int port) {
    try {
      m_soc = new Socket(hostname, port);
      System.out.println("Connection established with server!");
      m_out = new PrintWriter(m_soc.getOutputStream(), true);
      m_in = new BufferedReader(new InputStreamReader(m_soc.getInputStream()));
    } catch (Exception e) {
      e.printStackTrace();
      System.exit(0);
    }
  }
}
