#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode{
    int data;
    struct ListNode *link; 
}ListNode;
void DisplayList (ListNode **);

void PrintMenu(){
    printf("메뉴)\n1. 원소등록\n2. 원소삭제\n3. 원소내역\n4. 원소검색\n5. 원소개수\n6. 종료\n입력)");
}
         
void AddList(ListNode **head){
    printf("등록원소) ");
    int data;

    scanf("%d",&data);
    ListNode *Newnode = (ListNode*)malloc(sizeof(ListNode));
    Newnode->data = data;
    Newnode->link = NULL; 
    
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    
    if(*head == NULL){
        *head = Newnode; 
    }
    else{
        for(p=*head; p->link != NULL ; p=p->link){}
        p->link = Newnode;
    }
  DisplayList(head) ;
}

void RemoveList(ListNode **head){
    printf("원소 삭제: ") ;
    int data;
    scanf("%d",&data) ;
    int num=0;

    if(*head == NULL){
        printf("Empty!\n");
        return;
    } 
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    for(p=*head ; p->data != data ; p = p->link ){
        num++;
        if(p->link==NULL){
            printf("존재하지않음\n");
            return;
        }
    }
    ////
    if(num == 0){
       *head = (*head)->link; 
    }
    else if(p->link == NULL)
    {
        for(p = *head; num<0 ; p=p->link) {
            num--;
        }
        p->link = NULL;
    }
    else{
        for(p=*head ; num<0 ; p=p->link) num--;
             p->link = p->link->link;
    } 
   DisplayList(head);
}

void DisplayList(ListNode **head){
    ListNode *p = *head;
   
   printf("\nList = ") ;
   if(p == NULL){
       printf("Empty\n");
       return;
   }

    for( ; p != NULL ; p= p->link){
           printf("%d ",p->data);
    } 
   printf("\n") ;
}


void Findlist(ListNode **head){
    ListNode *p = *head;
    int num;

    printf("원소 검색 : ");
    scanf("%d",&num);
    for( ; p!= NULL ; p = p->link ){
        if(p->data == num){
            printf("존재함");
            return;
        }
    } printf("존재 하지 않음");
}

void GetSize(ListNode **head){
    ListNode *p = *head;
    int num = 0;

    for( ; p!=NULL ; p= p->link){
        num++;
    }
    printf("%d개 있음\n",num);
}

void FreeList(ListNode **head){
    ListNode *temp, *p;

    for(p=*head ; p!=NULL ; p=p->link){
        temp = p;
        free(temp);
    }
}

int main(int argc, char* argv[]){
    
    ListNode *head = NULL;
    int input =  0 , loop = 1;

    while(loop){
        PrintMenu();
         scanf("%d",&input);

         switch(input){
            case 1: AddList(&head); break;
            case 2: RemoveList(&head); break;
            case 3: DisplayList(&head); break;
            case 4: Findlist(&head); break;
            case 5: GetSize(&head); break;
            case 6: loop = 0; break;
            default: printf("Wrong input...\n");
         
         }
    }
    FreeList(&head);

    return 0;
}
