/***************************************************************************************************************************************************
*Author         :Emertxe(http://www.emertxe.com)
*Date           :Mon 22 May 2017 16:06:15 IST
*File           :display_output.c
*Title          :To display  the results.
*Description    :When all the words are searched the ouput list is formed. In this the file with max count
		:(representing maximum word match ) can be selected and displayed. For advanced searched,
		:(weightage of words stored in database linkedlist) can also be used. So the results will be more
		:accurate.
****************************************************************************************************************************************************/
#include "inverted_search.h"

void display_database( Wlist *head[] )
{
    /* Definition here */
    printf("[index]  [word]      file_count       file/s      File: File_name       word_count\n");
   for(int i=0;i<130;i++)
   {
         printf("-");
   }
   printf("\n");
   for(int i=0;i<27;i++)
   {
	   if(head[i]!=NULL)
	   {
		   print_word_count(head[i]);
	   }
   }
   for(int i=0;i<130;i++)
   {
           printf("-");
   }
   printf("\n");

}
int print_word_count(Wlist *head)
{
	while(head!=NULL)
	{
		//[index] [word] file_count file/s File: File_name word_count
		int index;
		if(isalpha(head->word[0]))
		{
            index=tolower(head->word[0])%97;
		}
		else
		{
			index=26;
		}
        printf("[%d]   %-15s     [%d]      file/s : ", index,head->word,head->file_count);

		Ltable *Thead=head->Tlink;
		//Traverse through the link table
		while(Thead)
		{
			printf("File : %s   [%d]  ",Thead->file_name,Thead->word_count);
			Thead=Thead->table_link;
		}
		printf("\n");

		head=head->link;
		
	}
	
}

 
