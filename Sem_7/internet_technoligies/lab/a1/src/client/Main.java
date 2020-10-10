package client;

class Main {
  public static void main(String args[]) {
    String hostname = "localhost";
    int port = 8888;
    Client client = new Client(hostname, port);
    client.run();
  }
}
