//
// Created by Thimo Van der meer on 09/06/2021.
//

#ifndef MY_FT_CONTAINERS_MAPNODE_HPP
#define MY_FT_CONTAINERS_MAPNODE_HPP

#include <clocale>

enum color{Red, Black};

template <class T>
class mapNode {
	// data members
public:
	// redirects
	typedef T			value_type;
	typedef T&			reference;
	typedef const T&	const_reference;
	typedef T*			pointer;
	typedef const T*	const_pointer;

	// constructors

	explicit mapNode(value_type const& elem = value_type()) :
		_color(Red),
		_data(elem),
		_left(NULL),
		_right(NULL),
		_parent(NULL),
		_isnill(false)
	{
	}

	mapNode(const mapNode<T>&x) :
		_data(x.getData(),
		_parent(x.getParent()),
		_left(x.getLeft()),
		_right(x.getRight()),
		_color(x.getColor()),
		_isnill(false))
	{

	}
	// destructors
	virtual ~mapNode(){};

	// operator=
	mapNode& operator=(mapNode object)
	{
		if (this != &object)
		{
			_color = object._color;
			_data = object._data;
			_left = object._left;
			_right = object._right;
			_parent = object._parent;
		}
		return (*this);
	}

	// getters

	mapNode*	getNext()
	{
		mapNode<T> *tmp = this;
		if(tmp->getRight() != NULL)
		{
			tmp = tmp->getRight();
			while(tmp->getLeft() != NULL)
			{
				tmp = tmp->getLeft();
			}
			return (tmp);
		}
//		else
//		{
//			if (tmp->getNill() == true)
//				return (tmp->getParent());
//			while(tmp->getParent() && (tmp->getParent()->getData().first < tmp->getData().first()))
//			{
//				tmp = tmp->getParent();
//			}
//			if (tmp->getParent() && (tmp->getParent()->getData().first > tmp->getData().first()))
//				return tmp->getParent();
//		}
		return tmp;
	}

	mapNode*	getPrev()
	{
		mapNode<T> *tmp = this;
		if(tmp->getLeft() != NULL)
		{
			tmp = tmp->getLeft();
			while(tmp->getRight() != NULL)
			{
				tmp = tmp->getRight();
			}
			return tmp;
		}
//		else
//		{
//			if (tmp->getNill() == true)
//				return (tmp->getParent());
//			while(tmp->getParent() && (tmp->getParent()->getData().first > tmp->getData().first()))
//			{
//				tmp = tmp->getParent();
//			}
//			if (tmp->getParent() && (tmp->getParent()->getData().first < tmp->getData().first()))
//				return tmp->getParent();
//		}
		return tmp;
	}

	mapNode* 	getLeft() const
	{
		return _left;
	}

	mapNode*	getRight() const
	{
		return _right;
	}

	mapNode*	getParent() const
	{
		return _parent;
	}

	T			getData() const
	{
		return _data;
	}

	color		getColor() const
	{
		return _color;
	}

	bool 		getNill() const
	{
		return _isnill;
	}


	// setters

	void 		setLeft(mapNode *newLeft)
	{
		_left = newLeft;
	}

	void 		setRight(mapNode *newRight)
	{
		_right = newRight;
	}

	void 		setParent(mapNode *newParent)
	{
		_parent = newParent;
	}

	void 		setData(T *newData)
	{
		_data = newData;
	}

	void 		setColor(color newColor)
	{
		_color = newColor;
	}

private:
	color				_color;
	T					_data;
	mapNode				*_left;
	mapNode				*_right;
	mapNode				*_parent;
	bool 				_isnill;
};
#endif //MY_FT_CONTAINERS_MAPNODE_HPP
