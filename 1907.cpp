#include<iostream>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<cmath>
using namespace std;
struct dd{int x,y;}a[1001];
int f[1002]={0},n,m,k,i,j,M=0;
double t;
bool cmp(dd a,dd b){if(a.x==b.x)return a.y<b.y;return a.x<b.x;} 
int main()
{
 	cin>>n>>m>>k;
    for(i=1;i<=k;i++)cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+k,cmp); 
    for(i=2;i<=k;i++)
       for(j=1;j<i;j++)
         if(a[i].x>a[j].x&&a[i].y>a[j].y&&f[j]+1>f[i])f[i]=f[j]+1;
    for(i=1;i<=k;i++)if(f[i]>M)M=f[i]; M++;
    t=(m+n)*100-((2-sqrt(2))*100*M);
    cout<<int(t)+(t-int(t)>=0.5);
    return 0; 
}
