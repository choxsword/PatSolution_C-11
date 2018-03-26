#include<iostream>
#include<unordered_map> 
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<limits>
#include<algorithm>
using namespace std;
enum Color{black,white};
struct Vertex
{
	vector<int> edge;
	vector<int> weight;//corresponding to edge
	Color color=white;
	//vector<int> pre;
};
vector<int> dis;
vector<int> rescue; 
unordered_map<int,Vertex> mmap;
vector<int> team;
vector<int> short_path;
auto cmp= [](const int&lhs,const int&rhs)
{
	return dis[lhs]<dis[rhs];
};
 
namespace xzj
{	
	void dj(int start,int size)
	{
		multiset<int,decltype(cmp)> mset(cmp);
		dis[start]=0;
		rescue[start]=team[start];
		short_path[start]=1; 
		for(int i=0;i<size;++i)
			mset.insert(i);
		while(!mset.empty())
		{
			 int min=*mset.begin();
			 mmap[min].color=black;
			 mset.erase(mset.begin());
			 int no_w=0;
			 for(int &e:mmap[min].edge)
			 {
				if(mmap[e].color==black)
				{
					++no_w;continue; 
				} 
			 	int w=dis[min]+mmap[min].weight[no_w];
				if(w<dis[e])
				{
					short_path[e]=short_path[min];
					auto it=find(mset.begin(),mset.end(),e);
					mset.erase(it);
					dis[e]=w;
					rescue[e]=rescue[min]+team[e];
					mset.insert(e);
				}
				else if(w==dis[e])
				{
					short_path[e]+=short_path[min];
					if(rescue[e]<rescue[min]+team[e])
					{
						auto it=find(mset.begin(),mset.end(),e);
						mset.erase(it);
						dis[e]=w;
						mset.insert(e);
						rescue[e]=rescue[min]+team[e];
					}
				}
				++no_w;
			 } 
		}
	}
}

int main()
{
 	using namespace xzj;
    int N;//城市数0-N-1;
	int M;//道路数
	int C1,C2;//当前城市，目标城市
	cin>>N>>M>>C1>>C2;
	dis.resize(N,numeric_limits<int>::max());
	rescue.resize(N,0);
	short_path.resize(N,0);
	for(int i=N;i>0;--i)
	{
		int id;
		cin>>id;
		team.push_back(id);
	}
	
	for(int i=M;i>0;--i)
	{
		int c1,c2,w;
		cin>>c1>>c2>>w;
		mmap[c1].edge.push_back(c2);
		mmap[c2].edge.push_back(c1);
		mmap[c1].weight.push_back(w);
		mmap[c2].weight.push_back(w);
	}

	dj(C1,N);
	int min_dis=dis[C2];
	cout<<short_path[C2]<<' '<<rescue[C2]<<endl; 

	
}
