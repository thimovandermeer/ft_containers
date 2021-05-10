//
// Created by Thimo Van der meer on 06/05/2021.
//

#ifndef MY_FT_CONTAINERS_LIST_HPP
#define MY_FT_CONTAINERS_LIST_HPP
namespace ft {
	template < class T, class Alloc = Alllocator<T>
	class list
	{
	public:
		class iterator;
		class const_iterator;
		// test
		typedef typename Allocator::reference 						reference;
		typedef typename Allocator::const_reference					const_reference;
		typedef typename Allocator::size_type						size_type;
		typedef typename Allocator::difference_type					difference_type;
		typedef T													value_type;
		typedef typename Allocator::pointer							pointer;
		typedef typename Allocator::const_pointer					const_pointer;
		typedef typename Allocator									allocator_type;
		typedef typename std::reverse_iterator<iterator>			reverse_iterator;
		typedef typename std::reverse_iterator<const_iterator>		const_reverse_iterator;

		// Constructors
		explicit list(const Allocator& alloc = Allocator)
		{

		}

		explicit list(size_type n)
		{

		}

		list (size_type n, const T& value, const Allocator& alloc = Allocator())
		{

		}

		template<class InputIterator>
				list(InputIterator start, InputIterator finish, const Allocator& alloc = Allocator())
		{

		}

		list (const list<T, Allocator>& x)
		{

		}
		// Destructors
		~list()
		{

		}
		// Assignment operators
		list<T, Allocator>& operator=(const list<T, Allocator>& x)
		{

		}
		// Allocators
		allocator_type get_allocator() const
		{

		}
		// Iterators
		iterator begin()
		{

		}

		const_iterator begin() const
		{

		}

		iterator end()
		{

		}

		const_iterator end() const
		{

		}

		reverse_iterator rbegin()
		{

		}

		const_reverse_iterator rbegin() const
		{

		}

		reverse_iterator rend()
		{

		}

		const_reverse_iterator rend() const
		{

		}

		// Member Functions
		template <class InputIterator> void assign(InputIterator start, InputIterator finish)
		{

		}

		void assign(size_type n, const T& t)
		{

		}

		reference back()
		{

		}

		const_reference back() const
		{

		}

		void clear()
		{

		}

		bool empty() const
		{

		}

		iterator erase(iterator position)
		{

		}

		iterator erase(iterator start, iterator finish)
		{

		}

		reference front()
		{

		}

		const_reference front() const
		{

		}

		iterator insert(iterator position, const T& x)
		{

		}

		void 	insert(iterator position, size_type n, const T& x)
		{

		}

		void 	insert(iterator position, size_type n, const T& x)
		{

		}

		template<class InputIterator>
				void insert(iterator position, InputIterator start, InputIterator finish)
		{

		}

		size_type max_size() const
		{

		}

		void merge(list<T, Allocator>&x)
		{

		}

		void pop_back()
		{

		}

		void pop_front()
		{

		}

		void push_back(const T& x)
		{

		}

		void push_front(const T& x)
		{

		}

		void remove(const T& value)
		{

		}

		template<class class Predicate>
				void remove_if(predicate pred)
		{

		}

		void resize(size_type sz, T c)
		{

		}

		void reverse()
		{

		}

		size_type size() const
		{

		}

		size_type size() const
		{

		}

		void sort()
		{

		}

		template< class compare>
				void sort (compare comp)
		{

		}

		void splice(iterator position, list<T, Allocator>& x)
		{

		}

		void splice(iterator position, list<T, Allocator>& x, iterator i)
		{

		}

		void splice(iterator position, list<T, Allocator>& x, iterator start, iterator finish)
		{

		}

		void swap(list<T, Allocator& x)
		{

		}

		void unique()
		{

		}

		template <class BinaryPredicate>
				void unique(BinaryPredicate binary_pred)
		{

		}


		// Nonmember Operators
		template<class T, class Allocator>
				bool operator==(const list<T, Allocator>& x, const list<T, Allocator>&y)
		{

		}

		template<class T, class Allocator>
		bool operator!=(const list<T, Allocator>& x, const list<T, Allocator>&y)
		{

		}

		template<class T, class Allocator>
		bool operator<(const list<T, Allocator>& x, const list<T, Allocator>&y)
		{

		}

		template<class T, class Allocator>
		bool operator>(const list<T, Allocator>& x, const list<T, Allocator>&y)
		{

		}

		template<class T, class Allocator>
		bool operator<=(const list<T, Allocator>& x, const list<T, Allocator>&y)
		{

		}

		template<class T, class Allocator>
		bool operator>=(const list<T, Allocator>& x, const list<T, Allocator>&y)
		{

		}

	};
}

#endif //MY_FT_CONTAINERS_LIST_HPP
