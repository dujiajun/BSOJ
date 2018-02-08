#include<iostream>
using namespace std;
int n,k;
char a[200];
int main()
{
	cin>>n>>k;
	int i=1;
	while(n)
	{
		int l=n%k;
		n/=k;
		if(l<0){l-=k;n++;}
		if(l<10)a[i]='0'+l;
		else
		{
			l-=10;
			a[i]='A'+l;
		}
		i++;
	}
	for(int j=i-1;j>=1;j--)cout<<a[j];
	return 0;
}