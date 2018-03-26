#include<unordered_map> 
#include<iostream>
#include<list>
#include<unordered_set>
#include<cmath>
using namespace std;

struct Data
{
	int content;
	int pnext;
	int address;
	Data(int&_address,int _con,int& _pn)
	{
		content=_con;
		pnext=_pn;
		address=_address;
	}
	Data()=default;
};


int main()
{
	int pfirst;
	int num;
	cin>>pfirst>>num;
	unordered_map<int,Data> mymap;
	for(int k=num;k>0;--k)
	{
		int address,pnext;
		int content;
		cin>>address>>content>>pnext;
		mymap[address]=Data(address,content,pnext);
	}
	
	list<Data> result,rest;
	unordered_set<int> myset;
	int pbegin=pfirst;
	
	while(pbegin!=-1)
	{
		Data dat=mymap[pbegin];
		auto p=myset.insert(abs(dat.content));
		if(p.second)
		{
			if(!result.empty())
			{(result.back()).pnext=dat.address;}
			result.push_back(dat);
		}
		else
		{
			if(!rest.empty())
			{rest.back().pnext=dat.address;}
			rest.push_back(dat);
		}
		pbegin=dat.pnext;
	}
	if(!result.empty())
	{
	
		auto end=--result.end();
		for(auto it=result.begin();it!=end;++it)
		{
			printf("%05d %d %05d\n",it->address,it->content,it->pnext);
		}
		printf("%05d %d ",end->address,end->content);
		printf("%d\n",-1);
		
	}
	
	if(!rest.empty())
	{
	
		auto end=--rest.end();
		for(auto it=rest.begin();it!=end;++it)
		{
			printf("%05d %d %05d\n",it->address,it->content,it->pnext);
		}
		printf("%05d %d ",end->address,end->content);
		printf("%d",-1);
	}


}


