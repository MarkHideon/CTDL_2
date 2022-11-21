#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
  
// Function to sort arr[] of 
// size n using bucket sort
void bucketSort(float arr[], int n)
{
      
    // 1) Create n empty buckets
    vector<float> b[n];
  
    // 2) Put array elements 
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }
  
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
  
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

void reverse(int arr[], int n)  
{  
    reverse(arr, arr + n);   
}  

void display(int arr[], int n)
{
        for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

/* Driver program to test above function */
int main()
{
    float arr[]= { 0.72,0.84,0.2,0.95,0.25,0.91,0.33,0.44,0.65,0.52,0.32,0.56,0.18,0.67,0.83 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    
    display(arr,n);
    // cout << "Sorted array is \n";
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    
    reverse(arr,n);
    return 0;
}