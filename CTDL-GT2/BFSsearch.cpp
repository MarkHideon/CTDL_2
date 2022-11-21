 #include<iostream>
 using namespace std;
 #define MAX 30
 #define indef 32655
 #define white 0
 #define black -1
 #define gray 1
 #define NIL -1
 typedef  struct node *LIST;
  struct node{
					int v;
					LIST next;
			};
 typedef struct NODE_LIST{
							LIST f,r;
			 } QUEUE;
 struct GRAPH {
						int numv;
						int a[MAX][MAX];
			};
 GRAPH G;
 int color[MAX];
 int d[MAX];
 int befor[MAX];
  
 void queueinit(QUEUE &Q)
 {
	Q.f=Q.r=NULL;
 }
 int queueempty(QUEUE Q)
 {
	if(Q.r==NULL) return 1;
	else return 0;
 }
 void push_queue(int x, QUEUE &Q)
 {
   LIST  q;
   q=new(node);
   q->v=x;
   q->next=NULL;
   if(Q.r==NULL) Q.f=q;
   else Q.r->next=q;
   Q.r=q;
 }
 int pop_queue(QUEUE &Q)
 {
  int s;
  LIST q;
  if(!queueempty(Q))
  {
	   q=Q.f;
	   s=q->v;
	   Q.f=q->next;
	   if(Q.f==NULL) Q.r=NULL;
	   delete q;
  }
  return s;

 }
 void init(GRAPH &G)
 {
  int i,j;
  cout<<"given number of vertices of graph:"; cin>>G.numv;
  cout<<"input adjacent matrix of graph:\n";
  for(i=1;i<=G.numv;i++)
  {
      for(j=i+1;j<=G.numv;j++)
      {
	      cout<<"a["<<i<<","<<j<<"]="; cin>>G.a[i][j]; G.a[j][i]=G.a[i][j];
      }
      G.a[i][i]=0; cout<<"\n";
   }
 
 }
 void print_data(GRAPH G)
 {
  int i,j;
  cout<<"adjacent matrix:\n";
  for(i=1;i<=G.numv;i++)
  {
	for(j=1;j<=G.numv;j++) cout<<G.a[i][j]<<"  "; cout<<"\n";
  }
 }

 void BFS(GRAPH G, int s)
 {
  int u,v;
  QUEUE Q;
  for(u=1;u<=G.numv;u++) 
  {
	  color[u]=white;
	  d[u]=indef;
	  befor[u]=NIL;
  }
  color[s]=gray;
  d[s]=0;
  befor[s]=NIL;
  queueinit(Q);
  push_queue(s,Q);
  while(!queueempty(Q))
  {
      u=pop_queue(Q);
      cout<<"("<<u<<", "<<d[u]<<")\n";
      for(v=1;v<=G.numv;v++)
	   if((G.a[u][v]==1)&&(color[v]==white))
	   {
	     color[v]=gray;
		 d[v]=d[u]+1;
		 befor[v]=u;
		 push_queue(v,Q);
	   }
	  color[u]=black;
  }
 } // of procedure BFS
 

int main()
{
	int s;
	init(G);
	print_data(G);
	cout<<"Start vertex: "; cin>>s;
	cout<<"search order from vertex "<<s<<"\n"; 
	BFS(G,s);
}