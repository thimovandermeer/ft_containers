//
// Created by Thimo Van der meer on 25/05/2021.
//

#ifndef MY_FT_CONTAINERS_VECTOR_HPP
#define MY_FT_CONTAINERS_VECTOR_HPP
#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/ReverseIterator.hpp"
namespace ft {
	template < class T, class Alloc = std::allocator<T>>
	class vector
	{
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
			_space = _alloc.allocate(_space);
			for(size_type i = 0; i < _size; i++)
				_alloc.construct(_space[i], val);
		};

		// destructor
		~vector()
		{

		}

		// operator=
		vector& operator= (const vector& x)
		{

		}

		// range
		template < class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		{

		}
		// copy
		vector (const vector& x)
		{

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

		}

		void resize(size_type n, value_type val = value_type())
		{

		}

		size_type capacity() const
		{
			return (_space);
		}

		bool empty() const
		{

		}

		void reserve(size_type n)
		{

		}


		// element access
		reference operator[] (size_type n)
		{

		}

		const_reference  operator[] (size_type n) const
		{

		}

		reference at (size_type n)
		{

		}

		const_reference at (size_type n) const
		{

		}

		reference front()
		{

		}

		const_reference  front() const
		{

		}

		reference back()
		{

		}

		const_reference back() const
		{

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
			if(_size >= _space)
			{
				// dit moet met allocator types
				reserve();
			}
			_elements[_size] = val;
			_size++;
		}

		void pop_back()
		{

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
