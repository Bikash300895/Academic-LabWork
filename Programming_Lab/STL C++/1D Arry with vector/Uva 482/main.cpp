#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

string toString(int i)
{
    stringstream ss;
    string str;
    ss<<i;
    ss>>str;
    return str;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str,s;
        vector <string> ind,val;
        map <string, string> Map;
        stringstream ss;
        getline(cin, str);
        getline(cin, str);
        getline(cin, str);
        ss<<str;
        while(ss>>s) ind.push_back(s);
        int n=ind.size();
        int i;
        for(i=0 ;i<n ;i++)
        {
            cin>>str;
            Map[ind[i]]=str;
        }
        for(i=0; i<n; i++) cout<<Map[toString(i+1)]<<endl;
        if(t>0) cout<<endl;

    }
    return 0;
}

