#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
const int du_RPS[5][5]=
{
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0}
};
int du_n=0,du_na=0,du_nb=0,du_a[205]={0},du_b[205]={0},du_marka=0,du_markb=0,du_sta=1,du_stb=1;
int main()
{
	cin>>du_n>>du_na>>du_nb;
	for(int i=1;i<=du_na;i++)cin>>du_a[i];
	for(int i=1;i<=du_nb;i++)cin>>du_b[i];
	for(int i=1;i<=du_n;i++)
	{
		du_marka+=du_RPS[du_a[du_sta]][du_b[du_stb]];
		du_markb+=du_RPS[du_b[du_stb]][du_a[du_sta]];
		du_sta++;du_stb++;
		if(du_sta>du_na)du_sta=(du_sta%du_na);
		if(du_stb>du_nb)du_stb=(du_stb%du_nb);
	}
	cout<<du_marka<<" "<<du_markb<<endl;
	return 0;
}
