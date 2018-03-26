#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

namespace xzj
{
	int N;//½ÚµãÊý
	vector<int> pre;
	vector<int> post;
	vector<int> result;
	bool is_unique=true;	
	void init()
	{
		pre.reserve(N);
		post.reserve(N);
		result.reserve(N);
	}
	using It=vector<int>::iterator;
	void in_order(const It&pre_begin,const It&pre_end,const It&post_begin,const It&post_end)
	{
		if(pre_begin==pre_end)
			return;
		int root=*pre_begin;
		if(pre_end-pre_begin==1)
		{
			result.push_back(root);
			return; 
		}
		if(*(pre_begin+1)==*(post_end-2))
				is_unique=false;
		It rtree=pre_end;
		rtree=find(pre_begin+1,pre_end,*(post_end-2)); 
		int cnt_ltree=rtree-pre_begin-1;
		in_order(pre_begin+1,rtree,post_begin,post_begin+cnt_ltree);
		result.push_back(root);
		in_order(rtree,pre_end,post_begin+cnt_ltree,post_end-1);
	}
	void print()
	{
		is_unique?printf("Yes\n"):printf("No\n");
		auto end=result.end()-1;
		for(auto it=result.begin();it!=end;++it)
			printf("%d ",*it);
		printf("%d\n",*end);
	}
}
int main()
{
	using namespace xzj;
	cin>>N;
	init();
	for(int i=N;i>0;--i) 
	{
		int id;
		cin>>id;
		pre.push_back(id);
	}
	for(int i=N;i>0;--i) 
	{
		int id;
		cin>>id;
		post.push_back(id);
	}
	in_order(pre.begin(),pre.end(),post.begin(),post.end());
	print();
}
