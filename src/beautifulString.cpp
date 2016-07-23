#include <iostream>
#include <string.h>
using namespace std;

using namespace std;

int getCountToTransformBeautiful(string s,int n)
{
    int i;
    char prev1 = s[0];
    char prev2 = s[1];
    int count = 0;
    for(int i=2;s[i]!='\0';i++)
    {
        cout << prev1 << " "<< prev2 << " "<<s[i]<<endl;
        if(prev1 == '0' && prev2 == '1' && s[i]=='0')
        {
            s[i]='1';    
            count++;
        }
        prev1 = prev2;
        prev2 = s[i];
     
    }
    return count;
    
}


int main(){
    int n;
    cin >> n;
    string B;
    cin >> B;
    cout << getCountToTransformBeautiful(B,n);
    return 0;
}

