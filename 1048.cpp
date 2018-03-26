#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	int M;
	cin>>N>>M;
	int a[1000]={0};
	vector<int> money;
	money.resize(N,0);
	for(int i=0;i<N;++i)
	{
		int value;
		cin>>value;
		++a[value];
		money[i]=value;
	}
	vector<pair<int,int>>result;
	for(auto&i:money)
	{
		if(a[M-i]!=0)
		{
			if(i==M-i)
			{
				if(a[i]==1)
					continue;
			}
			pair<int,int> p={min(i,M-i),max(i,M-i)};
			result.push_back(move(p));
		}
	}
	sort(result.begin(),result.end(),[](pair<int,int>&lhs,pair<int,int>&rhs){return lhs.first<rhs.first;});
	if(result.empty())
	{
		printf("No Solution\n");
	}
	else
		printf("%d %d\n",result[0].first,result[0].second);
		
}
