#include<iostream>
using namespace std;
const int R=0;
const int D=1;
const int RU=3;
const int LD=4; 
int main()
{
      int a[15][15]={1};
      int s=D,dir=0,x=0,y=0,n,i=1;
      cin>>n;
      while(i!=n*n)
      {
      	switch(s)
      	{
      		case R:
      			x++;
      			a[y][x]=++i;
      			s=dir?RU:LD;
      			break;
   			case D:
   				y++;
   				a[y][x]=++i;
   				s=dir?LD:RU;
   				break;
  			case RU:
  				if(y<1&&x==n-1){dir=1;s=D;}
  				else if(y<1)s=R;
  				else if(x==n-1)s=D;
  				else a[--y][++x]=++i;
  				break;
   			case LD:
   				if(x<1&&y==n-1){dir=1;s=R;}
  				else if(x<1)s=D;
  				else if(y==n-1)s=R;
  				else a[++y][--x]=++i;
			   break;	
      	}
      }
      for(int i=0;i<n;i++)
      {
	  for(int j=0;j<n;j++)
      cout<<a[i][j]<<" ";
      cout<<endl;
      }
      return 0;
}