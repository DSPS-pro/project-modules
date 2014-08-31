#include "iostream"
#include <string.h>
#include <stdlib.h>
using namespace std;
struct node
{
   node *left;
   char word[20],meaning[100];
   node  *right;
};
node * bsearch(node *,char []);
void showmenu();
void displayall(node *);
node *addword(node *,char [],char[]);
node * maketree(char [],char []);

void prog()
{

 	char word[20];
  char meaning[100];
	int menuchoice;
	node *root=NULL;
	while(1)
	{
		showmenu();
		cin>>menuchoice;
		switch(menuchoice)
		{
			case 1 : cout<<"\n enter word:";
			cin>>word;
			cout<<"\n enter meaning:";
			cin>>meaning;
			if(root==NULL)
				root=maketree(word,meaning);
			else
				root=addword(root,word,meaning);
			break;
			case 2: if (root==NULL)
				cout<<"\n the dictionary is emptyâ€¦â€¦";
			else
				cout<<"\nfind meaning of: ";
			cin>>word;
			node *t;
			t=bsearch(root,word);
			if(t==NULL)
				cout<<"word not foundâ€¦";
			else
			{
				cout<<t->word<<":";
				cout<<t->meaning;
			}
			
			break;
			case 3: if(root==NULL)
				cout<<"\t\t\t dictionary is emptyâ€¦";
			else
				displayall(root);
			break;
			case 4:exit(0);
			default:cout<<"\n enter again :";
			
       prog();
			break;
			}
			}
			}

void showmenu()
{
	cout<<"\n \t\t\t\t computer dictionary";
  cout<<"\n  [1].add a word";
	cout<<"\n [2].find meaning";
	cout<<"\n [3] display all";
	cout<<"\n [4] save and close. \n  enter choice:";
}
node * maketree(char w[],char m[])
{
 	node *p;
	p=new node;
	strcpy(p->word,w);
	strcpy(p->meaning,m);
	p->left=NULL;
	p->right=NULL;
	return p;
}
node* addword(node *t, char wor[],char meaning[])
{    node *root=t;
     if (root == NULL)
     {
          root= new node;
          strcpy(root->word,wor);
          strcpy(root->meaning,meaning);
          root->left = NULL;
          root->right = NULL;
          return t;
     }
     int ret ;
     ret = strcmp(wor,root->word);
     if (ret>0)
     {
        root->right=addword(root->right,wor,meaning);
        return t;
     }
     else if(ret<0)
         root->left=addword(root->left,wor,meaning);
     else
         cout<<"\n The word already exists....";
     return root;
}


node  * bsearch(node *root,char  word[])
{
	node *q;
q=root;
while(q!=NULL)
{
	if(strcmp(word ,q->word)<0)
		q=q->left;
	else if(strcmp(word,q->word)>0)
		q=q->right;
	else if(strcmp(word,q->word)==0)
		break;
}
return q;
}
void displayall(node *root)
{
	if(root!=NULL)
	{
		displayall(root->left);
		cout<<"\n "<<root->word<<" : "<<root->meaning;
		displayall(root->right);
	}
}


int main()
{
	
	//intro();
	prog();
	return(0);
}
