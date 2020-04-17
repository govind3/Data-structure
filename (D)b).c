/*********** Code by GOVIND KUMAR  ************/
//b.  Double ended queue ADT Implementation using  Doubly linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*front=NULL,*rear=NULL;

typedef struct node Node;

void createfirstnode() //Creates first node
{
     int data;
     front=(Node*)malloc(sizeof(Node));
     if(front==NULL)
     {
         printf("Memory not allocated");
         return;
     }
     printf("\nEnter node data : ");
     scanf("%d",&data);
     front->data=data;
     front->prev=NULL;
     front->next=NULL;
     rear=front;
}

void insert_front() //Inserts from Front
{
    int data;
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory not allocated");
        return;
    }
    printf("\nEnter node data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=front;
    temp->prev=NULL;
    front=temp;
    if(rear==NULL)
        rear=temp;
    while((rear->next)!=NULL)
        rear=rear->next;
}

void insert_rear() //Inserts from Rear
{
    int data;
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory not allocated");
        return;
    }
    while((rear->next)!=NULL)
        rear=rear->next;
    printf("\nEnter node data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    temp->prev=rear;
    rear->next=temp;
    rear=temp;
    if(front==NULL)
        front=temp;
}

void delete_front() //Deletes from Front
{
    if(front==NULL)
    {
        printf("\nDeque is empty !!!");
        return ;
    }
    Node *temp=front;
    front=temp->next;
    front->prev=NULL;
    free(temp);
}

void delete_rear() //Deletes from Rear
{
    if(rear==NULL)
    {
        printf("\nDeque is empty !!!");
        return ;
    }
    Node *temp=rear;
    rear=temp->prev;
    rear->next=NULL;
    free(temp);
}

void display()     //Traverses the list
{
    Node *temp=front;
    printf("\nYour list is : ");
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main() //Driver Function
{
    int option=0;
    while(1)
    {
        printf("\n1.insert at front end\n");
        printf("2.insert at rear end\n");
        printf("3.delete from front end\n");
        printf("4.delete from rear end\n");
        printf("5.display\n");
        printf("6.Exit\n");
        printf("Enter your option: \n");
        scanf("%d",&option);
        switch(option)
        {
            case 1 : insert_front();
                     break;

            case 2 : insert_rear();
                     break;

            case 3 : delete_front();
                     break;

            case 4 : delete_rear();
                     break;

            case 5 : display();
                     break;

            case 6 : exit(1);

            default : printf("\nYou entered wrong choice !!!!!!!!!!!!");
                      break;
        }           
    }  
return 0;
}