import java.net.*;
import java.util.Scanner;

public class DNS_9 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a domain name :");
        String domain = scanner.nextLine();
        try {
            InetAddress[] addresses = InetAddress.getAllByName(domain);
            System.out.println("IP addresses for " + domain + ":");
            for (InetAddress address : addresses) {
                System.out.println(" - " + address.getHostAddress());
            }
        } catch (UnknownHostException e) {
            System.out.println("Could not resolve domain: " + e.getMessage());
        }
        scanner.close();
    }
}