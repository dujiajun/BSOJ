#include<iostream>
#include<cstdio>
using namespace std;
int n,prt[1000010],vst[1000010]={0};
int getfa(int x)
{  
	if(prt[x]==x)return x;
	prt[x]=getfa(prt[x]);
   	return prt[x];
}
int main()
{  
	cin>>n;
   	for(int i=1;i<=10001;i++)prt[i]=i;
   	for(int i=1,x,y;i<=n;i++)
   	{  
	   	scanf("%d%d",&x,&y);
      	x=getfa(x);y=getfa(y);
      	if(x==y)vst[x]=1;
        else
		{  
			if(x>y)swap(x,y);
            prt[x]=y;
            vst[x]=1;
        }
   	}
   	for(int i=1;i<=10001;i++)if(!vst[i]){cout<<i-1<<endl;break;}
   	return 0;
}
