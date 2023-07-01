#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i=1,count=0,size=2;
struct node {
	char name[20];
	char source[20];
	char destination[20];
	int age;
	int seat_no;
	struct node *next;
}*first=NULL,*last,*front=0,*rear=0;
void main()
{
    int ch;
    printf("\t\t WEL COME\n");
    do
    {
         printf("1.reserve a ticket\n2.cancel\n3.display passenger details\n4.exit\n\n");
      printf("enter your choice\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:
              if(count<size)
                reserve();
              else
              {
                printf("\ntickets are full we are adding your details into waiting list\n");
                enqueue();
              }
          break;
           case 2:cancel();
          break;
          case 3:display();
          break;
           case 4:exit(0);
          break;
          default :printf("invalid choice\n");
        break;
      }
    }while(ch!=10);
}
void reserve()
{
    struct node *newnode;
   newnode=((struct node*)malloc(sizeof(struct node))) ;
   printf("Enter passenger name\n");
   scanf("%s",newnode->name);
    printf("Enter passenger age\n");
   scanf("%d",&newnode->age);
    printf("Enter boarding station\n");
   scanf("%s",newnode->source);
    printf("Enter destination\n");
   scanf("%s",newnode->destination);
   newnode->seat_no=i;
   newnode->next=0;
    if(first==0)
    first=last=newnode;
    else
{
  last->next=newnode;
  last=newnode;
}
   i++;
   count++;
}
void display()
{
    struct node *temp1;
temp1=first;
    while(temp1!=0)
    {
        printf("seat number %d:\tname=%s\tage=%d\tboarding station=%s\tdestination=%s\n",temp1->seat_no,temp1->name,temp1->age,temp1->source,temp1->destination);
        temp1=temp1->next;
    }
}
void cancel()
{
    int reg;
    struct node *front1,*temp;
    front1=front;
    temp=first;
    printf("Enter the seat number to be cancelled\n");
    scanf("%d",&reg);
   if(reg>size)
    printf("invalid registration number\n");
   else
   {
       while(temp->next->seat_no!=reg){
         temp=temp->next;
       }
       printf("ticket is cancelled\n");
        front1->seat_no=reg;
       front1->next=temp->next->next;
       temp->next=front1;
       front=front->next;
      // dequeue(reg);
   }
}
void enqueue()
  {
       struct node *newnode;
   newnode=((struct node*)malloc(sizeof(struct node))) ;
   printf("Enter passenger name\n");
   scanf("%s",newnode->name);
   printf("Enter passenger age\n");
   scanf("%d",&newnode->age);
    printf("Enter boarding station\n");
   scanf("%s",newnode->source);
   printf("Enter destination\n");
   scanf("%s",newnode->destination);
   if(front==0&&rear==0)
    front=rear=newnode;
   else
    {
   rear->next=newnode;
   rear=newnode;
    }
}
