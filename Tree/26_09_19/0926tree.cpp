#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    TreeNode * left, *right;
    int data;
}TreeNode;

TreeNode* InitNode(int key){
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int preorder(TreeNode* root){
   
    if(root == NULL) return 0;
    else {
        printf("%d ",root->data);
         
        return preorder(root->left)+preorder(root->right)+root->data; 
    }
}

void inorder(TreeNode* root){
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);

}

void postorder(TreeNode* root) {
    if(root == NULL)return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(void){
    TreeNode* n1 = InitNode(1);
    TreeNode* n2 = InitNode(2);
    TreeNode* n3 = InitNode(3);
    int hap1;

    n1->left = n2;
    n1->right = n3;
    
    printf("전위 ");
    hap1  = preorder(n1); //전위순회
    printf("\n hap : %d",hap1);

    printf("\n중위 ");
    inorder(n1); //중위 순회
    printf("\n후위 ");
    postorder(n1);
    return 0;
}
