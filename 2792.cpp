#include<iostream>
using namespace std;
int a[51],b[51];
int main()
{
 	int n,m,i=0,j=0,flag=0;
 	cin>>n>>m;
 	a[0]=n/m;
 	b[0]=n%m;
 	while(i<=50&&b[i]!=0)
 	{
 		i++;
 		a[i]=b[i-1]*10/m;
 		b[i]=b[i-1]*10%m;
 		if(b[i]==0)break;
 		j=0;
 		while(b[j]!=b[i])j++;
 		if(j<i){flag=1;break;}
 	}
 	cout<<a[0];
 	if(!(i==0&&flag==0))
 	{
 		cout<<".";
 		if(flag==0)
 		for(int k=1;k<=i&&k<=50;k++)cout<<a[k];
		 else
		 {
 		 for(int k=1;k<=j;k++)cout<<a[k];
  		 cout<<"(";
  		 for(int k=j+1;k<=i;k++)cout<<a[k];
  		 cout<<")";
	   	 }
	 }
	return 0;
}
