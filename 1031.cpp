#include<iostream>
#include<string>
using namespace std;
void print_space(int len);
int main()
{
	string s_in;
	cin>>s_in;
	int num=s_in.size();
	int len,bottom;
	int rest=(num+2)%3;
	if(rest!=0)
	{
		len=(num+1)/3;
		bottom=len+rest;
	}
	else
	{
		bottom=len=(num+2)/3;
	}
	
	auto it=s_in.begin();auto it_r=s_in.rbegin();
	for(int k=len;k>1;--k)
	{
		cout<<*it++;
		print_space(bottom);
		cout<<*it_r++<<endl;
	}
	auto it_end=it_r.base();
	while(it!=it_end)
	{
		cout<<*it++;
	}
}
void print_space(int len)
{
	for(int k=len-2;k>0;--k)
	{
		cout<<' ';
	}
}
