#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct nood
{
    char tc;
    struct nood *left;
    struct nood *right;
};
      // struct nood *destart=NULL;
char infofile[200];
struct nood *decode(void);
void decompress(struct nood *destart);
void printleftdecomp(struct nood *destart);
void printrightdecomp(struct nood *destart);
void printtreedecomp(struct nood *destart);
void decompmain(void);
int main()
{

      decompmain();

}

void decompmain(void)
{
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
