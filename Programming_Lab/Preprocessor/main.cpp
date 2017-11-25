#include <iostream>
#define print_bob
using namespace std;


int main()
{
#ifdef print_bob
    cout<<"Bob"<<endl;
#endif // print_bob


#ifdef print_pop
cout<<"pop"<<endl;
#endif // print_pop
}
