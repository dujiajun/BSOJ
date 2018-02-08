#include<iostream>
using namespace std;
int a[101][3]={0},f[101][2]={0},n,usd[101][2]={0},root=0,l,k,b[101]={0},c[101]={0};
string s1[101],s2[101];
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
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>s1[i]>>a[i][0]>>s2[i];
}
void solve()
{
	int t;
	for(int i=1;i<=n;i++)
	{
		b[i]=i;
		for(int j=1;j<=n;j++)if(s2[i]==s1[j])c[i]=j;
	}
	for(int i=1;i<=n;i++)
		if(b[i]==0)root=i;
    for(int i=1;i<=n;i++)
    {
    	l=b[i],k=c[i];
        if(a[k][1]==0){a[k][1]=l;continue;}
        t=a[k][1];
        while(a[t][2])t=a[t][2];
        a[t][2]=l;        
    } 
    cout<<max(find(root,0),find(root,1));
}
int main()
{
    init();
    solve();
}
/*
5
BART 1 HOMER
HOMER 2 MONTGOMERY
MONTGOMERY 1 NOBODY
LISA 3 HOMER
SMITHERS 4 MONTGOMERY
*/