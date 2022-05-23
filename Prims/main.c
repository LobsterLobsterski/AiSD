#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define INFINITY 99999999
#define MAX 11

void prim(int G[MAX][MAX], int n, int startNode)
{

    int parent[MAX], weight[MAX];
    bool included[MAX];
    int i, j;

    //parent[] stores the constructed tree
    //weight[] holds the values used to find minimum weight edge
    //count holds the number of nodes seen so far

    //initialising the tables
    //we at first assume that no connections
    //exist
    for(i=0;i<n;i++){
        weight[i]=INFINITY;
        included[i]=false;
    }

    //initialises startNode indexes of
    //tables as we want to start here
    weight[startNode]=0;
    parent[startNode]=-1;


    for(i=0;i<n-1;i++){
        //finding minimal weight from the set
        //of vertices not in included[]
        int min = INFINITY, minIndex;
        ///printf("\ni=%d",i);
        for (int j = 0; j < n; j++){
            ///printf("\n\tj=%d",j);
            if (included[j] == false && weight[j] < min){
                min = weight[j];
                minIndex = j;
                ///printf("\n\tmin=%d and minIndex=%d", min, minIndex);
            }
        }
        //adding the vertex behind the min weight
        //to the set of included vertices
        included[minIndex]=true;

        //
        for (j=0; j<n;j++){
            //G[minIndex][j] is not a zero for adjacent vertices
            //parent[j] is false for vertices not yet included in the tree
            //update only if the adjacent vertex is smaller than the current
            //weight of the trail to that vertex
            if(G[minIndex][j]>0 && included[j]==false && G[minIndex][j]<weight[j]){
                parent[j] = minIndex;
                weight[j]=G[minIndex][j];
                ///printf("\n \t\tvertex %d added a new edge with weight %d", parent[j], weight[j]);
            }
        }

    }

    //outputting the constructed tree
    printf("\nEdge \tWeight\n");
    for (int i = 0; i < n; i++){
        if (i!=startNode){
            printf("%c - %c \t%d \n", (char)(parent[i]+65), (char)(i+65), G[i][parent[i]]);
        }
    }
    printf("\n\nNOTE: this is not the sequence the program goes through its just the output loop that arranges it that way");
    printf("\nTo see how it works uncomment the triple dash(///) comments and rerun\n");

}

int main()
{
    //setting the matrix up and
    //declaring the starting node

    int G[MAX][MAX], i, j, n, u;
    printf("Enter no. of vertices: (up to 11)");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&G[i][j]);
        }
    }

    printf("\nEnter the starting node: ");
    scanf("%d",&u);
    prim(G,n,u);
    return 0;
}

/*
adjacency matrix for the
graph from the script

0 0 1 4 5 5 0 0 22 0 0
0 0 16 0 0 0 0 0 3 30 0
1 16 0 1 0 0 0 0 0 0 0
4 0 1 0 1 0 0 0 0 0 0
5 0 0 1 0 12 0 0 0 0 0
5 0 0 0 12 0 27 0 0 0 0
0 0 0 0 0 27 0 5 0 10 18
0 0 0 0 0 0 5 0 5 20 0
22 3 0 0 0 0 0 5 0 25 0
0 30 0 0 0 0 10 20 25 0 3
0 0 0 0 0 0 18 0 0 3 0
*/
