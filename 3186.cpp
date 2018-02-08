#include<iostream>
using namespace std;
string s1,s2,s3;
int l1,l2,ans=0,fir=0;
int main()
{
	cin>>s1;
	getchar();
	getline(cin,s2);
	l1=s1.length();l2=s2.length();
	for(int i=0;i<s1.length();i++)if(s1[i]>='A'&&s1[i]<='Z')s1[i]=s1[i]-'A'+'a';
    for(int i=0;i<s2.length();i++)if(s2[i]>='A'&&s2[i]<='Z')s2[i]=s2[i]-'A'+'a';
	for(int i=0;i<l2;i++)
	{
		s3="";
		int j=i;
		if(s2[i]==' ')continue;
		while(s2[i]!=' '&&i<l2){s3=s3+s2[i];i++;}
		if(s1==s3){ans++;if(!fir)fir=j;}
	}
	if(!ans)cout<<-1<<endl;
	else cout<<ans<<" "<<fir;
	return 0;
}