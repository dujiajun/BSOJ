#include<iostream>
#include<cstring>
using namespace std;
int c[200000],a[200000],k=3,n,t=0;;
void num(int x)
{
    for(int i=1;i<=c[0];i++)c[i]=c[i]*x;
    for(int i=1;i<=c[0]+7;i++){c[i+1]+=c[i]/10;c[i]%=10;}
    c[0]=c[0]+7;
    while(c[c[0]]==0)c[0]--;
}
int main()
{  
	memset(c,0,2000);
    cin>>n;
    while(1)
    {    
		if(n-k>=0)a[t++]=k;else break;
        n-=k;
    }
    k=t-1;
    if(n==1)a[k]++;
    if(n==2)a[++k]=n;
    n=1;c[1]=1;c[0]=1;
    for(int i=0;i<=k;i++)
    {   
		n*=a[i];
       	if(n>100000){num(n);n=1;}
    }
    num(n);
    for(int i=c[0];i>=1;i--)cout<<c[i];  
}