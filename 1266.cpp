#include <iostream>
using namespace std;
int main()
{
 int n;
 cin >> n;
  int sum = 0; 
  int i = 0; 
  while (sum < n)
    {  i++; sum += i; }
  if (i % 2 == 1)
      cout << sum - n + 1 << '/' << n - sum + i;
  else
      cout << n - sum + i << '/' << sum - n + 1;
 return 0;
}