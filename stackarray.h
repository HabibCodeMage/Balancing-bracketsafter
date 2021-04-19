#pragma once
#ifndef STACKARRAY_H
#define STACKARRAY_H
template<typename T>
class stackarray
{
private:
	T* array;
	int capacity;
	int t;
public:
	stackarray(int c=100):capacity(c),t(-1),array(new T[capacity])
	{}
	bool empty()
	{
		return t == -1;
	}
	void push(T & value)
	{
		if (t + 1 == capacity)
			throw"stack overflow";
		array[++t] = value;
	}
	void pop()
	{
		if (empty())
			throw"stack empty";
		--t;
	}
	const T& top() 
	{
		if (empty())
			throw"stack empty";
		return array[t];
	}

	~stackarray()
	{}

};
#endif // !STACKARRAY_H


