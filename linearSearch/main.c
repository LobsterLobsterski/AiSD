#include <stdio.h>
#include <stdlib.h>

///linearSearch

int main()
{
    int nums[10];
    int find;
    int found=0;

    ///a loop which adds elements to the array
    printf("Enter 10 integers: \n");
    for (int i=0; i<10; i++){
        scanf("%d", &nums[i]);
    }

    ///setting the wanted value
    printf("Enter an integer to find: \n");
    scanf("%d", &find);

    ///it the wanted value is equal to the ith element of nums
    ///output and break out of the loop
    for(int i=0; i<10; i++){
        if (find==nums[i]){
            printf("The element is under index %d \n", i);
            printf("Where the index is in memory %d \n", &i);
            printf("Where the element is in memory %d \n", &nums[i]);
            found=1;
            break;
        }
    }
    ///if the value wasnt found, declare so
    if (found==0){
        printf("The element is not in the list");
    }


    return 0;
}
