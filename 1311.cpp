#include<iostream>
using namespace std;
int map[101][101]={0},a[101]={0},in[101]={0},deep[101]={0},m,n;
bool topsort()
{ 
  	for(int i=1;i<=n;i++)
   	{
    	int j=1;
    	while((j<=n)&&(in[j]!=0))j++;
    	if(j>n)return false;
        in[j]++;a[i]=j;
        for(int k=1;k<=n;k++)
        if(map[j][k])in[k]--;
    }
   	return true;
}
void work()
{ 
 	for(int i=2;i<=n;i++)
    for(int j=1;j<=i-1;j++)
    if(map[a[j]][a[i]]+deep[j]>deep[i])deep[i]=map[a[j]][a[i]]+deep[j];
}
int main()
{
  	cin>>n>>m;
  	for(int i=1,x,y,k;i<=m;i++)
   	{
	   	cin>>x>>y>>k;
     	map[x][y]=k;
     	in[y]++;
   	}
  	if(topsort())work();
  	cout<<deep[a[n]]<<endl;
  	return 0;
}
