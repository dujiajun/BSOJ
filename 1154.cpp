#include<iostream>
using namespace std;

int main()
{
    int a[26]={0};
    char c=' ';
    cin>>c;
    while(c!='.')
    {
                 if(c<='z'&&c>='a')
                 {
                                   a[c-'a']++;
                 }
                 cin>>c;
    }
    for(int i=0;i<26;i++)
    {
            if(a[i]>0)
            {
                      cout<<(char)('a'+i)<<":"<<a[i]<<endl;
            }
    }
    return 0;
    }
