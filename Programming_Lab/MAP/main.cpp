#include <iostream>
#include <iomanip>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

class RuntimeStringCmp
{
public:
    enum cmp_mode{normal,nocase};
private:
    const cmp_mode mode;

    static bool nocase_compare(char c1, char c2)
    {
        return toupper(c1)<toupper(c2);
    }

    RuntimeStringCmp(cmp_mode m=normal):mode(m)
    {

    }

    bool operator() (const string &s1, const string &s2) const
    {
        if(mode==normal)
            return s1<s2;
        else
        {
            return laxicographical_compare(s1.begin(),s1.end(),
                                           s2.begin(),s2.end(),
                                           nocase_compare);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
