//
// Created by Thimo Van der meer on 08/06/2021.
//

#ifndef MY_FT_CONTAINERS_MAP_HPP
#define MY_FT_CONTAINERS_MAP_HPP
#include "../iterators/BidirectionalIterator.hpp"
#include "MapNode.hpp"

namespace ft {
	template< 	class Key,
				class T,
				class Compare = std::less<Key>,
				class Alloc = std::allocator<std::pair<const Key, T> >
	> class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef mapNode<value_type> *node_pointer;
		typedef mapNode<value_type> node;
		typedef Alloc allocator_type;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef BidirectionalIterator<value_type, node_pointer, Alloc> iterator;
		typedef ConstBidirectionalIterator<value_type, node_pointer, Alloc> const_iterator;
		typedef RevBidirectionalIterator<value_type, node_pointer, Alloc> reverse_iterator;
		typedef ConstRevBidirectionalIterator<value_type, node_pointer, Alloc> const_reverse_iterator;


	private:
		node_pointer _root;
		node_pointer _first;
		node_pointer _last;
		size_type _size;
		key_compare _comp;
		allocator_type _alloc;

	public:
		// constructors
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) :
				_root(NULL),
				_first(NULL),
				_last(NULL),
				_size(0),
				_comp(comp),
				_alloc(alloc)
		{
			// should do nothing just an empty map
		}

		template<class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type())
		{

		}

		map(const map &x)
		{

		}

		// destructors
		~map()
		{

		}

		// operator==
		map &operator=(const map &x)
		{

		}

		// Iterators
		// begin
		iterator begin()
		{
			return iterator(_first->getParent());
		}

		const_iterator begin() const
		{
			return const_iterator(_first->getParent());
		}

		// end
		iterator end()
		{
			return iterator(_last);
		}

		const_iterator end() const
		{
			return const_iterator(_last);
		}

		// rbegin
		reverse_iterator rbegin()
		{
			return reverse_iterator(_first->getParent());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(_first->getParent());
		}

		// rend
		reverse_iterator rend()
		{
			return reverse_iterator(_last);
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(_last);
		}

		// capacity
		// empty
		bool empty() const
		{
			if (_size == 0)
				return true;
			else
				return false;
		}

		// size
		size_type size() const
		{
			return (_size);
		}

		// max_size
		size_type max_size() const
		{
			_alloc.max_size();
		}

		// element acces
		// operator[]
		mapped_type &operator[](const key_type &k)
		{
			// safe the key to the designated element

		}

		// modifiers
		// insert
		std::pair<iterator, bool> insert(const value_type &val)
		{
			mapNode<value_type> newNode(val);

			mapNode<value_type> y = nullptr;
			mapNode<value_type> x = _root;

			while (x.getNill() != true) {
				y = x;
				if (newNode.getData() < x.getData())
					x = x.getLeft();
				else
					x = x.getRight();
			}

			newNode.getParent() = y;
			if (y == nullptr)
				_root = newNode;
			else if (newNode.getData() < y.getData())
				y.getLeft() = newNode;
			else
				y.getRight() = newNode;

			if (newNode.getParent() == nullptr) {
				newNode.setColor(Black);
				return; // returns moeten naar pair return (later)
			}

			if (newNode.getParent()->getParent() == nullptr)
				return; // returns moeten naar pair return (later)

			// tree fixen
			fixInsert(newNode);
			// return statement hieronder nog
		}

		iterator insert(iterator position, const value_type &val)
		{

		}

		template<class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{

		}

		// erase
		void erase(iterator position)
		{

		}

		size_type erase(const key_type &k)
		{

		}

		void erase(iterator first, iterator last)
		{

		}

		// swap
		void swap(map &x)
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

		// value_comp later implementeren blijft nu rood
//		value_compare value_comp() const
//		{
//
//		}

		// operations
		// find
		iterator find(const key_type &k)
		{

		}

		const_iterator find(const key_type &k) const
		{

		}

		// count
		size_type count(const key_type &k) const
		{

		}

		// lower_bound
		iterator lower_bound(const key_type &k)
		{

		}

		const_iterator lower_bound(const key_type &k) const
		{

		}

		// upper_bound
		iterator upper_bound(const key_type &k)
		{

		}

		const_iterator upper_bound(const key_type &k) const
		{

		}

		// equal_range

		std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{

		}

		std::pair<iterator, iterator> equal_range(const key_type &k)
		{

		}

		// allocators
		// get_allocators
		allocator_type get_allocator() const
		{
			return _alloc;
		}
// mainly extra functions for the red black implementation
	private:
		void fixInsert(mapNode<value_type> newNode)
		{
			mapNode<value_type> u;
			// if color is red
			while (newNode.getParent()->getColor() == Red)
			{
				if (newNode.getParent() == newNode.getParent()->getParent()->getRight())
				{
					u = newNode.getParent()->getParent()->getLeft();
					if (u.getColor() == Red)
					{
						// case Parent is red and Uncle is red too
						u.setColor(Black); // change color of U to restore color balance
						newNode.getParent()->setColor(Black);
						newNode.getParent()->getParent()->setColor(Red); // two up in hierarchy change the color
						newNode = newNode.getParent()->getParent(); // change the position of the newNode so it moves up
					}
					else
					{
						if (newNode == newNode.getParent()->getLeft())
					}
				}
			}
			// if color is black

			// if newnode is root
		}

	};
}
#endif //MY_FT_CONTAINERS_MAP_HPP
