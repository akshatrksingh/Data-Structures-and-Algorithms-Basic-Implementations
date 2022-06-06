#include <bits/stdc++.h>
using namespace std;

void bubblesort(int[], int);

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
  bubblesort(arr, n);
  cout<<"Sorted Array: ";
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}

void bubblesort(int arr[], int n)
{
  int i, j;
  for(i = 0; i < n-1; i++)
  {
    for(j = 0; j < n-i-1; j++)
    {
      if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
    }
  }
}
