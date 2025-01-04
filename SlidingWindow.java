import java.util.Scanner;

public class SlidingWindow {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for window size and number of frames
        System.out.print("Enter window size: ");
        int n = scanner.nextInt();

        System.out.print("Enter number of frames to transmit: ");
        int f = scanner.nextInt();

        // Input for frames
        int[] frames = new int[30]; // Array to hold the frames
        System.out.println("Enter " + f + " frames:");
        for (int i = 1; i <= f; i++) {
            frames[i] = scanner.nextInt();
        }

        // Displaying the sliding window protocol output
        System.out.println(
                "With sliding window protocol, the frames will be sent in the following manner (assuming no corruption of frames):");
        System.out.println(
                "After sending " + n + " frames at each stage, sender waits for acknowledgment sent by the receiver.");

        // Sending frames and receiving acknowledgment
        for (int i = 1; i <= f; i++) {
            if (i % n == 0) {
                System.out.print(frames[i] + " ");
                System.out.println("Acknowledgment of above frames sent is received by sender.");
            } else {
                System.out.print(frames[i] + " ");
            }
        }

        // If the last batch doesn't fit perfectly in the window, acknowledgment is
        // received after all frames are sent
        if (f % n != 0) {
            System.out.println("Acknowledgment of above frames sent is received by sender.");
        }

        scanner.close(); // Close the scanner
    }

}