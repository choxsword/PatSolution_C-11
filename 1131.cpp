#include<iostream> 
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<limits>
#include<unordered_set>
#include<set>
using namespace std;

namespace xzj
{
	struct Vertex
	{
		vector<int> line;
		vector<int> edges;
		bool visit=false;
		int dis=numeric_limits<int>::max();
		vector<int> pre;
		bool is_cross=false;
		unordered_map<int,int> get_line;
	};
	int cnt_v=0;
	unordered_map<int,Vertex> mmap;
	unordered_map<int,int> dis;
	vector<int> path;
	vector<int> cur_path;
	int min_size=numeric_limits<int>::max();
	int cur_size;
	int dfs_start,dfs_des,min_dis;
	int get_line(int id,int next)
	{
		return mmap[id].get_line[next];
	}	
	int transfer(vector<int>& path1) 
	{
		int cnt=0;
		int size=path1.size();
		int pre=-1;
		int cur_line;
		for(int i=0;i<size-1;++i)
		{
			cur_line=get_line(path1[i],path1[i+1]);
			if(cur_line!=pre&&pre!=-1)
				++cnt;
			pre=cur_line;
		}
		return cnt;
	}
	void new_dfs(int cur,int dis)
	{
		cur_path.push_back(cur);
		if(cur==dfs_des)
		{
			if(min_dis>dis) 
			{
				min_dis=dis;
				min_size=transfer(cur_path);
				path=cur_path; 
			}
			else if(min_dis==dis)
			{
				if(min_size>transfer(cur_path))
				{
					min_size=transfer(cur_path);
					path=cur_path; 
				}
			}
			cur_path.pop_back();
			return;
		}
		mmap[cur].visit=true;
		for(auto&i:mmap[cur].edges)
		{
			if(mmap[i].visit==false) 
				new_dfs(i,dis+1);
		}
		cur_path.pop_back();
		mmap[cur].visit=false; 
		return;
	}
	void print()
	{
		printf("%d\n",path.size()-1);
		int start,end;
		int cur_line;
		vector<int> id_line;
		int size=path.size(); 
		id_line.resize(size);
		vector<int> path1;
		path1.reserve(size);
		for(auto it=path.rbegin();it!=path.rend();++it)
			path1.push_back(*it);
		for(int i=0;i<size;++i)
		{
			if((i+1)!=size)
				id_line[i]=get_line(path1[i],path1[i+1]);
			else
				id_line[i]=get_line(path1[i],path1[i-1]);
		}
		cur_line=id_line[0];
		start=path1[0];
		for(int i=1;i<size;++i) 
		{
			if(id_line[i]!=cur_line)
			{
				printf("Take Line#%d from %04d to %04d.\n",cur_line,start,path1[i]);
				start=path1[i];
				cur_line=id_line[i]; 
			}
		}
		printf("Take Line#%d from %04d to %04d.\n",cur_line,start,path1[size-1]); 
	}
	void init()
	{
		path.clear();
		cur_path.clear();
		min_size=numeric_limits<int>::max();
		min_dis=numeric_limits<int>::max();
		cur_size=0;
		for(auto&p:mmap)
		{
			auto&& v=p.second;
			v.dis=numeric_limits<int>::max();
			v.visit=false;
			v.pre.clear();
		} 
	}
}

int main()
{
	using namespace xzj;
	int N;//ÏßÂ·Êý  1-N
	cin>>N;
	for(int i=1;i<=N;++i)
	{
		int M;
		cin>>M;
		cnt_v+=M;
		vector<int> stops;
		stops.reserve(M);
		for(int j=M;j>0;--j)
		{
			int id;
			cin>>id;
			stops.push_back(id);
			if(mmap.find(id)!=mmap.end())
				mmap[id].is_cross=true;
			mmap[id].line.push_back(i);
		}
		auto &&begin=stops.begin();
		auto&&end= stops.end();
		int pre=-1;
		for(auto it=begin;it!=end;++it)
		{
			int id=*it;
			if(pre!=-1)
			{
				mmap[id].edges.push_back(pre);
				mmap[pre].edges.push_back(id);
				//lines[pair<int,int>{id,pre}]=i;
				mmap[id].get_line[pre]=i;
				mmap[pre].get_line[id]=i;
			}
			pre=id;
		}
	}
	int K;
	cin>>K;
	vector<pair<int,int>> query;
	for(int i=K;i>0;--i)
	{
		cin>>dfs_des>>dfs_start;
		init();
		new_dfs(dfs_start,0);
		print();
	}
}
