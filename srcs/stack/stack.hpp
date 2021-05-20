//
// Created by Thimo Van der meer on 20/05/2021.
//

#ifndef MY_FT_CONTAINERS_STACK_HPP
#define MY_FT_CONTAINERS_STACK_HPP
namespace ft{
	template<class T, class Container = list<T>>
	class stack
	{
	public:
		typedef T 			value_type;
		typedef container	container_type;
		typedef size_t		size_type;

	private:
		value_type 			_type;
		container_type 		_container;
		size_type			_size;

	public:
		explicit stack (const container_type& ctnr = container_type())
		{

		}

		bool	empty() const
		{
			if(_size == 0)
				return true;
			else
				return false;
		}

		size_type size() const
		{
			return(_size);
		}

		value_type &top()
		{

		}

		const value_type &top() const
		{

		}

		void push(const value_type &val)
		{

		}

		template<class... Args>
		void emplace(Args&&... args)
		{

		}

		void pop()
		{

		}

		void swap(stack& x) noexcept();
		{

		}
	};
}
#endif //MY_FT_CONTAINERS_STACK_HPP
