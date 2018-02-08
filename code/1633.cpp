#include<iostream>
#include<cstring>
using namespace std;
string s;
int f[81][81]={0},len,last=1,flag=0;
bool cmp(int i,int j,int x,int y)
{
	while (s[i]=='0'&&i<j)i++;
	while (s[x]=='0'&&x<y)x++;
	if (j-i<y-x)return 1;
	if (j-i>y-x)return 0;
	for(int k=0;k<=j-i;k++)
 	{
  		if(s[i+k]<s[x+k])return 1;;
  		if(s[i+k]>s[x+k])return 0;
 	}
	return 0;
}
void print(int x,int y)
{
	if (y==1) 
    {   
      	for(int i=1;i<=x;i++)cout<<s[i];
      	if(x<len)cout<<",";
    }
    else
    {
    	print(f[x][y]-1,y-1);
   		for(int i=f[x][y];i<=x;i++)cout<<s[i];
   		if(x<len)cout<<",";
    }
}
int main()
 {
 	cin>>s; 
 	len=s.length();
 	s=' '+s;
	for(int i=1;i<=len;i++)f[i][1]=1;
	for(int i=2;i<=len;i++) 
   	for(int j=2;j<=i;j++)
    {
    	flag=false;
      	for(int k=j;k<=i;k++) 
        if(cmp(f[k-1][j-1],k-1,k,i)&&f[k-1][j-1]!=-1)
        {
        	f[i][j]=k;
            flag=true;
        }
      	if(flag)last=j;else f[i][j]=-1;
  	}
	for(int i=len;i>=1;i--)
   		if(f[len][last]<=f[len][i])last=i;
	print(len,last);
	return 0;
}