#include <stdio.h>
#include <stdlib.h>

//it takes the first element of the unsorted part of the array
//and compares it to the second one and if its bigger they swap
//then the 2nd and 3rd are compared and so on and so forth
//this results in a single value bubbling up to the end
//the first for ensure we go through all the values
void bubbleSort(int tab[]){
    int temp;
    for (int i=0; i<15-1; i++){
        for (int j=0; j<15-i-1; j++){
            if(tab[j] > tab[j+1]){
                temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}

int main()
{
    //printf("bs \n");
    int tab[] = {13, 14, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    bubbleSort(tab);//calling the method

    for (int i=0; i<15; i++){//outputting the contents of the sorted array
        printf("%d \n", tab[i]);

    }

}
