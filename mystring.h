#pragma once
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstddef>
#include <string>
class MyString {
public:
	MyString();
	MyString(const char* str);
	~MyString();
	MyString(const MyString& str);
	void swap( MyString& other);
private:
	char* _str = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
};
7