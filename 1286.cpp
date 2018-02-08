#include<iostream>
#include<cstdlib>
using namespace std;
string s;char t[1005];
int ans=0,len,a[27]={0};
void dfs(int k)
{   int i,j;
    if(k==len)
    {   
		ans++;
        if(t==s){cout<<ans<<endl;exit(0);}
    }
    for(int i=1;i<=26;i++)
    if(a[i])
    {   
		t[k]=char(i-1+'a');
        a[i]--;
        dfs(k+1);
        a[i]++;
    }
}
int main()
{
    cin>>s;
    len=s.length();
    for(int i=0;i<len;i++)a[s[i]-'a'+1]++;
    dfs(0);
    return 0;
}