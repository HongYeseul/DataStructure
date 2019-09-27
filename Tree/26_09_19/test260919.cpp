#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct TreeNode{
    TreeNode *right, *left;
    int data;
}Node;

TreeNode* InitNode(int key){
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;  
    return newnode;
}

TreeNode* make_tree(){
    TreeNode* n1 = InitNode(1);
    TreeNode* n2 = InitNode(2);
    TreeNode* n3 = InitNode(3);
    TreeNode* n4 = InitNode(4);
    TreeNode* n5 = InitNode(5);
    TreeNode* n6 = InitNode(6);
    TreeNode* n7 = InitNode(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n5->right = n7;
    return n1;
}

void level_order(Node* root){
    queue<Node*> q;
    
    printf("[Level order] ");
    if(root == NULL) return;
    q.push(root);
    while(!q.empty()){
        root = q.front() ;
        q.pop();
        printf("%d ",root->data);
        if(root->left != NULL) q.push(root->left);
        if(root->right != NULL) q.push(root->right);
    }
}

void pre_order(Node* root){
    if(root == NULL) return;
    if(root->data == 1)   printf("\n[Pre order] ");
    printf("%d ",root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void find_leafnodes(Node* root){
    if(root == NULL ) return;
    if(root->data == 1) printf("\n[Find leafnodes] ");
    if(root->left == NULL && root->right ==NULL)
        printf("%d ", root->data);
    
    find_leafnodes(root->left);
    find_leafnodes(root->right);

}

int sum1(Node* root){
    if(root == NULL) return 0;
    else  return sum1(root->left) + sum1(root->right) + root->data;
}

void sum(Node* root){
    if(root->data == 1) printf("\n[Sum] ");
    int dap = sum1(root);
    printf("%d\n",dap );
}

void print_tree(Node* root){
    printf("%d", (**root)->data);
}

int main(void){
    Node *root = make_tree();
    level_order(root);
    pre_order(root);
    find_leafnodes(root);
    sum(root);
    print_tree(root);
    return 0;
}
