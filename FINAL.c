#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<malloc.h>
#include<string.h>

struct nood
{
    char tc;
    struct nood *left;
    struct nood *right;
};
      // struct nood *start=NULL;
char infofile[200];
struct nood *decode(void);
void decompress(struct nood *destart);
void printleftdecomp(struct nood *destart);
void printrightdecomp(struct nood *destart);
void printtreedecomp(struct nood *destart);
void decompmain(void);

FILE *write(char c,FILE *wf);
void encoding();

struct nod
 {
 	int no;
    char z;
 	struct nod *next;
 };
 char source[200],c_source[200],dest[200];
struct nod *analyze(struct nod *c_start,char c);
char *infofilename(char *name);
char *encryptfilename(char *name);
struct nod *counting()
{
	char c;
	struct nod *c_start=NULL;
    FILE *f;
    printf("Enter name of file which you want to encrypt :");
    do{
    scanf("%s",source);
 	f=fopen(source,"r");
 	if(f==NULL)
  {
	printf("\nfile did not open. \n");
 	printf("\nre_enter corret file path OR correct file name :");
  }
	 }while(f==NULL);
	 while((c=fgetc(f))!=EOF)
 	{
        if(c=='\n')
        {
        c_start=analyze(c_start,'~');
		}
		else
		{
		c_start=analyze(c_start,c);
		}

	 }
    fclose(f);
    return c_start;
}






struct node
{
    int value;
    char tc;
	struct node *next;
    struct node *left;
    struct node *right;
};
struct code
{
	int value;
	struct code *next;
};
struct code *t;
struct info
{
	int value;
	char chg;
	struct code *c;
	struct info *next;
};
struct info*istart,*temp;
struct info *nn,*tn;
struct code *cn,*tm;
int v[1000],z=0;
struct node *tree(struct node *start,int n);
struct node *sorting(struct node *start,int n);
void printinfo(struct node *start);
void printleft(struct node *start);
void printtree(struct node *start);
void printright(struct node *start);
//void filename(void);
void compress(void);

int main()
{
	char choice;
     step:
	printf("\n\n");
	printf("1.ENCRYPT FILE \n");
	printf("2.DECRYPT FILE\n");
	printf("3.EXIT\n");
    printf("Enter your choice :===>>> ");
    choice=getch();
	//scanf("%c",&choice);
    switch(choice)
    {
    	case '1':     printf("%c\n",choice);
		    					compress();
		    					printf("press  any  key to  terminate ");
		              getch();
					    break;
    	case '2':      printf("%c\n",choice);
		                decompmain();
		               printf("press  any  key to  terminate ");
					    getch();
		                break;
    	case '3':
		                printf("%c\n",choice);
						exit(0);
    	default :
    		           printf("%c",choice);
					   printf("\n\nenter right choice -> 1 2 OR 3\n");
    		           goto step;
		                       	break;
      }

  }









  void compress(void)
{
	int i,n=0;
	char choice;
   	struct node *start,*temp,*p;
printf("********************************************************************  IMPORTANT **********************************************************");
    printf("\nchar ->' ~ ' should not exist in your file it is considered as next line character\n");
    printf("\n FILE PATH SHOULD NOT START AND END WITH COMMA");
	printf("\n\nFILE PATH SHOULD NOT HAVE SPACE as->(c:/new folder/filename.txt) c:/new SPACE folder /filename.txt NOT ALLOWED\n");
    printf("  ___________________________________________________________________________________________________________________\n");
	struct nod *ph,*c_start;
    c_start=counting();
    ph=c_start;
    while(ph!=NULL)
    {
    	n++;
    	ph=ph->next;
	}
	ph=c_start;
	strcpy(c_source,source);
	printf("\nnumber of distinct characters in file :- \t%d\n\n",n);
	//printf("\n enter values and characters\n");
	start=NULL;
	for(i=0;i<n;i++)
	{
	temp=(struct node *)malloc(sizeof(struct node));
     temp->value=ph->no;
     temp->tc=ph->z;
	 ph=ph->next;
	//scanf("%d",&temp->value);
	temp->next=NULL;
	temp->left=NULL;
	temp->right=NULL;
	p=start;
	if(i>0){
		while(p->next!=NULL)
	   {
	  	p=p->next;
      	}
	    p->next=temp;
	}
      else{
      	start=temp;
	  }
	}
	start=sorting(start,n);
    start=tree(start,n);
    encoding();
    //printf("\n              _____________________________________File encoding sucessfull____________________________________\n\n");

	printinfo(start);
//	puts(source);
	printf("\n\n\n\n****************************************************   ENCRYPTION     SUCESSFULL   ***********************************************************\n  ");
	printf(" \n\n                                          YOU  HAVE  GOT  TWO  FILES (1. _INFO file 2. _ENCRYPT file) \n\n\n");
	printf("                                              _INFO  FILE  IS  NECESSARY  TO  DECRYPT  (_ENCRYPT FILE)");
    printf("\n\n\n\n\n");

}
struct node *tree(struct node* start,int n)
{
	int a,b,i;
	struct node *x,*pre,*nd,*tre,*temp;
	nd=NULL;
	temp=start;
	for(i=1;i<n;i++)
	{

    	pre=temp;
	    temp=temp->next;
		nd=(struct node *)malloc(sizeof(struct node));
	    if(nd==NULL)
	    {
	    	printf("memory not allocated");
		}
		a=pre->value;
		b=temp->value;
	    nd->value=a+b;
	    x=temp->next;
	    nd->next=x;
	    nd->left=pre;
	    nd->right=temp;
	    temp=sorting(nd,n-i);

	}
        printtree(temp);
}

