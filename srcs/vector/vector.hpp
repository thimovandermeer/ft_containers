//
// Created by Thimo Van der meer on 25/05/2021.
//

#ifndef MY_FT_CONTAINERS_VECTOR_HPP
#define MY_FT_CONTAINERS_VECTOR_HPP
#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/ReverseIterator.hpp"
#include <iostream>
namespace ft {
	template < class T, class Alloc = std::allocator<T>>
	class vector
	{
	public:
		typedef T 													value_type;
		typedef Alloc 												allocator_type;
		typedef T 													&reference;
		typedef const T 											&const_reference;
		typedef T 													*pointer;
		typedef const T 											*const_pointer;
		typedef RandomAccessIterator<T, T*, T&>						iterator;
		typedef RandomAccessIterator< const T, const T*, const T&>	const_iterator;
		typedef ReverseIterator<iterator>							reverse_iterator;
		typedef ReverseIterator<const_iterator>						const_reverse_iterator;
		typedef ptrdiff_t 											difference_type;
		typedef size_t												size_type;

	private:
		// member variabels
		size_t 			_size; // number of elements in Vector
		pointer			_elements; // pointer to first element
		size_t 			_space; // total space used by vector including elements and free space
		allocator_type 	_alloc; // which type of allocator is being used

	public:


		// constructors

		// default
		explicit vector (const allocator_type& alloc = allocator_type()):
			_size(0),
			_space(0),
			_elements(nullptr),
			_alloc(alloc)
		{
		};
		// fill
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type alloc = allocator_type()):
			_size(n),
			_space(n),
			_alloc(alloc)
		{
			_elements = _alloc.allocate(_space);
			for(size_type i = 0; i < _size; i++)
				_alloc.construct(&_elements[i], val);
		};

		// range // woensdag ochtend bouwen
//		template < class InputIterator>
//			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
//			_size(first - last),
//			_space(first - last),
//			_alloc(alloc)
//		{
//			_elements = _alloc.allocate(_space);
//			for (size_type i = 0; i < _size; i++, first++)
//				_alloc.construct(&_elements[i], *first);
//		}
		// copy
		vector (const vector& x) :
		_size(x.size()),
		_space(x._space),
		_alloc(x._alloc)
		{
			if(!x.size())
				return;
			_elements = _alloc.allocate(_space);
			for(int i = 0; i < _size; i++)
				_elements[i] = x._elements[i];

		}


		// destructor
		~vector()
		{
			// destroy all elements
			for(size_type i = 0; i < _size; i++)
				_alloc.destroy(&_elements[i]);
			_alloc.deallocate(_elements, _space);
			_elements = nullptr;
		}

		// operator=
		vector& operator= (const vector& x)
		{
			// de allocate current space and stuff
			for(size_type i = 0; i < _size; i++)
				_alloc.destroy(&_elements[i]);
			_alloc.deallocate(_elements, _space);

			_elements = NULL;
			_space = 0;
			_size = 0;

			// reallocate with the specs of X
			_space = x._space;
			_size = x._size;
			_alloc = x._alloc;
			_elements = _alloc.allocate(_space);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_elements[i], x._elements[i]);

			return (*this);
		}
		// iterators
		iterator begin()
		{
			return iterator(_elements);
		}

		const_iterator begin() const
		{
			return const_iterator(_elements);
		}

		iterator end()
		{
			return iterator(&_elements[_size]);
		}

		const_iterator end() const
		{
			return const_iterator(&_elements[_size]);
		}

//		reverse_iterator rbegin()
//		{
//
//		}
//
//		const_reverse_iterator rbegin() const
//		{
//
//		}
//
//		reverse_iterator rend()
//		{
//
//		}
//
//		const_reverse_iterator rend() const
//		{
//
//		}

		// capacity
		size_type size() const
		{
			return _size;
		}

		size_type max_size() const
		{
			return(_alloc.max_size());
		}

		void resize(size_type n, value_type val = value_type())
		{
			// need reserve for this one
			if (n > _space)
				reserve(n);
			while(_size < n)
				push_back(val);
			while(_size > n)
				pop_back();


		}

		size_type capacity() const
		{
			return (_space);
		}

		bool empty() const
		{
			if (_size == 0)
				return true;
			else
				return false;
		}

		// de allocate current space and stuff

		void reserve(size_type n)
		{
			if (n < _space)
				return;
			if (n > max_size())
				throw std::length_error("ft::vector: length exceeds max length");
			pointer new_elements = _alloc.allocate(n);
			for(size_type i = 0; i < _size; i++)
				_alloc.construct(&new_elements[i], _elements[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_elements[i]);
			_alloc.deallocate(_elements, _space);
			_space = n;
			_elements = new_elements;
		}


		// element access
		reference operator[] (size_type n)
		{
			return(_elements[n]);
		}

		const_reference  operator[] (size_type n) const
		{
			return(_elements[n]);
		}

		reference at (size_type n)
		{
			if (n < 0 || n >= _size)
				throw std::out_of_range("Index position out of range");
			return(_elements[n]);
		}

		const_reference at (size_type n) const
		{
			if (n < 0 || n >= _size)
				throw std::out_of_range("Index position out of range");
			return(_elements[n]);
		}

		reference front()
		{
			return(_elements[0]);
		}

		const_reference  front() const
		{
			return(_elements[0]);
		}

		reference back()
		{
			return(_elements[_size - 1]);
		}

		const_reference back() const
		{
			return(_elements[_size - 1]);
		}

		// Modifiers
		template<class InputIterator>
				void assign (InputIterator first, InputIterator last)
		{

		}

		void assign(size_type n, const value_type& val)
		{

		}

		void push_back(const value_type& val)
		{
			if (_space == 0)
				reserve(1);
			if(_size >= _space)
				reserve(_space * 2);
			_alloc.construct(&_elements[_size], val);
			_size++;
		}

		void pop_back()
		{
			if (!_size)
				return ;
			_alloc.destroy(&_elements[_size - 1]);
			_size--;
		}

		// insert single element
//		iterator insert (iterator position, const value_type& val)
//		{
//
//		}
//
//		// insert fill
//		void insert (iterator position, size_type n, const value_type& val)
//		{
//
//		}
//
//		// insert range
//		template<class InputIterator>
//				void insert (iterator position, InputIterator first, InputIterator last)
//		{
//
//		}
//
//		iterator erase (iterator position)
//		{
//
//		}
//
//		iterator erase (iterator first, iterator last)
//		{
//
//		}

		void swap(vector &x)
		{

		}

		void clear()
		{

		}

		// Allocators
		allocator_type get_allocator() const
		{
			return (_alloc);
		}

		// non  member functions overloads
//		template<class class T, class Alloc>
//				bool operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs))
//		{
//
//		}
//
//		template<class class T, class Alloc>
//		bool operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs))
//		{
//
//		}
//
//		template<class class T, class Alloc>
//		bool operator< (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs))
//		{
//
//		}
//
//		template<class class T, class Alloc>
//		bool operator <= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs))
//		{
//
//		}
//
//		template<class class T, class Alloc>
//		bool operator> (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs))
//		{
//
//		}
//
//		template<class class T, class Alloc>
//		bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs))
//		{
//
//		}
//
//		template<class T, class Alloc>
//				void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
//		{
//
//		}
	// random acces iterator bouwen (ander bestand)
	};
}
#endif //MY_FT_CONTAINERS_VECTOR_HPP
