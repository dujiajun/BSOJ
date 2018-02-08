#include<iostream>
using namespace std;

int main()
{
	string n;
	int s,max=0,k=0;
	cin>>n>>s;
	int len=n.length();
	for(int i=0;i<s;i++)
	{
		for(int j=0;j<len-1;j++)
		if(n[j]>n[j+1]){for(k=j;k<len-1;k++)n[k]=n[k+1];break;}
		len--;
	}
	k=0;
	while(n[k]=='0')k++;
	for(;k<len;k++)
	{cout<<n[k];}
	return 0;
}
