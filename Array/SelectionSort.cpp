#include <bits/stdc++.h>
using namespace std;

void selectionsort(int[], int);

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
  selectionsort(arr, n);
  cout<<"Sorted Array: ";
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}

void selectionsort(int arr[], int n)
{
  int i, j, min_idx;
  for(i = 0; i < n-1; i++)
  {
    min_idx = i;
    for(j = i+1; j < n; j++)
    {
      if(arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
  }
}
