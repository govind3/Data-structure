/*********** Code by GOVIND KUMAR  ************/
//Singly Linked List Implementation.
//a.	Create a singly linked list of integers.
//b.	Delete a given integer from the above linked list.
//c.	Display the contents of the above list after deletion.

#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create();
struct node *display();
struct node *delete();
int main()
{
    create();
    printf("your linked list is :\n");
    display();
    delete();
    printf("afetr deletation your linked list is:\n");
    display();
}
//a.Create a singly linked list of integers.
struct node *create()
{
	int num;
	struct node *ptr,*new_node;
	printf("enter -1 for exit\n");
	printf("enter the data :");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));//create a newnode
        new_node->data=num;
	    new_node->next=NULL;
	    if(start==NULL)
	    start=new_node;
	    else
	    {
          ptr=start;
          while(ptr->next!=NULL)//linked a newnode to head node
          	ptr=ptr->next;
          ptr->next=new_node;
	    }
	    printf("enter the data :");
	    scanf("%d",&num);
	}	
	return 0;
}
//b.Delete a given integer from the above linked list.
struct node *delete()
{
	struct  node *ptr,*q=NULL;// //ptr and q are temporary variable
	int pos,i;
	printf("enter the position from which the data has to be deleted:\n");
	scanf("%d",&pos);
	q=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(pos==1)
		start=start->next;//move head to next node
    else
     {
      for(i=0;i<pos-1;i++)
    	{
    		q=ptr;           //q go to  just previous of deleted node
    		ptr=ptr->next;
    	}	
        q->next=ptr->next;    //linked q to next of deleted node
     }
     return 0;	
}
//c.Display the contents of the above list after deletion.
struct node *display()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
      {
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	   }
	printf("\n");
	return 0;
}