#include<iostream>
#include<cstring>
using namespace std;
string s;int n,p[1000005];
void getp()
{
	p[1]=0;int j=0;
	for(int i=2;i<=n;i++)
	{
	    while(j&&s[j+1]!=s[i])j=p[j];
		if(s[j+1]==s[i])j++;
		p[i]=j;
	}
}
void kmp(int x)
{
	cin>>s;
	s=' '+s;
	getp();
	cout<<"Test case #"<<x<<endl;
	for(int i=2;i<=n;i++)
	    if(p[i]&&i%(i-p[i])==0)
            cout<<i<<" "<<i/(i-p[i])<<endl;
	cout<<endl;
}
int main()
{
 	for(int i=1;;i++)
 	{
 		cin>>n;
	 	if(n==0)break;
	 	kmp(i);
 	}
	return 0;
}