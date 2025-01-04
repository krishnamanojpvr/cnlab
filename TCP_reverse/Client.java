package TCP_reverse;

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        String hostname = "127.0.0.1";
        int port = 65432;
        try (Socket socket = new Socket(hostname, port)) {
            System.out.println("Connected to the server");
            // Create input and output streams for communication
            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true);
            InputStream input = socket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
            // Read user input
            BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));
            String text;
            System.out.println("Enter a sentence to reverse (or type 'exit' to quit):");
            while (true) {
                System.out.print(">> ");
                text = consoleReader.readLine();
                if ("exit".equalsIgnoreCase(text)) {
                    System.out.println("Closing connection...");
                    break;
                }
                // Send the sentence to the server
                writer.println(text);
                // Receive the reversed sentence from the server
                String reversedText = reader.readLine();
                System.out.println("Reversed sentence: " + reversedText);
            }
        } catch (UnknownHostException ex) {
            System.out.println("Server not found: " + ex.getMessage());
        } catch (IOException ex) {
            System.out.println("I/O error: " + ex.getMessage());
        }
    }
}