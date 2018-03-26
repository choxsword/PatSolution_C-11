#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<tuple> 
#include<limits> 
#include<unordered_map>
using namespace std;
namespace xzj
{
	struct Vertex
	{
		unordered_map<int,pair<int,int>> edges;
	};
	int N;//节点数 0-N-1
	int M;//路数
	vector<int> dis;
	vector<int> tim;
	vector<bool> visit;
	vector<Vertex> graph;
	vector<vector<int>> pre;
	vector<vector<int>> pre1;
	vector<int> path;
	vector<int> path1;
	vector<vector<int>>result;
	vector<int>result1; 
	int min_time=numeric_limits<int>::max();int cur_time=0;
	int min_size=numeric_limits<int>::max();int cur_size=0;
	//functions 
	void init()
	{
		graph.resize(N);
		dis.resize(N,numeric_limits<int>::max());
		visit.resize(N,false);
		pre.resize(N);
	}
	void init1() 
	{
		tim.resize(N,numeric_limits<int>::max());
		fill(visit.begin(),visit.end(),false);
		pre1.resize(N);
	}
	auto cmp=[&](int a,int b){return dis[a]<dis[b];};
	void dij(int start,int des) 
	{
		multiset<int,decltype(cmp)> mset(cmp);
		dis[start]=0;
		for(int i=0;i<N;++i)
			mset.insert(i);
		while(!mset.empty())
		{
			int min=*mset.begin();
			mset.erase(mset.begin());
			visit[min]=true;
			for(auto&p:graph[min].edges) 
			{
				int id=p.first;
				int len=p.second.first;
				if(dis[id]>dis[min]+len)
				{
					auto&&it=find(mset.begin(),mset.end(),id);
					mset.erase(it);
					dis[id]=dis[min]+len;
					mset.insert(id);
					pre[id].clear();
					pre[id].push_back(min);
				}
				else if(dis[id]==dis[min]+len)
				{
					pre[id].push_back(min); 
				}
			}
		}
	}
	auto cmp1=[&](int a,int b){return tim[a]<tim[b];};
	void dij1(int start,int des) 
	{
		init1();
		multiset<int,decltype(cmp1)> mset(cmp1);
		tim[start]=0;
		for(int i=0;i<N;++i)
			mset.insert(i);
		while(!mset.empty())
		{
			int min=*mset.begin();
			mset.erase(mset.begin());
			visit[min]=true;
			for(auto&p:graph[min].edges) 
			{
				int id=p.first;
				int len=p.second.second;
				if(tim[id]>tim[min]+len)
				{
					auto&&it=find(mset.begin(),mset.end(),id);
					mset.erase(it);
					tim[id]=tim[min]+len;
					mset.insert(id);
					pre1[id].clear();
					pre1[id].push_back(min);
				}
				else if(tim[id]==tim[min]+len)
				{
					pre1[id].push_back(min); 
				}
			}
		}
	}
	void dfs_visit(int start,int des) 
	{
		path.push_back(start);
		if(start==des)
		{
			min_time=min(min_time,cur_time);
			if(min_time==cur_time)			
			{
				result.push_back(path);
			}
			path.pop_back();
			return;
		}
		for(auto&i:pre[start])
		{
			int t=graph[i].edges[start].second;
			cur_time+=t;
			dfs_visit(i,des);
			cur_time-=t;
		}
		path.pop_back();
	}
	void dfs_visit1(int start,int des) 
	{
		path1.push_back(start);
		if(start==des)
		{
			int p_size=path1.size();
			min_size=::min(min_size,p_size);
			if(min_size==path1.size())			
			{
				result1=path1;
			}
			path1.pop_back();
			return;
		}
		for(auto&i:pre1[start])
		{
			dfs_visit1(i,des);
		}
		path1.pop_back();
	}
}
int main()
{
	using namespace xzj;
	cin>>N>>M;
	init();
	for(int i=M;i>0;--i)
	{
		int v1,v2,is_one,len,t;
		cin>>v1>>v2>>is_one>>len>>t;
		graph[v1].edges[v2]={len,t};
		if(is_one==0)
			graph[v2].edges[v1]={len,t};
	}
	int start,des;
	cin>>start>>des;
	dij(start,des);
	vector<int> res;
	dfs_visit(des,start);
	auto&& it=max_element(result.begin(),result.end(),[](vector<int>&lhs,vector<int>&rhs)
		{return lhs.size()<rhs.size();});
	res=*it;
	dij1(start,des);
	dfs_visit1(des,start);
	bool is_same=equal(res.begin(),res.end(),result1.begin());
	if(is_same)
	{
		printf("Distance = %d; Time = %d: ",dis[des],min_time);
		auto&&end=res.rend()-1;
		for(auto i=res.rbegin();i!=end;++i)
		{
			printf("%d -> ",*i);
		}
		printf("%d\n",*end);
	}
	else
	{
		printf("Distance = %d: ",dis[des]);
		auto&&end=res.rend()-1;
		for(auto i=res.rbegin();i!=end;++i)
		{
			printf("%d -> ",*i);
		}
		printf("%d\n",*end);
		auto&&end1=result1.rend()-1;
		printf("Time = %d: ",tim[des]);
		for(auto i=result1.rbegin();i!=end1;++i)
		{
			printf("%d -> ",*i);
		}
		printf("%d\n",*end1);	
	}
}
