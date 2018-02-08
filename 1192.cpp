#include<iostream>
using namespace std;
int wid[1000]={0},dep=0,a[1000]={0},n;
void count(int root,int k)
{ 
	if(dep<k)dep=k;
	for(int i=1;i<=n;i++)
	if(a[i]==root){wid[k+1]++;count(i,k+1);}
}
int main()
{  
	int root=1,x,y,mwid=0;
	cin>>n;
	wid[1]=1;
	for(int i=1;i<=n;i++){cin>>x>>y;a[x]=y;}
	for(int i=1;i<=n;i++)if(a[i]==0)root=i;
	count(root,1);
	for(int i=1;i<=dep;i++)if(wid[i]>mwid)mwid=wid[i];   
	cout<<dep<<" "<<mwid;
	return 0;
}
