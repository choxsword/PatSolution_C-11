
#include<string>
#include<iostream>
#include<stack>
using namespace std;
void output(int value)
{
  stack<char> result;
  string s_value=to_string(value);
  int count=0;
  for(auto it=s_value.rbegin();it!=s_value.rend();)
  {
   if(++count%4==0)
   {
     if(*it!='-')
     {
       result.push(',');
        continue;
     }
     else
     {
       result.push('-');
       break;
     }
   }
  else
    {
      result.push(*it);
      ++it;
    }
  }

while(result.empty()==false)
{
    cout<<result.top();
    result.pop();

}
  
}
int main()
{
  int a,b;
  cin>>a>>b;
  int c=a+b;
  output(c);
  return 0;
}
  
