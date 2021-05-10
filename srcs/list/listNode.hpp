//
// Created by Thimo Van der meer on 10/05/2021.
//

#ifndef MY_FT_CONTAINERS_LISTNODE_H
#define MY_FT_CONTAINERS_LISTNODE_H

template <class T>
class listNode {
	// constructor
public:
	explicit listNode() : _next(NULL), _prev(NULL), _data(T()) {};
	explicit listNode(T elem) : _next(NULL), _prev(NULL), _data(T(elem)) {};

	// destructor
	virtual ~listNode() {};
	// operator=
	listNode& operator==(listNode object)
	{
		if (this != &object)
		{
			this->_prev = object._prev;
			this->_next = object._next;
			this->_data = object._data;
		}
		return (*this);
	}
	// variables
	listNode 	*_next;
	listNode 	*_prev;
	T 			_data;
public:
	// functions
	listNode* getNext() const
	{
		return _next;
	}

	listNode* getPrev() const
	{
		return _prev;
	}

	T			getData()
	{
		return _data;
	}
};
#endif //MY_FT_CONTAINERS_LISTNODE_H