struct node *sorting(struct node *start,int n)
{
	int step,i,l;
	char c;
	struct node *pre,*run,*temp;
     do{
     	step=0;
     	run=start;
     	for(i=0;i<n-1;i++)
     	{
     		pre=run;
     		run=run->next;
     		if(pre->value>run->value)
     		{
     			l=pre->value;
     			pre->value=run->value;
     		 	run->value=l;

			    temp=pre->left;
     			pre->left=run->left;
     		 	run->left=temp;

			    temp=pre->right;
     			pre->right=run->right;
     		 	run->right=temp;

		        c=pre->tc;
		        pre->tc=run->tc;
		        run->tc=c;
			  step++;
			 }
		 }

	 }while(step!=0);
   return start;
}


void printtree(struct node *start)
{
	    int o,sum=0;
	  if(start->left!=NULL)
	  {
	  	printleft(start);
	   }
       if(start->right!=NULL)
	   {
	   	printright(start);
	   }
	   if(start->left==NULL && start->right==NULL)
	   {
	   	    nn=(struct info *)malloc(sizeof(struct info));
	   	    nn->value=start->value;
	   	    nn->next=NULL;
	   	    nn->chg=start->tc;
			  for(o=0;o<z;o++)
	   	   {
	   	   	   cn=(struct code *)malloc(sizeof(struct code));
	           cn->value=v[o];
	           cn->next=NULL;
					  if(o==0)
	   	   	      {   nn->c=cn;
	   	   	      }
					  else
					  {
					  	   tm=nn->c;
							 while(tm->next!=NULL)
			    	       {
			    	       	tm=tm->next;
						   }
						   tm->next=cn;

					  }

			}
			if(istart==NULL)
			{
				istart=nn;
			}
			else{
				tn=istart;
				while(tn->next!=NULL)
				{
					tn=tn->next;
				}
			    tn->next=nn;
			}

	   }
	  z--;
}
void printleft(struct node *start)
{
	start=start->left;
	v[z]=0;  z++;
	printtree(start);
}
void printright(struct node *start)
{
	start=start->right;
	v[z]=1; z++;
	printtree(start);
}
void printinfo(struct node *start)
{
	FILE *fp;
	char chm;
	char *te;
     char info[200];
		te = strchr(c_source,'.');   //Get the pointer to char token
      *te = '\0';
      strcpy(info,c_source);
		strcat(info,"_INFO.txt");

	fp=fopen(info,"w");
	if(fp==NULL)
	{
		printf(" info file not open");
	}
	//puts(b);
	printf("\t\tchar   occurance in file\t _________________________________________huffman_code________________________________________");
	temp=istart;
     do
     {

     	if(temp->chg=='~')
     	{
     		printf("\n  \tnextline(~)\t %d\t\t",temp->value);
		 }
		 else{
		printf("\n\t\t%c\t %d\t\t",temp->chg,temp->value);
		 }

     	chm=temp->chg;

     	t=temp->c;
		 while(t!=NULL)
		 {
		 	printf("\t%d",t->value);

		    if(t->value==1)
		    fputc('1',fp);
		    else{
		    	fputc('0',fp);
			}
		 t=t->next;
		 }
		    fputc('\n',fp);
		    fputc(chm,fp);
		    fputc('\n',fp);
		 temp=temp->next;
	 }while(temp!=NULL);
	     fclose(fp);
}

