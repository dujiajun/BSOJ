#include<iostream>
#include<cmath>
using namespace std;
int a,num,t;
long long sum1,sum2,tmp,k;
long long gcd(long long x,long long y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
void solve()
{
	cin>>a;
	num=0;sum1=0;sum2=0;
	for(int i=1;i<=a;i++)
	for(int j=1;j<=i;j++)
	{
		tmp=a*a+(i+j)*(i+j);
		k=sqrt(tmp);
		if(tmp==k*k)
		{
			sum1+=tmp;
			num++;
			sum2+=a*a+i*i+j*j;
		}
	}
	if(num==0)
	{
		cout<<"NULL/NULL NULL/NULL"<<endl;
		return;
	}
	long long x=gcd(sum1,num),y=gcd(sum2,num);
	cout<<sum1/x<<"/"<<num/x<<" "<<sum2/y<<"/"<<num/y<<endl;
}
int main()
{
	cin>>t;
	while(t--)solve();
	return 0;
}