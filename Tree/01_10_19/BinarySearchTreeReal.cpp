#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    TreeNode *left, *right;
    int key;
}TreeNode;

TreeNode* InitNode(int data){
    TreeNode* NewNode = (TreeNode*)malloc(sizeof(TreeNode*));
    NewNode->key = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}

TreeNode* insert_node(TreeNode* root, int data){
   if(root == NULL)  return InitNode(data);
   
   if(data < root->key) root->left = insert_node(root->left, data);
   else if(data > root->key) root->right = insert_node(root->right, data);
   else if(data == root->key){
        printf("이미 존재 함. 넣을 수 없습니다. 다시 입력 하세요. "); //다시 못 넣게 돼있음.
   }

   return root;
}

void Preorder(TreeNode *root){
    if(root == NULL ) return;

    printf("%d ", root->key);
    Preorder(root->left);
    Preorder(root->right);
}

void preorder(TreeNode *root){
    printf("[Preorder] ");
    Preorder(root);
    printf("\n");
}

void Search(TreeNode* root, int sn){
    int n=1;
    if(root == NULL) return;

    while(root != NULL ){
        if(sn == root->key){
        printf("찾는 값이 있고 %d번째에 있음.\n",n);
        return;
        }
        if(sn <  root->key){
            root = root->left;
            n++;
        }
        else if(sn >  root->key){
            root = root-> right;
            n++;
        }
    }
    printf("찾는 값 없음.\n");
}

TreeNode* min_value(TreeNode *node){
    
    while(node->left != NULL) node = node->left;
    return node;
}

TreeNode* DeleteNode(TreeNode* root, int data){
    if(root == NULL ) return root;
    
    if(data < root->key )
    {
        root->left = DeleteNode(root->left, data);
    }
    else if(data > root->key) root->right = DeleteNode(root->right, data);
    else{
        if(root->left == NULL){
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        
        TreeNode* temp = min_value(root->right);
        root->key = temp->key;
        root->right = DeleteNode(root->right,temp->key );
    }
    return root;
}

TreeNode* Delete(TreeNode* root, int dn){
    printf("삭제 할 값 ");
    scanf("%d",&dn);
    printf("[Delete %d]",dn);
    return DeleteNode(root, dn);
}

int main(void){
    TreeNode * root = NULL;
    int i,num,sn,dn;

    for(i=0 ; i<5 ; i++){
        scanf("%d",&num);
        root = insert_node(root, num);
    }
    preorder(root);
    printf("[Search] ");
    scanf("%d",&sn);
    Search(root,sn);
    root = Delete(root, dn);
    preorder(root);
    return 0;
}
