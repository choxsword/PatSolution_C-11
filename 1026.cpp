#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<unordered_set>
#include<deque>
using namespace std;

struct P
{
	string arrive;
	int m;
	int vip;
	P(string&_arrive,int _m,int _vip)	
	{
		arrive=_arrive;
		m=_m;
		vip=_vip;
	}
	P()=default;
};

struct Table
{
	string end;
	int id;
	Table()=default;
	Table(int _id,const string&_end)
	{
		id=_id;
		end=_end;
	}
};
deque<P> pq; 
int main()
{
	int N;//玩家总对数
	 int K;//桌子书
	 int M;//VIP桌子数
	 cin>>N;
	 for(int i=1;i<=N;++i) 
	 {
	 	string arrive;
	 	int m;
	 	int vip;
	 	cin>>arrive>>m>>vip;
	 	pq.emplace_back(arrive,m,vip);
	 }
	 sort(pq.begin(),pq.end(),[](const P&lhs,const P&rhs)
	 {
	 	return lhs.arrive<rhs.arrive;
	 });
	 cin>>K>>M;
	string T="08:00:00";
	 auto cmp=[](const Table&lhs,const Table&rhs) 
	 {
	 	if(lhs.end==rhs.end)
	 		return lhs.id<rhs.id;
	 	else
	 		return lhs.end<rhs.end;
	 };
	 set<Table,decltype(cmp)> vs(cmp);
	 unordered_set<int> vip_id;
	 for(int i=0;i<M;++i)
	 {
	 	int id;
	 	cin>>id;
	 	vs.insert(Table(id,T));
	 	vip_id.insert(id);
	 }
	 set<Table,decltype(cmp)> ms(cmp);
	 queue<P> vq;
	 queue<P> mq;
	 for(int i=1;i<=N;++i)
	 {
	 	auto it=vip_id.find(i);
		 if(it==vip_id.end())
	 		ms.insert(Table(i,T));
	 }
	while(T!="21:00:00") 
	{
		string mst=(ms.begin())->end;
		string vst=(vs.begin())->end;
		string next="";
		if(!pq.empty())
		{
			next=pq.front().arrive;
		}
		
		vector<string> next_clock;
		if(mst>T)
			next_clock.push_back(mst);
		if(mst>T)
			next_clock.push_back(mst);
		if(!pq.empty()) 
			next_clock.push_back(next);
		auto it=min_element(next_clock.begin(),next_clock.end());
		T=*it;
		if(T==next)
		{
			
			
		}
		
		
	}
	
}
