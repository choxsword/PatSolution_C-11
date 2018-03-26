#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using Vec=vector<int>;
using VecIt=vector<int>::iterator;

Vec vec;
Vec result;
void get_id(const VecIt&first,const VecIt&last,int no);
int main()
{
	
	int cnt_node;
	cin>>cnt_node;
	vec.reserve(cnt_node);
	result.resize(cnt_node+1);
	for(int i=cnt_node;i>0;--i)
	{
		int node;
		cin>>node;
		vec.push_back(node);
	}
	sort(vec.begin(),vec.end());
	
	get_id(vec.begin(),vec.end(),1);
	
	auto end=--result.end();
	for(auto it=result.begin()+1;it!=end;++it)
	{
		printf("%d ",*it);
	}
	printf("%d",*end);
}


void get_id(const VecIt&first,const VecIt&last,int no)
{
	//cout<<"OHOH"<<endl; 
	int cnt_node=last-first;
	//cout<<cnt_node<<endl;
	if(cnt_node==1)
	{
		result[no]=*first;
	//	cout<<*first<<endl;
		return;
	}
	else if(cnt_node==0)
	{
		return;
	}
	int level=log(cnt_node)/log(2)+1;
	//cout<<level<<endl;
	int leaf=cnt_node-(pow(2,level-1)-1);
	int half=leaf-pow(2,level-2);
	//cout<<half<<endl;
	int cnt_right=pow(2,level-2)-1+max(0,half);
	int root=cnt_node-cnt_right;
	result[no]=*(first+root-1);
	//cout<<result[no]<<endl;
	get_id(first,first+root-1,2*no);
	get_id(first+root,last,2*no+1);

}
