#include<iostream>
#include<algorithm>
using namespace std;
struct stn{int n;int c;int m;int e;int s;}s[500];
bool cmp(stn s1,stn s2)
{
	if(s1.s!=s2.s)return s1.s>s2.s;
	if(s1.c!=s2.c)return s1.c>s2.c;
	return s1.n<s2.n;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{cin>>s[i].c>>s[i].m>>s[i].e;s[i].s=s[i].c+s[i].m+s[i].e;s[i].n=i;}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=5;i++)cout<<s[i].n<<" "<<s[i].s<<endl;
	return 0;
}
