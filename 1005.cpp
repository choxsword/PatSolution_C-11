#include<string> 
#include<iostream>
using namespace std;
void print(char);
int main()
{

	string s_input;
	cin>>s_input;
	int sum=0;
	for(auto i:s_input)
	{
		sum+=(i-48);
	}

	string s_res=to_string(sum);
	auto it=s_res.begin();
	while(true)
	{
		print(*it);
		if(++it!=s_res.end())
		{
			cout<<' ';
		}
		else
		{
			return 0;
		}
	}
	
}
void print(char in)
{
	switch(in)
	{
		case '0':cout<<"zero";break;
		case '1':cout<<"one";break;
		case '2':cout<<"two" ;break;
		case '3':cout<<"three";break;
		case '4':cout<<"four";break;
		case '5':cout<<"five";break;
		case '6':cout<<"six";break;
		case '7':cout<<"seven";break;
		case '8':cout<<"eight";break;
		case '9':cout<<"nine";break;	
	}
}
