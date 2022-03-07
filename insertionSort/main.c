#include <stdio.h>
#include <stdlib.h>


//takes 2nd element of array and compares it to
//the 1st one, if 1st is bigger then it goes to
//the 2nd's index. This is then repeated for all
//values where the nth goes through all the values
//to the left and is placed where it needs to be
void insertionSort(int tab[]){
    int temp;
    int j;
    for(int i=1; i<15; i++){
        temp=tab[i];
        j=i-1;
        while(j>=0 && tab[j]>temp){
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1]=temp;
    }
}

int main()
{
    //printf("is");
    int tab[] = {4, 14, 13, 12, 11, 9, 10, 8, 7, 6, 5, 3, 2, 1, 0};

    insertionSort(tab);

    for (int i=0; i<15; i++){
        printf("%d \n", tab[i]);

    }
}
