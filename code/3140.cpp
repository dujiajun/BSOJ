#include<iostream>
#include<algorithm>
using namespace std;
const string win="Brazil, we are coming!",lose="Go home, China Team!";
struct team{string n;int goal,lose,mark;team(){goal=lose=mark=0;}}a[15];
string s1,s2,ch;
int n,t,goal[15]={0},mark[15]={0};
bool cmp(team t1,team t2)
{
	/*
	if(t1.mark>t2.mark)return 1;
	if(t1.goal-t1.lose>t2.goal-t2.lose)return 1;
	if(t1.goal>t2.goal)return 1;
	return 0;*/
	if(t1.mark!=t2.mark)return t1.mark>t2.mark;
	if(t1.goal-t1.lose!=t2.goal-t2.lose)return t1.goal-t1.lose>t2.goal-t2.lose;
	if(t1.goal-t1.lose==t2.goal-t2.lose)return t1.goal>t2.goal;
}
int find(string tp)
{
	for(int i=1;i<=n;i++)if(a[i].n==tp)return i;
}
int main()
{
	cin>>n;t=n*(n-1);
	for(int i=1;i<=n;i++)cin>>a[i].n;
	for(int i=1,num1,num2,t2,t1;i<=t;i++)
	{
		cin>>s1>>num1>>ch>>num2>>s2;
		t1=find(s1),t2=find(s2);
		if(num1>num2)a[t1].mark+=3;
		else if(num2>num1)a[t2].mark+=3;
		else if(num1==num2){a[t1].mark+=1;a[t2].mark+=1;}
		a[t1].goal+=num1;a[t1].lose+=num2;
		a[t2].goal+=num2;a[t2].lose+=num1;
	}
	sort(a+1,a+n+1,cmp);
	cin>>ch;
	t=find("China");
	cout<<t<<endl;
	if((t==1)||(t==2)||(t==3&&ch=="Y"))cout<<win<<endl;
	else cout<<lose<<endl;
	return 0;
}