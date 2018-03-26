#include<iostream> 
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

namespace xzj
{
	int N;//和
	int K;//个数
	int P;//指数
	vector<int>result;
	vector<int>tmp;
	pair<bool,bool> is_in(vector<int>::iterator cur,int num)
	{
		bool is_in=false;bool is_large=false;
		int min=0;int max=0;
		for(auto it=tmp.begin();it!=cur;++it)
		{
			min+=pow((*it),P);
			max=min; 
		}
		int v=pow(*cur,P);
		min=(max+=v);
		
		for(auto it=cur+1;it!=tmp.end();++it)
		{
			min+=1;
			max+=v;
		}
		cout<<min<<' '<<max<<endl;
		if(min<=N&&max>=N)
			is_in=true;
		else if(max<N)
			is_large=true;
		return make_pair(is_in,is_large);
	}
	bool test(int max)
	{
		int cur=max;
		int pre=0;
		int min=1; 
		bool exist=true;
		for(auto it=tmp.begin();it!=tmp.end();++it)
		{
			while(is_in(it,cur).first==false)
			{
				if(is_in(it,cur).second==true)
					cur=(cur+max)/2;
				else
					cur=(cur+min)/2 ;
				if(cur==pre)	
				{
					exist=false; 
					break;
				}	
				pre=cur;
			}
			max=cur;
			*it=cur;
			cout<<cur<<endl;
		}
		return exist;
	}
} 


int main()
{
	using namespace xzj;
	cin>>N>>K>>P;
	result.resize(K,0);
	tmp.resize(K,0);
	int max=sqrt(N);
	 if(test(max)+1)
	 {
	 	for(auto&i:tmp)
	 		cout<<i<<' ' ;
	 }
	 
	 
}
