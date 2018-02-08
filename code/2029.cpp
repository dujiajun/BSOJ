#include<iostream>
using namespace std;
string s1;
int n,p[10000];
void get_next(string t)
{
	int j=0;p[1]=0;
	for(int i=2;i<=n;i++)
	{
		while(j>0&&t[i]!=t[j+1])j=p[j];
		if(t[j+1]==t[i])j++;
		p[i]=j;
	}
}
int main()
{
	cin>>s1;
	n=s1.length();
	s1=' '+s1;
	get_next(s1);
	if(n%(n-p[n])==0)cout<<n-p[n]<<endl;
	else cout<<n<<endl;
	return 0;
}