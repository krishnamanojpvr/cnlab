/*Develop a simple data link layer that performs the flow control using the Go Back N protocol in   “c”

Sample

*/
#include<stdio.h>
int main()
{
               int window=0;
	printf("enter Window size : ");
	scanf("%d",&window);
	int sent,ack,i=0;
	while(1){
		for(i=0;i<window;i++){
			printf("frame Transmitted %d \n",sent);
			sent++;
			if(sent==window){
				break;
			}
		}
		printf("enter last received acknowledgment : ");
		scanf("%d",&ack);
		if(ack==window){
			break;
		}
		else{
			sent = ack;
			}
	}
}