#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
void insertionStart(struct node** head,int value){
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=*head;
    if(*head!=NULL)
        (*head)->prev=newNode;
    *head=newNode;
}
void insertionEnd(struct node** head,int value){
    struct node *newNode,*ptr=*head;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->data=value;
    if(*head==NULL){
        newNode->prev=NULL;
        *head=newNode;
    }
    else{
       while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newNode;
        newNode->prev=ptr;
    }
}
void insertionMid(struct node** head,int pos,int value){
    struct node *newNode,*ptr;
    ptr=*head;
    int count=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    ptr=*head;
    if(pos>1&&count>=pos){
        while(--pos){
            ptr=ptr->next;
        }
        printf("ptr data %d",ptr->data);
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->next=ptr;
        newNode->data=value;
        newNode->prev=ptr->prev;
        ptr->prev->next=newNode;
    }
    else{
        printf("you select a wrong option\n");
    }
   
}
void deleteFront(struct node** head){
    if(*head==NULL){
        printf("It is already empty\n");
    }
    else if((*head)->next==NULL){
        printf("Delete %d\n",(*head)->data);
        free(*head);
        *head=NULL;
    }
    else{
        printf("Delete %d\n",(*head)->data);
        (*head)=(*head)->next;
        free((*head)->prev);
        (*head)->prev=NULL;
    }
}
void deleteEnd(struct node** head){
    struct node* ptr=*head;
    if(*head==NULL){
        printf("It is already empty\n");
    }
    else if((*head)->next==NULL){
        printf("Delete %d\n",(*head)->data);
        free(*head);
        *head=NULL;
    }
    else{
        while(ptr->next->next!=NULL)
            ptr=ptr->next;
         printf("Delete %d\n",ptr->next->data);
         free(ptr->next);
         ptr->next=NULL;
        
    }
    
}
void deleteMid(struct node** head,int pos){
    struct node* ptr=*head;
    int count=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    ptr=*head;
    if(pos>1&&count>=pos){
        while(--pos)
            ptr=ptr->next;
        printf("Delete %d\n",ptr->data);
        ptr->prev->next=ptr->next;
        free(ptr);
        ptr=NULL;
    }
    else{
        printf("Wrong input\n");
    }
}
void view(struct node* head){
    if(head==NULL)
        printf("List is Empty");
    else{
        printf("\nDouble linked list \n");
        while(head!=NULL){
            printf("%d\n",head->data);
            head=head->next;
        }
        printf("\n");
    }
}
void main(){
    struct node* head=NULL;
    int dis ,value,pos;
    do{
        printf("1-INSERTION AT START\n2-INSERTION AT END\n3-INSERTION AT INTERMEDIATE POSITION\n4-DELETE FORM FRONT\n5-DELETE FORM END\n6-DELETE FORM INTERMEDIATE POSITION\n7-EXIT\nENTER :");
        scanf("%d",&dis);
        switch(dis){
            case 1:printf("Enter value :");
                    scanf("%d",&value);
                    insertionStart(&head,value);
                    view(head);
                    break;
            case 2:printf("Enter value :");
                    scanf("%d",&value);
                    insertionEnd(&head,value);
                    view(head);
                    break;
            case 3:printf("Enter value :");
                    scanf("%d",&value);
                    printf("Enter position :");
                    scanf("%d",&pos);
                    insertionMid(&head,pos,value);
                    view(head);
                    break;
            case 4:deleteFront(&head);
                    view(head);
                    break;
            case 5:deleteEnd(&head);
                    view(head);
                    break;
            case 6: printf("Enter position :");
                    scanf("%d",&pos); 
                    deleteMid(&head,pos);
                    view(head);
                    break;
            default :printf("Wrong input\n");
        }

    }while(dis!=7);
}