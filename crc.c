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
#include <stdio.h>
#include <string.h>

void xorOperation(char dividend[], char generator[], int n)
{

    for (int i = 0; i < n; i++)
    {

        if (dividend[i] == generator[i])
            dividend[i] = '0';
        else
            dividend[i] = '1';
    }
}

void crc(char data[], char generator[], char crcCode[])

{

    int dataLen = strlen(data);
    int genLen = strlen(generator);
    char temp[128];
    strcpy(temp, data);
    for (int i = dataLen; i < dataLen + genLen - 1; i++)
    {
        temp[i] = '0';
    }
    temp[dataLen + genLen - 1] = '\0';
    char dividend[128];
    strncpy(dividend, temp, genLen);

    for (int i = 0; i < dataLen; i++)
    {

        if (dividend[0] == '1')
        {
            xorOperation(dividend, generator, genLen);
        }
        for (int j = 0; j < genLen - 1; j++)
        {

            dividend[j] = dividend[j + 1];
        }
        dividend[genLen - 1] = temp[i + genLen];
    }

    strncpy(crcCode, dividend, genLen - 1);
    crcCode[genLen - 1] = '\0';
}

int main()
{
    char data[128], generator[128], crcCode[128], transmitted[128];

    printf("Enter data to be transmitted: ");
    scanf("%s", data);

    printf("\nEnter the Generating polynomial: ");
    scanf("%s", generator);

    printf("\nData padded with n-1 zeros : ");
    crc(data, generator, crcCode);
    printf("%s%s", data, crcCode);

    printf("\nCRC or Check value is : %s", crcCode);

    strcpy(transmitted, data);
    strcat(transmitted, crcCode);
    printf("\nFinal data to be sent : %s", transmitted);


    printf("\nEnter the received data: ");
    scanf("%s", transmitted);

    printf("\nData received: %s", transmitted);

    crc(transmitted, generator, crcCode);

    if (strcmp(crcCode, "0000") == 0)
        printf("\nNo error detected\n");
    else
        printf("\nError detected\n");

    return 0;
}
