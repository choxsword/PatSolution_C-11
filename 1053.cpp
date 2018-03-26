#include<iostream> 
#include<vector>
#include<string>
#include<sstream>
#include<algorithm> 
using namespace std;

struct Node
{
	int id=0;
	int cnt_child=0;
	int weight=0;
	int father=-1;
	vector<int> child;	
};


int main()
{
	int cnt_node,cnt_non_leaf,S;
	cin>>cnt_node>>cnt_non_leaf>>S;
	vector<Node> tree(100);
	for(int i=0;i<cnt_node;++i)
	{
		int weight;
		cin>>weight;
		tree[i].weight=weight;
	}
	for(int i=cnt_non_leaf;i>0;--i)
	{
		int id,cnt_node,child;
		cin>>id>>cnt_node;
		for(int k=cnt_node;k>0;--k)
		{
			cin>>child;
			tree[id].cnt_child=cnt_node;
			tree[id].child.push_back(child);
			tree[child].father=id;
		}
	}
	
	vector<vector<int>> result;
	int w_root=tree[0].weight;
	for(int i=0;i<cnt_node;++i)
	{
		if(tree[i].cnt_child!=0)
		{
			continue;
		}
		else
		{
			vector<int> path;
			for(int id=i;id!=0;)
			{
				
				path.insert(path.begin(),tree[id].weight);
				id=tree[id].father;
			}
			path.insert(path.begin(), w_root);
			
			if(accumulate(path.begin(),path.end(),0)==S)
			{
				result.push_back(move(path));
			}
		}
	}
	
	sort(result.rbegin(),result.rend());
	for(auto&i:result)
	{
		auto end=--i.end();
		for(auto k=i.begin();k!=end;++k)
		{
			printf("%d ",*k);
		}
		printf("%d\n",*end);
	}
	
}
