#include<iostream>
using namespace std;
int x,y,ans=0;
struct node{int x,y,a;}c[101];
bool judge(int sa,int sx,int sy,int dep,int k)
{
    int temp,i;
    switch(k)
    {
             case 1:if(sa==0||sx==x)return false;break;
             case 2:if(sa==0||sy==y)return false;break;
             case 3:if(sx==0)return false; break;     
             case 4:if(sx==0||sy==y)return false;break;
             case 5:if(sy==0)return false; break;
             case 6:if(sy==0||sx==x)return false;break;
    }
    switch(k)
    {
             case 1:
			 	temp=sa+sx;sx=min(temp,x);sa=temp-sx;
				break;
             case 2:
			 	temp=sa+sy;sy=min(temp,y);sa=temp-sy;
				break;
             case 3:
			 	sa+=sx;sx=0;
				break;            
             case 4:
			 	temp=sx+sy;sy=min(temp,y);sx=temp-sy;
				break;
             case 5:
			 	sa+=sy;sy=0;
				break;            
             case 6:
			 	temp=sx+sy;sx=min(temp,x);sy=temp-sx;
				break;
    }
    for(i=1;i<=dep;i++)
    	if(c[i].x==sx&&c[i].y==sy&&c[i].a==sa)return false;
    c[dep+1].x=sx;c[dep+1].y=sy;c[dep+1].a=sa;
    return true;
}

void divide(int deep)
{
     if((c[deep].a==(x+y)/2)&&(c[deep].x==(x+y)/2))ans++;
     for(int i=1;i<=6;i++)
	 	if(judge(c[deep].a,c[deep].x,c[deep].y,deep,i))
	 		divide(deep+1);
}
int main()
{
    cin>>x>>y;
    c[1].a=x+y;c[1].x=c[1].y=0;
    divide(1);
    if(ans==0)cout<<"NO";
    else cout<<ans;
    return 0;
}