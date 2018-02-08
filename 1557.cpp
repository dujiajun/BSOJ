#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int x[101]={0},y[101]={0},z[101]={0},i;
void init(int a[]) 
{  string s; 
   cin>>s;//读入字符串s 
   a[0]=s.length(); //用a[0]计算字符串s的位数 
   for(i=1;i<=a[0];i++)a[i]=s[a[0]-i]-'0';
     //将数串s转换为数组a，并倒序存储． 
}
int compare(int a[],int b[]) //比较a和b的大小关系，若a>b则为1，a<b则为-1,a=b则为0 
{  int i; 
   if(a[0]>b[0])return 1;  //a的位数大于b则a比b大 
   if(a[0]<b[0])return -1;  //a的位数小于b则a比b小 
   for(i=a[0];i>0;i--)  //否则a和b的位数相同，则从高位到低位比较 
   {  if(a[i]>b[i])return 1; 
      if(a[i]<b[i])return -1;
   } 
   return 0;//各位都相等则两数相等。 
} 
void jian(int a[],int b[])//计算a=a-b
{  int i; 
   for(i=1;i<=a[0];i++) 
   {  if(a[i]<b[i]){a[i+1]--;a[i]+=10;}//若不够减则向上借一位 
      a[i]=a[i]-b[i];
   } 
   while(a[0]>0&&a[a[0]]==0)a[0]--; //修正a的位数 
}
void print(int a[])  //打印输出
{  int i;
   if(a[0]==0){cout<<0<<endl;return;}
   for(i=a[0];i>0;i--)cout<<a[i];cout<<endl;
}
void numcpy(int p[],int q[],int det)//复制p数组到q数组从det开始
{  for(int i=1;i<=p[0];i++)q[i+det-1]=p[i];
   q[0]=p[0]+det-1;
}
void chugao(int a[],int b[],int c[])
{  int i,j,tmp[101]; 
   c[0]=a[0]-b[0]+1;//商的最大位数
   for(i=c[0];i>0;i--)
   {  memset(tmp,0,sizeof(tmp));//数组清零 
      numcpy(b,tmp,i);
      while(compare(a,tmp)>=0){c[i]++;jian(a,tmp);}//用减法来模拟
   }
   while(c[0]>0&&c[c[0]]==0)c[0]--;
}
int main()
{  init(x);
   init(y);
   chugao(x,y,z);
   print(z);
   print(x);
   return 0;
}