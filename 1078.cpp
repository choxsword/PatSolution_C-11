#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

inline bool check(int i)
{
	int k=sqrt(i);
	for(int j=2;j<=k;++j)
		if(i%j==0)
			return false;
	return true;
}

inline int find(int i)
{
	if(i==1)
		return 2;
	while(check(i)==false)
		++i;
	return i;
}

int main()
{
	int M;//表大小
	int N;//输入规模
	cin>>M>>N;
	M=find(M);
	vector<int> input;
	input.reserve(N);
	for(int i=N;i>0;--i)
	{
		int num;
		cin>>num;
		input.push_back(num);
	}
	vector<bool> is_insert(N,false);
	vector<bool> is_emp(M,true);
	vector<int> position(N,0);
	
	/////3ms 
	for(int i=0;i<N;++i)
	{
		int pos=input[i]%M;
		if(is_emp[pos]==true)
		{
			is_emp[pos]=false;
			is_insert[i]=true;
			position[i]=pos;
		}
		else
		{
			bool is_ok=false;
			for(int j=0;j<M;++j)
			{
				int k=((input[i]+j*j)%M);
				if(is_emp[k]==true)
				{
					is_emp[k]=false;
					is_ok=true;
					position[i]=k;
					break;
				} 
			}
			is_insert[i]=is_ok;
		}
	}
	///////   >100ms 
	for(int i=0;i<N-1;++i)
	{
		if(is_insert[i])
			printf("%d ",position[i]);
		else
			printf("- ");
	}

	if(is_insert[N-1])
		printf("%d\n",position[N-1]);
	else
		printf("-\n");
	
}

