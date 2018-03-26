#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<limits>
using namespace std;

namespace xzj
{
	struct Vertex
	{
		vector<pair<string,int>>edges;
		int happy;
		bool visit=false;
	};
	
	int min_int=numeric_limits<int>::min();
	int max_int=numeric_limits<int>::max();
	unordered_map<string,Vertex> graph;
	string des="ROM";
	vector<string> path;
	vector<string> temp_p;
	int min_cost,max_h,av_h;
	int cnt_min_cost;
	void init()
	{
		cnt_min_cost=0;
		min_cost=max_int;
		max_h=min_int;
	}
	
	void dfs(string start,int cost,int happy)
	{
		temp_p.push_back(start);
		//cout<<start<<min_cost<<endl;
		if(start==des)
		{
			//cout<<start<<cost<<endl;
			if(min_cost>cost)
			{
				path=temp_p;
				cnt_min_cost=1;
				max_h=happy;
				min_cost=cost; 
			}	
				
			else if(min_cost==cost)
			{
				if(max_h<happy) 
				{
					max_h=happy;
				 	min_cost=cost; 
				 	path=temp_p;
				}	
				else if(max_h==happy) 
				{
					if(path.size()>temp_p.size()) 
					{
						max_h=happy;
					 	min_cost=cost; 
					 	path=temp_p;
					}	
				} 
				++cnt_min_cost;
			} 
			temp_p.pop_back();
			return;
		}
		graph[start].visit=true;
		
		for(auto&p:graph[start].edges)
		{
			if(graph[p.first].visit==false)
			{
				dfs(p.first,p.second+cost,happy+graph[p.first].happy);
				//cout<<p.second<<endl; 
			}		
		}
			
			
		graph[start].visit=false;
		temp_p.pop_back();
		return;
	}
	
	void print()
	{
		av_h=max_h/(path.size()-1);
		printf("%d %d %d %d\n",cnt_min_cost,min_cost,max_h,av_h);
		
		auto&&end=path.end()-1;
		for(auto it=path.begin();it!=end;++it)
			printf("%s->",(*it).c_str());
		printf("%s\n",(*end).c_str());
	}
	
}
int main()
{
	using namespace xzj;
	int N;//城市数
	int K;//路线数
	string  start;
	cin>>N>>K>>start;
	for(int i=N-1;i>0;--i)
	{
		string name;
		int h;
		cin>>name>>h;
		graph[name].happy=h;
	}
	for(int i=K;i>0;--i)
	{
		string a,b;
		int w;
		cin>>a>>b>>w;
		graph[a].edges.push_back(make_pair(b,w));
		graph[b].edges.push_back(make_pair(a,w));
	}
	init();
	dfs(start,0,0);
	print();
	
}
