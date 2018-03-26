#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;//¸öÊý
	cin>>N;
	vector<int>input;
	input.reserve(N);
	for(int i=N;i>0;--i) 
	{
		int num;
		cin>>num;
		input.push_back(num);
	}
	for(auto&i:input)
		cout<<i<<' ';
	cout<<endl;
	
	sort(input.begin(),input.end());
	for(auto&i:input)
		cout<<i<<' ';
	cout<<endl;
	 
}
