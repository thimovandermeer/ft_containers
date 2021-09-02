//
// Created by Thimo Van der meer on 09/06/2021.
//

#ifndef MY_FT_CONTAINERS_MAPNODE_HPP
#define MY_FT_CONTAINERS_MAPNODE_HPP

#include <clocale>
#include "../iterators/BidirectionalIterator.hpp"


template< typename T >
class mapNode
{
public:

	mapNode*		left;
	mapNode*		right;
	mapNode*		parent;
	T				_data;

	explicit mapNode() : left(NULL), right(NULL), parent(NULL), _data() { return; }
	explicit mapNode(const T &data) : left(NULL), right(NULL), parent(NULL), _data(data) { return; }
	~mapNode() { return; }
	mapNode(const mapNode &src) : left(src.left), right(src.right), parent(src.parent), _data(src.data) { return *this; }

	mapNode&		operator=(const mapNode &obj)
	{
		if (this != &obj)
		{
			this->left = obj.left;
			this->right = obj.right;
			this->parent = obj.parent;
			this->_data = obj._data;
		}
		return *this;
	}

	mapNode*		getNext()
	{
		mapNode* next = this;
		mapNode* tmp = next->parent;
		if (next->right)
		{
			next = next->right;
			while (next->left)
				next = next->left;
			return next;
		}
		while (tmp && next == tmp->right)
		{
			tmp = tmp->parent;
			next = next->parent;
		}
		if (!tmp)
		{
			while (next->left != NULL)
				next = next->left;
			tmp = next->left;
		}
		return tmp;
	}
	mapNode*		getPrev()
	{
		mapNode* next = this;
		mapNode* tmp = next->parent;
		if (next->left)
		{
			next = next->left;
			while (next->right)
				next = next->right;
			return next;
		}
		while (tmp && next == tmp->left)
		{
			tmp = tmp->parent;
			next = next->parent;
		}
		if (!tmp) {
			while (next->right != NULL)
				next = next->right;
			tmp = next->right;
		}
		return tmp;
	}
	mapNode&	getNode()
	{
		return *this;
	}

	T	getData()
	{
		return this->_data;
	}

};


#endif //MY_FT_CONTAINERS_MAPNODE_HPP
