import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ThreadedEchoServer {

    static final int PORT = 3330;

    public static void main(String args[]) {
        ServerSocket serverSocket = null;
        Socket socket = null;

        try {
            serverSocket = new ServerSocket(PORT);
        } catch (IOException e) {
            e.printStackTrace();

        }
        while (true) {
            try {
                socket = serverSocket.accept();
            } catch (IOException e) {
                System.out.println("I/O error: " + e);
            }
            // new thread for a client
            new EchoThread(socket).start();
        }
    }
}

class EchoThread extends Thread {
    protected Socket socket;

    public EchoThread(Socket clientSocket) {
        this.socket = clientSocket;
    }

    public void run() {

        DataOutputStream dout = null;
        DataInputStream din = null;
        try {
            din = new DataInputStream(this.socket.getInputStream());
            dout = new DataOutputStream(this.socket.getOutputStream());

        } catch (IOException e) {
            e.printStackTrace();
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        String str = "", str2 = "";
        while (!str.equals("stop")) {
            try {
                str = din.readUTF();
                System.out.println("client says: " + str);
                str2 = br.readLine();
                dout.writeUTF(str2);
                dout.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }



    }
}