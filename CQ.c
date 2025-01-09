#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[max],data,front =-1,rear =-1;

void insert(){
    if((rear+1)%max == front){
        printf("Queue Overflow");
    }else {
        if(rear == -1){
        front = 0;
        }

        printf("Enter the element: ");
        scanf("%d",&data);
        rear =(rear+1)%max;
        q[rear] = data;

    }
}
void delete(){
    if(front == -1){
        printf("Queue Underflow");
    }else {
        printf("Element deleted: %d\n", q[front]);

        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % max;
        }
    }

}

void display(){
     if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", q[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % max;
        }
        printf("\n");
    }
}


int main(){
    int c;
    while(c){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
        scanf("%d",&c);
        switch(c){
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            
        }
    }
}