#include<iostream>
#include<stdlib.h>
using namespace std;
#define SIZE 5
void enQueue(int);
void deQueue();
void display();
int cQueue[SIZE],front = -1,rear = -1;
main()
{
   int choice,value;
   while(1){
      cout<<"\n****** MENU ******\n";
      cout<<"1. Insert\n2. Delete\n3. Display\n4. Exit\n";
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice)
     {
	 case 1: cout<<"\nEnter the value to be insert:  ";
		 cin>>value;
		 enQueue(value);
		 break;
	 case 2: deQueue();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	 default:cout<<"\nPlease select the correct choice!!!\n";
      }
   }
}
void enQueue(int value)
{
   if((front==0&&rear==SIZE-1)||(front==rear+1))
      cout<<"\nCircular Queue is Full! Insertion not possible!!!\n";
   else{
      if(rear==SIZE-1&&front!=0)
	 rear=-1;
      cQueue[++rear]=value;
      cout<<"\nInsertion Success!!!\n";
      if(front==-1)
	 front=0;
   }
}
void deQueue()
{
   if(front==-1&&rear==-1)
      cout<<"\nCircular Queue is Empty! Deletion is not possible!!!\n";
   else{
      cout<<"\nDeleted element : \n"<<cQueue[front++];
      if(front==SIZE)
	 front = 0;
      if(front-1==rear)
	 front=rear=-1;
   }
}
void display()
{
   if(front==-1)
      cout<<"\nCircular Queue is Empty!!!\n";
   else{
      int i=front;
      cout<<"\nCircular Queue Elements are : \n";
      if(front<=rear){
	 while(i<=rear)
	    cout<<cQueue[i++];
      }
      else{
	 while(i<=SIZE-1)
	   cout<<cQueue[i++];
	 i = 0;
	 while(i<=rear)
	    cout<<cQueue[i++];
      }
   }
}
