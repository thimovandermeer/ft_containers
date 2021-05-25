//
// Created by Thimo Van der meer on 20/05/2021.
//

#ifndef MY_FT_CONTAINERS_STACK_HPP
#define MY_FT_CONTAINERS_STACK_HPP
#include "../list/list.hpp"
namespace ft{
	template<class T, class Container = list<T>>
	class stack
	{
	public:
		typedef T 			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private:
		container_type 		_container;

	public:
		explicit stack (const container_type& ctnr = container_type()) : _container(ctnr) {}

		bool	empty() const
		{
			return _container.empty();
		}

		size_type size() const
		{
			return(_container.size());
		}

		value_type &top()
		{
			return (_container.back());
		}

		const value_type &top() const
		{
			return (_container.back());
		}

		void push(const value_type &val)
		{
			return (_container.push_back(val));
		}

		void pop()
		{
			_container.pop_back();
		}

	};
}
#endif //MY_FT_CONTAINERS_STACK_HPP
