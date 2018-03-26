#include<iostream>
#include<memory>
#include<queue>
#include<algorithm>
using namespace std;
namespace xzj
{
//decl
	struct Node;
	using pNode=shared_ptr<Node>;
	pNode NIL=make_shared<Node>(0,-1);
	 void insert_node(pNode&tree,int val);
	
	struct Node
	{
		pNode left=NIL;
		pNode right=NIL;
		pNode father=NIL;
		int value;
		int height;
		void insert(int val);
		
		Node(int _val,int _height=0):value(_val),height(_height){}
	};
	struct Tree
	{
		pNode root=NIL;
		void insert(int val)
		{
			insert_node(root,val);	
		}
		bool print(int cnt);
	};
	
	bool Tree::print(int cnt)
	{
		queue<Node> que;
		que.push(*root);
		bool is_complete=true;
		int printing=1;
		bool result=true;
		while(!que.empty())
		{
			auto father=que.front();
			que.pop();
			if(father.left!=NIL)
			{
				que.push(*father.left);
				result=true&&is_complete;
			}
			else
			{
				is_complete=false;
				//cout<<"shit"<<endl;
			}
			if(father.right!=NIL)
			{
				que.push(*father.right);
				result=true&&is_complete;
			}
			else
			{
				is_complete=false;
				//cout<<"shit"<<endl;
			}
			if(printing!=cnt)
			{
				printf("%d ",father.value);	
				++printing;
			}
			else
			{
				printf("%d\n",father.value);
				return result;	
			}
		}	
	
	}
		int geth(pNode node)
	{
		return 	max(node->left->height,node->right->height)+1;
	}
	pNode& single_rot_right(pNode&tree)
	{
		pNode t1=tree;
		pNode t2=tree->left;
		pNode t3=t2->right;
		t1->left=t3;
		t2->right=t1;
		t1->height=geth(t1);
		t2->height=geth(t2); 
		tree=t2;
	}

	pNode& single_rot_left(pNode&tree)
	{
		pNode t1=tree;
		pNode t2=tree->right;
		pNode t3=t2->left;
		t1->right=t3;
		t2->left=t1;
		t1->height=geth(t1);
		t2->height=geth(t2);
		tree=t2;
	}
	pNode& double_rot_left(pNode&tree)
	{
		pNode t1=tree;
		pNode t2=tree->left;
		pNode t3=tree->left->right;
		t2->right=t3->left;
		t1->left=t3->right;
		t3->left=t2;
		t3->right=t1;
		t2->height=geth(t2);
		t1->height=geth(t1);
		t3->height=geth(t3);
		tree= t3;
	}
	pNode& double_rot_right(pNode&tree)
	{
		pNode t1=tree;
		pNode t2=tree->right;
		pNode t3=t2->left;
		//cout<<"shit"<<t3->value<<endl;
		t2->left=t3->right;
		t1->right=t3->left;
		t3->right=t2;
		t3->left=t1;
		t2->height=geth(t2);
		t1->height=geth(t1);
		t3->height=geth(t3);
		tree=t3;
	}
	
	//functions
	void insert_node(pNode&tree,int val)
	{
		if(tree==NIL)
		{
			tree=make_shared<Node>(val);
			//printf("%d\n",val);
		}
		else
		{
			if(val<tree->value)
			{
				insert_node(tree->left,val);
				tree->height=tree->left->height+1;
				int left_h=tree->left->height;
				int right_h=tree->right->height;
				int diff= left_h-right_h;
				if(diff>1)
				{
					if(val<tree->left->value)
					{
						single_rot_right(tree);//
						
					}
					else
					{
						double_rot_left(tree);
					}
				}
			}
			else
			{
				insert_node(tree->right,val);
				tree->height=tree->right->height+1;
				int diff= tree->left->height-tree->right->height;
				if(diff<-1)
				{
					if(val>tree->right->value)
					{
						single_rot_left(tree);
					}
					else
					{
						double_rot_right(tree);
					}
				}
		
			}
			
		}
		
	}
	

}


int main()
{
	using namespace xzj;
	Tree tree;
	int cnt_node;
	cin>>cnt_node;
	for(int i=cnt_node;i>0;--i)
	{
		int val;
		cin>>val;
		tree.insert(val);
	}
	bool is_comp=tree.print(cnt_node);
	is_comp?printf("YES"):printf("NO");
	//printf("YES\n");
	return 0;
}

