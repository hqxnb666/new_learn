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
	size_t MyString::size() const
	{
		return _size;
	}
	size_t MyString::capacity() const
	{
		return _capacity;
	}
	bool  MyString::empty() const
	{
		return _size == 0;
	}
	const char* MyString::c_str() const
	{
		return _str;
	}
	MyString::iterator MyString::begin()
	{
		return _str;
	}
	MyString::iterator MyString::end()
	{
		return _str + _size;
	}
	MyString::const_iterator MyString::begin() const
	{
		return _str;
	}
	MyString::const_iterator MyString::end() const
	{
		return _str + _size;
	}
	void MyString::reserve(size_t n)
	{
		if (n > _capacity) {
			char* temp = new char[n + 1];
			strcpy_s(temp, n + 1, _str);
			delete[] _str;
			_str = temp;
			_capacity = n;
		}
	}
	void MyString::resize(size_t n, char ch )
	{
		if (n <= _size) {
			_str[n] = '\0';
			_size = n;
		}
		else {
			MyString::reserve(n);
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = ch;
			}
			_str[n] = '\0';
			_size = n;
		}
	}