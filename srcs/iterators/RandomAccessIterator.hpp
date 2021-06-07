//
// Created by Thimo Van der meer on 26/05/2021.
//

#ifndef MY_FT_CONTAINERS_RANDOMACCESSITERATOR_HPP
#define MY_FT_CONTAINERS_RANDOMACCESSITERATOR_HPP
#include "../utils/typeTraits.hpp"
namespace ft{
	template< typename T, class Pointer, class Reference, class Category = ft::random_access_iterator_tag>
	class RandomAccessIterator
	{
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef ptrdiff_t	difference_type;
		typedef value_type	*pointer;
		typedef value_type	&reference;

	protected:
		pointer _ptr;

	public:
		RandomAccessIterator(): _ptr(nullptr) {}
		RandomAccessIterator(pointer ptr) : _ptr(ptr) {}
//		explicit RandomAccessIterator(pointer ptr) : _ptr(ptr) {}
		RandomAccessIterator(const RandomAccessIterator<T, Pointer, Reference>& obj) { *this = obj;}
		RandomAccessIterator& operator= (const RandomAccessIterator<T, Pointer, Reference>& obj){
			if(&obj != this){
				_ptr = obj._ptr;
			}
			return *this;
		}

		virtual ~RandomAccessIterator() {}

		// operators : misc
		RandomAccessIterator& operator+=(const RandomAccessIterator<T, Pointer, Reference>& rhs) { _ptr += rhs; return *this;}
		RandomAccessIterator& operator-=(const RandomAccessIterator<T, Pointer, Reference>& rhs) { _ptr -= rhs; return *this;}
		reference operator*() {return *_ptr;}
		pointer   operator->() {return _ptr;}
		reference operator[] (const int& rhs) {return _ptr[rhs];}

		// operators: arithmetic
		RandomAccessIterator& operator++() {++_ptr; return *this;}
		RandomAccessIterator& operator--() {--_ptr; return *this;}
		RandomAccessIterator operator++(int) {RandomAccessIterator<T, Pointer, Reference> tmp(*this); ++_ptr; return tmp;}
		RandomAccessIterator operator--(int) {RandomAccessIterator<T, Pointer, Reference> tmp(*this); --_ptr; return tmp;}
		RandomAccessIterator  operator+(const difference_type &number) const
		{
			RandomAccessIterator tmp(*this);
			tmp._ptr += number;
			return (tmp);
		}

		difference_type operator-(RandomAccessIterator<T, Pointer, Reference> rhs) const
		{
			return (this->_ptr - rhs._ptr);
		}

		RandomAccessIterator operator-(const difference_type &number) const
		{
			RandomAccessIterator tmp(*this);
			tmp._ptr -= number;
			return (tmp);
		}

		// operators comparison

		bool operator==(const RandomAccessIterator<T, Pointer, Reference> &rhs) {return _ptr == rhs._ptr;}
		bool operator!=(const RandomAccessIterator<T, Pointer, Reference> &rhs) {return _ptr != rhs._ptr;}
		bool operator>(const RandomAccessIterator<T, Pointer, Reference> &rhs) {return _ptr > rhs._ptr;}
		bool operator<(const RandomAccessIterator<T, Pointer, Reference> &rhs) {return _ptr < rhs._ptr;}
		bool operator>=(const RandomAccessIterator<T, Pointer, Reference> &rhs) {return _ptr >= rhs._ptr;}
		bool operator<=(const RandomAccessIterator<T, Pointer, Reference> &rhs) {return _ptr <= rhs._ptr;}

	};
}
#endif //MY_FT_CONTAINERS_RANDOMACCESSITERATOR_HPP
