package server;
import java.net.Socket;

class GuestClientHandler extends ClientHandler {
  public GuestClientHandler(Socket soc) {
    super(soc);
  }

  public void processReceivedMessage(String msg) {
    super.sendMessage("Received");
  }
}
