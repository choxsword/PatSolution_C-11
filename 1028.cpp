#include<iostream> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


struct Record
{
	int id;
	string name;
	int grade;
	Record(int&_id,string& _name,int& _grade):id(_id),name(std::move(_name)),grade(_grade){
	}
};

struct CmpId:public binary_function<Record,Record,bool>
{
	bool operator()(const Record&lhs,const Record&rhs)
	{
		return (lhs.id<rhs.id);
	}
};
struct CmpName:public binary_function<Record,Record,bool>
{
	bool operator()(const Record&lhs,const Record&rhs)
	{
		if(lhs.name!=rhs.name)
		{
			return (lhs.name<rhs.name);
		}
		else
		{
			return (lhs.id<rhs.id);
		}
	}
};
struct CmpGrade:public binary_function<Record,Record,bool>
{
	bool operator()(const Record&lhs,const Record&rhs)
	{
		if(lhs.grade!=rhs.grade)
		{
			return (lhs.grade<rhs.grade);
		}
		else
		{
			return (lhs.id<rhs.id);
		}
	}
};


int main()
{
	int records,column;
	cin>>records>>column;
	vector<Record> vec;
	for(int i=records;i>0;--i)
	{
		int id,grade;string name;
		cin>>id>>name>>grade;
		vec.emplace_back(id,name,grade);
	}
	
	switch(column)
	{
		case 1:sort(vec.begin(),vec.end(),CmpId());break;
		case 2:sort(vec.begin(),vec.end(),CmpName());break;
		case 3:sort(vec.begin(),vec.end(),CmpGrade());break;		
		default:throw 0;
	}
	
	//Êä³ö
	 for(auto i:vec) 
	 {
	 	printf("%06d %s %d\n",i.id,i.name.c_str(),i.grade);
	 }
	
}
