#include "inverted_search.h"

void save_database( Wlist *head[])
{
	//To store the filename
	char file_name[FNAME_SIZE];
	//Prompt the user to enter the filename
	printf("Enter the filename : ");
	scanf("%s",file_name);

	//Open the file
	FILE *fptr=fopen(file_name,"a");

	for(int i=0;i<27;i++)
	{
		if(head[i]!=NULL)
		{
			write_databasefile(head[i],fptr);
		}
	}
	printf("Database saved successfully\n");
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
	//Write to the file
	//#<index no.>
	//<word><file_count><filename>
	int index;
	if(isalpha(head->word[0]))
	{
		index=tolower(head->word[0])%97;
	}
	else
	{
		index=26;
	}
	fprintf(databasefile,"#:%d\n",index);

	Wlist *temp=head;
	while(temp)
	{
			fprintf(databasefile,"%-15s:%d :file/s:",temp->word,temp->file_count);

			Ltable *Thead=temp->Tlink;
			while(Thead)
			{
				fprintf(databasefile," %s:%d:",Thead->file_name,Thead->word_count);
				Thead=Thead->table_link;
			
			}
			fprintf(databasefile, "#");
			fprintf(databasefile, "\n");
			temp=temp->link;
	}

}
