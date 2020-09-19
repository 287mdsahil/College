package ft;

public class Ft {
  enum Type {
    SEND,
    RECEIVE;
  }

  private static Type type;
  private static String filename;
  private static String address;

  private static void printInvalidArgsMessage(String code) {
    System.out.println(code);
    System.out.println("Invalid arguments");
    System.out.println("Syntax to send:-  $ Ft send <filename>");
    System.out.println("Syntax to receive:-  $ Ft receive <filename> <address>");
    System.exit(0);
  }

  private static void parseArgs(String args[]) {
    if (args.length < 2) printInvalidArgsMessage("0");

    if (args[0].toLowerCase().equals("send")) type = Type.SEND;
    else if (args[0].toLowerCase().equals("receive")) type = Type.RECEIVE;
    else printInvalidArgsMessage("1");

    filename = args[1];

    if (type == Type.RECEIVE) {
      if (args.length < 3) printInvalidArgsMessage("2");
      address = args[2];
    }
  }

  public static void main(String args[]) {
    parseArgs(args);
    if (type == Type.SEND) {
      Server server = new Server(8888);
      server.sendFile(filename);
    } else if (type == Type.RECEIVE) {
      String[] addr = address.split(":");
      Client client = new Client(addr[0], Integer.parseInt(addr[1]));
      client.receiveFile(filename);
    }
  }
}
