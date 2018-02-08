#include<iostream>
using namespace std;
bool check(string s)
{
	char c1[9]={' ','{','[','(','<','>',')',']','}'};
 	bool x=true;
 	int w=0,k=0,c[255]={0};
 	int len=s.length();
 	for(int i=0;i<len;i++)
 	{
 		for(w=1;w<=8;w++)if(s[i]==c1[w])break;
 		if(w<=4)
 		{
 			if(c[k]>w){return false;}else{k++;c[k]=w;}
 		}
		else if(c[k]+w!=9){return false;}
		else k--;
 	}
 	if(x==true){if(k==0)return true;else return false;}
}
int main()
{
	int n;
	cin>>n;
 	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(check(s))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
