#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<memory>
using namespace std;
struct Node;
using pNode=shared_ptr<Node>;


struct Node
{
	int num;
	pNode left=nullptr;
	pNode right=nullptr;
	Node(int n):num(n){}
};
struct Tree
{
	pNode root=nullptr;
	void insert(int num)
	{
		insert(root,num,1);
	}
	void insert(pNode &node,int num,int level)
	{
		if(node==nullptr)
		{
			node=make_shared<Node>(num);
			if(cnt.find(level)==cnt.end())
				cnt[level]=1;
			else
				++cnt[level];
		}
		else
		{
			if(num<=node->num)
				insert(node->left,num,level+1);
			else
				insert(node->right,num,level+1); 
		}
	}
	static unordered_map<int,int> cnt;
};
unordered_map<int,int> Tree::cnt;

int main()
{
	int N;//¸öÊý
	Tree tree;
	cin>>N;
	for(int i=N;i>0;--i) 
	{
		int num;
		cin>>num;
		tree.insert(num);
	}
	vector<pair<int,int>> result;
	for(auto&p:tree.cnt)
		result.push_back(move(p));
	sort(result.begin(),result.end(),[](pair<int,int>&lhs,pair<int,int>&rhs)
	{
		return lhs.first<rhs.first;
	});
	int last=result.back().second;
	result.pop_back();
	int next=result.back().second;
	printf("%d + %d = %d\n",last,next,last+next);
}
