#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


//typedef int data_t;
typedef struct list
{
	char data[100];
	struct list *link;
}Slist;

typedef struct main_node
{
	char word[20];
	int f_count;
	struct sub_node *s_link;
	struct main_node *m_link;

}m_node;

typedef struct sub_node
{
	int w_count;
	char f_name[20];
	struct sub_node *s_link;

}s_node;

typedef struct array
{
	struct main_node *link;
}data_base;

//functions declaration;
int validate(int argc,char *argv[],Slist **head);
int insert_last(char *file_name,Slist **head);
int create_db(data_base *,Slist **);
int display_db(data_base *);
//m_node *create_mnode(char *word,Slist **);
//s_node *create_snode(Slist **);
int search(data_base *,char *w);
int save(data_base *,char *f);
int update(char *,data_base *,int *);

