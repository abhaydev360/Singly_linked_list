#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
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
void reverse_list(struct node **head);
void reverse_recursion(struct node **head,struct node *prev_node,struct node *curr_node,struct node *next_node);
void traverse_back(struct node **head);
int cisco();

	// main Function:
void main()
{
	struct node *head=NULL;
	struct node *prev_node=NULL;
	struct node *curr_node;
        struct node *next_node= NULL;
	 
	int choice = -1,i=0;
	 int c=cisco();
	//printing Options:
	while(choice != 0){

	
		printf("\n\t\t***Chose Option Below*** ");
		printf("\n\n\tINSERT at Begening: Press: 1     Remove Element: Press: 5");
		printf("\n\n\tINSERT at End:      Press: 2     Search Data:    Press: 6");
		printf("\n\n\tINSERT at Point:    Press: 3     Reverse List:   Press: 7");
		printf("\n\n\tTraverse Forward:   Press: 4     Reverse Rcrsn:  Press: 8");
		printf("\n\n\tTraverse backend:   Press: 9     Exit:           Press: 0");
	
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
			reverse_list(&head);
			break;
		case 8:
			 curr_node=head;
			 reverse_recursion(&head,prev_node,curr_node,next_node);
			 break;
		case 9:
			 traverse_back(&head);
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


void traverse_back(struct node **head){
	system("clear");
	struct node *node;
	struct node *ptr=*head;
	struct node *x;
	while(ptr!=NULL){
		node=ptr;
		ptr=ptr->link;
	}
	printf("\n\n\tTraversing List.....\n\t");
	printf("--> %d",node->data);
	ptr=*head;
	while(node!=*head){
		while(ptr!=node){
			x=ptr;
			ptr=ptr->link;
		}
		printf("--> %d",x->data);
		node=x;
		ptr=*head;
	}
}
	//Insert at End:
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
	// Traverse List:
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
	//Remove Element:
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
	//Insert at Point:
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

	//Insert at Begening1:
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
//Password Protected:	
int cisco(){

char echo[20];
char tes[20];
printf("Enter Username:  ");
scanf("%s",echo);
printf("Enter Password:  ");
scanf("%s",tes);
if(strcmp(echo,"abhaydce")==0 && strcmp(tes,"abc@123")==0){
        system("clear");
printf("\n***Login seccefull***\n");
}
else {
        system("clear");
        printf("\n***Incorrect Id Or Password***\n");
        cisco();

}

return 0;
}		
	//Reverse List Using Loop:
void reverse_list(struct node **head){
	system("clear");
	struct node *prev_node=NULL;
	struct node *curr_node=*head;
	struct node *next_node= NULL;
	while(curr_node!=NULL){
	
		next_node = curr_node->link;
		
		curr_node->link=prev_node;

		prev_node = curr_node;

		curr_node = next_node;

	}
	*head=prev_node;
}
	//Reverse_list Using Recursion:
void reverse_recursion(struct node **head,struct node *prev_node,struct node *curr_node,struct node *next_node){
	system("clear");
	if(curr_node!=NULL){
		next_node = curr_node->link;
                curr_node->link=prev_node;
                prev_node = curr_node;
                curr_node = next_node;
	}
	else {
		*head=prev_node;
		return;
	}
reverse_recursion(&*head,prev_node,curr_node,next_node);
}

