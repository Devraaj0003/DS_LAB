#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node * head = NULL;

void in_beg(){
    int data;
    printf("Enter the element: \n");
    scanf("%d",&data);
    struct node *newnode = (struct node *)malloc(sizeof(struct node)); 
    newnode->data = data;
    newnode->link= head;
    head = newnode;
    printf("Inserted at begining");
}
void in_end(){
    int data;
    printf("Enter the element:");
    scanf("%d",&data);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    struct node *cur= head;
    while(cur->link != NULL){
        cur = cur->link;
    }
    cur->link = newnode;
    newnode->link= NULL;
}

void in_pos(){
    int data,pos,i=1;

    printf("enter the position:");
    scanf("%d",&pos);

    struct node *cur = head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (pos == 1){
        in_beg();
    }else{
        printf("enter the element: ");
        scanf("%d",&data);
        while(i<pos-1){
            cur = cur->link;
            i++;
        }
        newnode->data = data;
        newnode->link = cur->link;
        cur->link = newnode;
    }
}

void del_beg(){
    printf("%d is deleted",head->data);
    head = head->link;
}
void del_end(){
    struct node * cur = head;
    while(cur->link->link != NULL){
        cur = cur->link;
    }
        printf("%d is deleted",cur->link->data);
        cur->link = NULL;
}

void del_pos(){
    int pos,i=1;
    struct node *cur = head;
    printf("enter a position:");
    scanf("%d",&pos);
    if (pos ==1){
        del_beg();
    }else{
        while(i<pos-1){
            cur = cur->link;
            i++;
        }
        printf("%d is deleted",cur->link->data);
        cur->link = cur->link->link;
    }

}

void display(){
    struct node *cur =head;
    while(cur->link!=NULL){
        printf("%d->",cur->data);
        cur = cur->link;
    }
    printf("%d->",cur->data);
}

int main(){
    int c;
    while(c){
        printf("\n1. Insert at begin\n2. Inserted at end\n3. Insert at position\n4. Delete at begin\n5. Delete at end\n6. Delete at position\n7. Display\n8. Exit\n\n");
        scanf("%d",&c);
        switch(c){
            case 1: in_beg();
                    break;
            case 2: in_end();
                    break;
            case 3: in_pos();
                    break;
            case 4: del_beg();
                    break;
            case 5: del_end();
                    break;
            case 6: del_pos();
                    break;
            case 7: display();
                    break;
            case 8: exit(0);
            
        }
    }
}
