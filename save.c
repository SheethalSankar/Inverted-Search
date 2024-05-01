/*Name :
Date :
Description :
Sample input :
Sample output :
*/

#include "struct.h"

int save(data_base *arr,char *file_n)
{
	if(!strstr(file_n,".txt")) //file name is not of type .txt
	{
		return 0;
	}
	else
	{
		FILE *ptr=fopen(file_n,"w");
		if(ptr==NULL)
		{
			printf("Error in opening the file\n");
			return 0;
		}
		else
		{
			for(int i=0;i<27;i++)
			{
				m_node *temp_m=arr[i].link;
				while(temp_m!=NULL)
				{
					fprintf(ptr,"#%d;%s;%d;",i,temp_m->word,temp_m->f_count);
					s_node *temp_s=temp_m->s_link;
					while(temp_s!=NULL)
					{
						fprintf(ptr,"%s;%d;",temp_s->f_name,temp_s->w_count);
						temp_s=temp_s->s_link;
					}
					fprintf(ptr,"#\n");
					temp_m=temp_m->m_link;
				}
			
			}
			return 1;
		}
	}
}


	
