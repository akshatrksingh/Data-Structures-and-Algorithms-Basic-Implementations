#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v = {40, 30, 20, 50, 15};
	for( int i = 0; i < v.size() ; i++)
        cout<<v[i]<<"  ";
    cout<<endl;
	is_heap(v.begin(), v.end())? cout << "It is a heap\n": cout << "It is not a heap\n";
	cout<<"Front element: "<<v.front()<<"\n\n"; 
	
	auto it = is_heap_until(v.begin(), v.end());
    for (auto it1=v.begin(); it1!=it; it1++)
       cout<<*it1<<"  ";
    cout<<endl;
	cout<<"Front element: "<<v.front()<<"\n\n"; 

	make_heap(v.begin(), v.end()); // max heap
	for( int i = 0; i < v.size() ; i++)
        cout<<v[i]<<"  ";
    cout<<endl;
    is_heap(v.begin(), v.end())? cout << "It is a heap\n": cout << "It is not a heap\n";
	cout<<"Front element: "<<v.front()<<"\n\n";; // max element
	
	pop_heap(v.begin(), v.end()); //moves the largest to the end
	v.pop_back(); // removes the largest element
    for( int i = 0; i < v.size() ; i++)
        cout<<v[i]<<"  ";
    cout<<endl;
    is_heap(v.begin(), v.end())? cout << "It is a heap\n": cout << "It is not a heap\n";
    cout<<"Front element: "<<v.front()<<"\n\n";;

    v.push_back(27);
    make_heap(v.begin(), v.end());
    for( int i = 0; i < v.size() ; i++)
        cout<<v[i]<<"  ";
    cout<<endl;
    is_heap(v.begin(), v.end())? cout << "It is a heap\n": cout << "It is not a heap\n";
    cout<<"Front element: "<<v.front()<<"\n\n";;

	sort_heap(v.begin(),v.end());
    for( int i = 0; i < v.size() ; i++)
        cout<<v[i]<<"  ";
    cout<<endl;
    is_heap(v.begin(), v.end())? cout << "It is a heap\n": cout << "It is not a heap\n";
    cout<<"Front element: "<<v.front()<<"\n\n";;
	
	return 0;
}