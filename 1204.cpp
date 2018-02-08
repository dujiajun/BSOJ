#include<iostream>
#include<cstring>
using namespace std;
int n,k;
int hashnine[10][10]={0},hashx[10][10]={0},hashy[10][10]={0};
int x[10]={0,0,0,0,1,1,1,2,2,2},y[10]={0,1,1,1,2,2,2,3,3,3};
bool sovle()
{
	bool flag=true;
	memset(hashnine,0,sizeof(hashnine));
	memset(hashx,0,sizeof(hashx));
	memset(hashy,0,sizeof(hashy));
	for(int i=1;i<=9;i++)
	for(int j=1;j<=9;j++)
	{
		cin>>k;
		hashnine[x[i]*3+y[j]][k]++;
		hashx[j][k]++;hashy[i][k]++;
		if(hashnine[x[i]*3+y[j]][k]>1||hashx[j][k]>1||hashy[i][k]>1)
			flag=false;
	}
	if(flag)return true;
	else return false;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(sovle())cout<<"Right"<<endl;
		else cout<<"Wrong"<<endl;
	}
	return 0;
}