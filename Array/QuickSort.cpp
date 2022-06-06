#include <bits/stdc++.h>
using namespace std;

void quicksort(int[], int, int);
int partition(int[], int, int);

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
  quicksort(arr, 0, n-1);
  cout<<"Sorted Array: ";
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}

void quicksort(int arr[], int low, int high)
{
  if(low < high)
  {
    int j = partition(arr, low, high);
    quicksort(arr, low, j-1);
    quicksort(arr, j+1, high);
  }
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = low, j = high+1;
  while(i < j)
  {
    do
    {
      i++;
    } while(arr[i] <= pivot);
    do
    {
      j--;
    } while(arr[j] > pivot);
    if(i < j)
    {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[low], arr[j]);
  return j;
}
