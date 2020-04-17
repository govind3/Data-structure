/*********** Code by GOVIND KUMAR  ************/
//a.  Double ended queue ADT Implementation using array 
#include<stdio.h>
#include<conio.h>
#define MAX 50
int deque[MAX];          //declaratiion of array as a Global variable
int left=-1,right=-1;
void insert_rear(void);
void insert_front(void);
void delete_rear(void);
void delete_front(void);
void display(void);
int main()
{
  int option;
  do
  {
    printf("1.insert at rear end\n");
    printf("2.insert at front end\n");
    printf("3.delete from rear end\n");
    printf("4.delete from front end\n");
    printf("5.display\n");
    printf("6.Exit\n");
    printf("Enter your option :");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
          insert_rear();
          break;
      case 2:
          insert_front();
          break;
      case 3:
          delete_rear();
          break;
      case 4:
          delete_front();
          break;
      case 5:
          display();
          break;
      }
  }while(option!=6);
return 0;
}
void insert_rear()
{
 int num;
 printf("Enter the value to be added\n");
 scanf("%d",&num);
 if( (left==0 && right==MAX-1) || (left==right+1) ) // over flow condition 
 {
  printf("queue is OVERFLOW\n");
 }
 if(left==-1)        //if queue is initially empty
 {
  left=0;
  right=0;
 }
 else
 {
  if(right==MAX-1)        
   right=0;
  else
   right=right+1;
 }
 deque[right]=num;                 // insert one by one numbers at rear end in deque(array)
}
void insert_front()
{
 int num;
 printf("Enter the value to be added\n");
 scanf("%d",&num);
 if( (left==0 && right==MAX-1) || (left==right+1) )  //over flow condition
 {
  printf("queue is OVERFLOW\n");
 }
 if(left==-1)        //if queue is initially empty
 {
  left=0;
  right=0;
 }
 else
 {
  if(left==0)
   left=MAX-1;
  else
   left=left-1;
 }
 deque[left]=num;    // insert one by one numbers at front end in deque(array)
}
void delete_rear()
{
 if(left==-1)
 {
  printf("queue UNDERFLOW\n");
  return;
 }
 printf("The deleted element is %d\n", deque[right]);
 if(left==right)          //Queue has only one element
 {
  left=-1;
  right=-1;
 }
 else
 {
  if(right==0)
   right=MAX-1;
  else
   right=right-1;
 }
}
void delete_front()
{
 if(left==-1)
 {
  printf("queue UNDERFLOW\n");
  return;
 }
 printf("The deleted element is %d\n", deque[left]);
 if(left==right)          //Queue has only one element
 {
  left=-1;
  right=-1;
 }
 else
 {
  if(left==MAX-1)
   left=0;
  else
   left=left+1;
 }
}
void display()
{
 int front=left, rear=right;
 if(front==-1)
 {
  printf("Queue is Empty\n");
  return;
 }
 printf("The elements in the queue are:\n");
 if(front<=rear)
 {
  while(front<=rear)
  {
   printf("%d\t",deque[front]);
   front++;
  }
 }
 else
 {
  while(front<=MAX-1)
  {
   printf("%d\t",deque[front]);
   front++;
  }
  front=0;
  while(front<=rear)
  {
   printf("%d\t",deque[front]);
   front++;
  }
 }
 printf("\n");
}
