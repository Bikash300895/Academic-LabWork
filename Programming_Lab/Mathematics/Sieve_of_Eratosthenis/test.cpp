#include<stdlib.h>
#include<vector>

using namespace std;
#define Max 100;

vector<int> Q[Max];

int main()
{
    Q[1].push_back(2);
    Q[2].push_back(1);
    Q[1].push_back(3);
    Q[3].push_back(1);
    Q[4].push_back(1);
    Q[1].push_back(4);
    Q[2].push_back(6);
    Q[6].push_back(2);
    Q[3].push_back(7);
    Q[3].push_back(8);
    Q[8].push_back(3);
    Q[4].push_back(7);
    Q[7].push_back(4);
    Q[7].push_back(8);
    Q[8].push_back(7);
    Q[7].push_back(9);
    Q[9].push_back(7);
    Q[5].push_back(8);
    Q[8].push_back(5);
    Q[9].push_back(10);
    Q[10].push_back(9);
    Q[5].push_back(10);
    Q[10].push_back(5);
    Q[7].push_back(3);
}
