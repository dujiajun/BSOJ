#include<iostream>
#include<map>
using namespace std;
int n,k,a[100005],ans=0,kind=0;
map<int,int>cnt;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,j=1;i<=n;i++)
	{
		if(cnt[a[i]]==0)kind++;
		cnt[a[i]]++;
		while(kind>k+1)
		{
			cnt[a[j]]--;
			if(cnt[a[j]]==0)kind--;
			j++;
		}
		ans=max(ans,cnt[a[i]]);
	}
	cout<<ans<<endl;
	return 0;
} 