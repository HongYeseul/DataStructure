#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

#ifndef TREE_H
#define TREE_H

typedef int element;

struct TreeNode{
    element data;
    struct TreeNode *left, *right;
};

TreeNode* TreeNodeInit(element data);

void TreeNodeLink(TreeNode *left, TreeNode *med, TreeNode *right);



#endif
