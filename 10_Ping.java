import java.net.*;
import java.io.*;

// command to run : sudo java Ping_10.java <hostname>
class Ping {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Ping_10 <hostname>");
            return;
        }
        String hostname = args[0];
        try {
            System.out.println("Pinging " + hostname + "...");
            InetAddress inetAddress = InetAddress.getByName(hostname);
            boolean isReachable = inetAddress.isReachable(5000);
            if (isReachable) {
                System.out.println("Host " + hostname + " is reachable.");
                System.out.println("IP Address: " + inetAddress.getHostAddress());
            } else {
                System.out.println("Host " + hostname + " is not reachable.");
            }
        } catch (UnknownHostException e) {
            System.out.println("Unknown host: " + hostname);
        } catch (IOException e) {
            System.out.println("Error occurred while pinging " + hostname + ": " + e.getMessage());
        }
    }
}