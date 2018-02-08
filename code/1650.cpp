#include<iostream>
#include<algorithm>
using namespace std;
struct line{int bg,ed;};
bool cmp(line a,line b){return a.ed<=b.ed;}
int main()
{
 	int n,sum=2;
 	line ln[10001];
 	cin>>n;
 	for(int i=1;i<=n;i++)cin>>ln[i].bg>>ln[i].ed;
 	sort(ln+1,ln+n+1,cmp);
 	int l=ln[1].ed-1,r=ln[1].ed;
	for(int i=2;i<=n;i++)
	{
		if(ln[i].bg>r){sum+=2;l=ln[i].ed-1;r=ln[i].ed;}
		if(ln[i].bg>=l&&ln[i].ed<=r)continue;
		if(ln[i].bg>=l&&ln[i].ed>r&&ln[i].bg<r)
		{
			if(r-ln[i].bg+1>=2){sum+=2;l=ln[i].ed-1;r=ln[i].ed;}
			else 
			{sum++;l=ln[i].ed-1;r=ln[i].ed;}
		}
	}
	cout<<sum;
	return 0;
}
