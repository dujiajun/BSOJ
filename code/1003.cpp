#include<iostream>
using namespace std;
int main(){
	int n,pk[55],link[110];
	cin>>n;
	for(int i=1;i<=n;i++)link[i]=i;
	int h=0,t=n;
	for(int i=1;i<=n;i++)
	{
		pk[link[++h]]=i;
		link[++t]=link[++h];
		link[++t]=link[++h];
	}
	for(int i=1;i<=n;i++)cout<<pk[i]<<" ";
	return 0;
}