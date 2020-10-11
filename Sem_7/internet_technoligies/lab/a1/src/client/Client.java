package client;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {
  private static final String GUEST_PROMPT = "$ ";
  private static final String MANAGER_PROMPT = "# ";
  private static final String EXIT_CMD = "EXIT";
  private static final String c_UPGRADE = "upgrade";
  private static final String c_DOWNGRADE = "downgrade";
  private Socket m_soc;
  private PrintWriter m_out;
  private BufferedReader m_in;
  private Thread m_listenerThread;
  private String prompt = GUEST_PROMPT;
  protected boolean m_exit = false;

  private class Listener implements Runnable {

    public void run() {
      try {
        while (m_soc.isConnected() && !m_exit) {
          if (m_in.ready()) {
            String msg = m_in.readLine();
            if (msg.equals(EXIT_CMD)) {
              m_exit = true;
              System.out.println("Press any key to close");
            } else if (msg.equals(c_UPGRADE)) upgrade();
            else if (msg.equals(c_DOWNGRADE)) downgrade();
            System.out.println("\r" + msg);
            System.out.print(prompt);
          }
        }
      } catch (IOException e) {
        e.printStackTrace();
        System.exit(0);
      }
    }
  }

  protected void upgrade() {
    prompt = MANAGER_PROMPT;
  }

  protected void downgrade() {
    prompt = GUEST_PROMPT;
  }

  private void runSender() {
    Scanner sc = new Scanner(System.in);
    while (!m_exit) {
      System.out.print(prompt);
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
