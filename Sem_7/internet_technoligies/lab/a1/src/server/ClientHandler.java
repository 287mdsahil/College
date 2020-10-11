package server;

import java.io.*;
import java.net.Socket;
import java.util.HashMap;

public abstract class ClientHandler implements Runnable {
  private Socket m_soc;
  private PrintWriter m_out;
  private BufferedReader m_in;
  protected HashMap<String, String> data;
  boolean m_exit = false;

  public ClientHandler(Socket soc) {
    m_soc = soc;
    data = new HashMap<String, String>();
    try {
      m_out = new PrintWriter(soc.getOutputStream(), true);
      m_in = new BufferedReader(new BufferedReader(new InputStreamReader(soc.getInputStream())));
    } catch (IOException e) {
      e.printStackTrace();
      System.exit(0);
    }
  }

  public ClientHandler(Socket soc, HashMap<String, String> d) {
    m_soc = soc;
    data = new HashMap<String, String>(d);
    try {
      m_out = new PrintWriter(soc.getOutputStream(), true);
      m_in = new BufferedReader(new BufferedReader(new InputStreamReader(soc.getInputStream())));
    } catch (IOException e) {
      e.printStackTrace();
      System.exit(0);
    }
  }

  public Socket getSoc() {
    return m_soc;
  }

  public HashMap<String, String> getData() {
    return data;
  }

  protected void sendMessage(String msg) {
    m_out.println(msg);
  }

  protected void exit() {
    try {
      m_soc.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  protected abstract void processReceivedMessage(String msg);

  public void run() {
    System.out.println("Connected to :" + m_soc.getRemoteSocketAddress().toString());

    try {
      while (!m_soc.isClosed() && !m_exit) {
        if (m_in.ready()) {
          String msg = m_in.readLine();
          System.out.println("\r" + m_soc.getPort() + ": " + msg);
          System.out.print("# ");
          processReceivedMessage(msg);
        }
      }
    } catch (IOException e) {
      e.printStackTrace();
      System.exit(0);
    }
  }

  public void stop() {
    m_exit = true;
  }
}
