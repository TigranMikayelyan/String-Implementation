#include "string.h"

String::String()
{
	m_capacity = 5;
	m_size = 0;
	m_buf = new char[m_capacity];
}

String::~String()
{
	m_capacity = 0;
	m_size = 0;
	delete[] m_buf;
	m_buf = nullptr;
}

String::String(char* buf)
{
	m_size = strlen(buf);
	delete[] m_buf;
	m_buf = new char[m_size + 1];
	this->m_buf = buf;
}

String::String(std::size_t size, std::size_t capacity)
{
	this->m_size = size;
	this->m_capacity = capacity;
}

String::String(const String& other) 
{ 
	this->m_size = other.m_size;	
	this->m_capacity = other.m_capacity; 
	delete[] m_buf;
	this->m_buf = new char[this->m_capacity];
	for (int i = 0; i < m_size; ++i)
	{
		this->m_buf[i] = other.m_buf[i];
	}
}

String::String(String&& other)
{
	this->m_size = other.m_size;	
	this->m_capacity = other.m_capacity; 
	this->m_buf = other.m_buf;
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_buf = nullptr;
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	delete[] m_buf;
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
	m_buf = new char[m_capacity];
	for (int i = 0; i < m_size; ++i)
	{
		m_buf[i] = rhs.m_buf[i];
	}
	return *this;
}

String& String::operator=(String&& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
	m_buf = rhs.m_buf; 
	rhs.m_size = 0;
	rhs.m_capacity = 0;
	rhs.m_buf = nullptr;
	return *this;
}

String String::operator+(const String& rhs)
{
	String tmp;
	tmp.m_size = m_size + rhs.m_size;
	tmp.m_capacity = m_capacity + rhs.m_capacity;
	int i = 0;
	int j = 0;
	for (i = 0; this->m_buf[i] != '\0'; ++i){}
	for (j = 0; rhs.m_buf[j] != '\0'; ++j)
	{
		this->m_buf[i++] = rhs.m_buf[j];
	}
	this->m_buf[i] = '\0';
	for (int i = 0; this->m_buf[i] != '\0'; ++i)
	{
		tmp.m_buf[i] = this->m_buf[i];
	}
	tmp.m_buf[i] = '\0';
	return tmp;	
}

String& String::operator+=(const String& str)
{
	if (this == &str)
	{
		return *this;
	}
	this->m_size += str.m_size;
	this->m_capacity += str.m_capacity;
	int i = 0;
	int j = 0;
	for (i = 0; this->m_buf[i] != '\0'; ++i){}
	for (j = 0;	str.m_buf[j] != '\0'; ++j, ++i)
	{
		this->m_buf[i] = str.m_buf[j];
	}
	this->m_buf[i] = '\0';
	return *this;
}

const char& String::operator[](int index) const
{
	if (index >= m_size && index < 0)
	{
		throw std::cout << "There isn't this index in this string";
	}
	return m_buf[index];
}

char& String::operator[](int index)
{
	if (index >= m_size && index < 0)
	{
		throw std::cout << "There isn't this index in this string";
	}
	return m_buf[index];
}

bool String::operator==(String& rhs)
{
	if (m_size != rhs.m_size)
	{
		return false;
	}
	for (int i = 0; i < m_size; ++i)
	{
		if (m_buf[i] != rhs.m_buf[i])
		{
			return false;
		}
	}
	return true;
}

bool String::operator!=(String& rhs)
{
	if (m_size != rhs.m_size)
	{
		return true;
	}
	for (int i = 0; i < m_size; ++i)
	{
		if (m_buf[i] != rhs.m_buf[i])
		{
			return true;
		}
	}
	return false;
}

bool String::operator>(const String& rhs)
{
	if (m_size > rhs.m_size)
	{
		return true;
	}
	for (int i = 0; i < m_size; ++i)
	{
		if (m_buf[i] > rhs.m_buf[i])
		{
			return true;
		}
	}
	return false;
}

bool String::operator<(const String& rhs)
{
	if (m_size < rhs.m_size)
	{
		return true;
	}
	for (int i = 0; i < m_size; ++i)
	{
		if (m_buf[i] < rhs.m_buf[i])
		{
			return true;
		}
	}
	return false;
}

