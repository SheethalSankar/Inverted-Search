/*Name :
Date :
Description :
Sample input :
Sample output :
*/

#include "struct.h"
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int databasecreated=0;
	int ch;
	//declare list
	Slist *file_name=NULL;   //*head is null
	//declare array
	data_base arr[27]={NULL}; //data type of array is data_base

	//call validation function
	if(validate(argc,argv,&file_name))
	{
		printf("VALIDATION SUCCESSFULL\n");
		if(file_name==NULL)
		{
			printf("LIST EMPTY\n");
		}
		else
		{
			Slist *temp=file_name;  //here file_name is head
			while(temp!=NULL)
			{
				printf("%s -> ",temp->data);
				temp=temp->link;
			}	
			printf("NULL\n");
		}
	
		while(1)
		{	
			printf("\nEnter a choice:\n 1.CREATE \n 2.DISPLAY\n 3.SEARCH\n 4.SAVE\n 5.UPDATE\n 6.EXIT\n");
			scanf("%d",&ch);
			//getchar();
			switch(ch)
			{
				case 1:
					//printf("Selected create database");
					if(create_db(arr,&file_name))
					{
						//flag=1;
						printf("Creation successfull !!!!!!!\n");
					}
					else
					{
						printf("Creation failed !!!!!\n");
						return 0;
					}
					break;
				case 2:
					if(display_db(arr))
					{
						printf("Display successfull !!!!!\n");
						break;
					}
					else
					{
						printf("display failed !!!!!!!\n");
						return 0;
					}
				case 3:
					char w[100];

					printf("Enter a word --> ");
					scanf("%s",w);
					if(search(arr,w))
					{
					
						printf("!!!!!!! Search successfull !!!!!!!\n");
						break;
					}
					else
					{
						printf("Word not found\n");
						break;
					
					}
				case 4:
					char f[100];
					printf("ENter the file name --> ");
					scanf("%s",f);
					if(save(arr,f))
					{
						printf("!!!!! Save successfull !!!!!\n");
						break;
					}
					else
					{
						printf("!!!!! Save failed !!!!!\n");
						break;
					}
				case 5:
					char b[100];
					printf("Enter the backup file name --> ");
					scanf("%s",b);
					if(update(b,arr,&databasecreated))
					{
						printf("!!!!!! Update successfull !!!!!!\n");
						break;
					}
					else
					{
						printf("!!!!!! Update failed !!!!!!\n");
						break;
					}

				case 6:
					exit(0);
					break;
				default:
					printf("ENTER A VALID CHOICE\n");
					break;
			}
		}
	}
	else
	{
		printf("VALIDATION FAILED\n");
		return 0;
	}


}
int validate(int argc,char * argv[],Slist **head) // head stores the address of list file_name which is null initially
{ 
	
		 if(argc<2)
		 {
			 printf("ENTER VALID NUMBER OF ARGUMENTS\n");
			 return 0;
		 }
		 else
		 {
			 for(int i=1;i<argc;i++)
			 {
				 if(strstr(argv[i],".txt"))
				 {
					 
						 FILE *ptr=fopen(argv[i],"r");
						 if(ptr!=0)
						 {
							 fseek(ptr,0,SEEK_END);
							 int pos=ftell(ptr);
							 if(pos!=0)
							 {
								 if(!insert_last(argv[i],head))
								 {
									 printf("%s DUPLICATE FOUND\n",argv[i]);
									 //return 1;
									 //fclose(ptr);

							 	 }
								 else
								 {
								 	printf("%s INSERTION SUCCESSFULL\n",argv[i]);
									
									
								 }
						     }
							 else
							 {
								 printf("%s is EMPTY\n",argv[i]);
								 fclose(ptr);
							 }
							 
						 }
						 
						 else
						 {
							 printf("%s DOESNT EXIST\n",argv[i]);
						 }
				 }
				 else
				 {
					 printf("FILE EXTENSTION DOESNT MATCH\n");
				 }
			 }
			 return 1;
		 }
}




int insert_last(char *file_name,Slist **head)
{
	Slist *new=malloc(sizeof(Slist));
	if(new==NULL)
	{
		return 0;
	}
	strcpy(new->data,file_name);
	new->link=NULL;
	if(*head==NULL)
	{
		*head=new;
		return 1;
		
	}
	else
	{
		Slist *temp=*head;
		Slist *prev=NULL;
		while(temp!=NULL)
		{
			if(strcmp(temp->data,file_name)==0)
			{
				//free(new);
				return 0;
			}
			prev=temp;
			temp=temp->link;
				
			
		}
		prev->link=new;
		return 1;
	}
}


