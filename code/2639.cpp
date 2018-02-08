#include<iostream>
using namespace std;
int num[50010]={0},c[50010]={0},f[50010]={0};
int a0,a1,b0,b1,n,ans=0,k=0,ss=0;
void getyin(int x)
{
    int i=2;k=0;
    while(i*i<=x)
    {
    	if(x%i==0){k++;num[k]=i;c[k]=0;}
        while(x%i==0)c[k]++,x/=i; 
        i++;
    }
    if(x>1)num[++k]=x,c[k]=1;
}
int gcd(int a,int b)
{
	if(a<b)swap(a,b);
   	if(b==0)return a;
   	return gcd(b,a%b);   
}
void dfs(int x,int h)
{
    if(h>k){f[++ss]=x;return;}
    dfs(x,h+1);
    for(int i=1;i<=c[h];i++){x*=num[h];dfs(x,h+1);}
}
void solve()
{
    cin>>a0>>a1>>b0>>b1;
    getyin(b1);
    ss=0;ans=0;
    dfs(1,1);
    for(int i=1;i<=ss;i++)
    {
    	int t=gcd(f[i],b0);
        if(gcd(f[i],a0)==a1&&f[i]/t*b0==b1)ans++;
    }
    cout<<ans<<endl;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)solve();
	return 0;
}