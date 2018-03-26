#include<iostream> 
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<limits>
#include<set>
#include<tuple>
using namespace std;
namespace xzj
{
	const double max_i=numeric_limits<int>::max();
	struct Vertex
	{
		vector<pair<string,int>>edge;
		bool visit=false;
		int dis=max_i;
	};
	unordered_map<string,Vertex> graph;
	int N;//住户数 1-N
	int M;//候选数
	int K;//路数
	int DS;//最大范围
	//vector<int> dis;
	//vector<bool> visit; 
	void init()
	{
		//int sum=N+M;
		for(auto&p:graph)
		{
			Vertex&v=p.second;
			v.visit=false;
			v.dis=max_i;
		}
	}
	auto cmp=[](const string&a,const string&b)
	{
		return graph[a].dis<graph[b].dis;
	};
	bool dij(string& start)
	{
		//cout<<start<<endl;
		graph[start].dis=0;
		multiset<string,decltype(cmp)>mset(cmp);
		for(auto&p:graph)
			mset.insert(p.first);
		while(!mset.empty())
		{
			string min=*mset.begin();
			mset.erase(mset.begin());
			Vertex& minv=graph[min];
		//	cout<<min<<"fuck"<<minv.dis<<endl;
			if(minv.dis>DS&&min[0]!='G')
				return false;
			minv.visit=true;
			for(auto&e:minv.edge)
			{
				string&id=e.first;
				int w=e.second;
				Vertex& v=graph[id];
				if(v.visit==false)
				{
					if(v.dis>minv.dis+w)
					{
						auto it=find(mset.begin(),mset.end(),id);
						mset.erase(it);
						v.dis=minv.dis+w;
						mset.insert(id);
						//cout<<id<<' '<<min<<endl;
					}
				}
			}
		}
		return true;
	}
}

int main()
{
	using namespace xzj;
	
	cin>>N>>M>>K>>DS;
	for(int i=0;i<K;++i) 
	{
		string a,b;int w;
		cin>>a>>b>>w;
		graph[a].edge.push_back(make_pair(b,w));
		graph[b].edge.push_back(make_pair(a,w));
	}
	vector<tuple<string,int,int>> result;
	for(int i=1;i<=M;++i)
	{
		init();
		string g="G";
		g+=to_string(i);
		if(dij(g))
		{
			int min=max_i;double sum=0;
			for(auto&p:graph)
			{
				Vertex&v=p.second;
				const string&name=p.first;
				if(v.dis<min&&name[0]!='G')
					min=v.dis;
				if(name[0]!='G')
					sum+=v.dis;
			}
			result.push_back(make_tuple(g,min,sum));
		}
	}
	
	//cout<<graph["1"].pre<<endl;
	
	if(result.empty()) 
	{
		printf("No Solution\n");
		return 0; 
	}

	sort(result.begin(),result.end(),[](const tuple<string,int,int>&lhs,const tuple<string,int,int>&rhs)->bool
	{
		if(get<1>(lhs)==get<1>(rhs))
		{
			if(get<2>(lhs)==get<2>(rhs))
				return get<0>(lhs)>get<0>(rhs);
			else
				return get<2>(lhs)>get<2>(rhs);
		}	
		else
			return get<1>(lhs)<get<1>(rhs);
	});
	auto &&t=result.back();
	string& name=get<0>(t);
	double min=get<1>(t);
	double av=(double)get<2>(t)/N+0.00001;
	printf("%s\n%.1f %.1f\n",name.c_str(),min,av);
	 
}
