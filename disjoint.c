#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int parent[MAX];
int rank[MAX];

void makeset(int n){
    for( int i = 1; i <= n; i++){
        parent[i]= i;
        rank[i] = 0;
    }
}

int find(int x){
    if (parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}


void unionset(int x, int y){
    int rootx = find(x);
    int rooty = find(y);
    
    if ( rootx == rooty){
        printf("Both belong to same set");
        return;
    }
    if (rank[rootx] > rank[rooty]){
        parent[rooty] = rootx;
    }else if(rank[rooty] > rank[rootx]){
        parent[rootx] = rooty;
    }else{
        parent[rooty] = rootx;
        rank[rootx]++;
    }
    printf("Union Completed");
}

void display(int n){
    for (int i = 1; i <= n; i++){
        printf("%d -> %d\n",i,find(i));
    }
}

int main(){
    int c,item1,item2,n;
    printf("enter the size of the set:");
    scanf("%d",&n);
    makeset(n);

    while(c){
        printf("\n1. Find\n2. Union\n3. Display\n4.Exit\n\n");
        scanf("%d",&c);
        
        switch(c){
            case 1: printf("Enter a element to be find : ");
                    scanf("%d",&item1);
                    printf("parent of %d is %d ",item1, find(item1));
                    break;
            case 2: printf("Enter 2 number to be unioned: ");
                    scanf("%d%d",&item1,&item2); 
                    unionset(item1, item2);
                    break;
            case 3: display(n);
                    break;
            case 4: exit(0);
        }
    }
}