#include<iostream>
#include<vector>
using namespace std;

void josephus_problem(vector<int> &vec, int k, int index, int &ans)
{
    if(vec.size() == 1)
    {
        ans = vec[0];
        return;
    }

    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<index<<endl;;

    index = (index + k)%vec.size();
    vec.erase(vec.begin() + index);

    josephus_problem(vec, k, index, ans);
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> vec;
    for(int i=1; i<=n; i++)
        vec.push_back(i);

    k--;
    int index=0;
    int ans=-1;

    josephus_problem(vec, k, index, ans);
    cout<<"The safe position is = "<<ans;
}
