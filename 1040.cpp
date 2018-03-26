#include<string>
#include<iostream>
#include<vector>
using namespace std;
string input;
inline int get(int i)
{
	int k=1;
	int value=input[i];
	for(int j=i-1;j>=0;--j)
	{
		if(input[j]==value)
			++k;
		else
			break;
	}
	return k;
}
int main() 
{

	getline(cin,input);
	vector<int> cnt;
	int N=input.size(); 
	cnt.resize(N,0);
	cnt[0]=1;
	if(N<2)
	{
		cout<<1<<endl;
		return 0;
	}
	input[1]==input[0]?cnt[1]=2:cnt[1]=1;
	for(int i=2;i<N;++i)
	{
		if(input[i-1-cnt[i-1]]==input[i])
			cnt[i]=cnt[i-1]+2;
		else 
			cnt[i]=get(i);
	}
	int max=-1;
	for(int i=0;i<N;++i)
		if(cnt[i]>max)
			max=cnt[i];
	cout<<max<<endl;
}
