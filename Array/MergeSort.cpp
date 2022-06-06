#include <bits/stdc++.h>
using namespace std;

void mergesort(int[], int, int);
void merge(int[], int, int);

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
  mergesort(arr, 0, n-1);
  cout<<"Sorted Array: ";
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}

void mergesort(int arr[], int low, int high)
{
  if(low < high)
  {
    int mid = (low+high)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, high);
  }
}

void merge(int arr[], int low, int high)
{
  int mid = (low+high)/2;
  int len_left = mid-low+1;
  int len_right = high-mid;
  int arr_left[len_left];
  int arr_right[len_right];
  int i;
  for(i = 0; i < len_left; i++)
  {
    arr_left[i] = arr[low+i];
  }
  for(i = 0; i < len_right; i++)
  {
    arr_right[i] = arr[mid+1+i];
  }
  int *end_left = arr_left + len_left;
  int *end_right = arr_right + len_right;
  int *p1 = arr_left;
  int *p2= arr_right;
  i = low;
  while(p1 != end_left && p2 != end_right)
  {
    if(*p1 <= *p2) arr[i++] = *p1++;
    else arr[i++] = *p2++;
  }
  while(p1 != end_left) 
  {
    arr[i++] = *p1++;
  }
  while(p2 != end_right) 
  {
    arr[i++] = *p2++;
  }
}
