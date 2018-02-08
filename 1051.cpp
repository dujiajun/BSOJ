#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class student
{
	public:
	student(){this->jiangxuejin=0;}
	string name;
	int mark1;
	int mark2;
	char xibu;
	char ganbu;
	int lunwen;
	int jiangxuejin;
};

int main()
{
 	int n,sum=0,max=0;
 	string name;
 	cin>>n;
 	student stdt[100];
 	for(int i=0;i<n;i++)
 	{
 		cin>>stdt[i].name>>stdt[i].mark1>>stdt[i].mark2>>stdt[i].ganbu>>stdt[i].xibu>>stdt[i].lunwen;
 	}
 	for(int i=0;i<n;i++)
 	{
 		//max=0;
 		if(stdt[i].mark1>80&&stdt[i].lunwen>0)
	 	{
	 		stdt[i].jiangxuejin+=8000;
 			sum+=8000;
	 	}
	 	if(stdt[i].mark1>85&&stdt[i].mark2>80)
	 	{
	 		stdt[i].jiangxuejin+=4000;
 			sum+=4000;
	 	}
 		if(stdt[i].mark1>90)
 		{
 			stdt[i].jiangxuejin+=2000;
 			sum+=2000;
 		}
	 	if(stdt[i].mark1>85&&stdt[i].xibu=='Y')
	 	{
	 		stdt[i].jiangxuejin+=1000;
 			sum+=1000;
	 	}
	 	if(stdt[i].mark2>80&&stdt[i].ganbu=='Y')
	 	{
	 		stdt[i].jiangxuejin+=850;
 			sum+=850;
	 	}
	 	if(stdt[i].jiangxuejin>max)
 		{
 			max=stdt[i].jiangxuejin;
 			name=stdt[i].name;
 		}
 	}
	cout<<name<<endl<<max<<endl<<sum;
	return 0;
}
