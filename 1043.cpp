#include<iostream> 
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
using It=vector<int>::iterator;
stack<int> my_stack;
bool get_post(const It& first,const It& last,bool is_origin);
int main()
{
	int cnt;
	cin>>cnt;
	vector<int> vec;
	
	for(int i=cnt;i>0;--i)
	{
		int num;
		cin>>num;
		vec.push_back(num);
	}
	if(cnt==1)
	{
		printf("YES\n%d",vec[0]);
	}
	else if(cnt==2)
	{
		printf("YES\n%d %d",vec[0],vec[1]);
	}
	else
	{
		bool is_BST=false;

		is_BST=get_post(vec.begin(),vec.end(),vec[1]<vec[0]);

		if(is_BST)
		{
			printf("YES\n");
			while(my_stack.size()!=1)
			{
				printf("%d ",my_stack.top());
				my_stack.pop();
			}
			printf("%d",my_stack.top());
		} 
		else
		{
			printf("NO");
		}
	}
	
}

bool get_post(const It& first,const It& last,bool is_origin)
{
	if(first!=last)
	{
		my_stack.push(*first);
	}
	else
	{
		return true;
	}
	
	auto left_end=find_if(first+1,last,[&](int it){return is_origin?(it>=*first):(it<*first);});
	auto test=left_end;
	if(is_origin)
	{
		while(test!=last)
		{
			if(*test<*first)
			{
				return false;
			}
			++test;
		}
	}
	else
	{
		while(test!=last)
		{
			if(*test>=*first)
			{
				return false;
			}
			++test;
		}
	}

	if(!get_post(left_end,last,is_origin))
	{return false;}
	if(!get_post(first+1,left_end,is_origin))
	{return false;}
	return true;
}
