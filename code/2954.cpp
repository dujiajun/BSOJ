#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1000005;
string s;int p[maxn],len;
void getp()
{  
   p[1]=0;int j=0;
   for(int i=2;i<=len;i++)
   {  
   	  while(j>0&&s[j+1]!=s[i])j=p[j];
      if(s[j+1]==s[i])j++;
      p[i]=j;
   }
}
int main()
{  
   while(1)
   {  
   	  cin>>s;
   	  len=s.length();
	  s=' '+s;
      if(s[1]=='.')break;
      getp();
      int k=len-p[len];
      if(len%k==0)cout<<len/k<<endl;
	      else cout<<1<<endl;   
   }
   return 0;
}