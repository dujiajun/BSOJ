#include <iostream>
using namespace std;
unsigned int a[9]={0},m=0,mask=0,sum=0;
int main()
{
	
	for(int i=0;i<9;i++)scanf("%x",&a[i]);
	for(int i=0;i<32;i++)
	{
		sum=0;mask+=(1<<i);
		for(int k=0;k<8;k++)sum+=((a[k]^m)&mask);
		if((sum&mask)!=((a[8]^m)&mask))m+=(1<<i);
	}
	printf("%x\n",m);
	return 0;
}