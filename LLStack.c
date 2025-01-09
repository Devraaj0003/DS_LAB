#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
int size,count = 0;


struct node * head = NULL;

void in_beg(){
    int data;
    printf("Enter the element to be pushed: \n");
    scanf("%d",&data);
    if (count <size){
        struct node *newnode = (struct node *)malloc(sizeof(struct node)); 
        newnode->data = data;
        newnode->next= head;
        count++;
        head = newnode;
        printf("element pushed");
    }else{
        printf("\nStack Overflow\n");
    }
}


void del_beg(){
    if (count!=0){    
        printf("%d is deleted",head->data);
        head = head->next;
        count--;
    }else{
         printf("\nStack Underflow\n");
    }
}


void display(){
    struct node *cur =head;
    while(cur->next!=NULL){
        printf("%d<->",cur->data);
        cur = cur->next;
    }
    printf("%d<->",cur->data);
}

int main(){
    int c;
    printf("Enter the size of stack:");
    scanf("%d",&size);
    while(c){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n\n");
        scanf("%d",&c);
        switch(c){
            case 1: in_beg();
                    break;
            case 2: del_beg();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            
        }
    }
}
