#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int main()
{
	int N;//¸öÊý
	cin>>N;
	deque<double> rope;
	for(int i=N;i>0;--i)
	{
		double l;
		cin>>l;
		rope.push_back(l);
	}
	sort(rope.begin(),rope.end());
	while(rope.size()>1)
	{
		double a,b;
		a=rope.front();
		rope.pop_front();
		b=rope.front();
		rope.pop_front();
		double sum=(a+b)/2;
		auto it=upper_bound(rope.begin(),rope.end(),sum);
		rope.insert(it,sum);
	}
	int k=rope.front();
	cout<<k<<endl; 
}
