#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<limits>
using namespace std;
struct Vertex
{
	vector<pair<int,int>> edges;
	int bike;
	int pre;
};
vector<Vertex> graph;
vector<bool> visit;
vector<int> dis;
vector<int>gather;
int Cmax;//偶数，最大容量 
int N;//站数
int Sp;//问题站号
int M;//道路数
int half;
int take;
namespace xzj
{
	auto cmp=[](int i,int j){return dis[i]<dis[j];};	
	void print(int des)
	{
		vector<int> result;
		int pre=graph[des].pre;
		result.push_back(des);
		while(pre!=0)
		{
			result.push_back(pre);
			pre=graph[pre].pre;
		}
		result.push_back(0);
		auto rend=result.rend()-1;
		for(auto it=result.rbegin();it!=rend;++it)
		{
			printf("%d->",*it);
		}
		printf("%d ",*rend);
	}
	void dfs();
	void dj(int start,int des)
	{
		multiset<int,decltype(cmp)> mset(cmp);
		dis[0]=0;
		graph[0].bike=0;
		for(int i=0;i<=N;++i) 
			mset.insert(i);
		while(!mset.empty())
		{
			int mini=*mset.begin();
			visit[mini]=true;
			//cout<<mini<<endl; 
			mset.erase(mset.begin());
			for(auto&p:graph[mini].edges)
			{
				int e=p.first;
				int w=p.second;
				if(dis[e]>dis[mini]+w)
				{
					auto&&it=find(mset.begin(),mset.end(),e);
					mset.erase(it);
					dis[e]=dis[mini]+w;
					graph[e].pre=mini; 
					mset.insert(e);
					gather[e]=gather[mini]+max(graph[mini].bike-half,0);
				}
				else if(dis[e]==dis[mini]+w)
				{
					//cout<<e<<"mmp"<<endl;
					if(graph[graph[e].pre].bike<graph[mini].bike)
					{
						graph[e].pre=mini; 
						gather[e]=gather[mini]+max(graph[mini].bike-half,0);
					}
				}
			}
		}
	}
}

int main()
{
	using namespace xzj;
	cin>>Cmax>>N>>Sp>>M;
	graph.resize(N+1);
	visit.resize(N+1,false);
	gather.resize(N+1,0);
	dis.resize(N+1,numeric_limits<int>::max());
	half=Cmax/2;
	for(int i=1;i<=N;++i)
	{
		int cnt;
		cin>>cnt;
		graph[i].bike=cnt;
	}
	for(int i=0;i<M;++i)
	{
		int left,right,cnt;
		cin>>left>>right>>cnt;
		graph[left].edges.push_back({right,cnt});
		graph[right].edges.push_back({left,cnt});
	}	
	dj(0,Sp);
	take=(half-gather[Sp])>0?half-gather[Sp]:0;
	printf("%d ",take);
	print(Sp);
	int rest=take+gather[Sp]-half;
	printf("%d\n",rest);
}
