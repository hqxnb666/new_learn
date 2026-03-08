#pragma once
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstddef>
#include <string>
class MyString {
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	MyString();
	MyString(const char* str);
	~MyString();
	MyString(const MyString& str);
	void swap( MyString& other);
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	const char* c_str() const;
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	void reserve(size_t n);
	void resize(size_t n, char ch = '\0');
private:
	char* _str = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
	
};
