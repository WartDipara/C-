#pragma once
#include <iostream>
using namespace std;

class Base{
public:
	int x;
	Base(int i) :x(i)
	{
		cout << "->" << x << endl;
	}
	Base() {};
	~Base()
	{

	}
};