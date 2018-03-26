#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>
#include<limits>
#include<list>
using namespace std;

int main()
{
	int N;//银币数
	int M;//钱总数
	cin>>N>>M;
	vector<int> coin;
	coin.reserve(N+1);
	coin.push_back(0);
	for(int i=N;i>0;--i)
	{
		int v;
		cin>>v;
		coin.push_back(v);
	}
	sort(coin.begin()+1,coin.end());
	int total=accumulate(coin.begin(),coin.end(),0);
	vector<vector<int>> result;
	const int inf=numeric_limits<int>::max();
	const vector<int> INF=vector<int>(1,inf); 
	result.resize(M+1,INF);
	const vector<int> ZERO=vector<int>(1);
	result[0]=ZERO;
	for(int i=N;i>=1;--i)
	{
		int low=max(coin[i],M-total); 
		for(int j=M;j>=low;--j)
		{
			vector<int> a;
			if(result[j-coin[i]]!=INF)
			{
				a.push_back(coin[i]);
				if(result[j-coin[i]]!=ZERO)
					a.insert(a.end(),result[j-coin[i]].begin(),result[j-coin[i]].end());
			}
			else 
				a=INF;
			auto&& b=result[j];
			result[j]=min(a,b);
		}
		total-=coin[i];
	}

	if(result[M]==INF)
		printf("No Solution\n");
	else
	{
		vector<int> ans=result[M];
		if(ans.empty())
			throw 1;///To prove it's not empty
		auto&&end=prev(ans.end());///////////////here I use the auto&& 
		for(auto it=ans.begin();it!=end;++it)
			cout<<*it<<' ';
		cout<<*end<<endl;
	}

	
}
