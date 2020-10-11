package server;

import java.net.Socket;
import java.util.HashMap;

class ManagerClientHandler extends ClientHandler {
  private static final String c_PUT = "put";
  private static final String c_GET = "get";
  private static final String c_EXIT = "exit";
  private static final String EXIT_CMD = "EXIT";
  private HashMap<Integer, ClientHandler> users;

  public ManagerClientHandler(
      Socket soc, HashMap<String, String> data, HashMap<Integer, ClientHandler> users) {
    super(soc, data);
    this.users = users;
  }

  public void processReceivedMessage(String msg) {
    String msgs[] = msg.split(" ");

    try {
      for (int i = 0; i < msgs.length; i++) {
        String m = msgs[i];
        if (m.equals(c_PUT)) {
          String key = msgs[i + 1];
          String value = msgs[i + 2];
          super.data.put(key, value);
          i += 2;
        } else if (m.equals(c_GET)) {
          String key = msgs[i + 1];
          String value = super.data.get(key);
          super.sendMessage(value);
        } else if (m.equals(c_EXIT)) {
          super.sendMessage(EXIT_CMD);
          super.exit();
        }
      }
    } catch (Exception e) {
      super.sendMessage("Invalid command");
    }
  }
}
