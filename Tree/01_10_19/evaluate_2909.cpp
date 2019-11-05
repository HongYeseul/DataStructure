#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    TreeNode *left, *right;
    int key;
}TreeNode;

TreeNode* InitNode(int data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode*));
    node->left = NULL;
    node->right = NULL;
    node->key = data;
    return node;
}

TreeNode* MakeTree(){
    TreeNode* n1 = InitNode(1);
    TreeNode *n2 = InitNode(4);
    TreeNode *n3 = InitNode('*');
    TreeNode *n4 = InitNode(16);
    TreeNode *n5 = InitNode(25);
    TreeNode *n6 = InitNode('+');
    TreeNode *n7 = InitNode('+');
    n7->left = n3;
    n7->right = n6;
    n3->left = n1;
    n3->right = n2;
    n6->left = n4;
    n6->right = n5;

    return n7;
}

int evaluate(TreeNode * node){
    if(node == NULL) return 0;
    if(node->left == NULL && node->right == NULL) return node->key;
    else{
        int op1 = evaluate(node->left);
        int op2 = evaluate(node->right);
        printf("%d %c %d 계산 \n",op1,node->key,op2);
        switch(node->key){
            case '+': return op1+op2;
            case '-': return op1-op2;
            case '*':return op1*op2;
            case '/': return op1/op2;
        }
    
    }
    return 0;
}

int main(void){
    TreeNode *root = MakeTree();
    int dap = evaluate(root);
    printf("dap : %d\n",dap);
    return 0;
}
