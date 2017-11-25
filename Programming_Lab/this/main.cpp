#include <iostream>
using namespace std;


class Student
{
	int id;
	string name;

	Student(int id, string name) {
		this.id = id;
		this.name = name;
	}

	void display() {
		cout << id << " " << name;
	}
};

int main()
{
	Student s1 = new Student(111, "Bikash");
	Student s2 = new Student(222, "Hasib");
		s1.display();
		s2.display();
}
