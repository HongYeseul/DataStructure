#include <stdio.h>
#include <stdlib.h>

typedef int element; 
typedef struct TreeNode{
    TreeNode *left, *right;
    element key;
}TreeNode;

TreeNode* NewNode( element data ){
    TreeNode* node = (TreeNode *)malloc(sizeof(TreeNode *));
    
    node->left = NULL;
    node->right = NULL;
    node->key = data;
    return node;
}

TreeNode* InsertNode(TreeNode* root, element data){
    
    if(root == NULL) return NewNode(data);

    if(data < root->key) root->left = InsertNode(root->left, data);
    else if(data > root->key) root->right = InsertNode(root->right, data);
    
    return root;
}

void preorder(TreeNode* root){
    if(root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void Preorder(TreeNode* root){
    printf("[Preorder] ");
    preorder(root);
}

int main(void){
    TreeNode *root = NULL;
    int i,num,data;
    scanf("%d",&num);
    for(i=0 ; i<num ; i++){
        scanf("%d",&data);
        root = InsertNode(root, data);
    }
    Preorder(root);
    return 0;
}
