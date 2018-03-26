#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

struct Moon
{
	double cnt;
	double price;
	double av;
};
int main()
{
	int N;//种类
	int D;//需求
	cin>>N>>D;
	vector<Moon> cake;
	cake.resize(N);
	for(int i=0;i<N;++i)
	{
		double amount;
		cin>>amount;
		cake[i].cnt=amount;
	}
	for(int i=0;i<N;++i)
	{
		double amount;
		cin>>amount;
		cake[i].price=amount;
	}
	 for(auto&i:cake)
	 {
	 	i.av=i.price/i.cnt;
	 }
	 sort(cake.begin(),cake.end(),[](Moon&lhs,Moon&rhs)
	 {
	 	return lhs.av<rhs.av;
	 }); 
	double profit=0;
	double need=D;
	while(need!=0&&!cake.empty())
	{
		Moon& top=cake.back(); 
		//cout<<top.cnt<<endl;
		double cnt=top.cnt;
		if(cnt<need)
		{
			cake.pop_back();
			profit+=top.price;
			need-=top.cnt;
		}
		else
		{
			profit+=need*top.av;
			need=0;
		}		
	}
	printf("%.2f",profit);
	 
	 
}
