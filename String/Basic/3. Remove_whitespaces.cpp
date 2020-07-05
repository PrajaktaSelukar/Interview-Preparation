#include<iostream>
#include<string>
using namespace std;

char* remove_spaces(char* str)
{
    int i=0, j=0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ')
        {
            str[j++] = str[i];
        }
        i++;
    }
    str[j]='\0';
    return str;
}

int main()
{
    char str[50] = "g e e k";

    cout<<"\nAfter removing spaces : "<<remove_spaces(str);
}
