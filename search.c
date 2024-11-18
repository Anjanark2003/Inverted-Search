/***************************************************************************************************************************************************
*Author         :Emertxe(http://www.emertxe.com)
*Date           :Mon 22 May 2017 15:56:15 IST
*File           :search.c
*Title          :To search the words.
*Description    :Each word is now used to search in the linkedlist. The word has to be compared with
		:each word in the linked list. When found, the file details can be retrieved. Since the
		:linkedlist is in sorted order, the complexity of searching the word in the complete list
		:can be avoided. While string comparison, if the word in linkedlist is greater than the
		:word to be search, it shows the word doesnt exists in the list,
****************************************************************************************************************************************************/
#include "inverted_search.h"

void search( Wlist *head, char *word)
{
	//Check if list is empty
	if(head==NULL)
	{
		printf("Search word is not available in list\n");
		return;
	}
	//Traverse through the list
	while(head)
	{
		//check whether the word is present
		if(!strcmp(head->word,word))
		{
			printf("Word %s is present in %d file/s\n",word,head->file_count);
			Ltable *Thead=head->Tlink;
			//Traverse through the link table
			while(Thead)
			{
				printf("In file : %s %d time/s\n",Thead->file_name,Thead->word_count);
				Thead=Thead->table_link;
			}
			printf("\n");
			return;
		}
		head=head->link;
	}
	
	printf("Search word is not available in list\n");
}

