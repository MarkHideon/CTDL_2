#include<iostream>
using namespace std;
#define N 100

int c[N], b[N];

void input(int a[], int &n, int &max)
{
    cout << "nhap so luong ptu n: "; cin >> n;
    for (int i=1; i<=n; i++)
    {   
        cout << "Nhap a[" << i << "] = ";
        cin >> a[i];
    }
    max = a[1];
    for(int i=1;i<=n;i++)
        if(max < a[i]){
            max = a[i];
        }
}

void countingsort(int a[], int b[], int k, int n)
{
for(int i=1; i<=k;i++)
    c[i]=0;

for(int j=1;j<=n;j++)
    c[a[j]]++;

for(int i=1;i<=k;i++)
    c[i] = c[i] + c[i-1];

for(int j=n;j>=1;j--)
{
    b[c[a[j]]] = a[j];
    c[a[j]]--;
}
}


void output(int a[], int n)
{
    for(int i=1;i<=n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
int a[N], n, k=0; 

input(a,n,k);
output(a,n);

countingsort(a,b,k,n);
output(b,n);

return 0;
}