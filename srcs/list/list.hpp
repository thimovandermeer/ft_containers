//
// Created by Thimo Van der meer on 06/05/2021.
//

#ifndef MY_FT_CONTAINERS_LIST_HPP
#define MY_FT_CONTAINERS_LIST_HPP
#include "listNode.hpp"
#include <memory>
#include <iterator>
#include <algorithm>
#include "../utils/typeTraits.hpp"
#include "../iterators/BidirectionalIterator.hpp"
#include <iostream>
// include bidrectional iterators


namespace ft {
	template < class T, class Alloc = std::allocator<T>>
	class list
	{
	public:
		typedef T 															value_type;
		typedef Alloc 														allocator_type;
		typedef T 															&reference;
		typedef const T 													&const_reference;
		typedef T 															*pointer;
		typedef const T 													*const_pointer;
		typedef listNode<T> 												*node_pointer;
		typedef ptrdiff_t 													difference_type;
		typedef size_t 														size_type;
		typedef BidirectionalIterator<value_type, node_pointer> 			iterator;
		typedef ConstBidirectionalIterator<value_type, node_pointer> 		const_iterator;
		typedef RevBidirectionalIterator<value_type , node_pointer > 		reverse_iterator;
		typedef ConstRevBidirectionalIterator<value_type, node_pointer>		const_reverse_iterator;

	private:
		// here are the member vars
		node_pointer _head;
		node_pointer _tail;
		size_type _size;
		allocator_type _allocator;
		// Constructors
	public:
		explicit list(const allocator_type &alloc = allocator_type()) : _allocator(alloc)
		{
			_head = new listNode<value_type>;
			_tail = new listNode<value_type>;
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
		}

		explicit list(size_type n, const value_type &val = value_type(),
					  const allocator_type &alloc = allocator_type())
		{
			_head = new listNode<value_type>;
			_tail = new listNode<value_type>;
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
			assign(n, val);
		}

		template<class inputIterator>
		list(inputIterator first, inputIterator last, const allocator_type &alloc = allocator_type())
		{
			_head = new listNode<value_type>;
			_tail = new listNode<value_type>;
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
			assign(first, last);
		}

		list(const list &x)
		{
			_head = new listNode<value_type>;
			_tail = new listNode<value_type>;
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
			assign(x.begin(), x.end());
		}

		// Destructors
		~list()
		{
			this->clear();
			delete this->_tail;
			delete this->_head;
		}

		// Assignment operators
		list& operator=(const list& x)
		{
			_head = new listNode<value_type>;
			_tail = new listNode<value_type>;
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
			assign(x.begin(), x.end());
			return *this;
		}

		// Allocators
		allocator_type get_allocator() const
		{
			return _allocator;
		}

//		 Iterators
		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_tail);
		}

		const_iterator end() const
		{
			return const_iterator(_tail);
		}


		reverse_iterator rbegin()
		{
			return reverse_iterator (_head->_next);
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator (_head->_next);
		}

		reverse_iterator rend()
		{
			return reverse_iterator (_tail);
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator (_tail);
		}

