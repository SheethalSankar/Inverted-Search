/*Name :
Date :
Description :
Sample input :
Sample output :
 */
#include "struct.h"

//static int databasecreated=0;
int update(char *f_name,data_base *arr,int *databasecreated)
{
	static int databaseupdated=0;
	if(databaseupdated)
	{
		printf("Data base is already updated;cant update again\n");
		return 0;
	}
	if(*databasecreated)
	{
		printf("Databse is created already so cant update\n");
		return 0;
	}
		
	int i;
	if(!strstr(f_name,".txt"))  //checking the file is of type .txt or not
	{
		return 0;//return 0 if not
	}
	else
	{
		//check it is a proper file or not
		FILE *ptr=fopen(f_name,"r");
		if(ptr==NULL)
		{
			printf("Error opening file\n");
			return 0;
		}

		/*//make the databse null
		for(i=0;i<27;i++)
		{
			arr[i].link=NULL;
		}*/

		//read each line using fscanf()
		//to store each line create an array
		char backup[200];

		while(fscanf(ptr,"%s",backup)!=EOF)
		{
			if(backup[0] == '#' && backup[strlen(backup)-1] == '#')
			{
				//toget index use strtok
				char *fptr=strtok(backup,"#;");
				int index=atoi(fptr);//convert the character index given by strtok to integer

				m_node *new_m=malloc(sizeof(m_node));
				//m_node *temp=arr[index].link;
				if(arr[index].link==NULL)
				{
					arr[index].link = new_m;
				}
				else
				{
					m_node * temp = arr[index].link;
					while(temp -> m_link)
					{
						temp = temp->m_link;
					}
					temp->m_link = new_m;
				}
				//update the contents

				new_m->m_link=NULL;//store main link part as null
								   //	arr[index].link=new_m;  //store new main node address to that index
				strcpy(new_m->word,strtok(NULL,";"));//copy the word from the file to main node word part
				new_m->f_count=atoi(strtok(NULL,";")); //update file count from file to node

				//run loop for file count times and create subnodes that many times
				s_node *prev_s=NULL;
				for(i=1;i<=new_m->f_count;i++)
				{
					s_node *new_s=malloc(sizeof(s_node));
					strcpy(new_s->f_name,strtok(NULL,";"));//copy file name to subnode filename part
					new_s->w_count=atoi(strtok(NULL,";"));
					new_s->s_link=NULL;
					if(prev_s!=NULL)
					{
						prev_s->s_link=new_s;
					}
					else
					{
						new_m -> s_link = new_s;

					}
					prev_s=new_s;  //for next iteration the new node should link with previous node

				}
				
			}
			else   //if file is not of type #;
			{
				return 0;
			}
				
		}
		databaseupdated=1;
		return 1;
	}
}



