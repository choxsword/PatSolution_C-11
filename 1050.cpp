#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	unordered_set<char> mset;
	for(auto&i:s1)
	{
		mset.insert(i);
	}
	for(auto&i:s2)
	{
		auto it=mset.find(i);
		if(it!=mset.end())
			mset.erase(it);
	}
	
	for(auto&i:s1)
	{
		if(mset.find(i)!=mset.end())
			printf("%c",i);
	}
	
}
