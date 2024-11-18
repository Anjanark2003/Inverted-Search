#include "inverted_search.h"
extern char* fname;
int insert_at_last(Wlist **head, data_t *data)
{
	//Create a new node
	Wlist *new=malloc(sizeof(Wlist));
	if(new==NULL)
	{
		return FAILURE;
	}
	new->file_count=1;
	new->Tlink=NULL;
	new->link=NULL;
	strcpy(new->word,data);

	update_link_table(&new);

	//Check whether the list is empty or not
	if(*head==NULL)
	{
		*head=new;
		return SUCCESS;
	}

	//Create a local reference to head
	Wlist *temp=*head;
	//Traverse through the list
	while(temp->link)
	{
		temp=temp->link;
	}
	temp->link=new;
	return SUCCESS;

}
int update_link_table(Wlist **head)
{
	//Create a node
	Ltable *new=malloc(sizeof(Ltable));
	if(new==NULL)
	{
		return FAILURE;
	}
	//Update the node
	new->word_count=1;
	strcpy(new->file_name,fname);
	new->table_link=(*head)->Tlink;
    (*head)->Tlink=new;
	return SUCCESS;

}

