#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;
namespace xzj
{
	int M;//切片大小
	int N;//
	int L;//切片数
	int T;//上限
	int area;
	array<int,6> addx={1,-1,0,0,0,0};
	array<int,6> addy={0,0,1,-1,0,0};
	array<int,6> addz={0,0,0,0,1,-1};
	vector<int> visit;
	vector<int> a3;
	vector<int>result;
	inline bool is_in(int x,int y,int z)
	{
		if(x<0||x>N-1)
			return false;
		else if(y<0||y>M-1)
			return false;
		else if(z<0||z>L-1)
			return false;
		else 
			return true;
	}
	
	inline int& get(vector<int>&v,int x,int y,int z) 
	{
		return v[area*z+(x+N*y)];	
	}
	
	
	void dfs(int x,int y,int z)
	{
		get(a3,x,y,z)=0;
		++result.back();
		for(int i=0;i<6;++i)
		{
			int x1=x+addx[i];
			int y1=y+addy[i];
			int z1=z+addz[i];
			if(is_in(x1,y1,z1)&&get(a3,x1,y1,z1)==1)
			{
				dfs(x1,y1,z1);
			}
		}
	}
}
int main()
{
	
	using namespace xzj;
	cin>>M>>N>>L>>T;
	area=M*N;
	a3.resize(M*N*L,0);
	//visit.resize(M*N*L,0);
	for(int i=0;i<L;++i)
	{
		for(int j=0;j<M;++j)
		{
			for(int k=0;k<N;++k)
			{
				int num;
				cin>>num;
				get(a3,k,j,i)=num;
			}
		}
	}
	
	for(int z=0;z<L;++z)
	{
		for(int y=0;y<M;++y)
		{
			for(int x=0;x<N;++x)
			{
				if(get(a3,x,y,z)==0)
					continue;
				result.push_back(0);
				dfs(x,y,z);
			}	
		}
	}

	int res=accumulate(result.begin(),result.end(),0,[&](int a,int b)
	{
		return b>=T?a+b:a;
	});
	cout<<res<<endl;

		 
}
