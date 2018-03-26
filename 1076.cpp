#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct User
{
	vector<int> follower;
};
vector<User> mmap;
vector<int> level;
int main()
{

	int N;//用户数
	int L;//间接用户的层数 
	cin>>N>>L;
	mmap.resize(N+1);
	level.resize(N+1,0);
	for(int i=1;i<=N;++i)
	{
		int follow;
		cin>>follow;
		for(int j=follow;j>0;--j)
		{
			int id;
			cin>>id;
			mmap[id].follower.push_back(i);
		}	
	}
	
	int cnt_query;
	cin>>cnt_query;
	vector<int> query;
	for(int i=cnt_query;i>0;--i)
	{
		int id;
		cin>>id;
		query.push_back(id);
	}
//	for(auto& it:mmap)
//	{
//		for(auto & i:it.follower)
//		{
//			cout<<i;
//		}
//		cout<<endl;
//	}
	vector<bool> forward(N+1,false); 
	
	for(auto &id:query)
	{
		//cout<<id<<"___"<<endl;
		fill(level.begin(),level.end(),0);
		fill(forward.begin(),forward.end(),false);
		queue<int> que;
		que.push(id);
		forward[id]=true;
		int cnt_view=0;
		while(!que.empty())
		{
			int id=que.front();
			//cout<<id<<endl;
			++cnt_view;
			que.pop();
			if(level[id]<L)
			{
				auto&vec=mmap[id].follower;
				if(!vec.empty())
				{
					for(auto&nb:vec)
					{
						if(forward[nb]==false)
						{
							que.push(nb);
							forward[nb]=true;
							level[nb]=level[id]+1;
						}
						
					}	
				}
			}
		}
		printf("%d\n",cnt_view-1);
		
	}
	
	
}
