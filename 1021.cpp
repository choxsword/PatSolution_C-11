#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct Vertex
{
	vector<int> edges;
	int height=0;
};
enum Color{white,gray,black};
vector<Vertex> mmap;
vector<Color> visit;
int dfs_visit(int v,int);
int cycle_num=0;
int main()
{
	int N;//the number of nodes, and hence the nodes are numbered from 1 to N
	cin>>N;
	mmap.resize(N+1);
	visit.resize(N+1,white);
	vector<int> result;
	result.resize(N,0);
	for(int i=N-1;i>0;--i)
	{
		int left,right;
		cin>>left>>right;
		mmap[left].edges.push_back(right);
		mmap[right].edges.push_back(left);
	}
	int max_height=0;
	for(int i=1;i<=N;++i)
	{
		fill(visit.begin(),visit.end(),white);
		int height=dfs_visit(i,0);
		//cout<<"shit"<<endl;
		result[i-1]=height;
		//cout<<height<<endl;
		max_height=max(max_height,height);
	}
	int connect=0;
	if(cycle_num!=0)
	{
		fill(visit.begin(),visit.end(),white);
		for(int i=1;i<=N;++i)
		{
			if(visit[i]==white)
			{
				dfs_visit(i,0);
				++connect;
			}
		}
		printf("Error: %d components",connect);
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		if(result[i]==max_height)
		{
			printf("%d\n",i+1);
		}
	}
}


int dfs_visit(int v,int father)
{
	visit[v]=gray;
	if(mmap[v].edges.empty())
	{
		mmap[v].height=0;
	}
	else
	{
		int height=0;
		for(auto i:mmap[v].edges)
		{
			//cout<<i<<endl;
			Color color=visit[i];
			if(i!=father&&color==gray)
			{
				++cycle_num;
			}
			else if(color==white)
			{
				height=max(dfs_visit(i,v),height);
			}	
		}
		mmap[v].height=height+1;
	}
	visit[v]=black;
	return mmap[v].height;
}


