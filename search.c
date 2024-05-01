/*Name :
Date :
Description :
Sample input :
Sample output :
 */
#include "struct.h"

int search(data_base *arr,char *word)
{
	//find index of the word
	int index=tolower(word[0])-97;
	//printf("%d and %c",index,word[0]);
	
		if(arr[index].link==NULL)
		{
			return 0;   //word not found
		}
		else 
		{
			m_node *temp_m=arr[index].link;
			while(temp_m!=NULL)
			{
				int same_w=strcmp(word,temp_m->word);
				if(!same_w)
				{
					s_node *temp_s=temp_m->s_link;
					printf("Word %s is present in %d files\n",word,temp_m->f_count);
					printf("\n");
					while(temp_s != NULL)
					{

						printf("In %s word %s is %d times\n",temp_s->f_name,word,temp_s->w_count);
						printf("\n");

						temp_s=temp_s->s_link;

					}
					return 1;// word found


				}
				temp_m=temp_m->m_link;  //when temp_s becomes null and first node word is not same then move to next main node
			}
			
			

		}
	
}
