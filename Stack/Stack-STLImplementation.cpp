#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	s.push(8); 
	s.push(4);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.empty()<<endl;
	s.pop();
	cout<<s.empty()<<endl;
	return 0;
}