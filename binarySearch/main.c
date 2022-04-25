#include <stdio.h>
#include <stdlib.h>

///binarySearch


///bubbleSort
void bubbleSort(int tab[]){
    int temp;
    for (int i=0; i<10; i++){
        for (int j=0; j<10-i; j++){
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
    int nums[]={12, 1, 13, 2, 14, 3, 15, 4, 16, 5};
    int find;
    int found=0;

    ///sorting the numbers
    bubbleSort(nums);

    ///setting the wanted value
    printf("Enter an integer to find: \n");
    scanf("%d", &find);


    ///setting the start and end valuables which point
    ///towards the start and end of the array we are
    ///working with. These are used to calculate where
    ///the pivot is pointing to.

    int start=0;
    int end=9;
    int pivot;

    while(pivot != 0 && pivot!=9){
        pivot=start + (end-start)/2;
        //printf("Pivot:  %d \n", pivot);
        //printf("nums[pivot]:  %d \n", nums[pivot]);

        ///if the values is in the pivot, output
        if (find == nums[pivot]){
            printf("The element is under index %d \n", pivot);
            printf("Where the index is in memory %d \n", &pivot);
            printf("Where the element is in memory %d \n", &nums[pivot]);
            found=1;
        }
        ///if the value is bigger then the pivot element
        ///increase start to be 1 bigger then pivot
        ///such that when new pivot is calculated we
        ///consider only the upper half of the array
        else if(find > nums[pivot]){
            start=pivot+1;
        }
        ///if the value is smaller then the pivot element
        ///we do the same but decrease the end instead to
        ///consider the lower half of the array.
        else{
            end=pivot-1;
        }

        ///if the new pivot is equal to the old one
        ///then nothing is happening and we can
        ///stop trying to find a value
        if (pivot == (start + (end-start)/2)){
            break;
        }

    }
    if (found==0){
        printf("The element is not in the list");
    }

    return 0;
}
