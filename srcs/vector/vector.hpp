//
// Created by Thimo Van der meer on 25/05/2021.
//

#ifndef MY_FT_CONTAINERS_VECTOR_HPP
#define MY_FT_CONTAINERS_VECTOR_HPP
#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/ReverseIterator.hpp"
#include "../utils/utils.hpp"
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
		typedef RandomAccessIterator<T, const T*, const T&>			const_iterator;
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
			_elements(nullptr),
			_space(0),
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
		template < class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		   		typename iterator_traits<InputIterator>::type* = NULL) :
			_size(0),
			_elements(NULL),
			_space(0),
			_alloc(alloc)
		{
				std::cout << "voor assign\n";
				assign(first, last);
				std::cout << "na assign\n";
		}
		// copy
		vector (const vector& x) :
		_size(x.size()),
		_elements(NULL),
		_space(x._space),
		_alloc(x._alloc)
		{
			if(!x.size())
				return;
			_elements = _alloc.allocate(_space);
			for(int i = 0; i < (int)_size; i++)
				_elements[i] = x._elements[i];

		}
		// destructor
		~vector()
		{
			// destroy all elements
			for(size_type i = 0; i < _size; i++)
				this->_alloc.destroy(&this->_elements[i]);
			this->_alloc.deallocate(this->_elements, this->_space);
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

		reverse_iterator rbegin()
		{
			return reverse_iterator (end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator (begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator (begin());
		}

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
			if (n <= _space)
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
			clear();
			while(first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void assign(size_type n, const value_type& val)
		{
			clear();
			reserve(n);
			_size = n;
			for(size_type i = 0; i < n ; i++)
				_alloc.construct(&_elements[i], val);
		}

		void push_back(const value_type& val)
		{
			if(_size == _space)
			{
				if (_space == 0)
					reserve(1);
				else
					reserve(_space * 2);
			}

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
		iterator insert (iterator position, const value_type& val)
		{
			difference_type index = distance(this->begin(), position);
//			std::cout << index << std::endl;
			this->insert(position, 1, val);
			iterator ret = this->begin();
			for (difference_type i = 0; i < index; i++)
				ret++;
			return (ret);
		}

		// insert fill
		void insert (iterator position, size_type n, const value_type& val)
		{
			difference_type pos = distance(begin(), position);
			if (_size + n > _space)
				reserve(this->_size + n);
			for (size_type i = _size + n - 1; i >= pos + n; i--)
			{
				_alloc.construct(&_elements[i], _elements[i - n]);
				_alloc.destroy(&_elements[i - n]);
			}
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_elements[pos + i], val);
			_size += n;
		}

		// insert range
		template<class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last,
				 			typename iterator_traits<InputIterator>::type* = 0)
		{
			vector tmp(position, this->end());
			while(position != this->end())
				this->pop_back();
			while (first != last)
			{
				this->push_back(*first);
				++first;
			}
			for (InputIterator it = tmp.begin(); it != tmp.end(); ++it)
				this->push_back(*it);
		}

		iterator erase (iterator position)
		{
			difference_type n = distance(begin(), end() - 1);
			difference_type pos = distance(begin(), position);
			pointer new_elements = _alloc.allocate(n);
			_size--;
			size_type j = 0;
			iterator ret(position);
			ret++;
			for (size_type i = 0; i < _size; i++)
			{
				if (i == (size_type)pos)
					j++;
				_alloc.construct(&new_elements[i], _elements[j]);
				j++;
			}
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_elements[i]);
			_alloc.deallocate(_elements, _space);
			_elements = new_elements;
			return (ret);
		}

		iterator erase (iterator first, iterator last)
		{
			// creert een blok met de grote van de huidige min de distance tussen begin en end
			difference_type new_size = _size - distance(first, last);
			difference_type start_pos = distance(begin(), first);
			difference_type skip_amount = distance(first, last);
			pointer new_elements = _alloc.allocate(new_size);
			_size = new_size;

			size_type i = 0;
			iterator ret(last);
			ret++;
			for (size_type j = 0; i < _size; j++)
			{
				while (j >= (size_type)start_pos && j < (size_type)start_pos + skip_amount)
					j++;
				_alloc.construct(&new_elements[i], _elements[j]);
				i++;
			}
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_elements[i]);
			_alloc.deallocate(_elements, _space);
			_elements = new_elements;
			return (ret);
		}

		void swap(vector &x)
		{
			itemSwap(_elements, x._elements);
			itemSwap(_space, x._space);
			itemSwap(_alloc, x._alloc);
			itemSwap(_size, x._size);
		}

		void clear()
		{
			for(size_type i = 0; i < _size; i++)
				_alloc.destroy(&_elements[i]);
			_size = 0;
		}

		// Allocators
		allocator_type get_allocator() const
		{
			return (_alloc);
		}

	private:
		template<typename S>
		void itemSwap(S& first, S& second)
		{
			S tmp = first;
			first = second;
			second = tmp;
		}

		template<typename RandomAccessIterator>
		typename iterator_traits<RandomAccessIterator>::difference_type
		distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag)
		{
			return (last - first);
		}

		template<typename InputIterator>
		typename iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last, input_iterator_tag)
		{
			typename iterator_traits<InputIterator>::difference_type ret(0);
			while (first != last)
			{
				first++;
				ret++;
			}
			return (ret);
		}
		template<typename Iterator>
		typename iterator_traits<Iterator>::difference_type
		distance(Iterator first, Iterator last)
		{
			return (distance(first, last, typename iterator_traits<Iterator>::iterator_category()));
		}
	};

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		for (typename ft::vector<T>::size_type i = 0; i < lhs.size();i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return true;
	}

	template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template<class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}



}
#endif //MY_FT_CONTAINERS_VECTOR_HPP
