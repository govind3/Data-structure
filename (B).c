/*********** Code by GOVIND KUMAR ************/
//Doubly Linked List Implementation.
//a.	Create a doubly linked list of integers.
//b.	Delete a given integer from the above doubly linked list.
//c.	Display the contents of the above list after deletion.
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node *prev;
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
    printf("your linked list after deletation is :\n");
    display();
}
//a.Create a doubly linked list of integers.
struct node *create()
{
	int num;
	struct node *ptr,*new_node;
	printf("enter -1 for exit\n");
	printf("enter the data :");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));//create a new node 
        new_node->data=num;
	    new_node->next=NULL;
	    new_node->prev=NULL;
	    if(start==NULL)
	    	start=new_node;
	    else
	    {
          ptr=start;
          while(ptr->next!=NULL)
          	ptr=ptr->next;
          ptr->next=new_node;       //linked head node to new node
            ptr->next->prev=ptr;
            
	    }
	    printf("enter the data :");
	    scanf("%d",&num);
	}	

	return 0;
}
//b.Delete a given integer from the above doubly linked list.
struct node *delete()
{
	struct  node *ptr;
	int pos,i,x=-1;
	printf("enter the position from which the data has to be deleted:\n");
	scanf("%d",&pos);
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(pos==1)                    //when head node is deleted
	{
	    start=start->next;
	    if(start)
	     start->prev=NULL;
     	    x=start->data;
	    free(ptr);
	}
    else
     {                          //when delete other then head node
      for(i=0;i<pos-1;i++)
    	{
    		ptr=ptr->next;
    	}	
        ptr->prev->next=ptr->next;
        if(ptr->next)
         ptr->next->prev=ptr->prev;
        x=ptr->data;
        free(ptr);
     }
     return 0;
}
//c.Display the contents of the above list after deletion
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