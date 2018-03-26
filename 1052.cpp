#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

struct Data
{
	int value;
	int pnext;
	int address;
	Data(int&_address,int _v,int& _pn)
	{
		value=_v;
		pnext=_pn;
		address=_address;
	}

	Data(const Data& _data)
	{
		value=_data.value;
		address=_data.address;
		pnext=_data.pnext;
	}
	Data()=default;
};

bool operator <(const Data&lhs,const Data&rhs)
{
	return (lhs.value<rhs.value);
}

int main()
{
	int count,pfirst;
	cin>>count>>pfirst;
	unordered_map<int,Data> mymap;
	vector<Data> myvec;
	myvec.reserve(1000);
	for(int k=count;k>0;--k)
	{
		int addr,value,pnext;
		cin>>addr>>value>>pnext;
		mymap[addr]=Data(addr,value,pnext);
	}
	for(int addr=pfirst;addr!=-1;)
	{
		Data& data=mymap[addr];
		myvec.push_back(move(data));
		addr=data.pnext;
	}
	if(!myvec.empty())
	{
	
	sort(myvec.begin(),myvec.end());
	auto end=--myvec.end();
	printf("%d %05d\n",myvec.size(),myvec.front().address);
	for(auto begin=myvec.begin();begin!=end;)
	{
		auto it=begin++;
		it->pnext=begin->address;
		printf("%05d %d %05d\n",it->address,it->value,it->pnext);
	}
	end->pnext=-1;
	
	//Êä³ö
	printf("%05d %d -1",end->address,end->value);
	
	}
	else
	{
		printf("0 -1");
	}
}
