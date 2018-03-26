#include<string> 
#include<iostream>
using namespace std;
void print(int k);
int main()
{
	int first,second,third;
	cin>>first>>second>>third;
	cout<<'#';
	
	print(first);
	print(second);
	print(third);
	
	return 0;
	
}


void print(int k)
{	char format(int k);
	cout<<format(k/13)<<format(k%13);	
}

char format(int k)
{
	if(k<10)
	{
		return k+48;
	}
	else
	{
		switch(k)
		{
			case 10: return 'A';
			case 11: return 'B';
			case 12: return 'C';
		}

	}
}
