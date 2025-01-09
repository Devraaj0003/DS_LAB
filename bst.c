#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(struct node **current, int data) {
    if (*current == NULL) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        *current = newnode;
    } else if (data < (*current)->data) {
        insert(&(*current)->left, data);
    } else {
        insert(&(*current)->right, data);
    }
}


void inorder(struct node* root){
    if(root ==NULL) return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

void postorder(struct node* root){
    if(root ==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}

void preorder(struct node* root){
    if(root ==NULL) return;
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node *minNode(struct node *cur){
    while (cur->left != NULL){
        cur = cur->left;
    }
    return cur;
}

struct node *delete(struct node *root,int data){
    if (root == NULL){
        printf("\nNot found\n");
    }else if (data < root->data ){
        root->left = delete(root->left, data);
    }else if (data > root->data){
        root->right = delete(root->right, data);
    }else{
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
            struct node * temp = minNode(root->right);
            root->data = temp->data;
            root->right =delete(root->right,temp->data);
        
    }
        return root;
}

int main(){
    int c,data;
    while(c){
        printf("\n1. Insert a node\n2. Inorder Traversal\n3. Postorder Traversal\n4. Preorder Traversal \n5. Delete\n6. Exit\n\n");
        scanf("%d",&c);
        switch(c){
            case 1: printf("Enter the item: ");
                    scanf("%d",&data);
                    insert(&root,data);
                    break;
            case 2: inorder(root);
                    break;
            case 3: postorder(root);
                    break;
            case 4: preorder(root);
                    break;
            case 5: printf("Enter the item to be deleted: ");
                    scanf("%d",&data);
                    root = delete(root,data);
                    break;
            case 6: exit(0);
            
        }
    }
}