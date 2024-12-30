#include <stdio.h>
#include <stdlib.h>
#define INF 9999
#define MAX_NODES 10
// Function to initialize distance vector and routing table
void initialize(int numNodes, int costMatrix[MAX_NODES][MAX_NODES], int distVector[MAX_NODES][MAX_NODES], int nextHop[MAX_NODES][MAX_NODES])
{
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            distVector[i][j] = costMatrix[i][j];
            if (costMatrix[i][j] != INF && i != j)
            {
                nextHop[i][j] = j;
            }
            else
            {
                nextHop[i][j] = -1;
            }
        }
    }
}
// Function to print routing table for each node
void printRoutingTable(int numNodes, int distVector[MAX_NODES][MAX_NODES], int nextHop[MAX_NODES][MAX_NODES])
{
    for (int i = 0; i < numNodes; i++)
    {
        printf("Routing table for node %d:\n", i);
        printf("Destination\tNext Hop\tDistance\n");
        for (int j = 0; j < numNodes; j++)
        {
            if (distVector[i][j] == INF)
            {
                printf("%d\t\t-\t\tINF\n", j);
            }
            else
            {
                printf("%d\t\t%d\t\t%d\n", j, nextHop[i][j], distVector[i][j]);
            }
        }
        printf("\n");
    }
}
// Function to implement Distance Vector Routing algorithm
void distanceVectorRouting(int numNodes, int costMatrix[MAX_NODES][MAX_NODES], int distVector[MAX_NODES][MAX_NODES], int nextHop[MAX_NODES][MAX_NODES])
{
    int updated;
    do
    {
        updated = 0;
        for (int i = 0; i < numNodes; i++)
        {
            for (int j = 0; j < numNodes; j++)
            {
                for (int k = 0; k < numNodes; k++)
                {
                    if (distVector[i][k] + distVector[k][j] < distVector[i][j])
                    {
                        distVector[i][j] = distVector[i][k] + distVector[k][j];
                        nextHop[i][j] = nextHop[i][k];
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);
}
int main()
{
    int numNodes, costMatrix[MAX_NODES][MAX_NODES];
    int distVector[MAX_NODES][MAX_NODES];
    int nextHop[MAX_NODES][MAX_NODES];
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the cost matrix (use %d for INF):\n", INF);
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            scanf("%d", &costMatrix[i][j]);
        }
    }
    initialize(numNodes, costMatrix, distVector, nextHop);
    distanceVectorRouting(numNodes, costMatrix, distVector, nextHop);
    printRoutingTable(numNodes, distVector, nextHop);
    return 0;
}