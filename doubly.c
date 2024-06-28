#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *prev;
	int data;
	struct  node *next;
}node;
node *head;
void create(int n){
	node *new=(node *)malloc(sizeof(struct node));
	new->prev=NULL;
	new->next=NULL;
	printf("\nenter the data for node 1:\n");
	scanf("%d",&new->data);
	head=new;
	node *tmp=head;
	for(int i=2;i<=n;i++){
		node *new_node=(node *)malloc(sizeof(struct node));
		printf("\nenter the data for node %d:\n",i);
		scanf("%d",&new_node->data);
		tmp->next=new_node;
		new_node->prev=tmp;
		new_node->next=NULL;
		tmp=new_node;

	}
}
void insert_beg(){
	node *tmp=head;
	if(tmp==NULL)
		printf("list is empty");
	else{
	node *new=(node *)malloc(sizeof(struct node));
	printf("\nenter the element to insert:\n");
	scanf("%d",&new->data);
        new->prev=NULL;
	new->next=tmp;
	tmp->prev=new;
        head=new;
	}
}
void insert_end(){
	node *tmp=head;
        if(tmp==NULL)
                printf("list is empty");
        else{
        node *new=(node *)malloc(sizeof(struct node));
	printf("\nenter the element to insert:\n");
        scanf("%d",&new->data);
	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=new;
	new->prev=tmp;
	new->next=NULL;
	}
}
void insert_loc(){
	int pos;
        printf("\nenetr the position to insert the node:\n");
	scanf("%d",&pos);
	node *new=(node *)malloc(sizeof(struct node));
	node *tmp=head;
	node *tmp1;
	if(tmp==NULL)
		printf("list is empty");
	else{
	printf("\nenter the element to insert:\n");
        scanf("%d",&new->data);
        for(int i=pos;i!=1;i--){
		tmp1=tmp;
		tmp=tmp->next;}
	tmp1->next=new;
	new->prev=tmp1;
	new->next=tmp;
	tmp->prev=new;
	}
}
void delete_beg(){
	node *tmp=head;
	if(tmp==NULL)
		printf("list is empty");
	head=tmp->next;
	head->prev=NULL;
	free(tmp);
}
void delete_end(){
	node *tmp=head,*tmp1;
	if(tmp==NULL)
                printf("list is empty");

	while(tmp->next!=NULL)
	{
		tmp1=tmp;
		tmp=tmp->next;
	}
	tmp1->next=NULL;
	free(tmp);
}
void delete_pos(){
	int pos;
	printf("enetr the position to delete ");
	scanf("%d",&pos);
	node *tmp=head;
	if(tmp==NULL)
		printf("list is empty");
	else{
		node *tmp1,*tmp2;
		for(int i=pos;i>1;i--){
			tmp1=tmp;
			tmp=tmp->next;
		}
		tmp2=tmp->next;
		tmp2->prev=tmp1;
		tmp1->next=tmp2;
		free(tmp);
	}
}
void traverse_f(){
      node *tmp=head;
      node *tmp1;
      if(tmp==NULL)
	      printf("list is empty");
      printf("forward:");
      while(tmp->next!=NULL){
	      printf("%d ",tmp->data);
	      tmp=tmp->next;
      }printf("%d ",tmp->data);

      printf("\nbackward:");
      while(tmp->prev!=NULL){
	       printf("%d ",tmp->data);
	       tmp=tmp->prev;
      }           printf("%d ",tmp->data);


}
void f(){
	node *tmp1,*tmp=head;
	while(tmp!=NULL){
		tmp1=tmp;
		tmp=tmp->next;
		free(tmp1);
	}
}


int main(){
        int n,e,ele;
        while(1){
        printf("\neneter the operation to continue:\n");
        printf("1.create \n 2.insert at beg\n3.insert at end\n4.insert at loc\n5.traverse forward\n6.traverse backward\n7.delete front\n8.delete end\n9.delete pos\n");
        scanf("%d",&n);
        switch(n){
                case 1:
                        printf("\nenterr the no of list to create");
                        scanf("%d",&e);
                        create(e);
                        break;
                case 2:
                        insert_beg();
                        break;
                case 3:
                        insert_end();
                        break;
		case 4:
			insert_loc();
			break;
		case 5:
			printf("displaying forward way:\n");
			traverse_f();
			break;
		case 7:
			delete_beg();
			break;
		case 8:
			delete_end();
			break;
		case 9:
			delete_pos();
			break;
			
        default:
		    f();
            exit(0);
            break;
        }

      }
}



