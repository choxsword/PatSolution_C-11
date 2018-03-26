#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<array>
#include<vector>
#include<utility>
#include<functional>
using namespace std;

struct Item
{
	int id;
	int total=0;
	array<int,5> part={{-2,-2,-2,-2,-2}};
	int perfect=0;

	Item()=default;
	void update(int _id,int num,int grade,bool _perfect)
	{
		id=_id;
		if(grade>part[num-1])
		{
			part[num-1]=grade;
			if(_perfect)
			{
				++perfect;
			}
		}
	}
	
	static int cnt_subject; 
	void count_sum()
	{
		for(int i=0;i<cnt_subject;++i)
		{
			if(part[i]!=-2)
			{
				if(part[i]!=-1)
				{
					total+=part[i];
				}
			}
		}
	}
};
int Item::cnt_subject;


struct CmpItem:public binary_function<Item,Item,bool>
{
	bool operator()(const Item&lhs,const Item&rhs)
	{
		if(lhs.total==rhs.total)
		{
			if(lhs.perfect==rhs.perfect)
			{
				return (lhs.id<rhs.id);
			}
			else
			{
				return (lhs.perfect>rhs.perfect);
			}
		}
		else
		{
			return (lhs.total>rhs.total);
		}
	}
};

struct CmpItem2:public binary_function<Item,Item,bool>
{
	bool operator()(const Item&lhs,const Item&rhs)
	{
			return (lhs.total>rhs.total);
	}
};


struct Pre:unary_function<Item,bool>
{
	bool operator()(const Item& item)
	{
		for(int i=0;i<Item::cnt_subject;++i)
		{
			if(item.part[i]>=0)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	int N,K,M;
	cin>>N>>K>>M;
	Item::cnt_subject=K; 
	array<int,5> full_mark;
	for(int i=0;i<K;++i)
	{
		int mark;
		cin>>mark;
		full_mark[i]=mark;
	}
	unordered_map<int,Item> mymap;
	for(int i=M;i>0;--i)
	{
		int id,num,grade;bool perfect=false;
		cin>>id>>num>>grade;
		if(full_mark[num-1]==grade){perfect=true;
		}
		
		mymap[id].update(id,num,grade,perfect);
	}
	//ÅÅÐò 
	vector<Item> vec;
	for(auto i:mymap)
	{
		Item& tmp=i.second;
		vec.push_back(std::move(tmp));
	}
	auto new_end=remove_if(vec.begin(),vec.end(),Pre());
	vec.erase(new_end,vec.end());
	
	for_each(vec.begin(),vec.end(),mem_fn(&Item::count_sum));
	
	sort(vec.begin(),vec.end(),CmpItem());
	
	//Êä³ö½á¹û 
	int rank=1;
	auto end=vec.end();
	auto begin=vec.begin();
	int printed=0;
	
	while(begin!=end)
	{
		auto range=equal_range(begin,end,*begin,CmpItem2());
		begin=range.second;
		for(auto it=range.first;it!=begin;++it)
		{
			++printed;
			printf("%d %05d %d",rank,(*it).id,(*it).total);
			for(int i=0;i<Item::cnt_subject;++i)
			{
				int score=it->part[i];
				printf(" ");
				if(score==-2)
				{
					printf("-");
				}
				else if(score==-1)
				{
					printf("0");
				}
				else
				{
					printf("%d",score);
				}
			}
			printf("\n");
		}
		rank=printed+1;
	}
	
} 
