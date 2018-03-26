#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

namespace xzj
{
	vector<int> sorting;
	using It=vector<int>::iterator;
	
	bool check_max(int pos,int end)
	{
		if(sorting[2*pos+1]>=end)
			return true;
		else
		{
			if(sorting[2*pos+1]>sorting[pos])
				return false;
		}
		
		if(sorting[2*pos+2]>=end)
			return true;
		else
		{
			if(sorting[2*pos+2]>sorting[pos])
			{
				//cout<<sorting[2*pos+2]<<' '<<sorting[pos]; 
				return false;
			}
				
		}
		return true;	
	}
	void in_sort(int N)
	{
		int end=0;
		while((end+1)<N&&sorting[end]<=sorting[end+1]) 
			++end;
		
		int next=end+1;
		while(next>0&&sorting[next]<=sorting[next-1])
		{
			swap(sorting[next],sorting[next-1]);
			--next;
		}
	}
	void heap_sort(int begin,int end)
	{
		if(end-1==0)
			return;
		while(begin*2+1<end)
		{
			int mmax=max(sorting[begin],sorting[2*begin+1]);
			if(begin*2+2<end)
			{
				mmax=max(mmax,sorting[2*begin+2]);
				if(mmax==sorting[2*begin+2])
				{
					swap(sorting[begin],sorting[2*begin+2]);
					begin=2*begin+2; 
					continue;
				}
			}
			if(mmax==sorting[2*begin+1])
			{
				swap(sorting[begin],sorting[2*begin+1]);
				begin=2*begin+1; 
			}
			else
				break;
		}
		
	}
	bool check()
	{
		int max=sorting[0];
		auto&& end=find_if(sorting.begin(),sorting.end(),[&](int&i){return i>max;});
		if(end==sorting.end())
			return false;
		else
		{
			auto it=end;
			while((it+1)!=sorting.end()&&(*it<*(it+1)))
				++it;
			if((it+1)!=sorting.end())
				return false;
		}
		
		int num=end-sorting.begin();
		for(int i=0;i<num;++i)
		{
			if(check_max(i,num)==false)
				return false;
		}
		swap(sorting[0],sorting[num-1]);
		heap_sort(0,num-1);
		return true;
	}
	
}
int main()
{
	using namespace xzj;
	int N;//¸öÊý
	cin>>N;
	vector<int> input;
	input.reserve(N);
	for(int i=N;i>0;--i) 
	{
		int num;
		cin>>num;
		input.push_back(num);
	}
	
	sorting.reserve(N);
	for(int i=N;i>0;--i) 
	{
		int num;
		cin>>num;
		sorting.push_back(num);
	}
	bool is_heap=check();
	is_heap?printf("Heap Sort\n"):printf("Insertion Sort\n");
	
	if(!is_heap)
	{
		in_sort(N);
	}	

	auto&& end=sorting.end()-1;
	for(auto it=sorting.begin();it!=end;++it)
	{
		printf("%d ",*it);
	}
	printf("%d\n",*end);
}
