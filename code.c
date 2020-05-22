#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
	//structure creating:
struct node
{
 int data;
 struct node *link;
};
	//Declear function:
void traverse_list(struct node **head);
void insert_end(struct node **head);
void remove_element(struct node **head);
void insert_beg(struct node **head);
void insert_point(struct node **head);
void search(struct node **head);
void reverse(struct node **head);
	// main Function:
void main()
{
	struct node *head=NULL;
	int choice = -1;
	//printing Options:
	while(choice != 0){

	
		printf("\n\t\t***Chose Option Below*** ");
		printf("\n\n\tINSERT at Begening: Press: 1     Remove Element: Press: 5");
		printf("\n\n\tINSERT at End:      Press: 2     Search Data:    Press: 6");
		printf("\n\n\tINSERT at Point:    Press: 3     Reverse List:   Press: 7");
		printf("\n\n\tTraverse list:      Press: 4     Exit:           Press: 0");
	
		printf("\n\n\t      ***Enter your choise***: ");
		scanf("%d",&choice);
		switch(choice)
		{
	
		case 1:
			insert_beg(&head);
			break;
		case 2:
			insert_end(&head);
			break;
		case 3:
			insert_point(&head);
			break;
		case 4:
			traverse_list(&head);
			break;
		case 5:
			remove_element(&head);
			break;
		case 6:
			search(&head);
			break;
		case 7:
			reverse(&head);
			break;
		case 0:
			break;
		default:
			system("clear");
			printf("\n\n\t***Invalid selection***");
			break;
		}

	}
}
	//insert Function : End
void insert_end(struct node **head){
	 system("clear");
	 struct node *temp_node = (struct node*) malloc(sizeof(struct node));
	 traverse_list(head);
	 printf("\n\tEnter the item:");
	 scanf("%d",&temp_node->data);
	 system("clear");
	 temp_node->link = NULL;
	 int inserted = 0;

	 if(*head == NULL){
  		*head = temp_node;
  		inserted = 1;
	 }
	 else{
 		struct node *temp_head = *head;
  		while(temp_head != NULL){
   			if(temp_head->link == NULL){
    	 			temp_head->link = temp_node;
         			inserted = 1;
         			break;
   			}
   			temp_head = temp_head->link;
		}
	}

	 if(inserted){
 		 printf(" \n\n\t ***Inserted successfully***\n");
	 
	 }
	 else{
 		printf("\n\n\t ***Failed to insert item in linked list***");
	 }

}

	//Traverse Function: 
void traverse_list(struct node **head){
	system("clear");
	if(*head == NULL){
  		printf("\n\n\t***There Is No Data***");
		return;
  	}
  	int count=0;
 	 struct node *temp_node  = *head;
	 printf("\n\n\tTraversing List.....\n\t");
	 while(temp_node != NULL){
		printf("-->");
   	 	printf(" %d",temp_node->data);	  
	 	count++;
	 	if(count==10){
			printf("\n\t");
	 		count=0;
	 	}
		temp_node = temp_node->link;
  	}
}
	//Remove Function:
void remove_element(struct node **head)
{
	system("clear");
	if(*head==NULL)
	{ 	
		printf("\n\n\t***There is no Node:***");
		return;
	}
	else
	{
		struct node *pre_node,*temp_head = *head;
		int temp_var;
		
		traverse_list(head);
		printf("\n\tEnter element Which you want to Remove: ");
		scanf("%d",&temp_var);
		if(temp_head->data==temp_var)
		{
			*head=temp_head->link;
			temp_head->link=NULL;
			system("clear");
			printf("\n\n\t***Data Removed***\n");
			return;
		}
	
		while(temp_head!=NULL){
			if(temp_head->data==temp_var){
				pre_node->link=temp_head->link;
  				temp_head->link=NULL;
				printf("\n\n\t***Data Removed***\n");
				return;
			}
		
			pre_node=temp_head;	
			temp_head=temp_head->link;
	 	}
		system("clear");
		printf("\n\n\t***Element Does not exist in linked list***\n");
		return;
	
	}
}
	//Insert Function: Point:
void insert_point(struct node **head){
	system("clear");
	if(*head==NULL){
		void insert_end();
		return;
	}
	int temp_var;
	traverse_list(head);
	printf("\n\tEnter Element after which you want to enter new element: ");
	scanf("%d",&temp_var);
	struct node *temp_head;
	struct node *temp_node = (struct node*) malloc(sizeof(struct node));
	temp_head=*head;
	
	while(temp_head!=NULL){
		
		if(temp_head->data==temp_var){
			printf("\n\tEnter Element: ");
		        scanf("%d",&temp_node->data);
			temp_node->link=temp_head->link;
        		temp_head->link=temp_node;
			system("clear");
			printf("\n\n\t***Inserted Seccessful***\n");
			return;
		}
		temp_head=temp_head->link;
	}
	printf("\n\n\t***Element does not exist in linked list***\n");
	

}
	//Insert Function: Begening:
void insert_beg(struct node **head){

	system("clear");
	struct node *temp_head = *head;
	struct node *new_node = (struct node*) malloc(sizeof(struct node)); 
	printf("\nEnter element: ");
	scanf("%d",&new_node->data);
	new_node->link=temp_head;
	*head=new_node;
	system("clear");
	printf("\n\n\t***Inserted Seccessful***\n");

}
	//Search Function: 
void search(struct node **head){
	system("clear");
	struct node *temp_head=*head;
	int search_data;
	int count=1;
	printf("\n\tEnter element which you want to search: ");
	scanf("%d",&search_data);
	while(temp_head!=NULL)
	{
		if(temp_head->data==search_data){
			system("clear");
			printf("\n\n\t***This Data (%d) Is Available In Linked List:***",search_data);
			printf("\t***At position %d***\n",count);
			return;
		}
		count++;
		temp_head=temp_head->link;
	}
	system("clear");
	printf("\n\n\t***Sorry..Your Entered Data (%d) Is Not Available In Linked List:***\n",search_data);


}

void reverse(struct node **head){

	if(*head==NULL){
		printf("Invalid Head");
	}
	else{
		struct node *pre_node,*reverse_node,*next_node;
		pre_node=*head;
		reverse_node=pre_node->link;
		next_node=reverse_node->link;
		pre_node->link=NULL;
		
		while(next_node!=NULL){
			reverse_node->link=pre_node;
			pre_node=reverse_node;
			reverse_node=next_node;
			next_node=next_node->link;
		
		}
		reverse_node->link=pre_node;
		*head=reverse_node;
		system("clear");
		printf("\n\t***Reversing Seccessful***\n");
	
	}


}
