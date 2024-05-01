/*Name :
Date :
Description :
Sample input :
Sample output :
*/
#include "struct.h"

int display_db(data_base *arr)
{
	//printf("[INDEX] WORD W_COUNT F_NAME F_COUNT W_COUNT\n");
	for(int i=0;i<27;i++)
	{
		m_node *temp_m; //temp stores the first main node address 
		if(arr[i].link != NULL) 
		{
			temp_m=arr[i].link;
			while(temp_m!=NULL)
			{

				printf("[%d]\t%s\t%d\t",i,temp_m->word,temp_m->f_count);

				s_node *temp_s=temp_m->s_link;   //storing first sub node address to temp_s
				while(temp_s !=NULL)
				{
					printf("%s\t%d\t",temp_s->f_name,temp_s->w_count);
					temp_s=temp_s->s_link;//traversing temp pointer from the first subnode to second subnode
				}
				printf("\n");
				temp_m=temp_m->m_link; //traversing to the next main node
			}

			
		}
	
				
	}
	return 1;
}
