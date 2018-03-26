#include<iostream> 
#include<vector>
#include<limits>
using namespace std;


int main()
{
	
	int min_int=numeric_limits<int>::min();
	int max_int=numeric_limits<int>::max();
	int N;//¸öÊý
	cin>>N;
	vector<int> input;
	input.resize(N+1,0);
	for(int i=1;i<=N;++i) 
		cin>>input[i];
	vector<int> low(N+1,0);
	vector<int> sum(N+1,0);
	input[0]=min_int;
	sum[0]=min_int;
	for(int i=1;i<=N;++i)
	{
		if(sum[i-1]<0) 
		{
			sum[i]=input[i];
			low[i]=i;
		}
		else
		{
			sum[i]=input[i]+sum[i-1];
			low[i]=low[i-1];
		}
	}
	int max=min_int;
	int index=max_int;
	for(int i=1;i<=N;++i)
	{
		if(sum[i]>max)
		{
			index=i;
			max=sum[i];
		}
	}
	if(max<0)
		printf("%d %d %d\n",0,input[1],input[N]);
	else
		printf("%d %d %d\n",max,input[low[index]],input[index]);
	
}
