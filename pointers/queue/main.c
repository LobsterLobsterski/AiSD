#include <stdio.h>
#include <stdlib.h>

int top=-1;
int *queue;

///adds an element to the end of the queue
void enqueue(int element){
    top++;
    queue[top] = element;
}

///overwrites size-1 elements removing the first
///value and then shortening the queue
void dequeue(int size){
    for(int i=1; i<size;i++){
        queue[i-1] = queue[i];
    }
    top--;
}



int main()
{
    ///allocating space in memory for the queue
    int size=5;
    queue = (int *) malloc(sizeof(int) * size);

    ///adding values to the queue
    for (int i=0;i<size;i++){
        enqueue(i+1);
    }

    printf("Queue after adding values \n \n");

    for (int i=0;i<top+1;i++){
        printf("queue[%d]: %d \n", i, queue[i]);
    }

    ///removing a value from the queue
    dequeue(size);

    printf("\n Queue after removing a value \n \n");

    for (int i=0;i<top+1;i++){
        printf("queue[%d]: %d \n", i, queue[i]);
    }

}
