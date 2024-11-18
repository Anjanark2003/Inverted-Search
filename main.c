/***************************************************************************************************************************************************
*Author		:Emertxe(http://www.emertxe.com)
*Date		:Mon 22 May 2017 14:00:05 IST
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"

int main(int argc, char *argv[])
{

	/* Define the main function here */

	//Variable declarations
	
	Wlist *head[27]={NULL};
	//Validate the CLA
	if(argc==1)
	{
		printf("Enter valid no. of argument: ./Slist f1.txt ...\n");
	       return 0;
	}

       //Create a file linked list

       Flist *f_head=NULL;
       
       //Validate the file and create a linked list

       file_validation_n_file_list(&f_head,argv); 
       
       //if no valid file is found
       if(f_head==NULL)
       {
	 printf("No files available in the file linked list\n");
         printf("Hence terminating the process\n");
         return 1;
       }
       //prompt a menu to the user
       //1. Create database
       //2. Display datatabase
       //3. Update database
       //4. Search the data
       //5. Save database
      
       char ch;
      int option;
      //scanf("%d",&option);
      do
      {
	      printf("Select your choice among the following: \n");
	      printf("1. Create database\n 2. Display datatabase\n 3. Update database\n 4. Search the data\n 5. Save database\n");
	      printf("Enter your choice : ");
              scanf("%d",&option);
	      switch(option)
	      {
		      case 1: printf("Create Database\n");
			      create_database(f_head,head);
			      break;
		      case 2: printf("Display Database\n");
                              display_database(head);
                              break;
		     case 3: printf("Update Database\n");
                              update_database(head,&f_head);
                              break;
		     case 4: printf("Search Database\n");
			     char word[WORD_SIZE];
			     printf("Enter the word you want to search : ");
			     scanf("%s",word);
                          if(isalpha(word[0]))
                              search(head[tolower(word[0])%97],word);
                          else
                              search(head[26],word);
                              break;
		     case 5: printf("Save Database\n");
                              save_database(head);
                              break;
	      }

	      printf("Do you want to continue ? \n");
	      printf("Enter Y/y to Continue and n/N to Discontinue : \n");
	      //char ch;
	      scanf(" %c",&ch);
      }while(ch=='Y' || ch=='y');      
}

