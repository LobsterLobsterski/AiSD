#include <stdio.h>
#include <stdlib.h>

int top=-1;
int *stack;

///function checking whether our stack is empty or not
_Bool stack_empty(int top){
    if (top == -1){
            printf("stack empty \n");
            return 1;
    }
    else{
            printf("stack not empty \n");
            return 0;
    }
}

///function returning the top element of the stack
int Top(){
    return stack[top];
}

///function which adds elements to the top of the stack
void push(int element){
    top++;
    stack[top] = element;
    //printf("\n stack[top]: %d &stack[top]: %d top: %d", stack[top], &stack[top], top);
}

///function which 'removes' (ignores) the top element as long as there is a top element
void pop(){
    if (stack_empty(top)==0){
        top--;
    }
}


int main()
{
    ///allocating space in memory for the stack
    int size= 6;
    stack = (int *) malloc(sizeof(int) * size);

    ///adding values to the stack
    for (int i=0;i<6;i++){
        push(i+1);
    }

    printf("Stack after adding values \n \n");

    for (int i=0;i<top+1;i++){
        printf("stack[%d]: %d \n", i, stack[i]);
    }

    printf("\n Stack after taking values away \n");

    ///'removing' values from the stack
    pop();
    pop();

    for (int i=0;i<top+1;i++){
        printf("stack[%d]: %d \n", i, stack[i]);
    }

    printf("\n Calling Top function, stack[top] = %d \n", Top());
}
