#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<deque>
using namespace std;
namespace xzj
{
	struct Node
	{
		//int id;
		int left;
		int right;
		int level;
	};
	unordered_map<int,Node> tree;
	vector<int> in;
	vector<int> post;
	vector<int> result;
	using It=vector<int>::iterator;
	int get_root(const It&in_begin,const It&in_end,const It&post_begin,const It&post_end,int level)
	{
		int root=-1;
		if(post_begin!=post_end)
		{
			root=*(post_end-1);	
			tree[root].level=level;
		}
		else 
			return root;
		auto&&it=find(in_begin,in_end,root);
		int cnt_left=it-in_begin;
		int cnt_right=in_end-it-1;
		if(cnt_left!=0)
			tree[root].left=get_root(in_begin,it,post_begin,post_begin+cnt_left,level+1);
		else
			tree[root].left=-1;
		
		if(cnt_right!=0)
			tree[root].right=get_root(it+1,in_end,post_begin+cnt_left,post_end-1,level+1);
		else
			tree[root].right=-1;
			
		return root;
	}
	
	void level(int root)
	{
		deque<int> mque;
		tree[root].level=1;
		int pre=0;
	
		mque.push_back(root);
		while(!mque.empty())
		{
			int left=mque.front();
			int right=mque.back();
			if(pre%2==1)
			{
				if(tree[right].level!=pre)
				{
					mque.pop_front();
					result.push_back(left);
					if(tree[left].left!=-1)
						mque.push_back(tree[left].left);
					if(tree[left].right!=-1) 
						mque.push_back(tree[left].right);
				}
				else
				{
					mque.pop_back();
					result.push_back(right);
					if(tree[right].right!=-1)
						mque.push_front(tree[right].right);
					if(tree[right].left!=-1)
						mque.push_front(tree[right].left);
				}
			}
			else
			{
				if(tree[left].level!=pre)
				{
					mque.pop_back();
					result.push_back(right);
					if(tree[right].right!=-1)
						mque.push_front(tree[right].right);
					if(tree[right].left!=-1)
						mque.push_front(tree[right].left);
				}
				else
				{
					mque.pop_front();
					result.push_back(left);
					if(tree[left].left!=-1)
						mque.push_back(tree[left].left);
					if(tree[left].right!=-1)
						mque.push_back(tree[left].right);
				}
			}
			pre=tree[result.back()].level;
		}
		auto end=result.end()-1;
		for(auto it=result.begin();it!=end;++it)
			printf("%d ",*it);
		printf("%d\n",*end);
		
	}
}

int main()
{
	using namespace xzj;
	int N;//½ÚµãÊý
	cin>>N;
	
	in.reserve(N);
	for(int i=N;i>0;--i) 
	{
		int id;
		cin>>id;
		in.push_back(id);
	}
	result.reserve(N);
	post.reserve(N);
	for(int i=N;i>0;--i) 
	{
		int id;
		cin>>id;
		post.push_back(id);
	}
	get_root(in.begin(),in.end(),post.begin(),post.end(),1);
	level(*(post.end()-1));
	
}
