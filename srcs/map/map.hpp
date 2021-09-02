//
// Created by Thimo Van der meer on 08/06/2021.
//

#ifndef MY_FT_CONTAINERS_MAP_HPP
#define MY_FT_CONTAINERS_MAP_HPP
#include "../iterators/BidirectionalIterator.hpp"
#include "MapNode.hpp"
#include <iostream>
# define COUNT 10

namespace ft {

	enum findType {
		EQUAL,
		LOWER,
		UPPER
	};

	template< 	class Key,
				class T,
				class Compare = std::less<Key>,
				class Alloc = std::allocator<std::pair<const Key, T> >
	> class map
	{
	public:
		typedef Key 																key_type;
		typedef T 																	mapped_type;
		typedef std::pair<const key_type, mapped_type> 								value_type;
		typedef Compare 															key_compare;
		typedef T 																	&reference;
		typedef const T 															&const_reference;
		typedef T 																	*pointer;
		typedef const T 															*const_pointer;
		typedef mapNode<value_type> 												*node_pointer;
		typedef mapNode<value_type> 												node;
		typedef Alloc 																allocator_type;
		typedef ptrdiff_t 															difference_type;
		typedef size_t 																size_type;
		typedef BidirectionalIterator<value_type, node_pointer, Alloc> 				iterator;
		typedef ConstBidirectionalIterator<value_type, node_pointer, Alloc> 		const_iterator;
		typedef RevBidirectionalIterator<value_type, node_pointer, Alloc>			reverse_iterator;
		typedef ConstRevBidirectionalIterator<value_type, node_pointer, Alloc>		const_reverse_iterator;

	private:
		node_pointer 	_root;
		node_pointer 	_first;
		node_pointer 	_last;
		size_type 		_size;
		key_compare 	_comp;
		allocator_type 	_alloc;


		class value_compare : std::binary_function<value_type, value_type , bool>
		{
			friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

		void variabels()
		{
			this->_root->left = this->_first;
			this->_root->right = this->_last;

			this->_first->parent = this->_root;
			this->_last->parent = this->_root;
		}

	public:

		// constructors
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) :
				_root(new node),
				_first(new node),
				_last(new node),
				_size(0),
				_comp(comp),
				_alloc(alloc)
		{
			variabels();
			return;
			// should do nothing just an empty map
		}

		template<class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()) :
				_root(new node),
				_first(new node),
				_last(new node),
				_size(0),
				_comp(comp),
				_alloc(alloc)
		{
			variabels();
			insert(first, last);
		}

		map(const map &x):
			_root(new node),
			_first(new node),
			_last(new node),
			_size(0),
			_comp(x._comp),
			_alloc(x._alloc)
		{
			variabels();
			insert(x.begin(), x.end());
		}

		// destructors
		~map()
		{
			std::cout << "size = " << this->size() << std::endl;

			this->clear();
			delete this->_first;
			delete this->_last;
			delete this->_root;
			return;
		}

		// operator==
		map &operator=(const map &x)
		{
			if (this != &x)
			{
				this->clear();
				this->_alloc = x._alloc;
				this->_comp = x._comp;
				this->_size = 0;
				insert(x.begin(), x.end());
			}
			return *this;
		}

		// Iterators
		// begin
		iterator begin()
		{
			return iterator(this->_first->parent);
		}

		const_iterator begin() const
		{
			return const_iterator(this->_first->parent);
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
			return reverse_iterator(this->_last->parent);
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(this->_last->parent);
		}

		// rend
		reverse_iterator rend()
		{
			return reverse_iterator(this->_first);
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(this->_first);
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
			return (_alloc.max_size());
		}

		// element acces
		// operator[]
		mapped_type &operator[](const key_type &k)
		{
			return (*((this->insert(std::make_pair(k, mapped_type()))).first)).second;
		}

		// modifiers
		// insert
		std::pair<iterator, bool> insert(const value_type &val)
		{
			node* checkExistence = searchNode(this->_root, val.first);

			if (checkExistence)
				return std::make_pair(iterator(checkExistence), false);

			checkExistence = insertNode(this->_root, val);
			this->_size += 1;
			return std::make_pair(iterator(checkExistence), true);
		}

