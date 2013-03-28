/*
 *  tlist.h
 *  Lab 10  deque used as a container instead of list
 *
 */

#ifndef __TLIST_H__
#define __TLIST_H__

using namespace std;
#include <algorithm>
#include <iostream>
#include <deque>


template <typename T>
class TList;

	//friend functions
template <typename T>
TList<T> operator+(const TList<T>& str, const TList<T>& str2);

template <typename T>
ostream& operator<<(ostream& os, const TList<T>& str);


template <typename T>
class TList
{
public:
	
	bool isEmpty() const { return q.empty(); }
	
	int size() const { return q.size(); }
	
	void addFront(const T& str);
	
	T popFront();
	
	void reverse();
	
	TList<T>& operator+=(const TList<T>& str);
	
	friend TList<T> (::operator+<T>)(const TList<T>& str, const TList<T>& str2);
	
	friend ostream& operator<< <T>(ostream& os, const TList<T>& str); 
	
	T& operator[](int i);
	
	const T& operator[](int i) const;
	
private:
	deque<T> q;   	
	
};


template <typename T>
void TList<T>::addFront(const T& str)
{
	q.push_front(str); 
}


template <typename T>
T TList<T>::popFront()
{
	T t = q.front();
    q.pop_front();
    return t;
}


template <typename T>
void TList<T>::reverse()
{
	::reverse(q.begin(), q.end());
}


template <typename T>
TList<T>& TList<T>::operator+=(const TList<T>& str)
{
    typename deque<T>::const_iterator iter;
    for (iter = str.q.begin(); iter != str.q.end(); ++iter){
		q.push_back(*iter);
	}
    return *this;
}


template <typename T>
TList<T> operator+(const TList<T>& str, const TList<T>& str2)
{
    TList<T> temp(str);
    temp += str2;
    return temp;
}


template <typename T>
ostream& operator<<(ostream& os, const TList<T>& str)
{
	typename deque<T>::const_iterator iter;
    os << "{ ";
    for (iter = str.q.begin(); iter != str.q.end(); ++iter)
		os << *iter << " ";
    os << "}";
    return os;
}


template <typename T>
T& TList<T>::operator[](int i)
{
    return q[i];
}


template <typename T>
const T& TList<T>::operator[](int i) const
{
	return ((TList<T> &)*this)[i]; 
	
}

#endif