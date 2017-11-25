#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    fstream file("in.txt",ios::in|ios::out);
    //input
    while(file)
    {
        string s;
        file>>s;
        cout<<s<<endl;
    }

    //output
    ofstream out("in.txt",ios::app);
    out<<"Bikash is coding"<<endl;
    out.close();
    return 0;
}
