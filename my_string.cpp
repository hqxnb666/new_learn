#include "mystring.h"
	MyString::MyString()
		:_size(0), _capacity(0) {
		_str = new char[1];
		_str[0] = '\0';
	}
	MyString::MyString(const char* str)
	{
		assert(str);
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy_s(_str,_capacity+1, str);
	}
	MyString::~MyString()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	void MyString::swap( MyString& other)
	{
		std::swap(_str, other._str);
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
	}
	MyString::MyString(const MyString& str)
	{
		MyString temp(str._str);
		swap(temp);
	}
