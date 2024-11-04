/*Write a program to compute CRC code for the polynomials

sample 
input=11100011
11001
11100011
output=Enter data to be transmitted:                                         
Enter the Generating polynomial:                                           
Data padded with n-1 zeros : 111000110000CRC or Check value is : 0000Final data 
to be sent : 111000110000Enter the received data:                       
Data received: 11100011No error detected 

*/
#include<stdio.h>
#include<string.h>
// length of the generator polynomial  
#define N strlen(gen_poly)  
// data to be transmitted and received  
char data[28];  
// CRC value  
char check_value[28];  
// generator polynomial  
char gen_poly[10];  
// variables   
int data_length,i,j;  
// function that performs XOR operation  
void XOR(){  
    // if both bits are the same, the output is 0  
    // if the bits are different the output is 1  
for(j = 1;j < N; j++)  
check_value[j] = (( check_value[j] == gen_poly[j])?'0':'1');  

}  
void crc(){  
    // initializing check_value
    for(i=0;i<N;i++)  
check_value[i]=data[i];  
do{
    // check if the first bit is 1 and calls XOR function  
        if(check_value[0]=='1')  
XOR();  
// Move the bits by 1 position for the next computation  
        for(j=0;j<N-1;j++)  
check_value[j]=check_value[j+1];  
        // appending a bit from data  
check_value[j]=data[i++];  
}while(i<=data_length+N-1);  
// loop until the data ends  
}  

// Function to check for errors on the receiver side  
void receiver(){  
// get the received data  
printf("Enter the received data: ");  
scanf("%s", data);  
//printf("-----------------------------\n");  
printf("Data received: %s", data);  
// Cyclic Redundancy Check  
crc();  
// Check if the remainder is zero to find the error  
    for(i=0;(i<N-1) && (check_value[i]!='1');i++);  

if(i<N-1)  
printf("Error detected\n\n");  
        else  
printf("No error detected\n\n");  
}  


int main()  
{  
    // get the data to be transmitted  
printf("Enter data to be transmitted: ");  
scanf("%s",data);  
printf("Enter the Generating polynomial: ");  
    // get the generator polynomial  
scanf("%s",gen_poly);  
    // find the length of data  
data_length=strlen(data);  
    // appending n-1 zeros to the data  
    for(i=data_length;i<data_length+N-1;i++)  
        data[i]='0';  
//printf("----------------------------------------");  
// print the data with padded zeros  
printf("Data padded with n-1 zeros : %s",data);  
//printf("----------------------------------------");  
// Cyclic Redundancy Check  
crc();  
// print the computed check value  
printf("CRC or Check value is : %s",check_value);  
// Append data with check_value(CRC)    
    for(i=data_length;i<data_length+N-1;i++)  
        data[i]=check_value[i-data_length];  
//printf("----------------------------------------");  
// printing the final data to be sent  
printf("Final data to be sent : %s",data);  
//printf("----------------------------------------\n");  
// Calling the receiver function to check errors  
receiver();  
        return 0;  
}