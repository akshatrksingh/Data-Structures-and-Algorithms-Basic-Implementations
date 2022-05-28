#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack
{
private:
	vector<T> v;
public:
	void push(T num)
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
	T top()
	{
		return v[v.size()-1];
	}
};

int main()
{
	Stack<char> s;
	s.push(65); // 65 is the ASCII value of 'A'
	s.push('c');
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.empty()<<endl;
	s.pop();
	cout<<s.empty()<<endl;
	return 0;
}