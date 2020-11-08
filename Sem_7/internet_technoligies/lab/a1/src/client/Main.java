package client;

class Main {
  public static void main(String args[]) {
    String hostname = "localhost";
    int port = Integer.parseInt(args[0]);
    Client client = new Client(hostname, port);
    client.run();
  }
}
