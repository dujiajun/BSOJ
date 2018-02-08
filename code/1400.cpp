#include<iostream>
using namespace std;
const  int   N = 5 ;
const short int Final[N][N]={1,1,1,1,1,0,1,1,1,1,0,0,2,1,1,0,0,0,0,1,0,0,0,0,0};
const short int Fx[8][2]={-2,-1,-1,-2,-2,1,-1,2,1,2,2,1,1,-2,2,-1};
 
int short a[N][N];
int DIFF=0;
int Space_X ,Space_Y;
bool Find_ans; 

void Search(int diff ,int step,int space_x,int space_y)
{
	if(step<diff) return; 
	if(step==0)
	{Find_ans=true;return;}
	int x0,y0 ;
	for(int i=0;i<8;i++)
	{
		x0=space_x+Fx[i][0] ;
		y0=space_y+Fx[i][1] ;
		if(x0<0||x0>=N||y0<0||y0>=N)continue;
		a[space_x][space_y]=a[x0][y0] ;
		a[x0][y0]=2;
		Search(diff+(a[space_x][space_y]==Final[x0][y0])-(a[space_x][space_y]==Final[space_x][space_y]),step-1,x0,y0);
		if(Find_ans)return;
		a[x0][y0]=a[space_x][space_y];
		a[space_x][space_y]=2; 
	}
}
void Init()
{         
	int i,j;
	char c; 
	DIFF=0;
	Find_ans=false ;
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	{
		cin>>c;
		if(c=='*'){a[i][j]=2;Space_X=i;Space_Y=j;}
		else 
		{
			a[i][j]=c-'0';
			if(a[i][j]!=Final[i][j])
			DIFF++;
		}
	}      
}
int main()
{ 
	int Cas,Maxstep; 
	cin>>Cas;
	while(Cas)
	{
		Init();  
		for(Maxstep=DIFF;Maxstep<=15&&!Find_ans;Maxstep++)
		Search(DIFF,Maxstep,Space_X,Space_Y);       
		if(Find_ans)cout<<Maxstep-1<<endl; 
		else cout<<-1<<endl;  
		Cas--;
	}
	return 0;
}