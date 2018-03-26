#include<iostream> 
#include<list>
#include<iomanip>
using namespace std;

struct Poly
{
	int exp;
	double coe;
	Poly(int _exp,double _coe)
	{
		exp=_exp;
		coe=_coe;
	}
};

list<Poly> add_list(const list<Poly>&first,const list<Poly>&second)
{
	list<Poly> result;
	auto it_first=first.begin();
	auto it_second=second.begin();
	while(true)
	{
		if((*it_first).exp>(*it_second).exp)
		{
			result.push_back(*it_first);
			if(++it_first==first.end())
			{
				result.insert(result.end(),it_second,second.end());
				return result;
			}
		}
		else if((*it_first).exp<(*it_second).exp)
		{
			result.push_back(*it_second);
			if(++it_second==second.end())
			{
				result.insert(result.end(),it_first,first.end());
				return result;
			}
		}
		else
		{
			double sum=(*it_first).coe+(*it_second).coe;
			if(sum!=0)
			{
			
			result.emplace_back((*it_first).exp,sum);
			} 
			
			
	     	if(++it_first==first.end())
			{
				result.insert(result.end(),++it_second,second.end());
				return result;
			}
			if(++it_second==second.end())
			{
				result.insert(result.end(),it_first,first.end());
				return result;
			}
		}

		}
					
	}
	     	 					

	 
	 
	



int main()
{
	int num1;
	cin>>num1;
	list<Poly> first;
	for(int k=num1;k>0;--k)
	{
		int exp;double coe;
		cin>>exp>>coe;
		first.emplace_back(exp,coe);
	}
	
	int num2;
	cin>>num2;
	list<Poly> second;
	for(int k=num2;k>0;--k)
	{
		int exp;double coe;
		cin>>exp>>coe;
		second.emplace_back(exp,coe);
	}

	
	list<Poly> result=add_list(first,second);
	cout<<result.size()<<setiosflags(ios::fixed)<<setprecision(1);
	for(auto mem:result)
	{
		cout<<' '<<mem.exp<<' '<<mem.coe;
	}
	return 0;
}
