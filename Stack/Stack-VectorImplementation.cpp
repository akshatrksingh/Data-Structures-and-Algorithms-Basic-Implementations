#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
	vector<int> v;
public:
	void push(int num)
	{
		v.push_back(num);
	}
	bool empty()
	{
		return v.size()==0;
	}
	void pop()
	{
		if(!empty())
			v.pop_back();
	}
	int top()
	{
		return v[v.size()-1];
	}
};

int main()
{
	Stack s;
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