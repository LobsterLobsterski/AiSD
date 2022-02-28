#include <stdio.h>
#include <stdlib.h>

void selectionSort(int tab[]){
    int min;
    int temp;
    for (int j=0;j<11;j++){
        min=j;
        for(int i=j+1; i<11; i++){
            if (tab[min]>tab[i]){
                min=i;
            }
        }
        temp=tab[j];
        tab[j]=tab[min];
        tab[min]=temp;
    }
}

int main()
{
    int tab[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0};

    selectionSort(tab);

    for(int i=0; i<11; i++){
        printf("%d ", tab[i]);
    }

    return 0;
}