bool String::operator>=(const String& rhs)
{
	if (m_size < rhs.m_size)
	{
		return false;
	}
	for (int i = 0; i < m_size; ++i)
	{
		if (m_buf[i] < rhs.m_buf[i])
		{
			return false;
		}
	}
	return true;
}

bool String::operator<=(const String& rhs)
{
	if (m_size > rhs.m_size)
	{
		return false;
	}
	for (int i = 0; i < m_size; ++i)
	{
		if (m_buf[i] > rhs.m_buf[i])
		{
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const String& ptr)
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

std::istream& operator>>(std::istream& in, String& ptr)
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

void String::set_size(std::size_t size)
{
	this->m_size = size;
}

std::size_t String::get_size() const
{
	return m_size;
}

void String::set_capacity(std::size_t capacity)
{
	this->m_capacity = capacity;
}

std::size_t String::get_capacity() const
{
	return m_capacity;
}

void String::set_buf(char* buf)
{
	delete[] m_buf;
	m_buf = new char[strlen(buf) + 1];
	strcpy(this->m_buf, buf);
}

char* String::get_buf() const
{
	return m_buf;
}

void String::insert(int index, const char* str)
{
    int size_1 = length(str);
    if ((m_size + size_1 + 1) >= m_capacity) 
    {
        realoc((size_1 + 1));
    }
    if (empty() && index == 0) 
    {
        op_assign(str);
    } 
    else if (!empty() && (index == m_size)) 
    {
	for (int i = 0; i < size_1; ++i) 
	{
            m_buf[m_size++] = str[i];
        }
        m_buf[m_size] = '\0';
    } 
    else if (index < m_size && index > 0) 
    {
       int j = m_size + size_1;
       for (int i = m_size; i >= index; --i) 
       {
           m_buf[j--] = m_buf[i];
       }
       j = 0;
       for (int i = index; i < index + size_1; ++i) 
	{
            m_buf[i] = str[j++];
        }
    }
}

void String::erase(int index)
{
	if (!m_buf)
	{
		delete[] m_buf;
		m_buf = nullptr;
	}
	else
	{
		m_buf[index] = '\0';
		m_size = m_size - index; 
	}
}

void String::push_back(char ch)
{
    if (!m_buf) 
    {
        m_capacity = 2;
        m_size = 1;
      	m_buf = new char[m_capacity];
        m_buf[0] = ch;
        m_buf[1] = '\0';
    } 
    else 
    {
         if ((m_size + 1) >= m_capacity) 
	 {
	     realoc(m_size);
	 }
	 m_buf[m_size++] = ch;
	 m_buf[m_size] = '\0';
	}
}

void String::push_back(const char* str)
{
	if (!m_buf)
	{	
		m_size = length(str);
		int len = m_size + 1;
		m_capacity = len;
		m_buf = new char[m_capacity];
		for (int i = 0; i < m_size; ++i)
		{
			m_buf[i] = str[i];
		}
		m_buf[m_size] = '\0';
	}
	else
	{
		int size2 = m_size + length(str);
		if (m_capacity <= size2)
		{
			realoc(size2);
		}
		int j = 0;
		int i = 0;
		for (;m_size < size2;)
		{
			m_buf[m_size++] = str[j++];
		}
		m_buf[m_size] = '\0';
	}
}

void String::pop_back()
{
   if (!m_buf) 
   {
        return;
   } 
   else if (m_size > 1)
   {
        m_size = m_size - 1;
        m_buf[m_size] = '\0';
   } 
   else if (m_size <= 1) 
   {
        m_size = 0;
        m_capacity = 0;
        m_buf = nullptr;
   }
}

bool String::cmp(String& oth)
{
	if (m_size != oth.m_size)
	{
		return false;
	}
	for (int i = 0; i < m_size; ++i)
	{
		if (m_buf[i] != oth.m_buf[i])
		{
			return false;
		}
	}
	return true;
}

bool String::empty()
{
    return !(m_size);
}

void String::clear()
{
    if (m_buf) 
	{
        m_size = 0;
        m_buf[m_size] = '\0';
    }
}

void String::realoc(int size) 
{
    m_capacity = m_capacity + size;
    char* ptr1 = new char[m_capacity];
    int i = 0;
    for (; i < m_size; ++i) 
	{
        ptr1[i] = m_buf[i];
    }
    ptr1[i] = '\0';
    delete[] m_buf;
    m_buf = ptr1;
    ptr1 = nullptr;
}

int String::length(const char* str)
{
    int i = 0;
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
 	++count;
    }
    return count;
}

int String::length() const
{
	int count = 0;
	for (int i = 0; m_buf[i] != '\0'; ++i)
	{
		++count;
	}
	return count;
}

void String::op_assign(const char* str)
{
    int size_1 = length(str);
    if (empty()) 
	{
        delete[] m_buf;
        m_buf = nullptr;
    } 
	else 
	{
        m_capacity = size_1 * 2;
        m_size = size_1;
        m_buf = new char[m_capacity];
        int i = 0;
        for (; i < size_1; ++i) 
		{
            m_buf[i] = str[i];
        }
        m_buf[i] = '\0';
    }
}

void String::op_assign(String& ptr2)
{
	int size1 = ptr2.length();
	if (empty())
	{
		delete[] m_buf;
		m_buf = nullptr;
	}
	else
	{
		m_capacity = size1 * 2;
		m_size = size1;
		m_buf = new char[m_capacity];
		int i = 0;
		for (; i < size1; ++i)
		{
			m_buf[i] = ptr2.m_buf[i];
		}
		m_buf[i] = '\0';
	}
}

int String::find(char ch)
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_buf[i] == ch)
		{
			return i;
		}
	}
	return -1;
}

