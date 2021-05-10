//
// Created by Thimo Van der meer on 06/05/2021.
//

#ifndef MY_FT_CONTAINERS_LIST_HPP
#define MY_FT_CONTAINERS_LIST_HPP
#include "listNode.hpp"
#include <memory>
#include <iterator>
#include <algorithm>
// include bidrectional iterators


namespace ft {
	template < class T, class Alloc = std::allocator<T>>
	class list
	{
	public:
		typedef T			value_type;
		typedef Alloc		allocator_type;
		typedef T			&reference;
		typedef const T		&const_reference;
		typedef T			*pointer;
		typedef const T		*const_pointer;
		typedef listNode<T>	*node_pointer;
		typedef ptrdiff_t	difference_type;
		typedef size_t		size_type;
//		typedef BidirectionalIterator<value_type, node_pointer >	iterator;
//		typedef ConstBidirectionalIterator<value_type , node_pointer > const_iterator;
//		typedef RevBidirectionalIterator<value_type , node_pointer > reverse_iterator;
//		typedef ConstRevBidirectionalIterator<value_type, node_pointer> const_reverse_iterator;

	private:
		// here are the member vars
		node_pointer	_head;
		node_pointer	_tail;
		size_type 		_size;
		allocator_type _allocator;
		// Constructors
	public:
		explicit list(const allocator_type& alloc = allocator_type()) : _allocator(alloc)
		{
			_head = new listNode<value_type>;
			_tail = new listNode<value_type>;
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
		}

		explicit list(size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type())
		{
			_head = new listNode<value_type>;
			_tail = new listNode<value_type>;
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
			assign(n, val);
		}

		template <class inputIterator>
			list (inputIterator first, inputIterator last, const allocator_type& alloc = allocator_type())
		{

		}

		list (const list &x)
		{

		}
		// Destructors
		~list()
		{

		}
		// Assignment operators
		list<T, Alloc>& operator=(const list<T, Alloc>& x)
		{

		}
		// Allocators
		allocator_type get_allocator() const
		{

		}

		// Iterators
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//
//		const_iterator begin() const
//		{
//			return const_iterator(_head->_next);
//		}
//
//		iterator end()
//		{
//			return iterator (_tail);
//		}
//
//		const_iterator end() const
//		{
//			return const_iterator (_tail);
//		}
//
//		reverse_iterator rbegin()
//		{
//			return reverse_iterator (_head->_next);
//		}
//
//		const_reverse_iterator rbegin() const
//		{
//			return const_reverse_iterator (_head->_next);
//		}
//
//		reverse_iterator rend()
//		{
//			return reverse_iterator (_tail);
//		}
//
//		const_reverse_iterator rend() const
//		{
//			return const_reverse_iterator (_tail);
//		}
//
//		// Member Functions
//		template <class InputIterator> void assign(InputIterator start, InputIterator finish)
//		{
//
//		}
//
		void assign(size_type n, const value_type& val)
		{
			clear();
			while(n)
			{
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
			while(_size) {
				pop_back();
			}
		}

		bool empty() const
		{
			if(_size == 0)
				return true;
			else
				return false;
		}

		size_type size() const
		{
			return _size;
		}

//		iterator erase(iterator position)
//		{
//
//		}

//		iterator erase(iterator start, iterator finish)
//		{
//
//		}
//
		reference front()
		{
			return _head->getNext()->_data;
		}

		const_reference front() const
		{
			return _head->getNext()->_data;
		}

//		iterator insert(iterator position, const T& x)
//		{
//
//		}
//
//		void 	insert(iterator position, size_type n, const T& x)
//		{
//
//		}
//
//		void 	insert(iterator position, size_type n, const T& x)
//		{
//
//		}
//
//		template<class InputIterator>
//				void insert(iterator position, InputIterator start, InputIterator finish)
//		{
//
//		}
//
		size_type max_size() const
		{
			return this->_allocator.max_size();
		}
//
//		void merge(list<T, Alloc>&x)
//		{
//
//		}
//
		void pop_back()
		{
			if (_size)
			{
				listNode<value_type>* tmp;
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
			if (_size)
			{
				listNode<value_type>* node;
				node = _head->_next;
				_head->_next = node->_next;
				node->_next->_prev = _head;
				_size--;
				delete node;
			}

		}

		void push_back(const value_type& val)
		{
			listNode<value_type>* node;
			node = new listNode<value_type>(val);
			node->_prev = _tail->_prev;
			_tail->_prev->_next = node;
			_tail->_prev = node;
			node->_next = _tail;
			_size++;
		}

		void push_front(const value_type& val)
		{
			listNode<value_type>* node;
			node = new listNode<value_type>(val);
			node->_prev = _head;
			node->_next = _head->_next;
			_head->_next->_prev = node;
			_head->_next = node;
			_size++;
		}

//		void remove(const T& value)
//		{
//
//		}
//
//		template<class class Predicate>
//				void remove_if(predicate pred)
//		{
//
//		}
//
//		void resize(size_type sz, T c)
//		{
//
//		}
//
//		void reverse()
//		{
//
//		}
//
//		size_type size() const
//		{
//
//		}
//
//		size_type size() const
//		{
//
//		}
//
//		void sort()
//		{
//
//		}
//
//		template< class compare>
//				void sort (compare comp)
//		{
//
//		}
//
//		void splice(iterator position, list<T, Allocator>& x)
//		{
//
//		}
//
//		void splice(iterator position, list<T, Allocator>& x, iterator i)
//		{
//
//		}
//
//		void splice(iterator position, list<T, Allocator>& x, iterator start, iterator finish)
//		{
//
//		}
//
//		void swap(list<T, Allocator& x)
//		{
//
//		}
//
//		void unique()
//		{
//
//		}
//
//		template <class BinaryPredicate>
//				void unique(BinaryPredicate binary_pred)
//		{
//
//		}
//

//		// Nonmember Operators
//		template<class T, class Alloc>
//				bool operator==(const list<T, Alloc>& x, const list<T, Alloc>&y)
//		{
//
//		}
//
//		template<class T, class Allocator>
//		bool operator!=(const list<T, Allocator>& x, const list<T, Allocator>&y)
//		{
//
//		}
//
//		template<class T, class Allocator>
//		bool operator<(const list<T, Allocator>& x, const list<T, Allocator>&y)
//		{
//
//		}
//
//		template<class T, class Allocator>
//		bool operator>(const list<T, Allocator>& x, const list<T, Allocator>&y)
//		{
//
//		}
//
//		template<class T, class Allocator>
//		bool operator<=(const list<T, Allocator>& x, const list<T, Allocator>&y)
//		{
//
//		}
//
//		template<class T, class Allocator>
//		bool operator>=(const list<T, Allocator>& x, const list<T, Allocator>&y)
//		{
//
//		}

	};
}

#endif //MY_FT_CONTAINERS_LIST_HPP
