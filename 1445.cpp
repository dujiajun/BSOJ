#include<iostream>
using namespace std;
int a[6001][3]={0},f[6001][2]={0},n,usd[6001][2]={0},root=0,l,k;
int find(int i,int y)
{
	int t,sum=0;
    if(usd[i][y]==true)return f[i][y];
    switch(y)
    {
    	case 1:
    		t=a[i][1];
        	while(t){sum+=find(t,0);t=a[t][2];}
        	f[i][y]=sum+a[i][0];usd[i][y]=1;
        	return f[i][y];
    	case 0:
    		t=a[i][1];
        	while(t){sum+=max(find(t,1),find(t,0));t=a[t][2];}
        	f[i][y]=sum;usd[i][y]=1;
        	return f[i][y];
    }
}
void init()
{
	int t;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i][0];
    while(true)
    {
        cin>>l>>k;
        if(l==0||k==0)break;
        if(root==0||root==l)root=k;
        if(a[k][1]==0){a[k][1]=l;continue;}
        t=a[k][1];
        while(a[t][2])t=a[t][2];
        a[t][2]=l;        
    } 
}
int main()
{
    init();
    cout<<max(find(root,0),find(root,1));
}