#include <stdio.h>

int main()
{
    int window = 0;
    printf("enter Window size : ");
    scanf("%d", &window); // User inputs the window size for transmission.

    int sent = 0; // Tracks the number of frames sent.
    int ack;      // Variable to store the acknowledgment received from the receiver.

    while (1)
    {
        for (int i = 0; i < window; i++)
        {
            printf("frame Transmitted %d\n", sent); // Print the frame-number being transmitted.
            sent++;                                 // Increment the count of sent frames.
            if (sent == window)
                break; // If all frames in the window are sent, break the loop.
        }

        printf("enter last received acknowledgment : ");
        scanf("%d", &ack); // User inputs the last acknowledgment received.

        if (ack == window - 1)
            break; // If the last acknowledgment is equal to window size - 1, exit the loop.
        else
        {
            sent = ack; // If the acknowledgment is not for the last frame, set sent to the last acknowledged frame.
        }
    }
}