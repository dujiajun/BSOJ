#include<iostream>
using namespace std;
int n,a[500]={0};
void bianli(int root)
{  
   for(int i=1;i<=n;i++)if(a[i]==root)bianli(i);
   cout<<root<<' ';
}
int main()
{  int root,x,y,i;
   cin>>n;
   for(i=1;i<=n;i++){cin>>x>>y;a[x]=y;}
   for(i=1;i<=n;i++)if(a[i]==0)root=i;//找根
   bianli(root);
   return 0;
}
