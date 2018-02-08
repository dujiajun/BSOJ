#include<iostream>
using namespace std;
int n,m,a,x,f[105]={0};
/*
站号             1 2 3   4    5     6     ...  n(n>=3)
斐波拉其数列f[]  1 1 2   3    5     8     ...  f[n-1]+f[n-2]
开车时人数num[]  a a 2a  2a+b 3a+2b 4a+4b ...  (f[n-2]+1)*a+(f[n-1]-1)*b
上车人数in[]     a b a+b a+2b 2a+3b 3a+5b ...  f[n-2]*a+f[n-1]*b
下车人数out[]    0 b b   a+b  a+2b  2a+3b ...  f[n-3]*a+f[n-2]*b  //out[i]==in[i-1];

num[n-1]=m=(f[n-3]+1)*a+(f[n-2]-1)*b;  b=(m-(f[n-3]+1)*a)/(f[n-2]-1);
  num[x]=p=(f[x-2]+1)*a+(f[x-1]-1)*b=(f[x-2]+1)*a+(f[x-1]-1)*(m-(f[n-3]+1)*a)/(f[n-2]-1);
*/
int main()
{
	cin>>a>>n>>m>>x;
	f[1]=1;f[2]=1;
	for(int i=3;i<=n;i++)f[i]=f[i-1]+f[i-2];
	cout<<(f[x-2]+1)*a+(f[x-1]-1)*(m-(f[n-3]+1)*a)/(f[n-2]-1)<<endl;
	return 0;
}

