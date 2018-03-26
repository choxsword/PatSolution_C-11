#include<string>
#include<iostream>
using namespace std;
void print_num(char k);
void print_unit(int k);
void decre(int&num);
void print_part(int k);
int main()
{
	int num;
	cin>>num;
	print_part(num);
}

void decre(int&num)
{
	switch(num)
	{
		case 9:cout<<' '<<"Yi";break;
		case 5:cout<<' '<<"Wan";break;
	}
	--num;
}

void print_part(int k)
{
	string s_in=to_string(k);
	auto i=s_in.begin();
	int num;
	if(s_in.front()=='-')
	{
		cout<<"Fu"<<' ';
		num=s_in.size()-1;
		++i;
	}
	else
	{
		num=s_in.size();
	}
	print_num(*i);
			print_unit(num);
			decre(num);
			++i;
	for(;i!=s_in.end();)
	{
		if(*i!='0')
		{
			cout<<' ';
			print_num(*i);
			print_unit(num);
			decre(num);
			++i;
		}
		else
		{
			while(*i=='0'){
				if(++i==s_in.end()){return;
				};
				decre(num);
			}
			if(i!=s_in.end())
			{
				cout<<' ';
				print_num('0');
			}
		}	
	}
	
}

void print_unit(int k) 
{
	
	switch(k%4)
	{
		case 0:cout<<' '<<"Qian";return;
		case 2:cout<<' '<<"Shi";return;
		case 3:cout<<' '<<"Bai";return;
		default:return;
	}
}

void print_num(char k)
{
	switch(k)
	{
		case '0':cout<<"ling";return;
		case '1':cout<<"yi";return;
		case '2':cout<<"er" ;return;
		case '3':cout<<"san";return;
		case '4':cout<<"si";return;
		case '5':cout<<"wu";return;
		case '6':cout<<"liu";return;
		case '7':cout<<"qi";return;
		case '8':cout<<"ba";return;
		case '9':cout<<"jiu";return;
	}
}
