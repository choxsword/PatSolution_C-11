#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
#include<unordered_set>
using namespace std;


struct Disjoint
{
	int id;
	int father=-1;
	int mother=-1;
	vector<int> child;
	double area=0.0;
	double set=0.0;
	// ADT
	int parent;
	int rank=0;
};
struct Family
{
	//int cnt=0;
	double set=0.0;
	double area=0.0;
	int min_id=numeric_limits<int>::max();
	unordered_set<int> mem;
};
bool operator <(const Family&lhs,const Family&rhs) 
{
	double a=lhs.area/lhs.mem.size();
	double b=rhs.area/rhs.mem.size();
	int avl=a*1000;
	int avr=b*1000;
	if( avl==avr )
	{
		return lhs.min_id<rhs.min_id;
	}
	else if(avl<avr)
	{
		return !true;
	}
	else
	{
		return !false;
	}
}

//vector<Disjoint> forest;
unordered_map<int,Disjoint> forest;
unordered_map<int,Family> result;
namespace func
{
	int find(int i)
	{
		int root;
		Disjoint&node=forest[i];
		if(node.id!=node.parent)
		{
			root=find(forest[node.parent].id);
		}
		else
		{
			root=node.id;
		}
		//if(root==0){cout<<i<<' '<<"shit"<<endl;}
		return root;
	}
	
	void calculate(Disjoint&node)
	{
		int root=find(node.id);
		Family&f=result[root];
		f.mem.insert(node.id);
		f.set+=node.set;
		f.area+=node.area;
		f.min_id=min(f.min_id,node.id);
		for(auto&i:node.child)
		{
			f.min_id=min(f.min_id,i);
		}
		if(node.father!=-1)
		{
			f.min_id=min(f.min_id,node.father);
		}
		if(node.mother!=-1)
		{
			f.min_id=min(f.min_id,node.mother);
		}
	} 
	
	
	void join(int x,int y)
	{
		if(y==-1)
		{
			return;
		}
		//cout<<x<<' '<<y<<endl;
		int id_x=find(forest[x].id);
		int id_y=find(forest[y].id);
//		if(id_x==0||id_y==0)
//		{
//			cout<<"mmp"<<forest[x].id<<forest[y].id<<endl;
//		}
		if(id_x==id_y)
		{
			return;
		}
		Disjoint&root_x=forest[id_x];
		Disjoint&root_y=forest[id_y];
		if(root_x.rank<root_y.rank)
		{
			root_x.parent=root_y.id;
		}
		else
		{
			root_y.parent=root_x.id;
			if(root_x.rank==root_y.rank)
			{
				++root_x.rank;
			}
		}
		
	}
}
int main()
{
	using namespace func; 
	int N;//ÌõÄ¿Êý
	cin>>N;
	for(int i=N;i>0;--i)
	{
		Disjoint node;
		cin>>node.id>>node.father>>node.mother;
		int cnt_child;
		cin>>cnt_child;
		for(int j=cnt_child;j>0;--j)
		{
			int id;
			cin>>id;
			node.child.push_back(id);
			forest[id].id=id;
			forest[id].parent=id;
		}
		if(node.father!=-1)
		{
			forest[node.father].id=node.father;
			forest[node.father].parent=node.father;
		}
		if(node.mother!=-1) 
		{
			forest[node.mother].id=node.mother;
			forest[node.mother].parent=node.mother;
		}
		
		node.parent=node.id;
		cin>>node.set>>node.area;
		forest[node.id]=move(node);
	}

	//cout<<"shit"<<endl;
	for(auto&p:forest)
	{
		Disjoint& node=p.second;
		join(node.id,node.father);
		join(node.id,node.mother);
		//cout<<"fuck"<<node.id<<endl;
		for(auto&child_id:node.child)
		{
//			cout<<child_id<<endl;
//			cout<<"ohoh"<<endl;
			join(node.id,child_id);
			
		}
	}
	

	for(auto&p:forest)
	{
		Disjoint& node=p.second;
		calculate(node);
	}
	
	vector<Family> output;
	for(auto&p:result)
	{
		output.push_back(p.second);
	}
	sort(output.begin(),output.end());
	printf("%d\n",output.size());

	for(auto&i:output)
	{
		int size= i.mem.size(); 
		printf("%04d %d %.3f %.3f\n",i.min_id,size,i.set/size,i.area/size);
	} 
	
}

