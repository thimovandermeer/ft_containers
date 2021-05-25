//
// Created by Thimo Van der meer on 25/05/2021.
//

#ifndef MY_FT_CONTAINERS_QUEUE_HPP
#define MY_FT_CONTAINERS_QUEUE_HPP
#include "../list/list.hpp"
namespace ft
{
	template<class T, class Container = list <T>>
	class queue
	{
	public:
		typedef T 			value_type;
		typedef Container 	container_type;
		typedef size_t 		size_type;

	private:
		container_type _container;

	public:
		explicit queue(const container_type &ctnr = container_type()) : _container(ctnr)
		{}

		bool empty() const
		{
			return _container.empty();
		}

		size_type size() const
		{
			return (_container.size());
		}

		value_type &front()
		{
			return (_container.front());
		}

		const value_type &front() const
		{
			return (_container.front());
		}

		void push(const value_type &val)
		{
			return (_container.push_back(val));
		}

		void pop()
		{
			_container.pop_front();
		}

		friend bool	operator==(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr == rhs._ctnr);
		}
		friend bool operator!=(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr != rhs._ctnr);
		}
		friend bool	operator<(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr < rhs._ctnr);
		}
		friend bool operator>(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr > rhs._ctnr);
		}
		friend bool	operator<=(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr <= rhs._ctnr);
		}
		friend bool operator>=(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr >= rhs._ctnr);
		}
	};
}
#endif //MY_FT_CONTAINERS_QUEUE_HPP
