/*Develop a simple datalink layer that performs the flow control using the sliding window protocol

sample output
Enter window size : 3
Enter number of frames to transmit: 5
Enter 5 frames:
1
2
5
8
9

With sliding window protocol the frames will be sent in the following manner (as
suming no corruption of frames)

After sending 3 frames at each stage sender waits for acknowledgement sent by th
e receiver

1 2 5
Acknowledgement of above frames sent is received by sender

8 9
Acknowledgement of above frames sent is received by sender
*/

#include <stdio.h>
int main()
{
    int k; // window size
    printf("Enter window size : ");
    scanf("%d", &k);

    int noOfFrames;
    printf("Enter number of frames to transmit: ");
    scanf("%d", &noOfFrames);

    // create a array of frames
    int frames[noOfFrames];
    printf("Enter %d frames:\n", noOfFrames);
    for (int i = 0; i < noOfFrames; i++)
    {
        scanf("%d", &frames[i]);
    }

    printf("With sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n");

    printf("\nAfter sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n", k);

    for (int i = 0; i < noOfFrames; i += k)
    {
        for (int j = i; j < i + k; j++)
        {
            if (j < noOfFrames)
                printf("%d ", frames[j]);
        }
        printf("\nAcknowledgement of above frames sent is received by sender\n\n");
    }
}