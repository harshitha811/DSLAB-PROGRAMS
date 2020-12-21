/*WAP to simulate the working of a queue of integers using an array. Provide the following
operations
a) Insert b) Delete c) Display
The program should print appropriate messages for queue empty and queue overflow
conditions*/
#include<stdio.h>
#include<process.h>
#define QUE_SIZE 3
int item,front=0,rear=-1,q[10];
void insert(){
if(rear==QUE_SIZE-1){
	printf("Queue Overflow\n");
	return;
}
rear=rear+1;
q[rear]=item;
}
int delete(){
	if(front>rear){
		front=0;
		rear=-1;
		return -1;
	}
	return q[front++];
}
void display(){
	int i;
	if(front>rear){
		printf("Queue is empty\n");
		return;
	}
	printf("Contents of queue:\n");
	for(i=front;i<=rear;i++)
	printf("%d\n",q[i]);
}
int main(){
	int count=0;
	int choice;
	for(;;){
		printf("\n1.insert\n2.delete\n3.display\n4.display size of queue\n5.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
			printf("Enter the item to be inserted\n");
			scanf("%d",&item);
			insert();
			count++;
			break;}
			case 2:
				item=delete();
				if(item==-1)
				printf("Queue is empty");
				else
				printf("Item deleted is %d\n",item);
				count--;
				break;
			case 3:display();
			break;
			case 4:
			printf("The size of the queue is %d",QUE_SIZE);
			break;
			default:
			exit(0);
		}
	}
	return 0;
}
