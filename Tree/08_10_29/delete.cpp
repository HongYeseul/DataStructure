#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct TreeNode{
    TreeNode *left,*right;
    int key;
}TreeNode;

TreeNode* InitNode(int data){
    TreeNode* Node = (TreeNode *)malloc(sizeof(TreeNode));
    Node->left = NULL;
    Node->right = NULL;
    Node->key = data;
    return Node;
}

TreeNode* InsertNode(TreeNode* root, int data){
    if(root == NULL) return InitNode(data);

    else if(root->key > data) root->left = InsertNode(root->left, data);
    else if(root->key < data) root->right = InsertNode(root->right, data);
}

void level_order(TreeNode* root){
    queue<TreeNode *> q;

    if(root == NULL){
        printf("X\n"); return;
    }
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        printf("%d ",root->key);
        if(root->left != NULL){
            printf("\n") ;
            q.push(root->left);
        } 
        if(root->right != NULL){
            printf("\n");
            q.push(root->right);
        }

        if(root->left == NULL && root->right == NULL){
            printf("X ");
        }
        else if(root->left == NULL || root->right == NULL){
            printf("X ");
        }
        
    }
}

TreeNode* min(TreeNode* root){
    while(root->left == NULL){
        root = root->left;
    }
    return root;
}

TreeNode* delete_node(TreeNode* root, int data){
    if(root == NULL) return root;

    if(root->key > data) root->left = delete_node(root->left, data);
    else if(root->key < data) root->right = delete_node(root->right, data);
    else{

        if(root->left == NULL){
            TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
            temp = root->right;
            return temp;
            free(root);
        }
        else if(root->right == NULL){
            TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
            temp = root->left;
            return temp;
            free(root);
        }
        
        TreeNode* temp = min(root->right);
        root->key = temp->key;

        root->right = delete_node(root, data);
    }
    return root;
}

int main(void){
    TreeNode *root = NULL;
    int i,num,data;
    scanf("%d",&num);

    for(i=0 ; i<num ; i++){
        scanf("%d",&data);
        root = InsertNode(root, data);
    }
    level_order(root);
    printf("Delete Number : ");
    scanf("%d",&data);
    delete_node(root,data);
    level_order(root);
    return 0;
}
