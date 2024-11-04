#include<stdio.h>

int main(){
	int n,f,frames[30],i;
	printf("Enter window size : ");
	scanf("%d",&n);
	printf("Enter number of frames to transmit: ");
	scanf("%d",&f);
	printf("Enter %d frames: \n",f);
	for(i=1;i<=f;i++){
		scanf("%d",&frames[i]);
	}
	printf("With sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n");
	printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n",n);

	for(i=1;i<=f;i++){
		if(i%n==0){
			printf("%d ",frames[i]);
			printf("Acknowledgement of above frames sent is received by sender\n");

		}
		else{
			//printf("recieved by sender\n");
			printf("%d ",frames[i]);
		}
	}
	if(f%n!=0){
	printf("Acknowledgement of above frames sent is received by sender\n");

	}
}
