#include<iostream>
using namespace std;
class fds
{
	public:
		string name;int mon,rec,giv;
		fds(){mon=0;rec=0;giv=0;}
};

int main()
{
	int n,id1,id2,num;
	string name1,name2;
	fds fd[11];
	cin>>n;
	for(int i=1;i<=n;i++)cin>>fd[i].name;
	for(int i=1;i<=n;i++)
	{
		cin>>name1;
		for(id1=1;id1<=n;id1++)if(name1==fd[id1].name)break;
		cin>>fd[id1].mon>>num;
		if(num!=0)
		{
			fd[id1].giv=int(fd[id1].mon/num)*num;
			for(int j=1;j<=num;j++)
			{
				cin>>name2;
				for(id2=1;id2<=n;id2++)if(name2==fd[id2].name)break;
				fd[id2].rec+=fd[id1].mon/num;
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<fd[i].name<<" "<<fd[i].rec-fd[i].giv<<endl;
	return 0;
}