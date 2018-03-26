#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node
{
	int left;
	int right;
	int value;
};
vector<int> values;
vector<Node>tree;
queue<int> nodes; 
int node_i=0;
void mid_travel(Node&node);
void level_travel(queue<int>&que,int cnt_node);

int main()
{
	int cnt_node;
	cin>>cnt_node;


	tree.resize(cnt_node);
	values.reserve(cnt_node);
	for(int i=0;i<cnt_node;++i) 
	{
		int left,right;
		cin>>left>>right;
		tree[i].left=left;
		tree[i].right=right;
	}
	for(int i=0;i<cnt_node;++i) 
	{
		int value;
		cin>>value;
		values.push_back(value);
	}
	sort(values.begin(),values.end());
	
	mid_travel(tree[0]);
	//for_each(tree.begin(),tree.end(),[](Node&node){cout<<node.value<<endl;});
	
	nodes.push(0);
	level_travel(nodes,cnt_node);
}

void mid_travel(Node&node)
{
	if(node.left!=-1)	
	{
		mid_travel(tree[node.left]);
	}
	node.value=values[node_i];
	++node_i;
	if(node.right!=-1)	
	{
		mid_travel(tree[node.right]);
	}	
}

void level_travel(queue<int>&que,int cnt_node)
{
	
	while(!que.empty())
	{
		Node& node=tree[que.front()];
		if(cnt_node!=1)
		{
			printf("%d ",node.value);
		}
		else
		{
			printf("%d",node.value);
		}
		--cnt_node;
		que.pop();
		if(node.left!=-1)
		{
			que.push(node.left);
		}
		if(node.right!=-1)
		{
			que.push(node.right);
		}
	}
}

