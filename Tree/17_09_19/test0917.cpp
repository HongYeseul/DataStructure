#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void PrintListData(const char str1[], ListNode* list){
    printf("%s%d\n",str1,list->data);
}

ListNode* GetNewNode(element num){
    ListNode *list3 = (ListNode *)malloc(sizeof(ListNode));
    list3->data = num;
    list3->link = NULL;
    return list3;
}

void Assign(ListNode *list2, ListNode **p){
    *p = list2;
}

int main(int argc, char* argv[]){
    ListNode *list1 = (ListNode *)malloc(sizeof(ListNode));
    list1->data = 100;
    PrintListData("list1->data = ",list1);

    ListNode *list2 = GetNewNode(1);
    PrintListData("list2->data = ",list2);

    ListNode *p = NULL;
    Assign(list2, &p);
    p->data = 10;
    PrintListData("list2->data = ",list2);

    free(list1);
    free(list2);
    return 0;
}
