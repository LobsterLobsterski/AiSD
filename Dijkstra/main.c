#include<stdio.h>
#include<conio.h>
#define INFINITY 99999999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startNode)
{

    int cost[MAX][MAX], distance[MAX], predecessors[n];
    int visited[MAX], count, minDistance, nextNode, i, j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",G[i][j]);
        }
        printf("\n");
    }

    //predecessors[] stores the predecessor of each node
    //distance[] holds the distances to all vertices
    //count holds the number of nodes seen so far

    //create the cost matrix
    //which is the same matrix as
    //adjacency matrix but the
    //distances of 0 signifying that
    //there is no connect are replaced
    //with INFINITY so that 0 don't
    //interfere with finding better
    //paths through nextNode
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
        }
    }

    //initialize predecessors[], distance[] and visited[]
    for(i=0;i<n;i++){
        distance[i]=cost[startNode][i];
        predecessors[i]=startNode;
        visited[i]=0;
    }

    //initialises startNode indexes of
    //tables as we don't need to go
    //through them
    distance[startNode]=0;
    visited[startNode]=1;
    count=1;

    //
    while(count<n-1){
        ///printf("\n Count = %d \n",count);
        minDistance=INFINITY;

        //finds nextNode which is a node which
        //has not been visited yet and is the
        //closest to the starting node
        for(i=0;i<n;i++){
            if(distance[i]<minDistance&&!visited[i]){
                minDistance=distance[i];
                nextNode=i;
            }
        }

        ///printf("minDistance = %d \n",minDistance);
        ///printf("nextNode = %d \n",nextNode);

        //checks if a better path exists through nextNode
        //it goes through and checks only the unvisited nodes
        //if a better path was discovered from a 'further away'
        //node then we update the distance to the new one
        //which goes through more nodes
        visited[nextNode]=1;
        for(i=0;i<n;i++){
            if(!visited[i]){
                ///printf("minDistance+cost[%d][%d]<distance[%d] = %d + %d < %d \n",nextNode, i, i, minDistance, cost[nextNode][i], distance[i]);

                if(minDistance+cost[nextNode][i]<distance[i]){
                    ///printf("\n true\n");

                    distance[i]=minDistance+cost[nextNode][i];
                    predecessors[i]=nextNode;

                    ///printf("distance[%d] = %d \n \n",i, distance[i]);
                }
            }
        }
        count++;
    }

    //prints the path and distance to each node
    for(i=0;i<n;i++){
        if(i!=startNode){
            printf("\nShortest distance to node%d = %d",i,distance[i]);
            printf("\nPath=%d",i);
            j=i;
            do{
                j=predecessors[j];
                printf("<-%d",j);
            }while (j!=startNode);
            printf("\n");
        }
    }
}

int main()
{
    //setting the matrix up and
    //declaring the starting node

    int G[MAX][MAX], i, j, n, u;
    printf("Enter no. of vertices: (up to 10)");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&G[i][j]);
        }
    }

    printf("\nEnter the starting node:");
    scanf("%d",&u);
    dijkstra(G,n,u);
    return 0;
}

/*
adjacency matrix for the
graph from the script
0 6 0 1 0
6 0 5 2 2
0 5 0 0 5
1 2 0 0 1
0 2 5 1 0
*/
