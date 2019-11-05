#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    TreeNode *left, *right;
    int key;
}TreeNode;

void PrintMenu(){
    printf("메뉴)\n");
    printf("1. 원소 등록\n2. 원소 내역(중위순회)\n3. 원소 검색\n4. 원소 개수\n5. 원소 삭제\n6. 종료\n");
}

TreeNode** InitNode(int data){
    TreeNode** Newnode = (TreeNode**)malloc(sizeof(TreeNode));
    (*Newnode)->left = NULL;
    (*Newnode)->right = NULL;
    (*Newnode)->key = data;
    return Newnode;
}

TreeNode** addtree(TreeNode * root, int data){
    if(root == NULL) return InitNode(data);
    if(data < root->key){
        root->left = addtree((*root).left, data);
    }
    else if(data> root->key){
        root->right = addtree(root->right, data);
    }
}

void AddTree(TreeNode ** root){
    int data;
    printf("입력) ");
    scanf("%d",&data);

    root = addtree(*root,data);
    
}

int main(void){
    TreeNode *root;
    int input = 0, loop = 1;

    while(loop){
        PrintMenu();
       scanf("%d",&input) ;
       switch(input){
            case 1: AddTree(&root);
            case 2: DisplayTree(&root);
            case 3: SearchTree(&root);
            case 4: GetSize(&root);
 //           case 5: RemoveTree(&root);
            case 6: loop = 0;
            default : printf("Wrong input...\n");
       }
    }
    return 0;
}
