//
//  String.h
//  myTest
//
//  Created by ������ on 2018/4/30.
//  Copyright �0�8 2018�� ������. All rights reserved.
//
#pragma once
#include <iostream>
#include <stddef.h>

class String
{
public:
	String(const char *str=NULL);
	String(const String &other);
	String & operator = (const String &other);
	size_t Lenth();
	~String(void);

	//���������
	char & operator[](int index);
	friend String& operator+(const String&, const String&);
	String& operator+=(const String&);
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String&, const String&);
	friend bool operator<=(const String&, const String&);
	friend bool operator>=(const String&, const String&);
	friend bool operator<(const String&, const String&);
	friend bool operator>(const String&, const String&);

	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, const String&);

	char*  c_str();
	bool IsEmpty();
	String& Insert(int pos, const String&);
	String& Mid(int nFirst, int nCount);
	int Find(const char *pVal);
private:
	char *m_data;
};
