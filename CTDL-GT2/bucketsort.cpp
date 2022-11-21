// #include<stdlib.h>
// #include<conio.h>
#include<cmath>
#include<iostream>
using namespace std;
#define MAX 1000
typedef struct CELL *LIST;
struct CELL {
				float x;
				LIST next;
	       };
typedef LIST TABLE[MAX];
typedef float VECTOR[MAX];
TABLE T;
VECTOR A;
int n;
void init(TABLE &T,int &n)
{
  for(int i=0; i<n;i++) T[i]=NULL;
}


void LIST_INSERT(LIST &L, float a)
{
	LIST p;
	p=new(CELL);
	p->x=a;
	p->next=L;
	L=p;
}
void LIST_sort(LIST &L)
{
	LIST p, q;
	float t;
	p=L;
	while(p!=NULL)
	{
	  q=p;
	  while(q!=NULL)
	  {
	    if(q->x<p->x) {t=p->x; p->x=q->x; q->x=t;}
	    q=q->next;
	  }
	  p=p->next;
	}
 }


void TABLE_INSERT(TABLE T,VECTOR A,int &n)
{

    for(int i=1; i<=n;i++)
		LIST_INSERT(T[int(n*A[i])], A[i]);
}

void trave(LIST L)
{
  if(L!=NULL)
  {
    cout <<(L->x) <<' ';
    trave(L->next);
  }
}

void TRAVEL(TABLE T, int m)
{
  for(int i=0;i<m; i++)
     if(T[i]!=NULL) {cout<<"T["<<i<<"]-> "; trave(T[i]);cout<<"\n";}
}
void TABLE_SORT(TABLE &T, int m)
{
  for(int i=0;i<m; i++)
     if(T[i]!=NULL) LIST_sort(T[i]);
}
void TABLE_CONCAT(TABLE &T, VECTOR &A, int m)
{
  LIST p;
  int j=1;
  for(int i=0;i<m; i++)
     if(T[i]!=NULL) {
			p=T[i];
			while(p!=NULL){ A[j]=p->x; p=p->next; j=j+1;}
		     }
 }

void print(VECTOR A, int n)
{
	for(int i=1;i<=n;i++) cout<<A[i]<<" ";
	cout<<"\n";
}

int main()
{
 
 n=10;
 init(T,n);
 for(int i=1;i<=n;i++)
	{
		cout<<"A["<<i<<"]="; cin>>A[i];
	}
 TABLE_INSERT(T,A,n);
 TRAVEL(T,n); cout<<"\n";
 TABLE_SORT(T,n);
 TABLE_CONCAT(T,A,n);
 print(A,n);
 return 0;
}