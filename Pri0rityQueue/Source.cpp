#include<iostream>

#include"PriorityQueue.h"

using namespace std;

int main()
{
	PriorityQueue<int> foo;
	foo.Enqueue(8, 5);
	foo.Enqueue(5, 5);
	foo.Enqueue(7, 5);
	foo.Enqueue(10, 10);
	foo.Enqueue(20, 10);
	foo.Enqueue(1, 25);
	foo.Print();
	cout << "\nsize:" << foo.GetSize();
	cout << endl;
	//PriorityQueue<int> bar;
	//bar.Enqueue(10, 10);
	//bar.Enqueue(20, 20);
	//bar = foo;
	//bar.Print();
	//cout << "\nsize:" << bar.GetSize();

	PriorityQueue<int> bar;
	bar.Clear();
}