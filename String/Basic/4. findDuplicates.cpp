#include<bits/stdc++.h>

using namespace std;

int alphabet[26];
int countOccurrences(string str)
{
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            alphabet[str[i]-'a']++;
        }
    }
    for(int i=0; i<26; i++)
    {
        cout<<char(i + 'a')<<" - "<<alphabet[i]<<endl;
    }
}

int main()
{
    string str;
    getline(cin, str);

    cout<<"\n in the string : "<<countOccurrences(str);
}
