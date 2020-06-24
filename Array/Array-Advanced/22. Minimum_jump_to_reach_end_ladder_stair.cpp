#include<bits/stdc++.h>
using namespace std;

int findMinJump(int arr[], int n)
{
    if(n == 0)
        return 0;

    //base case
    if(arr[0] == 0)
        return INT_MAX;

    //keeps track of largest ladder that u have
    int ladder = arr[0];
    //keeps track of stairs in the current ladder
    int stairs = arr[0];

    int jump = 1;

    for(int level = 1; level<n; level++)
    {
        //reaches the end
        if(level == n-1)
        {
            return jump;
        }

        //collect the ladder which is the largest
        if(level + arr[level] > ladder)
            ladder = level + arr[level];

        stairs--;

        if(stairs == 0)
        {
            jump++; // no stairs left, now jump
            stairs = ladder - level; // now get new set of stairs

            //corner case if level >= ladder check eg- {1, 2, 0, 1, 0, 4, 5}
            if(stairs <= 0)
                return INT_MAX;
        }
    }
    return jump;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"\nThe minimum jump to reach the end : "<<findMinJump(arr, n);
}
