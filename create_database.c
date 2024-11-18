/***************************************************************************************************************************************************
*Author         :Emertxe(http://www.emertxe.com)
*Date           :Mon 22 May 2017 14:04:05 IST
*File           :create_database.c
*Title          :To create the database
*Description    :The list of the files can be provided by storing all the file names in another file, FileList the names of the files which 
		:are to be documented are provided by this file. When a file is added or removed, FileList is changed accordingly.
		:So read the file names and start indexing.
****************************************************************************************************************************************************/
#include "inverted_search.h"
char *fname;
void create_database(Flist *f_head, Wlist *head[])
{
	/* Definition here */
	//Traverse through the file linked list
	while(f_head)
	{
		read_datafile(f_head,head,f_head->file_name);
		f_head=f_head->link;
	}
	printf("Successfully created the database.\n");
}
Wlist* read_datafile(Flist *file, Wlist *head[], char *filename)
{
	int flag;
	//Open the file in read mode
	FILE *fptr=fopen(filename,"r");
	if(fptr==NULL)
	{
		printf("Failed to open file: %s\n",filename);
		return NULL;
	}
	fname=filename;
	//Declare an array to store the word
	char word[WORD_SIZE];
	//Read the contents from the file
	while(fscanf(fptr,"%s",word)!=EOF)
	{
		flag=1;
		//int index;
		//to get the index
		int index=tolower(word[0])%97;

		//Non alphabets
		if(!(index>=0 && index<=25))
		{
			index=26;
		}
		//If words are repeated
		if(head[index])
		{
			Wlist *temp=head[index];
			while(temp)
			{
				if(!strcmp(temp->word,word))
				{
					//if words are repeated
					 update_word_count(&temp,filename);
					 flag=0;
					 break;
				}
				temp=temp->link;
			}
		}
		if(flag==1)
		{
			 insert_at_last(&head[index],word);
		}

	}
	fclose(fptr);
}
//If words are repeated
int update_word_count(Wlist **head, char *file_name)
{
	//Check whether filename are same or not
	//if it is same increment wordcount
	//if filename is different increment filecount and create Ltable node
	Ltable *temp=(*head)->Tlink;
	while(temp)
	{
		if(!strcmp(temp->file_name,file_name))
		{
			temp->word_count++;
			return SUCCESS;
		}
		temp=temp->table_link;

	}

	(*head)->file_count++;
	return update_link_table(head);
}

