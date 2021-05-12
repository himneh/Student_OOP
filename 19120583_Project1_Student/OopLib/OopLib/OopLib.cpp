#include "OopLib.h"

int Random::next() {
	if (!_seeded)
	{
		srand(time(NULL));
		_seeded = true;
	}
	int number = rand();
	return number;
}

int Random::next(int ceiling) {
	if (!_seeded)
	{
		srand(time(NULL));
		_seeded = true;
	}
	int number = rand() % ceiling;
	return number;
}


int Random::next(int left, int right) {
	if (!_seeded)
	{
		srand(time(NULL));
		_seeded = true;
	}
	int delta = right - left + 1;
	int number = rand() % delta + left;
	return number;
}


int Dice::roll(int left, int right)
{
	int ans = Random::next(left, right);
	return ans;
}

bool Ulti::isPrime(int k)
{
	if (k < 2) return false;
	if (k == 2) return true;
	if (k % 2 == 0) return false;
	for (int i = 3; i <= sqrt(k); i += 2)
		if (k % i == 0) return false;
	return true;
}

int Integer::gcd(int num, int den)
{
	if (den == 0)
		return num;
	return gcd(den, num % den);
}


template <class X>
int DynamicArray<X>::size() {
	return _currentSize;
}

template <class X>
X DynamicArray<X>::getAt(int i)
{
	if (i < _currentSize)
		return _a[i];
	else throw exception("Index out of bound.");
}

template <class X>
X DynamicArray<X>::operator[] (int index)
{
	return DynamicArray::getAt(index);
}

template <class X>
void DynamicArray<X>::push_back(X item) {
	const int step = 3;
	if (_currentSize == _bufferSize)
	{
		int newSize = _currentSize + step;
		X* temp = new X[newSize];
		for (int i = 0; i < _currentSize; i++)
			temp[i] = _a[i];
		delete[] _a;
		_a = temp;
		_bufferSize = newSize;
	}
	_a[_currentSize] = item;
	_currentSize++;
}

template <class X>
void DynamicArray<X>::printArray() {
	for (int i = 0; i < DynamicArray::size(); i++)
		cout << DynamicArray::getAt(i) << " ";
}

template <class X>
DynamicArray<X>::DynamicArray(int initialSize) {
	_currentSize = 0;
	_a = new X[initialSize];
	_bufferSize = initialSize;
}

template <class X>
DynamicArray<X>::DynamicArray(const DynamicArray<X>& other)
{
	_a = new X[other._bufferSize];
	_currentSize = other._currentSize;
	_bufferSize = other._bufferSize;
	for (int i = 0; i < _currentSize; i++)
		_a[i] = other._a[i];
}

template <class X>
DynamicArray<X>& DynamicArray<X>::operator=(const DynamicArray<X>& other)
{
	_a = new X[other._bufferSize];
	_currentSize = other._currentSize;
	_bufferSize = other._bufferSize;
	for (int i = 0; i < _currentSize; i++)
		_a[i] = other._a[i];
	return *this;
}

template <class X>
DynamicArray<X>::~DynamicArray<X>() {
	delete[] _a;
}

template class DynamicArray<char>;
template class DynamicArray<unsigned char>;
template class DynamicArray<signed char>;

template class DynamicArray<int>;
template class DynamicArray<unsigned int>;
template class DynamicArray<signed int>;
template class DynamicArray<short int>;
template class DynamicArray<unsigned short int>;
template class DynamicArray<signed short int>;
template class DynamicArray<float>;
template class DynamicArray<double>;
template class DynamicArray<long double>;
template class DynamicArray<string>;