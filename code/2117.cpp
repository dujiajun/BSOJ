#include<iostream>
using namespace std;
const int JC[10]={0,1,2,6,24,120,720,5040,40320};
struct node{int a[2][54],op,prt,t;}ed,q[90005];
int res,len[90005],prt[90005];
bool vst[400000];
char ans[90005];
int kang(node x)
{	
	int t,sum=0,b[10];
	for(int i=0;i<4;i++){b[i]=x.a[0][i];b[7-i]=x.a[1][i];}
	for(int i=0;i<8;i++)
	{ 
		t=0;
	  	for(int j=i+1;j<8;j++)if(b[j]<b[i])t++;
	  	sum+=JC[7-i]*t;
	}
	return sum;
}
node change(node x,int w)
{	
	node tmp;
	if(!w)
	{ 
		for(int i=0;i<4;i++)
	  	{ 
		  	tmp.a[1][i]=x.a[0][i];
	    	tmp.a[0][i]=x.a[1][i];
	  	}
	}
	if(w==1)
	{ 
		tmp.a[0][0]=x.a[0][3];
	  	tmp.a[1][0]=x.a[1][3];
	  	for(int i=1;i<4;i++)
	  	{ 
		  	tmp.a[0][i]=x.a[0][i-1];
			tmp.a[1][i]=x.a[1][i-1];
	  	}
	}
	if(w==2)
	{
		tmp.a[0][0]=x.a[0][0];tmp.a[0][3]=x.a[0][3];
		tmp.a[1][0]=x.a[1][0];tmp.a[1][3]=x.a[1][3];
		tmp.a[0][1]=x.a[1][1];tmp.a[0][2]=x.a[0][1];
		tmp.a[1][1]=x.a[1][2];tmp.a[1][2]=x.a[0][2];
	}
	return tmp;
}
void out(int x)
{	
	if(x==1)return;
	out(q[x].prt);
	printf("%c",q[x].op+'A');
}
void bfs()
{	
	for(int i=0;i<4;i++)
	{ 
		q[1].a[0][i]=i+1;
	  	q[1].a[1][i]=8-i;
	}
	vst[kang(q[1])]=1;
	res=kang(ed);
	if(vst[res]){cout<<0<<endl;return;}
	int l=1,r=1,tmp;node x;
	while(l<=r)
	{ 
	  	for(int i=0;i<3;i++)
	  	{ 
		  	x=change(q[l],i);tmp=kang(x);
	    	if(!vst[tmp])
	    	{ 
				vst[tmp]=1;
				q[++r]=x;q[r].prt=l;
	      		q[r].t=q[l].t+1;q[r].op=i;
	      		if(tmp==res)
				{
				  	cout<<q[r].t<<endl;
					out(r);
					return;
				}
	    	}
	  	}
	  	l++;
	}
}
int main()
{
	for(int i=0;i<4;i++)cin>>ed.a[0][i];
	for(int i=3;i>=0;i--)cin>>ed.a[1][i];
	bfs();
	return 0;
}