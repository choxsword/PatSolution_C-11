#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string multiply(const string&s_in);
int main()
{
	string s_in;
	cin>>s_in;
	string s_res=multiply(s_in);
string	s_res_copy=s_res;
	sort(s_in.begin(),s_in.end());
	sort(s_res.begin(),s_res.end());
	if(s_in==s_res)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
  cout<<s_res_copy;
}
string multiply(const string&s_in)
{
    int flag=0;
	string s_res;
	for(auto it=s_in.rbegin();it!=s_in.rend();++it)
	{
		int res=2*(*it-48)+flag;
		if(res>9)
		{
			s_res.insert(s_res.begin(),(res%10+48));
			flag=1;
		}
		else
		{
			s_res.insert(s_res.begin(),(res+48));
			flag=0;
		}
	}
	if(flag==1)
	{
		s_res.insert(s_res.begin(),49);
	}
	return s_res;
}
