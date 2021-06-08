//
// Created by Thimo Van der meer on 08/06/2021.
//

#ifndef MY_FT_CONTAINERS_MAP_HPP
#define MY_FT_CONTAINERS_MAP_HPP
#include "../iterators/BidirectionalIterator.hpp"
namespace ft {
	template< 	class Key,
				class T,
				class Compare = std::less<Key>,
				class Alloc = allocator<pair<const Key, T >>
	class map
	{
		typedef Key																	key_type;
		typedef T																	mapped_type;
		typedef pair<const key_type, mapped_type>									value_type;
		typedef Compare																key_compare;
		typedef T&																	reference;
		typedef const T&															const_reference;
		typedef T*																	pointer;
		typedef const T*															const_pointer;
		// nodepointer
		// node

		typedef Alloc																allocator_type;
		typedef ptrdiff_t 															difference_type;
		typedef size_t																size_type;
		typedef BidirectionalIterator<value_type, node_pointer, Alloc>				iterator;
		typedef ConstBidirectionalIterator<value_type, node_pointer, Alloc>			const_iterator;
		typedef RevBidirectionalIterator<value_type, node_pointer, Alloc>			reverse_iterator;
		typedef ConstRevBidirectionalIterator<value_type, node_pointer,Alloc>		const_reverse_iterator;

		// constructors
		explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type)
		{

		}

		template<class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
		{

		}

		map (const map& x)
		{

		}

		// destructors
		~map()
		{

		}
		// operator==
		map& operator= (const map& x)
		{

		}

		// Iterators
			// begin
		iterator begin()
		{

		}

		const_iterator begin() const
		{

		}

			// end
		iterator end()
		{

		}

		const_iterator end() const
		{

		}

			// rbegin
		reverse_iterator rbegin()
		{

		}

		const_reverse_iterator rbegin() const
		{

		}
			// rend
		reverse_iterator rend()
		{

		}

		const_reverse_iterator rend() const
		{

		}

		// capacity
		// empty
		bool empty() const
		{

		}
		// size
		size_type size() const
		{

		}

		// max_size
		size_type max_size() const
		{

		}

		// element acces
			// operator[]
		mapped_type& operator[] (const key_type& k)
		{

		}

		// modifiers
		// insert
		pair<iterator, bool> insert(const value_type& val)
		{

		}

		iterator insert (iterator position, const value_type& val)
		{

		}

		template <class InputIterator>
				void insert (InputIterator first, InputIterator last)
		{

		}

		// erase
		void erase(iterator position)
		{

		}

		size_type erase (const key_type& k)
		{

		}

		void erase(iterator first, iterator last)
		{

		}

		// swap
		void swap(map& x)
		{

		}

		// clear
		void clear()
		{

		}

		// observers
		// key_comp
		key_compare key_comp() const
		{

		}

		// value_comp
		value_compare value_comp() const
		{

		}

		// operations
		// find
		iterator find (const key_type& k)
		{

		}

		const_iterator find (const key_type& k) const
		{

		}

		// count
		size_type count (const key_type& k) const
		{

		}

		// lower_bound
		iterator lower_bound (const key_type& k)
		{

		}

		const_iterator lower_bound(const key_type& k) const
		{

		}

		// upper_bound
		iterator upper_bound (const key_type& k)
		{

		}

		const_iterator upper_bound(const key_type& k) const
		{

		}

		// equal_range

		pair<const_iterator, const_iterator> equal_range (const key_type& k) const
		{

		}

		pair<iterator, iterator>			equal_range(const key_type& k)
		{

		}

		// allocators
		// get_allocators
		allocator_type get_allocator() const
		{

		}

	};
}
#endif //MY_FT_CONTAINERS_MAP_HPP
