#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
public:
	String();
	~String();
	String(char*);
	String(std::size_t, std::size_t);
	String(const String&);
	String(String&&);
public:
	String& operator=(const String&);
	String& operator=(String&&);
	String operator+(const String&);
	String& operator+=(const String&);
	const char& operator[](int) const;
	char& operator[](int);
	bool operator==(String&);
	bool operator!=(String&);
	bool operator>(const String&);
	bool operator<(const String&);
	bool operator>=(const String&);
	bool operator<=(const String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
public:
	void set_size(std::size_t);
	std::size_t get_size() const;
	void set_capacity(std::size_t);
	std::size_t get_capacity() const;
	void set_buf(char*);
	char* get_buf() const;
public:
	void op_assign(String&); 
	void op_assign(const char*);
	void push_back(const char*);
	void push_back(char);
	void pop_back();
	char& at(int); 
	void insert(int, const char*);
	void erase(int);
	bool empty();
	void clear();
	void realoc(int);
	int length(const char*);
	int length() const;
	int find(char);
	char* c_str();
	void swapp(String&);
	void re_size(int);
	bool cmp(String&);
	char* data();
	char begin();
	char end();
	void foo(int);
	void print();
private:
	std::size_t m_size;
	std::size_t m_capacity;
        char* m_buf;
};	
#endif // STRING_H
