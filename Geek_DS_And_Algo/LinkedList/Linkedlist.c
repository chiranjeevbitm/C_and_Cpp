
#include <stdio.h>
#include <stdlib.h>
//#include<malloc.h>

int main(){
    struct node{
        int i;
        struct node *next;
    };
    typedef struct node NODE;

    NODE *head , *first , *temp = 0;
    int count = 0;
    int n;
    printf("Enter no of element to insert\n");
    scanf("%d" ,&n);
    while(n--){
        head = (NODE *) malloc (sizeof(NODE));
        printf("Enter the data item\n");
        scanf("%d",&head->i);
        if(first!=0){
            temp->next =head;
            temp = head;

        }
        else{
            first = temp = head;
        }

    }
    temp ->next =0;
    // reset temp to the beginning
    temp = first;
    printf("\n Status of the linked list is \n");
    while(temp !=0){
        printf("%d=>",temp->i);
        //count++;
        temp = temp ->next;
    }
}