void String::swapp(String& oth)
{
	if (empty())
	{
		delete[] m_buf;
		m_buf = nullptr;
	}
	else
	{
		char* tmp_buf = oth.m_buf;
		int tmp_size = oth.m_size;
		int tmp_capacity = oth.m_capacity;
		oth.m_buf = m_buf;
		oth.m_size = m_size;
		oth.m_capacity = m_capacity;
		m_buf = tmp_buf;
		m_size = tmp_size;
		m_capacity = tmp_capacity;
	}
}

void String::re_size(int size)
{
	if (empty())
	{
		delete[] m_buf;
		m_buf = nullptr;
	}
	else
	{
		m_size = size;
		m_capacity = size + 1;
		realoc(size);
	}
}

char* String::c_str()
{
	char* new_ptr = new char[m_size];
	if (empty())
	{
		delete[] m_buf;
		m_buf = nullptr;
	}
	else
	{	
		int i = 0;
		for (i = 0; i < m_size; ++i)
		{
			new_ptr[i] = m_buf[i];
		}
		new_ptr[m_size] = '\0';
	}
	return new_ptr;
}

char& String::at(int index)
{
	if (empty())
	{
		delete[] m_buf;
		m_buf = nullptr;
	}
	else
	{
		for (int i = 0; i < m_size; ++i)
		{
			if (i == index)
			{
				return m_buf[i];
			}
		}
	}
	throw std::out_of_range("Invalid index!!!");
}

char* String::data()
{
	return m_buf;
}

char String::begin()
{
	return m_buf[0];
}

char String::end()
{
    char index = m_buf[--m_size];
    return index;
}

void String::foo(int size)
{
	m_capacity = m_capacity + m_size;
	char* ptr1 = new char[m_capacity];
	int i = 0;
	for (; i < this->m_size; ++i)
	{
		ptr1[i] = m_buf[i];
	}
	if (i)
	{
		ptr1[i] = '\0';
	}
	delete[] m_buf;
	m_buf = ptr1;
	ptr1 = nullptr;
}

void String::print()
{
    int i = 0;
    while (m_buf[i]) 
	{
        std::cout << m_buf[i++];
    }
	std::cout << std::endl;
	std::cout << "size = " << m_size << std::endl;
	std::cout << "capacity = " << m_capacity << std::endl;
}
