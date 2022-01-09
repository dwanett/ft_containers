#pragma once
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include "utils.hpp"

namespace ft
{
	template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T        	value_type;
		typedef Distance 	difference_type;
		typedef Pointer  	pointer;
		typedef Reference	reference;
		typedef Category 	iterator_category;
	};

	template <class T>
	class random_access_iterator : public iterator<std::random_access_iterator_tag, T>
	{
	public:
		typedef typename iterator<std::random_access_iterator_tag, T>::value_type			value_type;
		typedef typename iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
		typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef T*																			pointer;
		typedef T&																			reference;
	private:
		pointer	_i;
	public:
		random_access_iterator(void) : _i(0){}
		random_access_iterator(pointer elem) : _i(elem){}
		random_access_iterator(const random_access_iterator& it) : _i(it._i){}
		virtual ~random_access_iterator() {}

		random_access_iterator& operator=(const random_access_iterator& it)
		{
			this->_i = it._i;
			return (*this);
		}

		random_access_iterator &operator++(void) //pre_fix
		{
			this->_i++;
			return(*this);
		}

		random_access_iterator operator++(int) //post_fix
		{
			random_access_iterator tmp(*this);
			this->_i++;
			return(tmp);
		}

		random_access_iterator &operator--(void) //pre_fix
		{
			this->_i--;
			return(*this);
		}

		random_access_iterator operator--(int) //post_fix
		{
			random_access_iterator tmp(*this);
			this->_i--;
			return(tmp);
		}

		bool operator==(const random_access_iterator& it) const
		{
			return (this->_i == it._i);
		}

		bool operator!=(const random_access_iterator& it) const
		{
			return (this->_i != it._i);
		}

		pointer base() const { return (this->_i); }

		reference operator*() const { return (*_i); }

		pointer operator->() const { return (this->_i); }

		random_access_iterator operator+(difference_type n) const { return (this->_i + n); }

		friend random_access_iterator operator+(difference_type n, const random_access_iterator& it) { return (it.base() + n); }

		random_access_iterator operator-(difference_type n) const { return (this->_i - n); }

		friend difference_type operator-(const random_access_iterator& it, const random_access_iterator& it_2) { return (it.base() - it_2.base()); }

		random_access_iterator &operator+=(difference_type n)
		{
			this->_i += n;
			return (*this);
		}

		random_access_iterator &operator-=(difference_type n)
		{
			this->_i -= n;
			return (*this);
		}

		reference operator[](difference_type n) const { return (*(this->_i + n)); }

		bool operator<(const random_access_iterator& it) const { return (this->_i < it._i); }

		bool operator>(const random_access_iterator& it) const { return (this->_i > it._i); }

		bool operator>=(const random_access_iterator& it) const { return (this->_i >= it._i); }

		bool operator<=(const random_access_iterator& it) const { return (this->_i <= it._i); }

		operator ft::random_access_iterator<const T>() const {
			return ft::random_access_iterator<const T>(_i);
		}

	};

	template <class Iter>
	class reverse_iterator
	{
	public:
		typedef Iter												iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;
	private:
		iterator_type	rev_i;
	public:
		reverse_iterator() : rev_i(){}
		explicit reverse_iterator(iterator_type it) : rev_i(it){}
		template <class Iterator>
			reverse_iterator (const reverse_iterator<Iterator>& it) : rev_i(it.base()){}

		virtual ~reverse_iterator() {}
		iterator_type base() const { return (rev_i); }
		reference operator*() const
		{
			iterator_type tmp = rev_i;
			return (*(--tmp));
		}
		reverse_iterator operator+(difference_type n) const { return (this->rev_i - n); }
		friend reverse_iterator operator+(difference_type n, const reverse_iterator& it) { return (it.base() - n); }
		reverse_iterator &operator++(void) //pre_fix
		{
			this->rev_i--;
			return(*this);
		}
		reverse_iterator operator++(int) //post_fix
		{
			reverse_iterator tmp(*this);
			this->rev_i--;
			return(tmp);
		}
		reverse_iterator operator-(difference_type n) const { return (this->rev_i + n); }
		friend reverse_iterator operator-(difference_type n, const reverse_iterator& it) { return (it.base() + n); }
		reverse_iterator &operator+=(difference_type n)
		{
			this->rev_i -= n;
			return (*this);
		}
		reverse_iterator &operator--(void) //pre_fix
		{
			this->rev_i++;
			return(*this);
		}
		reverse_iterator operator--(int) //post_fix
		{
			reverse_iterator tmp(*this);
			this->rev_i++;
			return(tmp);
		}
		reverse_iterator &operator-=(difference_type n)
		{
			this->rev_i += n;
			return (*this);
		}
		pointer operator->() const { return &(operator*()); }
		reference operator[](difference_type n) const { return (*(*this + n)); }
	};

	template <class Iter>
	bool operator==(const reverse_iterator<Iter>& lhs,
					const reverse_iterator<Iter>& rhs) {return (lhs.base() == rhs.base()); }
	template <class Iter>
	bool operator!=(const reverse_iterator<Iter>& lhs,
					 const reverse_iterator<Iter>& rhs) {return (lhs.base() != rhs.base()); }
	template <class Iter>
	bool operator<(const reverse_iterator<Iter>& lhs,
					 const reverse_iterator<Iter>& rhs) {return (lhs.base() > rhs.base()); }
	template <class Iter>
	bool operator<=(const reverse_iterator<Iter>& lhs,
					 const reverse_iterator<Iter>& rhs) {return (lhs.base() >= rhs.base()); }
	template <class Iter>
	bool operator>(const reverse_iterator<Iter>& lhs,
					 const reverse_iterator<Iter>& rhs) {return (lhs.base() < rhs.base()); }
	template <class Iter>
	bool operator>=(const reverse_iterator<Iter>& lhs,
					 const reverse_iterator<Iter>& rhs) {return (lhs.base() <= rhs.base()); }
	template <class Iterator>
	typename iterator_traits<Iterator>::difference_type distance (Iterator first, Iterator last)
	{
		typename iterator_traits<Iterator>::difference_type n;
		n = 0;
		while (first != last)
		{
			first++;
			n++;
		}
		return (n);
	}
}

#endif //ITERATOR_HPP
