#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Item
{
	string name;
	int age;
	int worth;
	Item(string& _name,int& _age,int& _worth)
	{
		name=_name;age=_age;worth=_worth;
	}
};
bool operator <(const Item&lhs,const Item&rhs)
{
	if(lhs.worth<rhs.worth)
	{
		return true;
	}
	else if(lhs.worth==rhs.worth)
	{
		if(lhs.age>rhs.age)
		{
			return true;
		}
		else if(lhs.age==rhs.age)
		{
			return (lhs.name>rhs.name);
		}
	}
	return false;
}
struct Query
{
	int cnt;
	int min;
	int max;
	Query(int &_cnt,int& _min,int& _max):cnt(_cnt),min(_min),max(_max){
	}
};
int main()
{
	//std::ios_base::sync_with_stdio(false);
	int cnt_item,cnt_query;
	cin>>cnt_item>>cnt_query;
	vector<Item> vec;
	vec.reserve(100000);
	for(int k=cnt_item;k>0;--k)
	{
		string name;
		int age,worth;
		cin>>name>>age>>worth;
		vec.emplace_back(name,age,worth);
	}
	sort(vec.begin(),vec.end());
	vector<Query> query;
	query.reserve(100000);
	for(int k=cnt_query;k>0;--k)
	{
		int piece,min,max;
		cin>>piece>>min>>max;
		query.emplace_back(piece,min,max);
	}
	int size_query=query.size();
	for(int k=0,i=1;k<size_query;++k)
	{
		int cnt_find=0;
		printf("Case #%d:\n",i);
		int max=query[k].max;
		int min=query[k].min;
		int cnt=query[k].cnt;
		auto end=vec.rend();
		for(auto i=vec.rbegin();i!=end;++i)
		{
			if((i->age<=max)&&(i->age>=min))
			{
				printf("%s %d %d\n",i->name.c_str(),i->age,i->worth);
				if(++cnt_find==cnt)
				{
					break;
				};
			}
		}
		if(cnt_find==0)
		{
			printf("None\n");
		}
		++i;
	}
	
}


