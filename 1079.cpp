#include<iostream> 
#include<vector>
#include<queue>
using namespace std;
struct Node
{
	vector<int> child;
	double price;
	int cnt;
};
double total=0;
vector<Node> tree;
queue<int> que;
void bfs(double);
int main()
{
	int cnt_node;double price, rate;
	cin>>cnt_node>>price>>rate;
	tree.resize(cnt_node);
	for(int i=0;i<cnt_node;++i)
	{
		int cnt_child;
		cin>>cnt_child;
		if(cnt_child!=0)
		{
			//cout<<cnt_child<<endl;
			for(int j=cnt_child;j>0;--j)
			{
				int id;
				cin>>id;
				tree[i].child.push_back(id);
			}
		}
		else
		{
			int num;
			cin>>num;
			tree[i].cnt=num;
		}
	}
	//cout<<tree.size()<<endl;
	tree[0].price=price;
	que.push(0);
	bfs(rate);
	printf("%.1f\n",total);
	
}

void bfs(double rate)
{
	double total_rate=1+0.01*rate;
	while(!que.empty())
	{
		int top=que.front();
		//cout<<top<<'\n';
		if(!tree[top].child.empty()) 
		{
			for(auto i:tree[top].child)
			{
				que.push(i);
				tree[i].price=total_rate*tree[top].price;
			}
		}
		else
		{
			total+=tree[top].price*tree[top].cnt;
		}
		que.pop();
	}
	
}
