#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1,s2;
    int count=0,n;
    while (cin>>s1>>s2)
    {
        n=s1.size();
        count=0;
        for(int i=0; i<s2.size()&& count<n; i++)
        {

            if(s2[i]==s1[count])
            {

                count++;
        }
    }
        if(count==n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }

}
