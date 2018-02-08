#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n%12==0){printf("YES\n");continue;}
		if(n%6==0){printf("4\n");continue;}
		if(n%4==0){printf("3\n");continue;}
		printf("NO\n");
	}
	return 0;
}