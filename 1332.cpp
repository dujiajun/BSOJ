#include<iostream>
using namespace std;
int n,m,pr[1005],k=0,cnt=0;
bool vst[1000005];
void make_pr()
{
	vst[1]=1;
	for(int i=2;i<=1000;i++)
	for(int j=i*i;j<=1000000;j+=i)vst[j]=1;
}
int main()
{
	make_pr();
	while(cin>>n>>m)
	{
		cnt=0;
		for(int i=n;i<=m;i++)if(!vst[i])cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}