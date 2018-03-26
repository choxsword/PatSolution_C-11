#include<iostream>
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

namespace xzj
{
	unordered_map<int,int> mright;
	unordered_map<int,int> mleft;
	unordered_set<int> mset;
}

int main()
{
	using namespace xzj;
	int K;//ÎÊÌâÊý
	cin>>K;
	for(int i=K;i>0;--i) 
	{
		int N;
		cin>>N;
		bool is_ok=true;
		for(int j=1;j<=N;++j)
		{
			int num;
			cin>>num;
			if(mset.find(num)!=mset.end())
			{
				is_ok=false; 
			}
			else
			{
				mset.insert(num);
				int r_no=j-(num-1);
				int l_no=num+j-1;
				if(++mright[r_no]>1||++mleft[l_no]>1)
				{
					is_ok=false; 
				}
			}
		}
		is_ok?printf("YES\n"):printf("NO\n");
		mright.clear();
		mleft.clear();
		mset.clear();	
	}
}
