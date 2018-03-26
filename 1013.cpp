#include<iostream>
#include<vector>
using namespace std;

struct Vertex
{
	vector<int> edges;
};
vector<Vertex> mmap;
int repair(int& num);
void dfs(int num,vector<bool>& visit,int);
int main()
{
	int N;// total number of cities
	int M;//the number of remaining highways
	int K;// the number of cities to be checked
	cin>>N>>M>>K;
	mmap.resize(N+1);
	for(int i=M;i>0;--i) 
	{
		int left,right;
		cin>>left>>right;
		mmap[left].edges.push_back(right);
		mmap[right].edges.push_back(left);
	}
	vector<int> check;
	for(int i=K;i>0;--i)
	{
		int num;
		cin>>num;
		check.push_back(num);
	}

	for(auto &i:check)
	{
		//cout<<i<<"wocao";
		int k=repair(i);
		printf("%d\n",k-1);
	}
		
}

int repair(int& num)
{
	int result=0;
	int cnt_v=mmap.size()-1;
	vector<bool> visit(cnt_v,false);
	for(int i=1;i<=cnt_v;++i)
	{
		if(i!=num&&visit[i]==false)
		{
			dfs(i,visit,num);
			++result;
		}	
	}
	return result;
}
void dfs(int num,vector<bool>& visit,int lost)
{
	visit[num]=true;
	//cout<<"-----"<<num<<'\n' ;
	for(auto i:mmap[num].edges) 
	{
		if(i!=lost&&visit[i]==false)
		{
			dfs(i,visit,lost);
		}
	}
}




