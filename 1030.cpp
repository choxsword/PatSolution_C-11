#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<tuple>
#include<set>
using namespace std;

namespace xzj
{
	int N;//城市数
	int M;//路数
	int S;//起点
	int D;//终点
	int max_i=numeric_limits<int>::max();
	int min_i=numeric_limits<int>::min();
	struct Vertex
	{
		vector<tuple<int,int,int>> edge;	
	};
	vector<Vertex> graph;
	vector<int>dis;
	vector<int>cost;
	vector<bool>visit;
	vector<int>pre;
	auto cmp=[](const int&lhs,const int&rhs)
	{
		return dis[lhs]<dis[rhs];
	};
	
	void dij(int start)
	{
		multiset<int,decltype(cmp)>mset(cmp);
		dis[start]=0;
		cost[start]=0;
		pre[start]=start;
		for(int i=0;i<N;++i)
			mset.insert(i);
		
		while(!mset.empty())
		{
			int min=*mset.begin();
			visit[min]=true;
			mset.erase(mset.begin());
			for(auto&t:graph[min].edge)
			{
				int id=get<0>(t);
				if(visit[id]==true)
					continue;
				int len=get<1>(t);
				int cos=get<2>(t);
				if(dis[id]>dis[min]+len)
				{
					auto it=find(mset.begin(),mset.end(),id);
					mset.erase(it);
					dis[id]=dis[min]+len;
					mset.insert(id);
					pre[id]=min;
					cost[id]=cost[min]+cos;
				}
				else if(dis[id]==dis[min]+len)
				{
					if(cost[id]>cost[min]+cos) 
					{
						pre[id]=min;
						cost[id]=cost[min]+cos;
					}
				} 
			}
		}
	}
	
	void print(int des)
	{
		int ori=des;
		vector<int>res;
		while(pre[des]!=des)
		{
			res.push_back(des);
			des=pre[des];
		}
		res.push_back(des);
		auto rend=res.rend()-1;
		for(auto it=res.rbegin();it!=rend;++it)
			printf("%d ",*it);
		printf("%d %d %d",*rend,dis[ori],cost[ori]);
	}
}

int main()
{
	using namespace xzj;

	cin>>N>>M>>S>>D;
	graph.resize(N);
	dis.resize(N,max_i);
	cost.resize(N,max_i);
	visit.resize(N,false);
	pre.resize(N,0);
	for(int i=M;i>0;--i)
	{
		int c1,c2,dis,cost;
		cin>>c1>>c2>>dis>>cost;
		graph[c1].edge.push_back(make_tuple(c2,dis,cost));
		graph[c2].edge.push_back(make_tuple(c1,dis,cost));
	}
	dij(S);
	print(D) ;
}
