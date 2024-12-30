#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function to convert an IP address to a 32-bit integer
unsigned int ipToInt(char *ip)
{
    unsigned int a, b, c, d;
    sscanf(ip, "%u.%u.%u.%u", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}
// Function to convert a 32-bit integer to an IP address
void intToIp(unsigned int ip, char *buffer)
{
    sprintf(buffer, "%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}
// Function to calculate the subnet mask from a prefix length
unsigned int calculateSubnetMask(int prefixLength)
{
    return prefixLength == 0 ? 0 : ~((1 << (32 - prefixLength)) - 1);
}
int main()
{
    char ip[16];
    int prefixLength, newPrefixLength;
    unsigned int subnetMask, newSubnetMask, ipInt;
    char buffer[16];
    // Input IP address and prefix length
    printf("Enter IP address (e.g., 192.168.1.0): ");
    scanf("%s", ip);
    printf("Enter current prefix length (e.g., 24): ");
    scanf("%d", &prefixLength); // New prefix length for creating two subnets
    newPrefixLength = prefixLength + 1;
    // Convert IP address to integer
    ipInt = ipToInt(ip);
    // Calculate original subnet mask and new subnet mask
    subnetMask = calculateSubnetMask(prefixLength);
    newSubnetMask = calculateSubnetMask(newPrefixLength);
    // Calculate the number of hosts per subnet
    int hostsPerSubnet = (1 << (32 - newPrefixLength)) - 2; // subtract 2 for network and broadcast addresses
    printf("\nNumber of subnets: 2\n");
    printf("Number of hosts per subnet: %d\n", hostsPerSubnet);
    // Generate subnets
    for (int i = 0; i < 2; i++)
    {
        unsigned int subnetNetwork = (ipInt & subnetMask) | (i << (32 - newPrefixLength));
        unsigned int subnetBroadcast = subnetNetwork | ~newSubnetMask;
        unsigned int firstHost = subnetNetwork + 1;
        unsigned int lastHost = subnetBroadcast - 1;
        printf("\nSubnet %d:\n", i + 1);
        printf("Network Address: ");
        intToIp(subnetNetwork, buffer);
        printf("%s\n", buffer);
        printf("Broadcast Address: ");
        intToIp(subnetBroadcast, buffer);
        printf("%s\n", buffer);
        printf("Subnet Mask: ");
        intToIp(newSubnetMask, buffer);
        printf("%s\n", buffer);
        printf("First Host: ");
        intToIp(firstHost, buffer);
        printf("%s\n", buffer);
        printf("Last Host: ");
        intToIp(lastHost, buffer);
        printf("%s\n", buffer);
    }
    return 0;
}