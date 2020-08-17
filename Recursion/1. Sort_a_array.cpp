#include<iostream>
#include<vector>
using namespace std;

void insert_at_right_pos(vector<int> &v, int tmp)
{
    if(v.size()==0 || v[v.size()-1] <= tmp)
    {
        v.push_back(tmp);
        return;
    }

    int val = v[v.size()-1];
    v.pop_back();
    insert_at_right_pos(v, tmp);
    v.push_back(val);
    return;
}

void sort_vec(vector<int> &v)
{
    if(v.size()==1)
    {
        return;
    }

    int tmp = v[v.size()-1];
    v.pop_back();
    sort_vec(v);
    insert_at_right_pos(v, tmp);
    return;
}

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    int tmp;
    for(int i=0; i<n; i++)
    {
        cin>>tmp;
        v.push_back(tmp);
    }

    sort_vec(v);

    vector<int> :: iterator ptr;
    for(ptr=v.begin(); ptr!=v.end(); ptr++)
    {
        cout<<*ptr<<" ";
    }
}
