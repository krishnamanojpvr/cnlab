#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10

int next_frame_to_receive = 0;
int next_frame_to_send = 0;    
bool frames_acknowledged[TOTAL_FRAMES] = {false};
int ack_last = -1;
void sender();
void receiver(int frame);

int main(){
    srand(time(0));
    printf("Go back starts :\n");
    sender();
    printf("simulation complete");
    return 0;
}

void sender(){
    while (ack_last<TOTAL_FRAMES-1)
    {
    for (int i = next_frame_to_send ; i < (next_frame_to_send+WINDOW_SIZE) && i<TOTAL_FRAMES; i++)
    {
        if(!frames_acknowledged[i]){
            printf("Sender : sent %d\n",i);
            receiver(i);
        }
    }

    int ack = next_frame_to_receive-1;
    if(ack>ack_last)
    {
        printf("Sender : acknowledgement till frames : %d\n",ack);
        for (int i = ack_last+1; i <= ack; i++)
        {
            frames_acknowledged[i] = true;
        }
        ack_last = ack;
        next_frame_to_send = ack+1;

    }
    else{
        printf("Sender : No acknowledgement , sending all outstanding frames from %d\n",next_frame_to_send);
    }
    
    usleep(500000);
    }
    
}

void receiver(int frame){
    int f = rand() % 5;
    if(f==0){
        printf("Receiver : frame %d lost\n",frame);
    }
    else if(frame==next_frame_to_receive){
        printf("Receiver : frame %d is received\n",frame);
        next_frame_to_receive++;
    }
    else{
        printf("Receiver : frame %d is discarded\n",frame);
    }
}