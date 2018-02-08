#include<iostream>
using namespace std;
int n,a[105][105]={0},q[105],into[105]={0};
void init()
{
	int x,y;
	cin>>n;
	while(cin>>x>>y){a[x][y]=1;into[y]++;}
}
bool topsort()
{
	int j;
	for(int i=1;i<=n;i++)
	{
		j=1;
		while(j<=n&&into[j]>0)j++;
		if(j>n)return false;
		q[i]=j;into[j]=0x7fffffff;
		for(int k=1;k<=n;k++)if(a[j][k])into[k]--;
	}
	return true;
}
int main()
{
	init();
	if(topsort())
		for(int i=1;i<=n;i++)cout<<q[i]<<" ";
	else cout<<"No answer"<<endl;
	return 0;
}