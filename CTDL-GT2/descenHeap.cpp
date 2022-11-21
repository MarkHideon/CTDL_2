#include <iostream>
using namespace std;

#define MAX 100

void input(int a[], int &n)
{
   cout << "Nhap so phan tu n: "; cin >> n;
   for(int i=0;i<=n;i++)
   {
        cout << "nhap a["<< i <<"]= "; cin >> a[i];
   }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int N, int i)
{

	// Initialize largest as root
	int smallest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	if (l < N && arr[l] < arr[smallest])
		smallest = l;

	if (r < N && arr[r] < arr[smallest])
		smallest = r;

	if (smallest != i) {
		swap(arr[i], arr[smallest]);

		heapify(arr, N, smallest);
	}
}

void heapSort(int arr[], int N)
{

	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	for (int i = N - 1; i > 0; i--) {

		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

int Partition(int a[], int p, int r)
{
    int i, j ,x;
    x=a[r];
    i = p-1;
    for(j=p; j<r;j++)
        if(a[j] > x)
        {
            i = i+1;
            swap (a[i], a[j]);
        }
    swap (a[i+1], a[r]);
    return i+1;
}

void Quicksort(int a[], int p, int r)
{
    int q;
    if(p<r)
    {
        q=Partition(a,p,r);
        Quicksort(a,p,q-1);
        Quicksort(a,q+1,r);
    }
}

//display function
void display(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << "\t"; 
    }
    cout << endl;
}

int main()
{
    int a[MAX],n;

    input(a,n);
    cout << "mang chua sap xep: ";
    display(a,n);
    heapSort(a,n);

    cout << "mang da dc sap xep bang HEAP: ";
    display(a,n);

    cout << "Mang da dc sap xep bang Quick: ";
    Quicksort(a,0,n-1);
    display(a,n);
}
