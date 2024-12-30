import java.net.*;
import java.io.*;

// command to run : sudo java Ping.java <hostname>
public class Ping {
    public static void main(String[] args) {
        // Check if the user provided a hostname as an argument
        if (args.length != 1) {
            System.out.println("Usage: java Ping <hostname>");
            return;
        }
        String hostname = args[0]; // Get the hostname from command-line arguments
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