#ifndef PRINT_ELEMENT_H_INCLUDED
#define PRINT_ELEMENT_H_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const string& optstr = "")
{
	//cout << optstr;
	for (const auto& elem : coll)
	{
		cout << elem << " ";
	}
	cout << endl;
}


#endif // PRINT_ELEMENT_H_INCLUDED
