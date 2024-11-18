#include "inverted_search.h"

void update_database( Wlist *head[], Flist **f_head)
{
	int empty;
	//To store the file name
	char file_name[FNAME_SIZE];

	printf("Enter the filename : ");
	scanf("%s",file_name);
	//validate the file
	
	empty= isFileEmpty(file_name);

	if(empty== FILE_NOTAVAILABLE)
	{
			printf("File %s is not available\n",file_name);
			printf("Hence we are not adding it to the file linked list\n");
			return ;
	}
	if(empty== FILE_EMPTY)
    {
        printf("File %s is empty\n",file_name);
        printf("Hence we are not adding it to the file linked list\n");
         return ;
   }

	//if file is valid then only add to linked list

	int ret=to_create_list_of_files(f_head,file_name);
	if(ret==SUCCESS)
	{
		printf("Successful in inserting the file %s into the linked list\n",file_name);
	}
	else if(ret==REPEATATION)
	{
		printf("File is repeated %s is not adding into linked list\n",file_name);
		return;
	}
	else
	{
		printf("Failed to add the file into linked list\n");
		return;
	}

	//After successfully inserting the file in the file linked list
	
	while(*f_head)
	{
		if(!strcmp((*f_head)->file_name,file_name))
			create_database(*f_head,head);
		*f_head=(*f_head)->link;
	}


}
