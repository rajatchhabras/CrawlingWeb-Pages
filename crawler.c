#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#define max_depth max 5;
 int m=1;
int w=0;
int x=0;
#define HASH_SIZE 100
#define URL_LENGTH 1000
#define get_url "https://www.chitkara.edu.in/"
#define get_seed "www.chitkara.edu.in/"
#define MAX_URL_PER_PAGE 500
struct URL
{
char str[500];
int depth;

};
struct node
{
struct URL U;
int key;
int isvisited;
struct node *next;
};
struct hash
{
struct node *head;
struct node *tail;
int count;
};
int key_generate(char *s)
{

int i=0,sum=0;
while(s[i]!='\0')
{
sum=sum+s[i];
i++;
}
while(sum>=50)
{
sum=sum/10;
}
return sum;
}
void create(struct hash *he,struct node **data,char *url,int dept,int keyy,int visited)
{

printf("%p",he->head);
printf("here kry is %d\n",keyy);
printf("getting inside\n");
struct URL *e;
int flag=0;
struct node *temp,*temparary;
temp=*data;
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
e=(struct URL *)malloc(sizeof(struct URL));
strcpy(e->str,url);
e->depth=dept;
newnode->key=keyy;
newnode->isvisited=visited;
newnode->U=(*e);
newnode->next=NULL;
printf("\n\ngetting inside\n");
if(he->head==NULL){
printf("\n\nok\n");
  if(temp!=NULL)
{
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;

}
else
{
(*data)=newnode;

}
he->head=newnode;
he->tail=newnode;
(he->count)++;
printf("count is %d\n",he->count);
}
else
{
int i;
flag=0;
temparary=he->head;
printf(" inside count is %d\n",he->count);
printf(" inside value is %s\n",(he->head->U).str);
for(i=0;i<he->count-1;i++)
{
if(strcmp((he->head->U).str,url)==0)
{
flag=1;
break;

}

temparary=temparary->next;
}
if(flag==0)
{
newnode->next=temparary->next;
temparary->next=newnode;
(he->count)++;
}
printf("count is %d\n",he->count);

}
printf("\n dddddd \n");
}
void traverse(struct node **data)
{
struct node *temp;
temp=*data;
while(temp!=NULL)
{

printf("%s   %d  %d\n",(temp->U).str,(temp->U).depth,temp->key);
temp=temp->next;
}
}
int remove_duplicate(char **st,int w,char *temp)
{
int i,flag=0;
for(i=0;i<w;i++)
{
 if(strcmp(st[i],temp)==0)
{
flag=1;
return 0;
}
}
if(flag==0)
return 1;
}


void checking_string(char *str,char **st)
{
int i=0,k=0;


char *temp=(char *)malloc(500);
for(i=0;i<strlen(str);)
{
if(str[i]=='a'&&str[i-1]=='<')
{
while(str[i]!='h')
i++;
if(str[i]=='h'&&str[i+1]=='r'){
while(str[i]!='"')
{
i++;
}
i++;
k=0;
while(str[i]!='"')
{//y14SD413807W
temp[k]=str[i];
k++;
i++;
}
i++;
temp[k]='\0';
if((temp[0]!='#')&&(strcmp(temp,get_url)!=0)&&(strstr(temp,get_seed)))
{
if(temp[strlen(temp)-1]=='/')
temp[strlen(temp)-1]='\0';
if((remove_duplicate(st,w,temp))&&(w<50)){
printf(" data for save %s\n",temp);
st[w]=temp;

w++;

}
}
}
}
else
i++;
}
}
int checking_insert(struct node **head,char *st)
{
struct node *temp;
int flag=0;
temp=*head;
while(temp!=NULL)
{
if(strcmp(((temp->U).str),st)==0){
flag=1;
return 0;
}
temp=temp->next;

}
if(flag==0)
return 1;
}
void fetch(char *url,char *dir)
{
char fetching[500]={0};
strcat(fetching,"wget --no-check-certificate -O ");

strcat(fetching,dir);
strcat(fetching,"/temp.txt ");
strcat(fetching,url);
//strcat(fetching," --header \"Referer: www.chitkara.edu.in\"");
system(fetching);

}
FILE * another_file(char *s,int i)
{
char filename[100];
FILE *ptr;
char e[50];
e[0]=i+48;
e[1]='\0';
printf("\n%c\n",e[0]);
strcpy(filename,s);
strcat(e,".txt\0");

strcat(filename,"/temp");
strcat(filename,e);
printf("%s",filename);
ptr=fopen(filename,"w");
return ptr;

}
int file_size()
{
int file_size;
struct stat st; 
stat("dd/temp.txt",&st);
file_size=st.st_size;
return file_size;
}
int url(char *wgett)
{
if(!system(wgett))
return 1;
else
return 0;

}

