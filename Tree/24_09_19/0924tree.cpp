#include "tree.h"

int main(void){
    
    TreeNode* root = NULL;
    int input = 0; loop = 1;

    while(loop){
        PrintMenu();
        scanf("%d",&input);
         switch(input){
            case 1: AddNode(&root);
            case 2: RemoveNode(&root);
            case 3: DisplayNode(&root);
            case 4: FindNode(&root);
            case 5: GetSize(&root);
            case 6: loop = 0;
            default : printf("Wrong input...\n");
         }
    }
    return 0;
}

void AddNode(TreeNode **root){
    int key;
    scanf("%d", &key);
    stack<TreeNode*> s;

    if(*root == NULL){
        (*root)->data = key;
    }
    else if(*)
}

void CreateNode(TreeNode *node, int key){
    
    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->data = key; 
}

void PrintMenu(){
    printf("");
}
