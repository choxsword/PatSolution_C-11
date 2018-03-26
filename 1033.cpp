#include<iostream>
#include<vector>
#include<algorithm> 
#include<utility>
#include<limits>
using namespace std;

int main()
{
	double Cmax;//最大容量
	double D;//目标距离
	double Davg;//燃油里数
	int N;//加油站数 
	cin>>Cmax>>D>>Davg>>N;
	double max_dis=Cmax*Davg;
	double max_double=numeric_limits<double>::max();
	vector<pair<double,double>> station;
	station.reserve(N);
	for(int i=N;i>0;--i)
	{
		double price,dis;
		cin>>price>>dis;
		station.push_back(make_pair(price,dis));
	}
	auto&&end=station.end(); 
	sort(station.begin(),end,[](pair<double,double>&lhs,pair<double,double>&rhs)
	{
		return lhs.second<rhs.second;
	});
	double money=0;
	double cur_gas=0;
	if(station.front().second!=0)	
	{
	 	printf("The maximum travel distance = %.2f",0);
	 	return 0; 
	}		
	
	for(auto it=station.begin();it!=end;)
	{		
		auto best=end;
		double add=0;
		double min_price=max_double;
		for(auto next=it+1;next!=end;++next)
		{
			if(next->first<it->first&&(next->second-it->second)<=max_dis)
			{
				best=next;
				min_price=next->first;
				break;
			} 
			else if(next->first<min_price&&(next->second-it->second)<=max_dis)
			{
				min_price=next->first;
				best=next;
			}
		}
		if(best==end)
		{
			 if(it->second+max_dis<D)
			 {
			 	printf("The maximum travel distance = %.2f",it->second+max_dis);
			 	return 0; 
			 }	
		}
		if(min_price>it->first)
		{
			if(D-it->second<max_dis) 
			{
				add=((D-it->second)/Davg)-cur_gas;
				best=end;
				if(add>0)
					money+=add*(it->first);	
			}
			else
			{
				add=(Cmax-cur_gas); 
				money+=add*(it->first);
				cur_gas=Cmax;
			}
		}
		else
		{
			add=((best->second-it->second)/Davg)-cur_gas;
			if(add>0)
			{
				money+=add*(it->first);
				cur_gas+=add;
			}
		}
		if(best==end)
			break;
		cur_gas-=(best->second-it->second)/Davg; 
		it=best;
	}
	printf("%.2f",money);
}