struct nod *analyze(struct nod *c_start,char c)
{
    struct nod *nn,*p,*temp;
	int s;
	temp=c_start;
	if(temp==NULL)
	{
		nn=(struct nod *)malloc(sizeof(struct nod));
		if(nn==NULL)
        {
           printf("memory not allocated\n");
        }
		nn->z=c;
		nn->next=NULL;
		nn->no=1;
     	c_start=nn;
	}
	else
	{

		while(c!=temp->z)
		{
			if(temp->next==NULL)
                goto step;
			temp=temp->next;

		}
		step:
		if(c==temp->z)
		{
		    s=temp->no;
		    s=s+1;
			temp->no=s;
		}
		else{
		p=(struct nod *)malloc(sizeof(struct nod));
		p->z=c;
		p->next=NULL;
        p->no=1;
		temp=c_start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
		}
	}
   return c_start;
}
void encoding()
{
	FILE *wf,*rf;
	char c;
     char *temp,*te;
//	puts(source);
	rf=fopen(source,"r");
	if(rf==NULL)
	{
		printf("source file not open");
	}
    strcpy(dest,c_source);
    	te = strchr(dest,'.');   //Get the pointer to char token
      *te = '\0';
      //strcpy(info,dest);

    strcat(dest,"_ENCRYPT.txt");

    //d=encryptfilename(dest);
	//strcpy(dest,d);
	wf=fopen(dest,"w");

	if(wf==NULL)
	{
		printf("encrypt file not open\n");
	}
		while((c=fgetc(rf))!=EOF)
		{
           	   if(c=='\n')
           	   {
           	   write('~',wf);
				  }
				  else{

				  	write(c,wf);
				  }

		}
    fclose(rf);
    fclose(wf);

}

FILE *write(char c,FILE *wf)
{
	int i;
	temp=istart;
	struct code *med;
	while(temp!=NULL)
	{
		if(c==temp->chg)
		{
			goto step;
		}
		temp=temp->next;
	}
	step:
	  med=temp->c;
	  while(med!=NULL)
	  {
	  	i=med->value;
	    if(i==1)
	  	putc('1',wf);
	  	else
	  	putc('0',wf);
		  med=med->next;
		  }
}

void decompmain(void)
{
	printf("*************************************************************** IMPORTANT *****************************************************************************");
	printf("\n FILE PATH SHOULD NOT START AND END WITH COMMA");
	printf("\n\nFILE PATH SHOULD NOT HAVE SPACE as->(c:/new folder/filename.txt) c:/new SPACE folder /filename.txt NOT ALLOWED\n\n");
struct nood *destart;
	destart=decode();
	decompress(destart);
}

struct nood *decode(void)
{
	   struct nood *destart=NULL;
	   struct nood *nn,*temp;

        char c;
    int flag;
	   FILE *rf;
	   printf("\n\t Enter _INFO  file   name:");
	   do{

	   scanf("%s",&infofile);
	   rf=fopen(infofile,"r");
	   if(rf==NULL)
	   {
	   	printf("\nINFO file did not open  ");
	    printf("\nre_enter correct name of INFO file :");
	   }
}while(rf==NULL);
	   	destart=(struct nood *)malloc(sizeof(struct nood));
	     if(destart==NULL)
		 printf("memory not allocate\n");
	    flag=0;

