#include<iostream>
#include<cmath>
using namespace std;
int a[600]={0},tmp[600]={0},p,t=1;
void cheng(int a[],int b[])
{     
	int c[1001]={0};
    for(int i=1;i<=500;i++)
    for(int j=1;j<=500-i+1;j++)c[i+j-1]+=a[i]*b[j];
    for(int i=1;i<=500;i++)
    {
		c[i+1]+=c[i]/10;        
        a[i]=c[i]%10;
	}           
}
int main()
{     
    
    cin>>p;
    tmp[1]=2;a[1]=1;
    cout<<int(p*log10(2)+1)<<endl;
    while(p)
    {      
		if(p%2)cheng(a,tmp);
        p/=2;
        cheng(tmp,tmp);
    }
    a[1]--;
    while(1)
    {   
        if(a[t]<0){a[t]+=10;a[t+1]--;}
        else break;
        t++;
    }
    for(int i=10;i>=1;i--)
    {
	  	for(int j=50;j>=1;j--)cout<<a[(i-1)*50+j];
		cout<<endl;
	}                  
}
