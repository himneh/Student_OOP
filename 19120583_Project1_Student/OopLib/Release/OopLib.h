#pragma once
#pragma once
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Random {
private:
	inline static bool _seeded = false;
public:
	static int next();
	static int next(int ceiling);
	static int next(int left, int right);
};

class Dice {
private:
	int _faces;
public:
	Dice()
	{
		_faces = 6;
	}
public:
	int roll(int left, int right);
};

class Ulti {
public: 
	static bool isPrime(int k);
};

class Integer {
public:
	static int gcd(int num, int den);
};

template <class X>
class DynamicArray {
private:
	X* _a;
	int _currentSize;
	int _bufferSize;
public:
	int size();

	X getAt(int i);
	
	X operator[] (int index);
	
	void push_back(X item);

	void printArray(); 

	DynamicArray<X>(int initialSize);

	DynamicArray<X>(const DynamicArray& other);

	DynamicArray<X>& operator=(const DynamicArray<X>& other);

	~DynamicArray<X>();
};