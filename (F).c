/*********** Code by GOVIND KUMAR  ************/
//a.	Number of Nodes in a Binary Tree
#include <stdio.h> 
#include <stdlib.h> 
struct Node 
{    
	struct Node *lchild;    
	int data;    
	struct Node *rchild;
}*root=NULL;
void Insert(int key) 
{    
	struct Node *t=root;    
	struct Node *r=NULL,*new_node;        
	if(root==NULL)    //create a root node
	{        
		new_node=(struct Node *)malloc(sizeof(struct Node));        
		new_node->data=key;       
		new_node->lchild=new_node->rchild=NULL;        
		root=new_node;        
		return;    
	}    
	while(t!=NULL)   //It is use for where insert a new_node 
	{        
		r=t;        
		if(key<t->data)             
			t=t->lchild;       
		else 
		if(key>t->data)            
			t=t->rchild;       
		 else            
		 	return;   
    }
    new_node=(struct Node *)malloc(sizeof(struct Node));    
    new_node->data=key;    
    new_node->lchild=new_node->rchild=NULL;    
    if(key<r->data) 
    	r->lchild=new_node;    
    else 
    	r->rchild=new_node; 
}
int totalNodes(struct Node *root) 
{ 
	if(root==NULL)  
		return 0;
	else  
		return(totalNodes(root->lchild) + totalNodes(root->rchild) + 1); 
}
int main() 
{    
	int num,n;
	printf("Enter the number of elements to be inserted in Binary tree:\n");
	scanf("%d",&n);
	printf("Enter the elements :\n");
	for (int i = 0; i < n;i++)
	{
		scanf("%d",&num);
		Insert(num);
	}      
    printf("Total number of nodes is:%d\n",totalNodes(root));    
    return 0; 
}
