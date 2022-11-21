//Đoàn Ngọc Hiếu
//2151013022
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
TABLE H;
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
	    if(q->x<p->x) 
        {
            t=p->x; p->x=q->x; q->x=t;
        }
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

void TRAVEL(TABLE H, int m)
{
  for(int i=0;i<m; i++)
     if(H[i]!=NULL) {cout<<"T["<<i<<"]-> "; trave(H[i]);cout<<"\n";}
}
void TABLE_SORT(TABLE &T, int m)
{
  for(int i=0;i<m; i++)
     if(T[i]!=NULL) LIST_sort(T[i]);
}
void TABLE_CONCAT(TABLE &T, VECTOR &A, int m)
{
  LIST p;
  int j=n;
  for(int i=0;i<m; i++)
    { 
     if(T[i]!=NULL) 
        {
			p=T[i];
			while(p!=NULL)
            { 
                A[j]=p->x; p=p->next; j--;
            }
		}
    }
 }

void print(VECTOR A, int n)
{
	for(int i=1;i<=n;i++) cout<<A[i]<<" ";
}

int main()
{
 
n=15;
init(H,n);
A[1]=0.72;
A[2]=0.84;
A[3]=0.2;
A[4]=0.95;
A[5]=0.25;
A[6]=0.91;
A[7]=0.33;
A[8]=0.44;
A[9]=0.65;
A[10]=0.52;
A[11]=0.32;
A[12]=0.56;
A[13]=0.18;
A[14]=0.67;
A[15]=0.83;
 
 TABLE_INSERT(H,A,n);
 TRAVEL(H,n); cout<<"\n";
 TABLE_SORT(H,n);
 TABLE_CONCAT(H,A,n);

 cout << "Sorted array is: "; 
 print(A,n);
 return 0;
}