		iterator insert(iterator position, const value_type &val)
		{
			node_pointer return_node;
			if(position->first > val.first)
			{
				iterator prev(position);
				--prev;
				while(prev != this->end() && prev->first >= val.first)
				{
					--position;
					--prev;
				}
			}
			else if (position->first < val.first)
			{
				iterator next(position);
				++next;
				while(next != this->end() && next->first <= val.first)
				{
					++position;
					++next;
				}
			}
			if (position != end() && val.first == position->first)
					return position;
			return_node = insertNode(position.getPtr(), val);
			this->_size += 1;
			return iterator(return_node);
		}

		template<class InputIterator>
		void insert(InputIterator first, InputIterator last,
			  typename iterator_traits<InputIterator>::type* = 0)
		{
			while(first != last)
			{
				insert(*first);
				++first;
			}
		}

//		// erase
		void erase(iterator position)
		{
			this->deleteNode(position.getPtr(), position->first);
			this->_size -= 1;
		}

		size_type erase(const key_type &k)
		{
			node_pointer exists = searchNode(this->_root, k);
			if(!exists)
				return 0;
			else
			{
				this->deleteNode(this->_root, k);
				this->_size -= 1;
				return 1;
			}
		}

		void erase(iterator first, iterator last)
		{
			while(first != last)
			{
				iterator tmp(first);
				++first;
				erase(tmp);
			}
		}

		// swap
		void swap(map &x)
		{
			swap(this->_root, x._root);
			swap(this->_first, x._first);
			swap(this->_last, x._last);
			swap(this->_size, x._size);
			swap(this->_alloc, x._alloc);
			swap(this->_comp, x._comp);
		}

//		// clear
		void clear()
		{
			erase(this->begin(), this->end());
		}

		// observers
		// key_comp
		key_compare key_comp() const
		{
			return (_comp);
		}

		value_compare value_comp() const
		{
			return (_comp);
		}

		// operations
		// find
		iterator find(const key_type &k)
		{
			node_pointer node = searchNode(_root, k);
			return (node ? iterator(node): end());
		}

		const_iterator find(const key_type &k) const
		{
			node_pointer node = searchNode(_root, k);
			return (node ? const_iterator(node): end());
		}
//
//		// count
		size_type count(const key_type &k) const
		{
			node_pointer  exists = searchNode(this->_root, k);

			if (exists)
				return 1;
			else
				return 0;
		}

//		// lower_bound
		iterator lower_bound(const key_type &k)
		{
			iterator it = this->begin();
			for(; it != this->end(); it++)
			{
				if(!this->_comp(it->first, k))
					break ;
			}
			return it;
		}

		const_iterator lower_bound(const key_type &k) const
		{
			const_iterator it = this->begin();
			for(; it != this->end(); it++)
			{
				if(!this->_comp(it->first, k))
					break ;
			}
			return it;
		}
//		// upper_bound
		iterator upper_bound(const key_type &k)
		{
			iterator it = this->begin();
			for(; it != this->end(); it++)
			{
				if (this->_comp(k, it->first))
					break;
			}
			return it;
		}

		const_iterator upper_bound(const key_type &k) const
		{
			const_iterator it = this->begin();
			for(; it != this->end(); it++)
			{
				if (this->_comp(k, it->first))
					break;
			}
			return it;
		}

//		// equal_range

		std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			const_iterator lower = lower_bound(k);
			const_iterator upper = upper_bound(k);
			return (std::make_pair(const_iterator(lower), const_iterator(upper)));
		}

		std::pair<iterator, iterator> equal_range(const key_type &k)
		{
			iterator lower = lower_bound(k);
			iterator upper = upper_bound(k);
			return (std::make_pair(iterator(lower), iterator(upper)));
		}

		// allocators
		// get_allocators
		allocator_type get_allocator() const
		{
			return _alloc;
		}

		void printBT() const {
			printBT("", this->_root, true);
			std::cout << std::endl;
		}
