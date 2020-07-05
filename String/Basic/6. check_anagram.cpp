#include<iostream>
#include<string>
using namespace std;

bool check_anagram(string str1, string str2)
{
    int count1[26]={0}, count2[26]={0}, ascii;
    int i=0;
    while(str1[i] != '\0')
    {
        ascii = str1[i]-97;
        count1[ascii]++;
        i++;
    }

    i=0;
    while(str2[i] != '\0')
    {
        ascii = str2[i]-97;
        count2[ascii]++;
        i++;
    }

    for(i=0; i<26; i++)
    {
        if(count1[i] != count2[i])
            return false;
    }
    return true;
}

int main()
{
    string str1, str2;
    cin>>str1>>str2;

    if(check_anagram(str1, str2))
        cout<<"\nYes they are anagrams\n";
    else
        cout<<"\nNo they are not anagrams \n";
}
