#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<string> input;
	for(int i=N;i>0;--i)
	{
		string a;
		cin>>a;
		input.push_back(move(a));
	}
	sort(input.begin(),input.end());
	
	for(auto&i:input)
		cout<<i;
	
}
