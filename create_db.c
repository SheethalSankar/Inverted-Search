/*Name :
Date :
Description :
Sample input :
Sample output :
 */

#include "struct.h"

static int databasecreated=0;
static int databaseupdated=0;

int create_db(data_base *arr,Slist **head)
{
	if(databaseupdated)
	{
		printf("Cant create again after updating\n");
		return 0;
	}
	if(databasecreated)
	{
		printf("Database created already!! \n");
		return 0;
	}


	char word[100];//declaring an array to store the words reading from the files.
	if(*head==NULL)
	{
		printf("LIST EMPTY");
		return 0;
	}
	Slist *temp=*head;
	while(temp !=NULL)
	{
		FILE *ptr=fopen(temp->data,"r");
		if(ptr==NULL)
		{
			printf("Cant open the file");
			return 0;
		}
		while(fscanf(ptr,"%s",word)!=EOF)
		{
			//to get first character of each word use word[0] this will give first character of first word
			int index=tolower(word[0])-97;
			if(index <= -33 && index >= -64) //indexes of special character and numbers
			{
				index=26;
			}
			if(arr[index].link==NULL)
				//CHECKING IF THE INDEX IS NULL OR NOT
			{
				//creat main node and subnodes
				m_node *new_m=malloc(sizeof(m_node));
				s_node *new_s=malloc(sizeof(s_node));
				//update the default values in main node and sub node

				new_m->f_count=1; //storing 1 in filecount
				new_m->m_link=NULL;//storing null as main node mainlink
				new_m->s_link=new_s;//storing subnode address in main node sublink part

				new_s->w_count=1;//sublink wordcount is set to 1
				new_s->s_link=NULL; //subnode sublink stored as null

				//storing remaining parts of main node and subnode

				strcpy(new_m->word,word);//storing the word to the main node word part
				strcpy(new_s->f_name,temp->data);//storing file name to subnode filename part
				arr[index].link=new_m;//main node address stored in 7th index
			}
			else             //if the index is not null
			{
				m_node *temp_m = arr[index].link;    //Storing first main node address to a temp variable
				while(temp_m)  //running loop untill that temp reaches null
				{
					int duplicate_w = strcmp(word,temp_m->word);   //checking if theword from the file is already stored in the data base

						if(!duplicate_w)    //if yes
						{
							s_node *temp_s = temp_m->s_link;   //create a temp variable and store first subnode address to it
							while(temp_s)    //traverse untill subnode address become null
							{
								int duplicate_f = strcmp(temp->data,temp_s->f_name);  //checking if file names are same
								if(duplicate_f !=0 && temp_s->s_link == NULL)//if file name are not same and sublink of                                                                                                         subnode is null then create a new subnode
								{
									s_node *new_s = malloc(sizeof(s_node));
									temp_s->s_link = new_s;
									new_s->s_link = NULL;
									new_s->w_count = 1;
									strcpy(new_s->f_name,temp->data);    //storing the new file name to new subnode
									(temp_m->f_count)++;   //incrementing the file count in the main node
									break;

								}
								if(!duplicate_f)    //if file name is same
								{
									(temp_s->w_count)++;    //increment the word count
									break;
								}
								else if(duplicate_f)//if file name is not same in the first subnode go for secnd subnode
									temp_s = temp_s->s_link;
							}
							break;
						}
						else if(duplicate_w != 0 && temp_m->m_link == NULL)//if word is not same  create a new main node and subnode
						{
							//assigning values in main node
							m_node *new_m = malloc(sizeof(m_node));
							s_node *new_s = malloc(sizeof(s_node));

							temp_m->m_link  = new_m;
							new_m->f_count = 1;
							strcpy(new_m->word,word);
							new_m->m_link = NULL;
							new_m->s_link = new_s;

							//assigning values in subnode

							new_s->s_link = NULL;
							new_s->w_count = 1;
							strcpy(new_s->f_name,temp->data);
							break;
						}
						else if(duplicate_w)   //if word is not same in first main node go to second main node
							temp_m = temp_m->m_link;
				}
			}
		}
		printf("DATABASE CREATED FOR %s\n",temp->data);
		temp = temp->link;   //moving to next file
	}
	databasecreated=1;
	return 1;
}
