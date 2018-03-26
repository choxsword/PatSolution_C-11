#include<iostream> 
#include<vector>
#include<string>
#include<algorithm> 
#include<unordered_map>
#include<utility>
using namespace std;
struct Node
{
	unordered_map<string,int> edge;
	bool visit=false;
	int weight=0;
	string name;
};
unordered_map<string,Node> mmap;
int N;//the number of phone calls
int K;//weight
int dfs_visit(Node&node);
string head;int max_w;int total;
int main()
{
	cin>>N>>K;
	for(int i=N;i>0;--i)
	{
		string a,b;
		int len;
		cin>>a>>b>>len;
		mmap[a].name=a;
		mmap[b].name=b;
		if(mmap[a].edge.find(b)!=mmap[a].edge.end())
		{
			mmap[a].edge[b]+=len;
		}
		else
		{
			mmap[a].edge[b]=len;
		}
		mmap[a].weight+=len;
		if(mmap[b].edge.find(a)!=mmap[a].edge.end())
		{
			mmap[b].edge[a]+=len;
		}
		else
		{
			mmap[b].edge[a]=len;
		}
		mmap[b].weight+=len;
	}
//	for(auto &p:mmap)
//	{
//		cout<<p.first<<"------------------"<<endl;
////		for(auto&p1:p.second.edge)
////		{
////			cout<<p1.first<<' '<<p1.second<<endl;
////		}
//		//cout<<p.second.weight<<endl;
//	}
	
	
	vector<pair<string,int>> result;
	for(auto&p:mmap)
	{
		Node&node=p.second;
		if(node.visit==false)
		{
			max_w=0;total=0;
			int num=dfs_visit(node);
			//cout<<node.name<<' '<<total<<endl;
			//cout<<"-----------"<<endl;
			if(num>2&&total/2>K)
			{
				result.push_back(pair<string,int>(head,num));
			}
		}
	}
	sort(result.begin(),result.end(),[](pair<string,int>&lhs,pair<string,int>&rhs){return lhs.first<rhs.first;});

	if(result.size()==0)
	{
		printf("0");
		return 0;
	}

	printf("%d\n",result.size());
	for(auto&i:result)
	{
		printf("%s %d\n",i.first.c_str(),i.second);
	}
	
}

int dfs_visit(Node&node)
{
	int cnt=1;
	node.visit=true;
	//cout<<node.name<<' '<<node.visit<<endl;
	for(auto&p:node.edge)
	{
		Node& neighbor=mmap[p.first];
//		if(p.second<K)
//		{
//			continue;
//		}
		total+=p.second;
		if(neighbor.visit==false)
		{
		    //cout<<"false"<<neighbor.name<<endl;
			//node.weight+=p.second;
			cnt+=dfs_visit(neighbor);
		}
	}
	if(max_w<node.weight)
	{
		head=node.name;
		max_w=node.weight;
	}
	return cnt;
}


