#include<bits/stdc++.h>
using namespace std;

int numDecoding(string s, int decodePointer)
{
	int n=s.size();

	vector<int> dp(n+1, 0);

    for(int i=0; i<n; i++)
    {
        if(i==0 && s[i]=='0' || s[i]<'0' || s[i]>'9')
            return 0;
    }

	dp[0]=1;
    dp[1]=1;

    for(int i=2; i<=n; i++)
    {
        int v1 = s[i-1]-'0';
        int v2= atoi(s.substr(i-2, 2).c_str());

        dp[i]= (v1 ? dp[i-1] : 0) + (v2 > 9 && v2 <= 26 ? dp[i-2] : 0);

        if(!dp[i])
            break;
    }
    return dp[n];
}

int main()
{
	string s;
	cin>>s;

	cout<<numDecoding(s, 0);
}
