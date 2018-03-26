#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

enum Color{red,black};
struct Node
{
	Color color;
	int height=1;
};
unordered_map<int,Node> tree;
namespace xzj
{
	using It=vector<int>::iterator;
	bool is_b(int i)
	{
		return i>0;
	}
	int geth(const It&begin,const It&end)
	{
		if(begin==end)
			return 1;
		int root=*begin;
		tree[root].color=root>0?black:red;
		const It& rtree=find_if(begin,end,[&root](int&v){return abs(root)<abs(v);});
		int rh,lh; 
		lh=geth(begin+1,rtree);
		rh=geth(rtree,end);
		if(tree[root].color==red)
		{
			if(begin+1!=end)
			{
				if(!is_b(*(begin+1)))
					return -1;
				if(rtree!=end) 
				{
					if(!is_b(*rtree))
						return -1; 
				}		
			}	
		}
		if(lh==-1||rh==-1)
			return -1;
		if(abs(lh-rh)>0)   //条件5 
			return -1;
		if(tree[root].color==black)
			tree[root].height=max(lh,rh)+1;
		else
			tree[root].height=max(lh,rh);			

		return tree[root].height;
	}
	
	bool check(vector<int>&cases)
	{
		if(cases[0]<0)
			return false;
		int i=geth(cases.begin(),cases.end());
		if(i==-1)
			return false;
		else
			return true;
	}
	
	
}

int main() 
{
	using namespace xzj;
	int K;//样例数目
	cin>>K;
	vector<bool>result;
	for(int i=K;i>0;--i) 
	{
		int cnt;
		cin>>cnt;
		vector<int> cases;
		cases.reserve(cnt);
		for(int i=cnt;i>0;--i)
		{
			int num;
			cin>>num;
			cases.push_back(num);
		}
		printf("%s\n",check(cases)?"Yes":"No");
	}
}
