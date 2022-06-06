#include <bits/stdc++.h>
using namespace std;

void insertionsort(int[], int);

int main()
{
  int n;
  cout<<"Enter no. of elements in the array: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the array elements: ";
  for(int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  insertionsort(arr, n);
  cout<<"Sorted Array: ";
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}

void insertionsort(int arr[], int n)
{
  int i, j, key;
  for(i = 0; i < n; i++)
  {
    key = arr[i];
    j = i-1;
    while(j >= 0 && arr[j] > key)
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}
