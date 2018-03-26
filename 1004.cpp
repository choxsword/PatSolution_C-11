#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
enum Color{white,gray,black};
struct Node
{
	//int id;
	int cnt_child;
	int level;
	vector<int> child;
	Node(int _id,int _cnt):cnt_child(_cnt){
	}
	Node()=default;
	Color color=white;
};
vector<Node> tree;
vector<int> tree_level;
void dfs_visit(Node &node,int level);
int main()
{
	int cnt_node,cnt_nonleaf;
	cin>>cnt_node>>cnt_nonleaf;
	tree.resize(cnt_node+1);
	for(int i=cnt_nonleaf;i>0;--i)
	{
		int id,cnt_child;
		cin>>id>>cnt_child;
		for(int i=cnt_child;i>0;--i)
		{
			int id_child;
			cin>>id_child;
			tree[id].child.push_back(id_child);
		}
	}
	//for_each(tree.begin(),tree.end(),[](Node&i){cout<<i.id<<endl;});
	
	dfs_visit(tree[1],1);
	auto end=--tree_level.end();
	for(auto it=tree_level.begin();it!=end;++it)
	{
		printf("%d ",*it);
	}
	printf("%d\n",*end);
}

void dfs_visit(Node &node,int level)
{
	//node.level=level;
	node.color=gray;
	if(!node.child.empty())
	{
		for(auto&i:node.child)
		{
			dfs_visit(tree[i],level+1);
		}
	}
	else
	{
		if(level>tree_level.size())
		{
			tree_level.resize(level);
			tree_level[level-1]=1;
		}
		else
		{
			++tree_level[level-1];
		}
	}
	node.color=black;
}

