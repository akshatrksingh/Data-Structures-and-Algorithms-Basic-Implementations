#include <iostream>
#include <vector>
using namespace std;


class Heap
{
private:
	bool maxHeap;
	bool compare(int a, int b)
	{
	    if(maxHeap)
	    {
	        return a > b;
	    }
	    else
	    {
	        return a < b;
	    }
	}
public:
	void display(int arr[], int n)
	{
    	cout << "Array representation of Heap is: ";
	    for (int i = 0; i < n; ++i)
	    {
	        cout << arr[i] << " ";
	    }
	    cout << "\n";
	}
	void heapify(int arr[], int n, int root)
	{
	    int largest = root; 
	    int left = 2 * root + 1; 
	    int right = 2 * root + 2; 
	    if (left < n && compare(arr[left], arr[largest])) 
	    {
	        largest = left;
	    }
	    if (right < n && compare(arr[right], arr[largest])) 
	    {
	        largest = right;
	    }
	    if (largest != root) 
	    {
	        swap(arr[root], arr[largest]);
	        heapify(arr, n, largest); 
	    }
	}
	void buildHeap(int arr[], int n)
	{
	    int startIdx = (n / 2) - 1;  // Index of last non-leaf node
	    for (int i = startIdx; i >= 0; i--) 
	    {
	        heapify(arr, n, i);
	    }
	}
};

int main()
{
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Heap h;
    h.buildHeap(arr, n);
    h.display(arr, n);
    return 0;
}
