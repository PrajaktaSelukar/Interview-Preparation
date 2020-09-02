/*	@Author - Jatin Goel
	@Institute - IIIT Allahabad
	Hardwork definitely pays off.
	There is no substitute of hardwork.
	There is no shortcut to success.
*/
#include <bits/stdc++.h>
using namespace std;
#define  LL long long
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL)

int maxProfit2trans(int price[], int n)
{
    int *profit = new int[n];
    for(int i=0; i<n; i++)
        profit[i]=0;

    int max_price = price[n-1];
    for(int i=n-2; i>=0; i--)
    {
        if(max_price < price[i])
            max_price = price[i];

        profit[i] = max(profit[i+1], max_price - price[i]);
    }

    for(int i=0;i<n;i++)
        cout<<profit[i]<<" ";
    cout<<"\n";

    int min_price = price[0];
    for(int i=1; i<n; i++)
    {
        if(min_price > price[i])
            min_price = price[i];

        profit[i] = max(profit[i-1], profit[i] + (price[i]-min_price));
    }

    for(int i=0;i<n;i++)
        cout<<profit[i]<<" ";
    cout<<"\n";

    int res = profit[n-1];
    delete [] profit;

    return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int price[n+5];
		for(int i=0;i<n;i++)
			cin >> price[i];

		cout<<maxProfit2trans(price, n);
	}
}
