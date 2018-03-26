#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
namespace xzj
{
	vector<int> node_rank;
	vector<int> node;//父节点 
	vector<int> cloud_size;
	int cnt_cloud;
	int find(int i)
	{
		int result=0;
		if(node[i]!=i)
			result=find(node[i]);
		else
			return i;
	}
	void join(int a,int b)
	{
		int i=find(a);
		int j=find(b);
		if(i==j)
			return;
		--cnt_cloud;
		if(node_rank[i]<node_rank[j]) 
		{
			node[i]=j;
			cloud_size[j]+=cloud_size[i];
		}
		else
		{
			node[j]=i;
			cloud_size[i]+=cloud_size[j];
			if(node_rank[i]==node_rank[j])
				++node_rank[i];
		}
	}
}
int main()
{
	using namespace xzj;
	int K;//总人数
	cin>>K;
	//unordered_set<int> hobby;
	unordered_map<int,vector<int>> cloud;
	node.resize(K+1);
	node_rank.resize(K+1,0);
	cloud_size.resize(K+1,1);
	for(int i=1;i<=K;++i) 
	{
		int cnt;
		char rub;
		cin>>cnt>>rub;
		for(int j=cnt;j>0;--j)
		{
			int hb;
			cin>>hb;
			//hobby.insert(hb);
			cloud[hb].push_back(i);
		}
		node[i]=i;
	}
	cnt_cloud=K;
	//cout<<cloud[3].size()<<endl;
	for(auto&p:cloud)
	{
		//cout<<p.first<<"-------"<<endl;
		vector<int>& mem=p.second;
		int size=mem.size();
		if(size>1)
		{
			//cout<<"shit"<<endl;
			auto end=mem.end()-1;
			for(auto begin=mem.begin();begin!=end;++begin)
			{
				join(*begin,*(begin+1));
				//cout<<*begin<<*(begin+1)<<endl;
			}
		}		
	}
	vector<int> result;
	for(int i=1;i<=K;++i)
	{
		if(i==find(i))
		{
			result.push_back(cloud_size[i] );
		}
	}
	sort(result.begin(),result.end());
	printf("%d\n",cnt_cloud);
	if(result.empty())
		return 0;
	auto rend=result.rend()-1;
	for(auto rbegin=result.rbegin();rbegin!=rend;++rbegin)
	{
		printf("%d ",*rbegin);
	}
	printf("%d",*rend);
}
