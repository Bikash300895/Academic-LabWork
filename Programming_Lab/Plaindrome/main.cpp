#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string name;
    cin>> name;
    int n=name.size();
    bool istrue=true;
    for(int i=0; i<n/2; i++)
    {
        if(name[i]!=name[n-i-1])
        {
            istrue=false;
            break;
        }
    }
    if(istrue==true) cout<<"Palindrome"<<endl;
    else cout<<"Not Palindrome"<<endl;
    return 0;
}
