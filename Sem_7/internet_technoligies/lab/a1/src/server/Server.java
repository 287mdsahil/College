package server;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Scanner;

public class Server {
  private static final String c_UPGRADE = "upgrade";
  private static final String c_DOWNGRADE = "downgrade";
  private static final String c_LIST = "list";
  private ServerSocket m_serverSocket;
  private static final int PORT = 8888;
  private HashMap<Integer, ClientHandler> users;

  protected void listUsers() {
    for (int userPort : users.keySet()) {
      if (users.get(userPort) instanceof GuestClientHandler) System.out.print("Guest:");
      else System.out.print("Manager:");

      System.out.println(userPort);
    }
  };

  protected void upgradeUser(int port) {
    System.out.println("Upgrading " + port);
    ClientHandler user = users.get(port);
    ClientHandler new_user = new ManagerClientHandler(user.getSoc(), user.getData(), users); 
    users.replace(port, new_user);
    new Thread(new_user).start();
    user.stop();
    new_user.sendMessage(c_UPGRADE);
  };

  protected void downgradeUser(int port) {
    System.out.println("Downgrading " + port);
    ClientHandler user = users.get(port);
    ClientHandler new_user = new GuestClientHandler(user.getSoc(), user.getData()); 
    users.replace(port, new_user);
    new Thread(new_user).start();
    user.stop();
    new_user.sendMessage(c_DOWNGRADE);
  };

  private class Terminal implements Runnable {
    boolean m_exit = false;

    public void run() {
      Scanner sc = new Scanner(System.in);
      while (!m_exit) {
        System.out.print("# ");
        String cmd = sc.nextLine();
        String cmds[] = cmd.split(" ");
        try {
          for (int i = 0; i < cmds.length; i++) {
            String cm = cmds[i];
            if (cm.equals(c_LIST)) {
              listUsers();
            } else if (cm.equals(c_UPGRADE)) {
              upgradeUser(Integer.parseInt(cmds[i + 1]));
            } else if (cm.equals(c_DOWNGRADE)) {
              downgradeUser(Integer.parseInt(cmds[i + 1]));
            }
          }
        } catch (Exception e) {
          System.out.println("Invalid command");
        }
      }
    }
  }

  public void run() {
    try {
      users = new HashMap<Integer, ClientHandler>();
      m_serverSocket = new ServerSocket(PORT);
      System.out.println("Server started at :" + InetAddress.getLocalHost().getHostAddress());
      new Thread(new Terminal()).start();
      while (true) {
        Socket soc = m_serverSocket.accept();
        GuestClientHandler guest = new GuestClientHandler(soc);
        users.put(soc.getPort(), guest);
        new Thread(guest).start();
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
