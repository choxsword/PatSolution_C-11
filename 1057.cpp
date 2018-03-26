#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<list> 
#include<set>
using namespace std;

namespace xzj1
{
	stack<int> ms;
	multiset<int> ls;
	multiset<int> rs; 
	int L=0;int R=0;
	int mid=0;
	int size=0;
	inline void insert(int v) 
	{
		ms.push(v);
		if(R-L==1)//L
		{
			if(v<=mid)
				ls.insert(v);
			else
			{
				ls.insert(mid);
				rs.insert(v);
				auto it=rs.begin();
				mid=*it;
				rs.erase(it);
			}
		}
		else if(size==0)
		{
			mid=v;	
			++size;
			return; 
		}
		else 
		{
			if(v>=mid)
				rs.insert(v);
			else
			{
				rs.insert(mid);
				ls.insert(v);
				auto it=--ls.end(); 
				mid=*(it);
				ls.erase(it); 
			}
		}
		R-L==1?++L:++R;
		++size;
	}

	inline int pop()
	{
		int res=ms.top();
		ms.pop();
		//cout<<"shig"<<L<<' '<<R<<endl;
		
		if(size==1) 
		{
			--size;
			return mid;
		}
		
		if(res==mid)
		{
			if(R-L==1)
			{
				auto it=rs.begin();
				mid=*it;
				rs.erase(it);
			}
			else
			{
				auto it=--ls.end();
				mid=*it;
				ls.erase(it); 
			} 
		}
		else if(R-L==1)
		{
			if(res>mid)
			{
				auto&&it=rs.find(res);
				rs.erase(it);
			}
			else
			{
				auto&&it=ls.find(res);
				ls.erase(it);
				ls.insert(mid);
				auto it1=rs.begin();
				mid=*it1; 
				rs.erase(it1);
			}
		}
		else
		{
			if(res<mid)
			{
				auto&&it=ls.find(res);
				ls.erase(it);
			}
			else
			{
				auto&&it=rs.find(res);
				rs.erase(it);
				rs.insert(mid);
				auto it1=--ls.end();
				mid=*it1;
				ls.erase(it1); 
			}
		} 
		R-L==1?--R:--L;
		--size;
		return res;
	}
}

int main()
{
	using namespace xzj1;
	int N;//Ö¸ÁîÊé
	cin>>N;
	for(int i=N;i>0;--i) 
	{
		string cmd;
		cin>>cmd;
		if(cmd=="Pop")
		{
			if(size==0)	
				printf("Invalid\n");
			else
			{
				int res=pop();
				printf("%d\n",res);
			}
		}
		else if(cmd=="PeekMedian")
		{
			if(size==0)	
				printf("Invalid\n");
			else
				printf("%d\n",mid);
		}
		else if(cmd=="Push")
		{
			int num;
			cin>>num;
			insert(num);
		}
	}
	
}
