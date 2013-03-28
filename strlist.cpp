/*
 * strlist.cpp
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "strlist.h"


//default constructor  DONE
StrList::StrList()
{
	initList(&list);
}


// destructor  DONE
StrList::~StrList()
{
	while(!isEmptyList(&list))
		StrList::popFront();
}


// copy constructor DONE
StrList::StrList(const StrList& str){
	initList(&list);
	
	reverse();
	struct Node *node = (str.list).head;
	while (node) {
		MyString *x = (MyString *)node->data;
		MyString *y = new MyString(*x);
		::addFront(&list, y);
		node = node->next;
	}
	
	reverse();
}

	
// assignment operator DONE
StrList& StrList::operator=(const StrList& str)
{
	if (this == &str) {
		return *this;
	}
	
	while(!isEmptyList(&list))
		StrList::popFront();
	
	reverse();
	struct Node *node = (str.list).head;
	while (node) {
		MyString *x = (MyString *)node->data;
		MyString *y = new MyString(*x);
		::addFront(&list, y);
		node = node->next;
	}
	
	reverse();
	return *this;
	
}




// returns the number of nodes in the list DONE
int StrList::size() const
{
	int i = 0;
	struct Node *node = list.head;
	while (node) {
		i++;
		node = node->next;
	}
	return i;
}


// adds a string to the front of the list DONE
void StrList::addFront(const MyString& str)

{
	MyString *temp = new MyString(str);
	::addFront(&list, temp);
}



// Pops a string from the front of the list and returns it. DONE
MyString StrList::popFront()
{
	MyString *str = (MyString *)::popFront(&list);
    MyString temp = *str;
    delete str;
    return temp;
}

// reverse the elements in the list  DONE
void StrList::reverse()
{
	reverseList(&list);
}



// operator+=  DONE
StrList& StrList::operator+=(const StrList& str)
{
	reverse();
	struct Node *node = (str.list).head;
	while (node) {
		MyString *x = (MyString *)node->data;
		MyString *y = new MyString(*x);
		::addFront(&list, y);
		node = node->next;
	}
	
	reverse();
	return *this;
}



// operator+   DONE
StrList operator+(const StrList& str, const StrList& str2)
{
	StrList temp(str);
	
	temp+=str2;
	
	return temp;
}


// operator << DONE
ostream& operator<<(ostream& os, const StrList& str)
{	
	struct Node *node = str.list.head;
	os << "{ ";
	while(node) {
		os << *(MyString *)node->data << " ";
		node = node->next;
	}
	os << "}";
	return os;
}


// operator[] DONE
MyString& StrList::operator[](int i)
{
	struct Node *node = list.head;
    for (int j = 0; j < i; j++) 
		node = node->next;
		return *(MyString *)node->data;
}


// operator[] const DONE
const MyString& StrList::operator[](int i) const
{
	return ((StrList&)*this)[i];
}

