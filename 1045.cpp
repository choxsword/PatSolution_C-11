#include<string> 
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;//颜色数 
	int M;//爱好数 
	cin>>N>>M; 
	unordered_map<int,int> rank;
	for(int i=1;i<=M;++i)
	{
		int color;
		cin>>color;
		rank[color]=i;
	}
	int L;
	cin>>L;
	vector<int> st; 
	st.reserve(L);
	for(int i=1;i<=L;++i)
	{
		int color;
		cin>>color;
		st.push_back(color);
	}
	vector<int>result;
	result.reserve(M);
	for(auto&i:st)
	{
		if(rank.find(i)==rank.end())
			continue;
		auto&&it =upper_bound(result.begin(),result.end(),i,[&](const int&lhs,const int&rhs)
		{return rank[lhs]<rank[rhs];});
		if(it!=result.end())
			*it=i;
		else
			result.push_back(i);
	}
	cout<<result.size()<<endl;
	
}
