#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[] )
{
	//variable declartion
	int empty,i=1;

	//Slist.exe f1.txt f2.txt...
	//check whether file is empty or not
	//check whether file is available or not
	//Traverse
	
	while(argv[i]!=NULL)
	{
		empty= isFileEmpty(argv[i]);

		if(empty== FILE_NOTAVAILABLE)
		{
			printf("File %s is not available\n",argv[i]);
			printf("Hence we are not adding it to the file linked list\n");
			i++;
			continue;
		}
		if(empty== FILE_EMPTY)
                {
                        printf("File %s is empty\n",argv[i]);
                        printf("Hence we are not adding it to the file linked list\n");
                        i++;
                        continue;
                }

		//if file is valid then only add to linked list

		int ret=to_create_list_of_files(f_head,argv[i]);
		if(ret==SUCCESS)
		{
			printf("Successful in inserting the file %s into the linked list\n",argv[i]);
		}
		else if(ret==REPEATATION)
		{
			printf("File is repeated %s is not adding into linked list\n",argv[i]);
		}
		else
		{
			printf("Failed to add the file into linked list\n");
		}
		i++;
	}
}
int isFileEmpty(char *filename)
{
	//check whether file is available or not
	FILE *file=fopen(filename,"r");
	if(file==NULL)
	{
		return FILE_NOTAVAILABLE ;
	}
	//if file is available check whether file is empty or not
	int c=fgetc(file);
	fclose(file);
	if(c==EOF)
	{
		return FILE_EMPTY;
	}
	return SUCCESS;
	
}
int to_create_list_of_files(Flist **f_head, char *name)
{
	//check whether file is repeated
	Flist *temp=*f_head;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->file_name)==0)
		{
			return REPEATATION;
		}
		temp=temp->link;
	}
	//else add it to the linked list
	
	Flist *new=malloc(sizeof(Flist));
	if(new==NULL)
	{
		return FAILURE;
	}
	strcpy(new->file_name,name);
	new->link=NULL;
	if(*f_head==NULL)
	{
		*f_head=new;
		return SUCCESS;
	}
	temp=*f_head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=new;
	return SUCCESS;

}
