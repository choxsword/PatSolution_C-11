#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int cnt;
	//¥Ê¥¢ ‰»Î 
	cin>>cnt;
	vector<int> in;
	in.reserve(1000);
	for(int k=cnt;k>0;--k)
	{
		int num;
		cin>>num;
		in.push_back(num);
	}
	vector<int> rank=in;
	//≈≈–Ú 
	int size=in.size();
	vector<int> lmax(size);
	vector<int> rmin(size);
	lmax[0]=-1;rmin[size-1]=2e9;
	for(int i=1;i<size;++i)
	{
		lmax[i]=(in[i-1]>lmax[i-1])?in[i-1]:lmax[i-1];
	}
	for(int i=size-2;i>=0;--i)
	{
		rmin[i]=(in[i+1]<rmin[i+1])?in[i+1]:rmin[i+1];
	}
	int cnt_pivot=0;
	vector<int> result;
	for(int i=0;i<size;++i)
	{
		if(in[i]>lmax[i]&&in[i]<rmin[i])
		{
			++cnt_pivot;
			result.push_back(in[i]);
		}
		
	}

	if(cnt_pivot!=0)
	{
		printf("%d\n",cnt_pivot);
		for(int k=0;k<cnt_pivot-1;++k)
		{
			printf("%d ",result[k]) ;
		}
		printf("%d\n",result[cnt_pivot-1]);
	}
	else
	{
		cout<<0<<endl<<endl;
	}
}