int testDir(char *dir)
{
int flag=0;
  struct stat statbuf;
  if ( stat(dir, &statbuf) == -1 ) 
  {
flag=1;
   return 0;
   
  }
  if ( !S_ISDIR(statbuf.st_mode) ) 
  {
   flag=1;
return 0;
  }

  if ( (statbuf.st_mode & S_IWUSR) != S_IWUSR ) 
  {
flag=1;
   return 0;   
  }
if(flag==0)
return 1;
}
void urlmake(char *wgett,char *url)
{
strcpy(wgett,"wget --spider ");
strcat(wgett,url);
strcat(wgett," --header \"Referer: www.chitkara.edu.in\"");
printf("wgett is %s\n\n",wgett);
}

int main(int argc,char *argv[])
{
struct hash h[50]={NULL};
struct node *head=NULL;
struct node *temp;
int upto;
int key;
char *save[MAX_URL_PER_PAGE];
   int i=0,get,l;
FILE *tk;
char *check;
int size;
char *temp_st;
   char wgett[500];
urlmake(wgett,argv[1]);
printf("%s\n",wgett);
   if((argc==4)&&(url(wgett))&&(testDir(argv[3])))
  {

fetch(argv[1],argv[3]);
size=file_size();
printf("%d",size);
temp_st=(char *)malloc((size+1)*sizeof(char));
FILE *ptr;
ptr=fopen("dd/temp.txt","r");

if(ptr==NULL)
printf("error opening in file");
tk=another_file(argv[3],m);
m++;
key=key_generate(argv[i]);
printf("first key is %d\n",key);
create(&(h[key]),&head,argv[1],0,key,1);

while(!feof(ptr)){
fgets(temp_st,size+1,ptr);
fputs(temp_st,tk);
checking_string(temp_st,save);
}

for(i=0;i<w;i++){
key=key_generate(save[i]);
printf("The key is %d \n",key);
create(&(h[key]),&head,save[i],1,key,0);
}
traverse(&head);
temp=head;
w=0;
fclose(ptr);
fclose(tk);
free(temp_st);
printf("\n pehlee \n");
while(temp!=NULL)
{
w=0;
if((!(temp->isvisited))&&((temp->U).depth<=10))
{
urlmake(wgett,(temp->U).str);
fetch(((temp->U).str),argv[3]);
size=file_size();
char sst[size];
ptr=fopen("dd/temp.txt","r");

if(ptr==NULL)
printf("error opening in file");
tk=another_file(argv[3],m);
fputs((temp->U).str,tk);
fputs("\n depth is :",tk);

m++;
temp->isvisited=1;
while(!feof(ptr)){
fgets(sst,size+1,ptr);

fputs(sst,tk);
checking_string(sst,save);
}

printf("w is %d",w);
for(i=0;i<w;i++){
if(checking_insert(&head,save[i])){
key=key_generate(save[i]);
printf("The key is %d",key);

create(&h[key],&head,save[i],((temp->U).depth+1),key,0);
}
}

traverse(&head);
printf("\n pehlee \n");

fclose(ptr);
fclose(tk);
temp=head;

}
else
temp=temp->next;

}
}
}
