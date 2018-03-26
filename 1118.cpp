#include<iostream>
#include<unordered_set>
#include<vector>
//#include<utility>
using namespace std;

namespace xzj
{
	int birds[10001];//¸¸½Úµã
	int b_rank[10001];
	int cnt_tree;
	inline void init(int i)
	{
		for(int j=1;j<=i;++j)
		{
			b_rank[j]=0;
			birds[j]=j;
		}
	}
	inline int find(int i) 
	{
		if(i==birds[i])
			return i;
		else
			 birds[i]=find(birds[i]);
		return birds[i];
	}
	inline void join(int a,int b)
	{
		int i=find(a);
		int j=find(b);
		if(i==j)
			return;
		if(b_rank[i]<b_rank[j])
			birds[i]=j;
		else
		{
			birds[j]=i;
			if(b_rank[j]==b_rank[i])
				++b_rank[i];
		}
	
	}
}


int main()
{
	using namespace xzj;
	int N;//ÕÕÆ¬Êý 
	cin>>N;
	unordered_set<int> mset;
	init(1e4);
	
	for(int i=N;i>0;--i)
	{
		int cnt;
		cin>>cnt;
		vector<int> input;
		input.reserve(cnt);
		for(int j=cnt;j>0;--j)
		{
			int id;
			cin>>id;
			mset.insert(id);
			input.push_back(id);
		}
		auto end=input.end()-1;
		for(auto it=input.begin();it!=end;++it)
			join(*it,*(it+1));
	}
	int q;
	//vector<pair<int,int>> query;
	int cnt_bird=mset.size();
	cnt_tree=0;
	for(int i=1;i<=cnt_bird;++i)
	{
		if(i==find(i))
			++cnt_tree;
	}
	printf("%d %d\n",cnt_tree,cnt_bird);
	cin>>q;
	int a,b;
	for(int i=q;i>0;--i)
	{
		cin>>a>>b;
		find(a)==find(b)?printf("Yes\n"):printf("No\n");
		//query.push_back(pair<int,int>(a,b));
	}
	return 0;
}
