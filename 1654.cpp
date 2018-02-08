#include<iostream>
using namespace std;
int main()
{
	int a[15][15];
	for(int i=1;i<=5;i++)
	for(int j=1;j<=10;j++)cin>>a[i][j];
	int minn=0x7fffffff;
    for(int i=1;i<=10;i++)
    for(int j=1;j<=10;j++)
    for(int k=1;k<=10;k++)
    for(int l=1;l<=10;l++)
	{
        int m=25-i-j-k-l;
        if(m<=10&&m>=1)
		{
            int s=a[1][i]+a[2][j]+a[3][k]+a[4][l]+a[5][m];
            minn=min(minn,s);
        }
    }
  	cout<<minn<<endl;
	return 0;
}
/*
333 700 1200 1710 2240 2613 3245 3956 4778 5899
300 610 960 1370 1800 2712 3834 4834 5998 7682
298 612 990 1560 2109 2896 3790 4747 5996 7654
289 577 890 1381 1976 2734 3876 5678 6890 9876
312 633 995 1467 1845 2634 3636 4812 5999 8123
*/