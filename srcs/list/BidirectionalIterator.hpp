//
// Created by Thimo Van der meer on 10/05/2021.
//

#ifndef MY_FT_CONTAINERS_BIDIRECTIONALITERATOR_HPP
#define MY_FT_CONTAINERS_BIDIRECTIONALITERATOR_HPP
#include <iterator>
#include <cstddef>
#include "listNode.hpp"

namespace ft {
	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class BidirectionalIterator {
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;
		typedef N                           node_pointer;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Category					iterator_category;
		typedef BidirectionalIterator		self_type;

	protected:
		node_pointer  _ptr;

	public:
		BidirectionalIterator(): _ptr(NULL) {}
		explicit BidirectionalIterator(node_pointer node) :_ptr(node) {}
		BidirectionalIterator(const BidirectionalIterator& obj) {*this = obj;}
		BidirectionalIterator& operator= (const BidirectionalIterator& obj){
			if(&obj != this){
				_ptr = obj._ptr;
			}
			return *this;
		}
		virtual ~BidirectionalIterator() {}

		// Prefix increment
		BidirectionalIterator&	operator++()
		{
			_ptr = _ptr->getNext();
			return *this;
		}

		// Postfix increment
		BidirectionalIterator 	operator++(int)
		{
			BidirectionalIterator ret(*this);
			++(*this);
			return ret;
		}

		// Prefix decrement
		BidirectionalIterator& operator--()
		{
			_ptr = _ptr->getPrev();
			return *this;
		}

		// Postfix decrement
		BidirectionalIterator operator--(int)
		{
			BidirectionalIterator ret(*this);
			--(*this);
			return ret;
		}

		reference operator*() const {
			return (_ptr->_data);
		}

		pointer 	operator->() {
			return &this->_ptr->_data;
		}

		bool operator== (const BidirectionalIterator& obj) {
			return (_ptr == obj._ptr);
		}

		bool operator!= (const BidirectionalIterator& obj) {
			return (_ptr != obj._ptr);
		}

		bool operator>=(const BidirectionalIterator& obj) {
			return (_ptr >= obj._ptr);
		}

		node_pointer getPtr() const {
			return (_ptr);
		}
	};

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class ConstBidirectionalIterator : public BidirectionalIterator<T, N>{
	public:
		typedef T								value_type;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
		typedef value_type*						pointer;
		typedef const value_type*				const_pointer;
		typedef N                          		node_pointer;
		typedef size_t							size_type;
		typedef ptrdiff_t						difference_type;
		typedef Category						iterator_category;
		typedef ConstBidirectionalIterator		self_type;

	public:
		ConstBidirectionalIterator(): BidirectionalIterator<T, N>() {}
		explicit ConstBidirectionalIterator(node_pointer node) : BidirectionalIterator<T,N>(node) {}
		ConstBidirectionalIterator(const ConstBidirectionalIterator& obj): BidirectionalIterator<T,N>(obj) {*this = obj;}
		ConstBidirectionalIterator(const BidirectionalIterator<T, N>& obj): BidirectionalIterator<T,N>(obj) {*this = obj;}
		ConstBidirectionalIterator& operator= (const ConstBidirectionalIterator& obj){
			if(&obj != this){
				this->_ptr = obj.getPtr();
			}
			return *this;
		}
		ConstBidirectionalIterator& operator= (const BidirectionalIterator<T, N>& obj){
			if(&obj != this){
				this->_ptr = obj.getPtr();
			}
			return *this;
		}
		virtual ~ConstBidirectionalIterator(){}

		const_reference operator*() const {
			return (this->_ptr->_data);
		}

		const_pointer 	operator->() {
			return (this->_ptr);
		}

		bool operator== (const ConstBidirectionalIterator& obj) {
			return (this->_ptr == obj._ptr);
		}

		bool operator!= (const ConstBidirectionalIterator& obj) {
			return (this->_ptr != obj._ptr);
		}

		bool operator>=(const ConstBidirectionalIterator& obj) {
			return (this->_ptr >= obj._ptr);
		}

		node_pointer getPtr() const {
			return (this->_ptr);
		}
	};
}


#endif //MY_FT_CONTAINERS_BIDIRECTIONALITERATOR_HPP
