#include<iostream>
using namespace std;
int n,v[21][21],f[21],p[21],t,maxx=0;
int main()
{  
   	cin>>n;
   	for(int i=1;i<=n;i++)cin>>f[i];
   	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)cin>>v[i][j];
   	f[0]=0;
   	p[n]=0;
   	for(int i=n-1;i>0;i--)
   	{  
	   	maxx=0;
      	for(int j=i+1;j<=n;j++)if(v[i][j]&&f[j]>f[maxx])maxx=j;               
        f[i]+=f[maxx];             
        p[i]=maxx;             
    }
    for(int i=1;i<=n;i++)if(f[i]>f[maxx])maxx=i;
    t=maxx;
    while(1)
    {  
		if(p[t]==0){cout<<t<<endl;break;}
       	cout<<t<<"-";
       	t=p[t];
    }
    cout<<"max="<<f[maxx];
}