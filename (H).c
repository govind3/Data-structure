/*********** Code by GOVIND KUMAR  ************/
//a.	Create a binary search tree of integers.
//b.	Traverse the above Binary search tree non recursively in order
//c.	Calculate its height
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
void Inorder(struct Node *root) 
{    
	if(root==NULL)  
	{
		return;
	}
	Inorder(root->lchild);        
	printf("%d ",root->data);        
	Inorder(root->rchild);    
} 
int  Height(struct Node *root)
{
	int leftHeight,rightHeight;
	if (root==NULL)   //node is NULL empty tree 
		return 0;
	else
	{
		leftHeight=Height(root->lchild);
	    rightHeight=Height(root->rchild);
	    if(leftHeight>rightHeight)
		   return (leftHeight+1);
	    else
	       return (rightHeight+1);
    }
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
	printf("Inorder is \n"); 
	Inorder(root);    
    printf("\n");   
    printf("Height of Binary tree is :%d\n",Height(root));      
    return 0; 
}