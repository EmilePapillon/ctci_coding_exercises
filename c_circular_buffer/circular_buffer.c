/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct buffer{
    int value; 
    struct buffer * next;
} buffer;

buffer getNextBuffer(buffer buf){
    return *buf.next;
}

// initializes a new buffer and sets the next to null
buffer * init_buffer(int first_value){
    buffer * new_buffer = malloc(sizeof(buffer));
    new_buffer->value=first_value;
    new_buffer->next=NULL;
    return new_buffer;
}

// appends an element at the end of the buffer
void put(buffer *buf, int new_value){
    buffer * last_buf = buf;
    while(last_buf->next != NULL){
        last_buf = last_buf->next;
    }
    buffer * next_buffer = malloc(sizeof(buffer));
    next_buffer->value=new_value;
    next_buffer->next = NULL;
    last_buf->next = next_buffer;
}

//returns the first element of the buffer and removes it
int pop(buffer * buf){
    int val = buf->value;
    buffer * to_delete = buf;
    buf = buf->next;
    free(to_delete);
    return val;
}

//prints all the values in the linked list
void printall(buffer * buf){
    buffer * to_print = buf;
    printf("%d\n",to_print->value);
    while (to_print->next != NULL){
        to_print = to_print->next;
        printf("%d\n",to_print->value);
    }
}

void f(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    /*
    buffer * my_ll = init_buffer(5);
    
    for (int i = 0; i < 10; i++){
        put(my_ll, i);
    }
    printf("Printing all values: \n");
    printall(my_ll);
    printf("pop: %d\n", pop(my_ll));
    printf("Printing all values: \n");
    printall(my_ll);
    printf("pop: %d\n", pop(my_ll));
    return 0;
    */
    int a=5;
    int b=6;
    f(&a,&b);
    printf("%d, %d", a,b);
    return 0;
}
