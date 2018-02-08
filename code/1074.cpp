#include<iostream>
#include<string>
using namespace std;
int t,bj=1;
string a,b,rule[7][2];
void dfs(int deep,string s,int last)
{
    if(deep==0){if(s==b)bj=false;return;}
    int pos;string tmp;
    for(int i=1;i<=t;i++)
    {
      	pos=max(0,last-(int)rule[i][0].length()+1);
      	while(true)
      	{   
		  	pos=s.find(rule[i][0],pos);
          	if(pos==-1)break;
          	tmp=s;
          	tmp.replace(pos,rule[i][0].length(),rule[i][1]);
          	dfs(deep-1,tmp,pos);
          	if(!bj)return;
          	pos++;                
      	}
    }
}
int main()
{    
    cin>>a>>b;
    int i=1;
    while(cin>>rule[i][0]>>rule[i][1])i++;
    t=i-1; 
    for(i=0;i<=10&&bj;i++)
    dfs(i,a,0);
    if(bj)cout<<"NO ANSWER!";
    else cout<<i-1;
}                       