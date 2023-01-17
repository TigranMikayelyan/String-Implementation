#ifndef STRING_H
#define STRING_H

class String
{
public:
	String();
	~String();
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
public:
	
	String(char*);
	String(std::size_t, std::size_t);
	String(const String&);
	String(String&&);
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
private:
	std::size_t m_size;
    std::size_t m_capacity;
    char* m_buf;
	/*
public:	
	friend std::ostream& operator<<(std::ostream& os, const String& ptr)
	{
		int i = 0;
		if (!ptr.length())
		{
			os<< "";
			return os;
		}
		while (ptr[i])
		{
			os << ptr[i++];
		}
		return os;
	}

	friend std::istream& operator>>(std::istream& in, String& ptr)
	{
		if (!ptr.empty())
		{
			delete[] ptr.m_buf;
			ptr.m_buf = nullptr;
			ptr.m_size = 0;
			ptr.m_capacity = 0;
		}
		std::string str = "";
		in >> str;
		ptr.foo(str.size() + 1);
		int count = 0;
		int i = 0;
		for (int i = 0; i < ptr.m_capacity; ++i)
		{
			ptr[ptr.m_size++] = str[i];
		}
		ptr[ptr.m_size] = '\0';
		return in;
	}
	*/
};
#endif // STRING_H
