# if 0

#include <iostream>

using namespace std;
class Matrix
{
	int data[10][10];
	int r;
	int c;
public:
	friend istream& operator >> (istream& in, Matrix& matrix)
	{
		cout << "row :";
		cin >> matrix.r;
		cout << "col :";
		cin >> matrix.c;

		for (int i = 0; i<matrix.r; i++)
		{
			for (int j = 0; j<matrix.c; j++)
			{
				cout << i << " " << j << " :";
				in >> matrix.data[i][j];

			}
		}
		return in;

	}

	friend ostream& operator<<(ostream& out, Matrix& matrix)
	{

		for (int i = 0; i<matrix.r; i++)
		{
			for (int j = 0; j<matrix.c; j++)
			{
				out << matrix.data[i][j] << " ";

			}
			out << endl;
		}
		return out;
	}


public:
	//class is inside Matrix class to acces it's private data
	class Proxy
	{
		int *p;
	public:
		Proxy(int *p) :p(p) {}
		//return the column
		//p is already pointing the required row
		int operator[](int i2)
		{
			return p[i2];
		}

	};


	Proxy operator[](int i1)
	{
		//Creating and returning a proxy class holding the row
		Proxy prox(&data[i1][0]);
		return prox;

	}

};
int main()
{
	Matrix a1;
	cin >> a1;
	cout << a1;
	//In first call it calls the overloaded[ ] of Matrix class as a1 is of type Matrix
	//When it returns it return a object of type Proxy
	// When the second [ ] is called, it is called on the returned proxy object which returns an integer
	cout << a1[1][1];

	return 0;
}


#endif