// mainly extra functions for the red black implementation
	private:

		template < typename U>
		void swap(U& a, U&b)
		{
			U tmp = a;
			a = b;
			b = tmp;
		}
		// find private functions
		node_pointer 	searchNode(node_pointer root, key_type key_value) const
		{
			// Statement if we've reached a max or min node or a leaf node
			if (root == NULL || root == this->_first || root == this->_last)
				return 0;

			// Statement if the key_value are equal the key_value already exist in the tree
			if (root->_data.first == key_value)
				return root;

			// Recursive loop that will go trough the whole tree
			if (root->_data.first > key_value && root->left && root->left != this->_first)
				return searchNode(root->left, key_value);
			if (root->_data.first < key_value && root->right && root->right != this->_last)
				return searchNode(root->right, key_value);
			return 0;

		}

		int heightTree(node_pointer root, int height)
		{
			if(root == NULL || root == this->_last || root == this->_first)
					return height -1;
			int leftHeight = heightTree(root->left, height + 1);
			int rightHeight = heightTree(root->right, height + 1);
			if(leftHeight > rightHeight)
				return leftHeight;
			else
				return rightHeight;
		}

		int balanceSubtrees(node_pointer node)
		{
			if (node == NULL)
				return 0;
			return heightTree(node->left, 1) - heightTree(node->right, 1);
		}

		void leftRotation(node *x)
		{
			node*  y = x->right;
			x->right = y->left;
			if(y->left)
				y->left->parent = x;
			y->left = x;
			y->parent = x->parent;

			if (x->parent && x->parent->left == x)
				x->parent->left = y;
			else if (x->parent)
				x->parent->right = y;
			x->parent = y;
			if(y->parent == NULL)
				this->_root = y;
		}

		void rightRotation(node* x)
		{
			node* y = x->left;

			x->left = y->right;

			if (y->right)
				y->right->parent = x;
			y->right = x;

			y->parent = x->parent;

			if(x->parent && x->parent->left == x)
				x->parent->left = y;
			else if (x->parent)
				x->parent->right = y;
			x->parent = y;

			if (y->parent == NULL)
				this->_root = y;

		}

		void balance_tree(node *node)
		{
			while(node)
			{
				int balanceFactor;

				if (((balanceFactor = balanceSubtrees(node)) < -1) && balanceSubtrees(node->right) < 0)
					leftRotation(node);
				else if (balanceFactor < -1 && (balanceSubtrees(node->right) >= 0))
				{
					rightRotation(node->right);
					leftRotation(node);
				}
				else if (balanceFactor > 1 && (balanceSubtrees(node->left) > 0))
					rightRotation(node);
				else if (balanceFactor > 1 && (balanceSubtrees(node->left) <= 0))
				{
					leftRotation(node->left);
					rightRotation(node);
				}
				node = node->parent;
			}
		}

		node *insertNode(node_pointer move, const value_type &val)
		{
			if (size() == 0)
			{
				delete this->_root;
				this->_root = new node(val);
				variabels();
				return this->_root;
			}

			if (move->_data.first == val.first)
				return 0;

			if (move->_data.first > val.first && move->left && move->left != this->_first)
				return insertNode(move->left, val);
			else if (move->_data.first < val.first && move->right && move->right != this->_last)
				return insertNode(move->right, val);

			node* new_node = new node(val);

			// left leaf
			if (move->_data.first > new_node->_data.first && !move->left)
			{
				move->left = new_node;
				new_node->parent = move;
			}
			// right lead
			else if (move->_data.first < new_node->_data.first && !move->right)
			{
				move->right = new_node;
				new_node->parent = move;
			}
			// min last element
			else if (move->left && (move->_data.first > new_node->_data.first))
			{
				new_node->left = this->_first;
				this->_first->parent = new_node;
				move->left = new_node;
				new_node->parent = move;
			}
			// max last element
			else if (move->right && (move->_data.first < new_node->_data.first))
			{
				new_node->right = this->_last;
				this->_last->parent = new_node;
				move->right = new_node;
				new_node->parent = move;
			}
			balance_tree(new_node);
			return new_node;
		}

		node_pointer  getMinNode(node_pointer root) const
		{
			if (root->left && root->left != this->_first)
				getMinNode(root->left);
			return root;
		}

		node_pointer  getMaxNode(node_pointer root) const
		{
			if(root->right && root->right != this->_last)
				getMaxNode(root->right);
			return root;
		}

		bool deleteNode(node_pointer deletePos, key_type k)
		{
			node_pointer tmpNode = NULL;
			node_pointer delNode = searchNode(deletePos, k);
			if(delNode == NULL)
				return false;

			if (delNode->parent == NULL)
			{
				if (delNode->left == this->_first && delNode->right == this->_last)
				{
					this->_first->parent = this->_last;
					this->_last->parent = this->_first;

					_alloc.destroy(&delNode->_data);
					this->_root = NULL;
				}
				else if (delNode->left && delNode->right == this->_last)
				{
					tmpNode = delNode->parent;
					this->_root = delNode->left;
					delNode->left->parent = NULL;

					this->_first->parent = delNode->left;
					delNode->left->right = this->_last;
				}

				else if(delNode->right && delNode->left == this->_first)
				{
					tmpNode = delNode->parent;
					this->_root = delNode->right;
					delNode->right->parent = NULL;

					this->_last->parent = delNode->right;
					delNode->right->left = this->_first;
				}
				else
				{
					node_pointer  maxNodeLeft = getMaxNode(delNode->left);
					_alloc.destroy(&delNode->_data);
					_alloc.construct(&delNode->_data, maxNodeLeft->_data);
					return deleteNode(delNode->left, maxNodeLeft->_data.first);
				}
			}
			else if ((delNode->left == NULL || delNode->left == this->_first) && (delNode->right == NULL || delNode->right == this->_last))
			{
				tmpNode = delNode->parent;
				node_pointer  lastElementLink = NULL;
				node_pointer firstElementLink = NULL;

				if (delNode->left == this->_first || delNode->right == this->_last)
				{
					lastElementLink = this->_last;
					firstElementLink = this->_first;
					if(delNode->_data.first <= delNode->parent->_data.first)
						this->_first->parent = delNode->parent;
					else
						this->_last->parent = delNode->parent;
				}
				if (delNode->_data.first <= delNode->parent->_data.first)
					delNode->parent->left = firstElementLink;
				else
					delNode->parent->right = lastElementLink;
			}
			else if ((delNode->left && delNode->left != this->_first) && (delNode->right == NULL || delNode->right == this->_last))
			{
				tmpNode = delNode->parent;
				if (delNode->_data.first <= delNode->parent->_data.first)
					delNode->parent->left = delNode->left;
				else
					delNode->parent->right = delNode->left;
				delNode->left->parent = delNode->parent;
				if (delNode->right == this->_last)
				{
					this->_last->parent = delNode->left;
					delNode->left->right = this->_last;
				}
			}
			else if ((delNode->left == NULL || delNode->left == this->_first) && (delNode->right && delNode->right != this->_last))
			{
				tmpNode = delNode->parent;

				if (delNode->_data.first <= delNode->parent->_data.first)
					delNode->parent->left = delNode->right;
				else
					delNode->parent->right = delNode->right;
				delNode->right->parent = delNode->parent;
				if (delNode->left == this->_first) {
					this->_first->parent = delNode->right;
					delNode->right->left = this->_first;
				}
			}
			else
			{
				node_pointer 	maxNodeLeftSubtree = getMaxNode(delNode->left);
				_alloc.destroy(&delNode->_data);
				_alloc.construct(&delNode->_data, maxNodeLeftSubtree->_data);
				return deleteNode(delNode->left, maxNodeLeftSubtree->_data.first);
			}
			balance_tree(tmpNode);
			delete delNode;
			return true;
		}

		node_pointer  getRoot()
		{
			return this->_root;
		}

		bool equal(key_type const &needle, key_type const &haystack) const
		{
			return (!key_comp()(needle, haystack) && !key_comp()(haystack, needle));
		}

		bool equal(value_type const & x, value_type const & y) const
		{
			return (!value_comp()(x, y) && !value_comp()(y, x));
		}

		void printBT(const std::string& prefix, const node_pointer& trav, bool isLeft) const {
			if (trav && trav != _first && trav != _last) {
				std::cout << prefix;
				std::cout << (isLeft ? "└L─" : "├R-" );
				// print the value of the node
				std::cout << trav->_data.first << std::endl ;
				// enter the next tree level - left and right branch
				printBT( prefix + (!isLeft ? "│   " : "    "), trav->right, false);
				printBT( prefix + (!isLeft ? "│   " : "    "), trav->left, true);
			}
		}
	};
}
#endif //MY_FT_CONTAINERS_MAP_HPP
