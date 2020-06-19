<------------------------coversion into balance tree------------------------>
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void PreOrder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d \t",root->data);
    PreOrder(root->left);
    PreOrder(root->right);

}

int max(int a, int b){
    return (a>=b) ? a:b;
}

int height(struct node *root){
    if(root == NULL){return 0;}
    return 1 + max(height(root->left), height(root->right));
}

struct node *ConvertToBST(int arr[],int start,int end){
    if (start>end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    //divide and conquer algo for converting a array of int into BST
    struct node *root = newNode(arr[mid]);
    root->left = ConvertToBST(arr,start,mid-1);
    root->right = ConvertToBST(arr,mid+1,end);
    return root;
    
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    struct node *root = ConvertToBST(arr,0,5);
    printf("Traversing the BST:\n");
    PreOrder(root);
    printf("\n Height of the tree = %d\n",height(root));
    return 0;
}
