//
// Created by Thimo Van der meer on 09/06/2021.
//

#ifndef MY_FT_CONTAINERS_MAPNODE_HPP
#define MY_FT_CONTAINERS_MAPNODE_HPP

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
	explicit mapNode() : 	_color(Red),
							_data(T(),
			 				_left(nullptr),
			 				_right(nullptr),
			 				_parent(nullptr))
	{

	}

	explicit mapNode(T elem) : 	_color(Red),
								_data(T(elem),
						  		_left(nullptr),
						  		_right(nullptr),
						  		_parent(nullptr))
	{
	}

	// destructors
	virtual ~mapNode(){};

	// operator=
	mapNode& operator==(mapNode object)
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
	T*					_data;
	mapNode				*_left;
	mapNode				*_right;
	mapNode				*_parent;
	// mogelijk nil toevoegen
};
#endif //MY_FT_CONTAINERS_MAPNODE_HPP
