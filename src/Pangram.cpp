#include <iostream>
#include <stdio.h>
using namespace std;

bool IsPangram(char* s)
{
    int a[26];
    for(int i=0;i<26;i++)
    {
        a[i]=0;    
    }

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
               a[s[i]-'a']=1;
        }
        if(s[i]>='A'&&s[i]<='Z')
        {
            a[s[i]-'A']=1;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(a[i]==0)
            return false;
    }
    return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char s[1000];
    gets(s);
    if(IsPangram(s)==true)
    {
        cout << "pangram";    
    }
    else
    {
        cout << "not pangram";    
    }
    return 0;
}