//		// Member Functions
		template<class InputIterator>
		void assign(InputIterator start, InputIterator finish)
		{
			clear();
			while (start != finish) {
				push_back(*start);
				start++;
			}
		}

		void assign(size_type n, const value_type &val)
		{
			clear();
			while (n) {
				push_back(val);
				n--;
			}
		}

		reference back()
		{
			return _tail->getPrev()->_data;
		}

		const_reference back() const
		{
			return _tail->getPrev()->_data;
		}

		void clear()
		{
			while (_size) {
				pop_back();
			}
		}

		bool empty() const
		{
			if (_size == 0)
				return true;
			else
				return false;
		}

		size_type size() const
		{
			return _size;
		}

		iterator erase(iterator position)
		{
			listNode<value_type> *tmp = position.getPtr();
			tmp->_prev->_next = tmp->_next;
			tmp->_next->_prev = tmp->_prev;
			position++;
			delete tmp;
			this->_size--;
			return position;
		}

		iterator erase(iterator start, iterator finish)
		{
			while (start != finish) {
				start = erase(start);
			}
			return start;
		}

		reference front()
		{
			return _head->getNext()->_data;
		}

		const_reference front() const
		{
			return _head->getNext()->_data;
		}

		iterator insert(iterator position, const value_type &val)
		{
			listNode<value_type> *newNode = new listNode<value_type>(val);
			listNode<value_type> *tmp = position.getPtr();

			newNode->_prev = tmp->_prev;
			newNode->_next = tmp;
			tmp->_prev = newNode;
			newNode->_prev->_next = newNode;
			_size++;
			return iterator(newNode);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			for (size_type i = 0; i < n; i++) {
				insert(position, val);
			}
		}

		template<class InputIterator>
		void insert(iterator position, InputIterator start, InputIterator finish,
					typename iterator_traits<InputIterator>::type* = 0)
		{
			while (start != finish) {
				insert(position, *start);
				start++;
			}
		}

		size_type max_size() const
		{
			return this->_allocator.max_size();
		}

		void merge(list &x)
		{
			iterator tmp = x.begin();
			iterator current = this->begin();
			iterator prev;
			while(tmp != x.end())
			{
				while(current != end() && *tmp > *current)
				{
					current++;
				}
				prev = tmp;
				tmp++;
				this->splice(current, x, prev);
			}
		}

		template<class Compare>
		void merge(list& x, Compare comp)
		{
			iterator tmp = x.begin();
			iterator current = this->begin();
			iterator prev;
			// need splice for this one
			while(tmp != x.end())
			{
				while(current != end() && !comp(*tmp, *current))
				{
					current++;
				}
				prev = tmp;
				tmp++;
				this->splice(current, x, prev);
			}
		}

		void pop_back()
		{
			if (_size) {
				listNode<value_type> *tmp;
				tmp = _tail->_prev;
				tmp->_next = NULL;
				_tail->_next = NULL;
				_tail->_prev = NULL;
				delete _tail;
				_tail = tmp;
				_size--;
			}
		}

		void pop_front()
		{
			if (_size) {
				listNode<value_type> *node;
				node = _head->_next;
				_head->_next = node->_next;
				node->_next->_prev = _head;
				_size--;
				delete node;
			}

		}

		void push_back(const value_type &val)
		{
			listNode<value_type> *node;
			node = new listNode<value_type>(val);
			node->_prev = _tail->_prev;
			_tail->_prev->_next = node;
			_tail->_prev = node;
			node->_next = _tail;
			_size++;
		}

		void push_front(const value_type &val)
		{
			listNode<value_type> *node;
			node = new listNode<value_type>(val);
			node->_prev = _head;
			node->_next = _head->_next;
			_head->_next->_prev = node;
			_head->_next = node;
			_size++;
		}

		void remove(const value_type &val)
		{
			iterator it = this->begin();
			while (it != this->end()) {
				if (*it == val) {
					it = erase(it);
				} else {
					it++;
				}
			}
		}

		template<class Predicate>
		void remove_if(Predicate pred)
		{
			iterator it = this->begin();
			while (it != this->end()) {
				if (pred(*it)) {
					it = erase(it);
				} else {
					it++;
				}
			}
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n < _size) {
				while (n != _size) {
					this->pop_back();
				}
			} else {
				while (_size != n) {
					this->push_back(val);
				}
			}
		}

		void reverse()
		{
			listNode<value_type> *current = _head;
			listNode<value_type> *prev = NULL;
			listNode<value_type> *next = NULL;

			while (current != NULL) {
				next = current->_next;
				current->_next = prev;
				prev = current;
				current = next;
			}
			_head = prev;
		}

		void sort()
		{
			iterator tmp = this->begin();
			tmp++;
			while (tmp != this->end()) {
				if (*tmp < tmp.getPtr()->_prev->_data) {
					swap(tmp.getPtr()->_prev, tmp.getPtr());
					tmp = this->begin();
				}
				tmp++;
			}
		}

		template<class compare>
		void sort(compare comp)
		{
			iterator tmp = this->begin();
			tmp++;
			while (tmp != this->end()) {
				if (comp(*tmp, tmp.getPtr()->_prev->_data)) {
					swap(tmp.getPtr()->_prev, tmp.getPtr());
					tmp = this->begin();
				}
				tmp++;
			}
		}

		void splice(iterator position, list &x, iterator i)
		{
			listNode<value_type> *node = i.getPtr();
			node->_prev->_next = node->_next;
			node->_next->_prev = node->_prev;
			x._size--;
			listNode<value_type> *ptr = position.getPtr();
			node->_prev = ptr->_prev;
			ptr->_prev->_next = node;
			node->_next = ptr;
			ptr->_prev = node;
			this->_size++;
		}

		void splice(iterator position, list &x)
		{
			iterator it = x.begin();
			iterator newit;
			while (it != x.end()) {
				newit = it;
				newit++;
				splice(position, x, it);
				it = newit;
			}
		}

		void splice(iterator position, list &x, iterator start, iterator finish)
		{
			iterator newit;
			while (start != finish) {
				newit = start;
				newit++;
				splice(position, x, start);
				start = newit;
			}
		}

		void swap(list &x)
		{
			itemSwap(this->_head, x._head);
			itemSwap(this->_tail, x._tail);
			itemSwap(this->_size, x._size);
			itemSwap(this->_allocator, x._allocator);
		}

		void unique()
		{
			iterator tmp = this->begin();
			iterator prev;
			tmp++;
			while (tmp != this->end()) {
				if (*tmp == tmp.getPtr()->_prev->_data) {
					prev = tmp;
					tmp++;
					erase(prev);
				}
				else
					tmp++;
			}
		}

		template <class BinaryPredicate>
				void unique(BinaryPredicate binary_pred)
		{
			iterator tmp = this->begin();
			iterator prev;
			tmp++;
			while (tmp != this->end()) {
				if (binary_pred(*tmp, tmp.getPtr()->_prev->_data)) {
					prev = tmp;
					tmp++;
					erase(prev);
				}
				else
					tmp++;
			}
		}



	private:
		void swap(node_pointer first, node_pointer second)
		{
			first->_prev->_next = second;
			second->_next->_prev = first;
			second->_prev = first->_prev;
			first->_next = second->_next;
			second->_next = first;
			first->_prev = second;
		}

		template<typename S>
		void itemSwap(S& first, S& second)
		{
			S tmp = first;
			first = second;
			second = tmp;
		}
	};

	// Nonmember Operators
	template<class value_type, class allocator_type>
	bool operator==(const list<value_type, allocator_type> &lhs, const list<value_type, allocator_type> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::list<value_type>::iterator lhsIT = lhs.begin();
		typename ft::list<value_type>::iterator rhsIT = rhs.begin();
		while(lhsIT != lhs.end() && rhsIT != rhs.end())
		{
			if(!(*lhsIT == *rhsIT))
				return false;
			++lhsIT;
			++rhsIT;
		}
		return true;
	}

	template<class value_type, class allocator_type>
	bool operator!=(const list<value_type, allocator_type> &lhs, const list<value_type, allocator_type> &rhs)
	{
		return !(lhs == rhs);
	}

	template<class value_type, class allocator_type>
	bool operator<(const list<value_type, allocator_type> &lhs, const list<value_type, allocator_type> &rhs)
	{
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class value_type, class allocator_type>
	bool operator>(const list<value_type, allocator_type> &lhs, const list<value_type, allocator_type> &rhs)
	{
		return (rhs < lhs);
	}

	template<class value_type, class allocator_type>
	bool operator<=(const list<value_type, allocator_type> &lhs, const list<value_type, allocator_type> &rhs)
	{
		return !(rhs < lhs);
	}

	template<class value_type, class allocator_type>
	bool operator>=(const list<value_type, allocator_type> &lhs, const list<value_type, allocator_type> &rhs)
	{
		return !(lhs < rhs);
	}
}
#endif //MY_FT_CONTAINERS_LIST_HPP