	    destart->left=NULL;
	    destart->right=NULL;
	    temp=destart;
		  while((c=getc(rf))!=EOF)
	   {
			if(flag==0)
			{
				if(c=='1')
				{
					if(temp->right==NULL)
					{
						nn=(struct nood *)malloc(sizeof(struct nood));
	   	              // nn->tc="@";
	                     nn->left=NULL;
	                     nn->right=NULL;

				       temp->right=nn;
				       temp=nn;
					}
					else
					{
						temp=temp->right;
					}
				}
				if(c=='0')
				{
				    if(temp->left==NULL)
				    {
				    	nn=(struct nood *)malloc(sizeof(struct nood));
	   	                  //nn->tc="@";
	                      nn->left=NULL;
	                     nn->right=NULL;
				      	temp->left=nn;
				        temp=nn;
					}
					else
					{
						temp=temp->left;
					}

				}
				if(c=='\n')
				{
		          	flag=1;
				}

			}
			else
			{
				if(c=='\n')
				{
					flag=0;
				}
				else{
					temp->tc=c;
					temp=destart;
				}
			}
}
	  fclose(rf);
	   return destart;

}

void decompress(struct nood *destart)
{
	//printf(" \ndecompressed destart= %d",destart);
	struct nood *temp;
	FILE *wf,*rf;
	char fname[100];
    char cc[100];
	char c,ch;
	char *r;
  strcpy(fname,infofile);
  r = strchr(fname,'_');   //Get the pointer to char token
*r = '\0';
    //puts(fname);
	strcat(fname,"_ENCRYPT.txt");
	rf=fopen(fname,"r");
	if(rf==NULL)
    {
    	printf("\n_ENCRYPT file did not open");
	    printf("\nplace the _ENCRYPT file in same directory of _INFO file\n");
	}


  strcpy(cc,fname);
  r = strchr(cc,'_');   //Get the pointer to char token
*r = '\0';
	strcat(cc,"_DECRYPT.txt");
	wf=fopen(cc,"w");
	if(wf==NULL)
	{
		printf("file not open %s",cc);

	}
	temp=destart;
	while((c=fgetc(rf))!=EOF)
	{
		     if(c=='\n')
		     {
		     	goto step;
			 }

			if(c=='1')
		{
			//putc(c,wf);
			temp=temp->right;
		      if(temp->left==NULL && temp->right==NULL)
		      {
			   //printf("%c",temp->tc);
			    if(temp->tc=='~')
			    {
			   //printf("%c",temp->tc);
				putc('\n',wf);
			    }
			else
			{
			//printf("%c",temp->tc);
			putc(temp->tc,wf);
	      	}
			temp=destart;
	     }
	}
	if(c=='0')
		{
		//        putc(c,wf);
		      temp=temp->left;
		      if(temp->left==NULL && temp->right==NULL)
		{
		//	printf("%c",temp->tc);
			if(temp->tc=='~')
			{
			//	printf("%c",temp->tc);
				fputc('\n',wf);
			}
		else{
			fputc(temp->tc,wf);
	//   	printf("%c",temp->tc);
			}
			temp=destart;

		}
	  }
	  step:
	  	{
	  		//kmvkf;
		  }
	}
	printf("\n\n");
	printf("\n******************************************* DECRYPTION  SUCESSFULL*********************************************** ");
	printf("\n\n\n                 YOU   HAVE   GOT  DECRYPTED  FILE  THERE->(%s)                        ",cc);
    printf("\n\n\n");
	fclose(wf);
	fclose(rf);

}
//void printresult(struct nood *temp,char c,struct nood *destart)

void printleftdecomp(struct nood *destart)
{
	destart=destart->left;
	printf("0");
	printtreedecomp(destart);
}
void printrightdecomp(struct nood *destart)
{
	destart=destart->right;
	printf("1");
	printtreedecomp(destart);
}
void printtreedecomp(struct nood *destart)
{
		if(destart->left!=NULL)
	  {
            	printleftdecomp(destart);
      }
       if(destart->right!=NULL)
	   {
           	printrightdecomp(destart);
	   }
	   if(destart->left==NULL && destart->right==NULL)
	   {
           printf("%c\t",destart->tc);

	   }

}
