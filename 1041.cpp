#include<iostream>
#include<vector>
using namespace std;


int main()
{
	const size_t size=1e4+1;
	int a[size]={0};
	int N;
	cin>>N;
	vector<int> person;
	person.resize(N,0);
	for(int i=0;i<N;++i)
	{
		int value;
		cin>>value;
		person[i]=value;
		++a[value];
	}
	int i=1;
	for(auto&i:person)
	{
		if(a[i]==1)
		{
			printf("%d\n",i);
			exit(0);
		}
	}
	printf("None");
	
}
