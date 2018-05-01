//
//  String.cpp
//  myTest
//
//  Created by 刘春涛 on 2018/4/30.
//  Copyright © 2018年 刘春涛. All rights reserved.
//
#include "StdAfx.h"
#include "String.h"
#include <string.h>
#include <assert.h>
using namespace std;

String::String(const char *str)
{
	if (str == NULL) {
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		size_t len = strlen(str)+1;
		m_data = new char[len];
		memset(m_data, 0, len);
		strcpy(m_data, str);
	}
}

String::String(const String &other)
{
	size_t len = strlen(other.m_data)+1;
	m_data = new char[len];
	memset(m_data, 0, len);
	strcpy(m_data, other.m_data);
}

String::~String(void)
{
	if (m_data != NULL) {
		delete[] m_data;
		m_data = NULL;
	}
}

size_t String::Lenth()
{
	return strlen(m_data);
}
String & String::operator = (const String &other)
{
	if (this == &other) {
		return *this;
	}
	if (m_data != NULL) {
		delete[] m_data;
	}
	size_t len = strlen(other.m_data)+1;
	m_data = new char[len];
	memset(m_data, 0, len);
	strcpy(m_data, other.m_data);
	return *this;
}

char & String::operator[](int index)
{
	return m_data[index];
}

String & operator+(const String &l_val, const String &r_val)
{
	size_t len = strlen(l_val.m_data)+strlen(r_val.m_data)+1;
	char* new_data = new char[len];
	memset(new_data, 0, len);
	strcat(new_data, l_val.m_data);
	strcat(new_data, r_val.m_data);
	String* new_string = new String(new_data);
	delete []new_data;
	return *new_string;
}

String & String::operator+=(const String & r_val)
{
	*this = *this+r_val;
	return *this;
}

bool operator==(const String& l_val, const String &r_val)
{
	return (strcmp(l_val.m_data, r_val.m_data) == 0 ? true:false);
}

bool operator!=(const String& l_val, const String& r_val)
{
	return (strcmp(l_val.m_data, r_val.m_data)!=0 ? true:false);
}

bool operator<=(const String& l_val, const String& r_val)
{
	if (strcmp(l_val.m_data, r_val.m_data)<=0) {
		return true;
	}
	return false;
}

bool operator>=(const String& l_val, const String& r_val)
{
	if (strcmp(l_val.m_data, r_val.m_data)>=0) {
		return true;
	}
	return false;
}

bool operator<(const String& l_val, const String& r_val)
{
	if (strcmp(l_val.m_data, r_val.m_data)<0) {
		return true;
	}
	return false;
}

bool operator>(const String& l_val, const String& r_val)
{
	return (strcmp(l_val.m_data, r_val.m_data)>0 ? true:false);
}

ostream& operator<<(ostream& os, const String& s)
{
	for (int i=0; i<strlen(s.m_data); i++) {
		os << s.m_data[i];
	}
	return os;
}

istream& operator>>(istream& is, const String& s)
{
	for (int i=0; i<strlen(s.m_data); i++) {
		is >> s.m_data[i];
	}
	return is;
}

char* String::c_str()
{
	return m_data;
}

bool String::IsEmpty()
{
	if (strlen(m_data) == 0)
		return true;
	return false;
}

String & String::Insert(int pos, const String &r_val)
{
	assert(pos>=0&&pos<=strlen(m_data));
	size_t len = strlen(m_data) + strlen(r_val.m_data) + 1;
	char *new_data = new char[len];
	memset(new_data, 0, len);
	size_t r_len = strlen(m_data)-pos+1;
	char* r_data = new char[r_len];
	memset(r_data, 0, r_len);
	for (int i=0; i<r_len; i++) {
		r_data[i] = m_data[pos+i];
	}
	m_data[pos] = '\0';
	strcpy(new_data, m_data);
	strcat(new_data, r_val.m_data);
	strcat(new_data, r_data);
	swap(m_data, new_data);
	delete []new_data;
	delete []r_data;
	return *this;
}

String & String::Mid(int nFirst, int nCount)
{
	assert(nFirst>=0 && (nFirst+nCount)<=strlen(m_data));
	size_t len = nCount+1;
	char *new_data = new char[len];
	memset(new_data, 0, len);
	m_data[nFirst+nCount] = '\0';
	strcpy(new_data, &m_data[nFirst]);
	swap(m_data, new_data);
	delete []new_data;
	return *this;
}

int String::Find(const char *pVal)
{
	const char *str = strstr(m_data, pVal);
	return str==NULL?-1:(int)(str-m_data);
}
