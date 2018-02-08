#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n)
{
    int i,j,t;
     for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
              t=arr[j+1];
              arr[j+1]=arr[j];
              arr[j]=t;
             }
        }
    }
 
}
int main()
{
    
    int n,a[100];
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubbleSort(a,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    
    return 0;
}