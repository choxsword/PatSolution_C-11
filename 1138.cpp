#include<iostream>
#include<vector>
#include<unordered_map> 
#include<algorithm>
using namespace std;

struct Node
{
	int id=0;
	int left=0;
	int right=0;
};
unordered_map<int,Node> tree;
namespace xzj
{
	using It=vector<int>::iterator;
	int get_root(const It&pbegin,const It&pend,const It&ibegin,const It&iend)
	{
		int root=*pbegin;
		//cout<<root<<endl;
		It root_in=find(ibegin,iend,root);
		int cnt_left=root_in-ibegin;
		int cnt_right=iend-root_in-1;
		tree[root].id=root;
		if(cnt_left>0)
			tree[root].left=get_root(pbegin+1,pbegin+1+cnt_left,ibegin,ibegin+cnt_left);
		if(cnt_right>0)
			tree[root].right=get_root(pbegin+1+cnt_left,pend,root_in+1,iend);
		return root;
	}
	void post_order(int root)
	{
		Node&node=tree[root];
		if(node.left!=0)
			post_order(tree[node.left].id);
		if(node.right!=0)
			post_order(tree[node.right].id);
		printf("%d\n",node.id);
		exit(0);
	}
	
	
}
int main()
{
	using namespace xzj;
	int N;//½ÚµãÊý
	cin>>N;
	vector<int> pre;
	for(int i=N;i>0;--i) 
	{
		int id;
		cin>>id; 
		pre.push_back(id);
	}
	vector<int> in;
	for(int i=N;i>0;--i) 
	{
		int id;
		cin>>id; 
		in.push_back(id);
	}
	//for_each(in.begin(),in.end(),[](int&k){cout<<k<<endl;});
	int root=get_root(pre.begin(),pre.end(),in.begin(),in.end());
	post_order(root);
}
