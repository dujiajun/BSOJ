#include<iostream>
using namespace std;
string key,cvt,src;
bool down[10005];
char change(char c1,char c2)
{
	if(c1>='a'&&c1<='z')c1=c1-'a'+'A';
	if(c2>='a'&&c2<='z')c2=c2-'a'+'A';
	char c='A'+(c1-c2);
	if(c>'Z')c=c-26;
	if(c<'A')c=c+26;
	return c;
}
int main()
{
	cin>>key>>cvt;src=cvt;
	for(int i=0;i<cvt.length();i++)if(cvt[i]>='a'&&cvt[i]<='z')down[i]=1;
	for(int i=0,j=0;i<cvt.length();i++)
	{
		src[i]=change(cvt[i],key[j]);
		if(down[i]==1)src[i]=src[i]-'A'+'a';
		j++;
		if(j==key.length())j=0;
	}
	cout<<src<<endl;
	return 0;
}