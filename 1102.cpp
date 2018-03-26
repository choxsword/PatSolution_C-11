#include<iostream> 
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node
{
	char left;
	char right;
	char father=0;
};
int printed;
void inorder(char father);
vector<Node> tree;
int main()
{
	int cnt_node;
	cin>>cnt_node;
	
	tree.resize(cnt_node);
	for(int i=0;i<cnt_node;++i)
	{
		char left,right;
		cin>>left>>right;
		tree[i].left=left;
		tree[i].right=right;
		if(right!='-')
		{
			tree[right-48].father=i+48;
		}
		if(left!='-')
		{
			tree[left-48].father=i+48;
		}
	}
	auto it=find_if(tree.begin(),tree.end(),[](Node&node){return node.father==0;});
	char root=(it-tree.begin())+48;
	//≤„–Ú
	 queue<char> que;
	 que.push(root);
	  printed=cnt_node;
	 while(!que.empty())
	 {
	 	char father=que.front();
	 	char left,right;
	 	if((right=tree[father-48].right)!='-')
	 	{
	 		que.push(right);
		}
		if((left=tree[father-48].left)!='-')
	 	{
	 		que.push(left);
		}
		if(printed!=1)
		{
			printf("%c ",father);
			--printed;
		}
		else
		{
			printf("%c\n",father);
		}
	 	que.pop();
	 }
	//÷––Ú
	 printed=cnt_node;
	 inorder(root);
}

void inorder(char father)
{
	char left,right;

	if((right=tree[father-48].right)!='-')
 	{
 		inorder(right);
	}
	if(printed!=1)
	{
		printf("%c ",father);
		--printed;
	}
	else
	{
		printf("%c\n",father);
	}
	if((left=tree[father-48].left)!='-')
 	{
 		inorder(left);
	}
	
}


