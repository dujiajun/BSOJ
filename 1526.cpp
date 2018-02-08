#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
    string s;
    cin>>s;
    int k;
    for(int i=0;i<s.length();i++)
     for(int j=s.length()-1;j>0;j--)
      {
      if(s[j]>s[j-1]) 
      {
                      k=s[j-1];
                      s[j-1]=s[j];
                      s[j]=k;
      }
      }
  cout<<s;
    return 0;
}
