#include <stdio.h>
#include <stdlib.h>

int size=0;

void heapify(int tab[], int size, int i)
{
    if (size==2){
        printf("Only root and 1 child so no need to check \n \n");
    }
    else{
        //printf("i= %d", i);
        //printf("\n");

        int max=i;//max=parent idx
        int left=2*i+1;
        int right=left+1;

        //printf("parent element= %d", tab[max]);
        //printf("\n");
        //printf("left element= %d", tab[left]);
        //printf("\n");
        //printf("right element= %d", tab[right]);
        //printf("\n \n");

        if (left<size && tab[left]>tab[max]){
            //printf("left bigger \n");
            max=left;
        }
        if (right<size && tab[right]>tab[max]){
            //printf("right bigger \n");
            max=right;
        }
        if (max!=i){
            //printf("max != element of parent idx \n \n");
            //printf("tab[max] = %d ", tab[max]);
            //printf("\n");
            change(&tab[i], &tab[max]);
            //printf("tab[parent] = %d ", tab[i]);
            //printf("\n");
            //printf("tab[swapped] = %d ", tab[max]);
            //printf("\n");
            heapify(tab, size, max);
        }

    }
}

void change(int *x, int*y)
{
    int temp=*y;
    *y=*x;
    *x=temp;
}

void insert(int tab[], int newValue)
{
    if (size==0){
        tab[0]=newValue;
        size++;

        //printf("tab[0]= %d", tab[0]);
        //printf("\n");
    }
    else{
        tab[size]=newValue;
        size++;

        //printf("size= %d", size);
        //printf("\n");
        //printf("tab[size-1]= %d", tab[size-1]);
        //printf("\n");
        for (int i=size/2-1; i>=0; i--){//parent idx
            //printf("i going into heapify= %d", i);
            //printf("\n");
            //printf("\n");
            heapify(tab, size, i);
        }
    }
}

void deleteRoot(int tab[], int deleteNum)
{
    change(&tab[0], &tab[size-1]);
    size--;
    heapify(tab, size, 0);
}

int main()
{
    int tab[10];

    for (int i=0; i<10; i++){
        //num = (rand() % (upper – lower + 1)) + lower
        insert(tab, (rand()%51));
    }

    printf("heap: \n");
    for (int i=0; i<10; i++){
        printf(" %d", tab[i]);
    }

    return 0;
}
