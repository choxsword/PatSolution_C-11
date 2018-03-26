#include<iostream>
#include<vector>
#include<algorithm> 
#include<deque>
using namespace std;

int main()
{
	int NC;//券数
	cin>>NC;
	deque<int> coupon;
	for(int i=NC;i>0;--i) 
	{
		int val;
		cin>>val;
		coupon.push_back(val);
	}
	int NP;//商品数
	cin>>NP;
	deque<int> product;
	for(int i=NP;i>0;--i) 
	{
		int val;
		cin>>val;
		product.push_back(val);
	}
	sort(coupon.begin(),coupon.end());
	sort(product.begin(),product.end());
	int money=0;
	for(auto&i:coupon)
	{
		if(i>0)
			break;
		else if(i<0)
		{
			if(product.front()<0)
			{
				money+=i*product.front();
				coupon.pop_front();
				product.pop_front(); 
			}	
			else
				break;
		}
		else
			coupon.pop_front();	
	}
	while(!coupon.empty() &&coupon.front()<=0) 
		coupon.pop_front();
	while(!coupon.empty()&&!product.empty())
	{
		if(product.back()<=0)
			break;
		money+=coupon.back()*product.back();
		coupon.pop_back();
		product.pop_back();
	}
	cout<<money<<endl;
}
