#include<iostream>
using namespace std;
int main()
{
 	int yusuan=0,money=0,mother=0;
 	for(int i=0;i<12;i++)
 	{
 		cin>>yusuan;
 		if(money+300<yusuan)
		 {
		 	cout<<-(i+1);
		 	return 0;
		 }
 		money+=300-yusuan;
 		if(money>=100)
 		{
 			mother+=100*(money/100);
 			money%=100;
 		}
 	}
 	cout<<money+mother*1.2;
 	
	return 0;
}
