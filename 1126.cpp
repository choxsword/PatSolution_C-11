#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Vertex
{
	vector<int> edge;
};
vector<Vertex> mmap;
vector<bool> visit;
vector<int> degree;
void dfs_visit(int id);
int cnt_even=0;
int main()
{
	int N;// ¶¥µã 
	int M;//±ß
	cin>>N>>M;
	mmap.resize(N+1);
	visit.resize(N+1,false);
	degree.resize(N+1,0); 
	for(int i=M;i>0;--i) 
	{
		int left,right;
		cin>>left>>right;
		mmap[left].edge.push_back(right);
		mmap[right].edge.push_back(left);
	}
	int cnt_con=0;
	for(int i=1;i<=N;++i)
	{
		if(visit[i]==false)
		{
			dfs_visit(i);
			++cnt_con; 
		}
	}
	//cout<<cnt_even<<endl;
	auto begin=++degree.begin();
	auto end=--degree.end();
	for(auto it=begin;it!=end;++it)
	{
		printf("%d ",*it);
	}
	printf("%d\n",*end);
	if(cnt_con>1)
	{
		printf("Non-Eulerian\n");
		//cout<<cnt_con<<endl;
		return 0;
	}
	
	if(cnt_even==N)
	{
		printf("Eulerian\n");
	}
	else if(cnt_even==N-2)
	{
		printf("Semi-Eulerian\n");
	}
	else
	{
		printf("Non-Eulerian\n");
	}
	
}

void dfs_visit(int id)
{
	visit[id]=true;
	for(auto &i:mmap[id].edge)
	{
		++degree[id];
		if(visit[i]==false)
		{
			dfs_visit(i);
		}
	}
	if(degree[id]%2==0)
	{
		++cnt_even;
		//cout<<cnt_even<<endl;
	}
}



