#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

namespace xzj
{
	struct Node
	{
		string v="";
		int l=-1;
		int r=-1;
		int f=-1;
	};
	vector<Node>tree;
	int root;
	void print(int id)
	{
		Node& node=tree[id];
		bool is_op=false; 
		if(id!=root&&node.v.size()==1)
		{
			if(node.l!=-1||node.r!=-1) 
				is_op=true;
		}
		if(is_op)
			printf("(");
		
		if(node.l!=-1)
		{
			print(node.l);
		}
		printf("%s",node.v.c_str());
		if(node.r!=-1)
		{
			print(node.r);
		}
		if(is_op)
			printf(")");
	}
}



int main()
{
	using namespace xzj;
	int N;//½ÚµãÊý
	cin>>N;
	tree.resize(N+1);
	for(int i=1;i<=N;++i) 
	{
		string v;
		int l,r;
		cin>>v>>l>>r;
		tree[i].v=v;
		tree[i].l=l;
		tree[i].r=r;
		if(l!=-1) 
			tree[l].f=i;
		if(r!=-1) 
			tree[r].f=i;
	}
	auto it=find_if(tree.begin()+1,tree.end(),[](const Node& n)
	{
		return n.f==-1;
	});
	root=1+distance(tree.begin()+1,it);
	//cout<<root<<endl;
	print(root);
}
