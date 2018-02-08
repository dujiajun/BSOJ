#include<iostream>
#include<algorithm>
using namespace std;
struct line{int bg,ed;};
bool cmp(line a,line b){return a.ed<=b.ed;}
int main()
{
	int n;
 	cin>>n;
 	int a[101];
 	a[1]=1;
 	int i=1,j=1;
 	cout<<a[1]<<" ";
 	for(int k=2;k<=n;k++)
 	{
 		if(a[i]*2+1<a[j]*3+1){a[k]=a[i]*2+1;i++;}
 		else {a[k]=a[j]*3+1;j++;if((a[i]*2+1)==(a[j]*3+1))i++;}
	 	cout<<a[k]<<" ";
 	}
	return 0;
}
