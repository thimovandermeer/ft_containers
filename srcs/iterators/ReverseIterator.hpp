//
// Created by Thimo Van der meer on 26/05/2021.
//

#ifndef MY_FT_CONTAINERS_REVERSEITERATOR_HPP
#define MY_FT_CONTAINERS_REVERSEITERATOR_HPP

namespace ft{
	template<class Iterator>
	class ReverseIterator {
		typedef Iterator						iterator_type;
		typedef typename Iterator::iterator_category		iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference				reference;

	protected:
		Iterator	_current;

	public:
		ReverseIterator(): _current() {}
		explicit ReverseIterator(iterator_type x)
		{
			Iterator tmp(x);
			this->_current = ++tmp;
		}

		template<class Iter>
				ReverseIterator(const ReverseIterator<Iterator>& other) : _current(other._current)
		{
		}

		iterator_type base() const
		{
			return (_current);
		}

		reference operator*() const
		{
			Iterator tmp = _current;
			*--tmp;
			return tmp;
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		ReverseIterator& operator++()
		{
			_current--;
			return (*this);
		}

		ReverseIterator operator++(int)
		{
			ReverseIterator tmp(*this);
			_current--;
			return(tmp);
		}

		ReverseIterator&	operator--()
		{
			_current++;
			return(*this);
		}

		ReverseIterator		operator--(int)
		{
			ReverseIterator tmp(*this);
			_current++;
			return (tmp);
		}

		ReverseIterator		operator+(difference_type number)
		{
			return (ReverseIterator(_current - number));
		}

		ReverseIterator&	operator+=(difference_type number)
		{
			_current -= number;
			return(*this);
		}

		ReverseIterator		operator-(difference_type number)
		{
			return (ReverseIterator(_current + number));
		}

		ReverseIterator&	operator-=(difference_type number)
		{
			_current += number;
			return(*this);
		}
	};

	// operators comparison
	template<class Iterator>
	bool operator==(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iterator>
	bool operator!=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<class Iterator>
	bool operator>(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<class Iterator>
	bool operator<(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<class Iterator>
	bool operator>=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return !(lhs.base() < rhs.base());
	}

	template<class Iterator>
	bool operator<=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return !(lhs.base() > rhs.base());
	}

	template <class Iterator>
	ReverseIterator<Iterator> operator+(typename ReverseIterator<Iterator>::difference_type number,
										const ReverseIterator<Iterator>& it)
	{
		return (it + number);
	}

	template <class Iterator>
	typename ReverseIterator<Iterator>::difference_type  operator-(
			const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}


#endif //MY_FT_CONTAINERS_REVERSEITERATOR_HPP
