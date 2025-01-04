import java.util.Scanner;

public class GoBackN2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Window size: ");
        int window = scanner.nextInt();  // User inputs the window size for transmission.

        int sent = 0;  // Tracks the number of frames sent.
        int ack;       // Variable to store the acknowledgment received from the receiver.

        while (true) {
            for (int i = 0; i < window; i++) {
                System.out.println("Frame Transmitted " + sent);  // Print the frame-number being transmitted.
                sent++;  // Increment the count of sent frames.
                if (sent == window) break;  // If all frames in the window are sent, break the loop.
            }

            System.out.print("Enter last received acknowledgment: ");
            ack = scanner.nextInt();  // User inputs the last acknowledgment received.

            if (ack == window - 1) {
                break;  // If the last acknowledgment is equal to window size - 1, exit the loop.
            } else {
                sent = ack;  // If the acknowledgment is not for the last frame, set sent to the last acknowledged frame.
            }
        }

        scanner.close();  // Close the scanner to avoid resource leak.
    }
}
