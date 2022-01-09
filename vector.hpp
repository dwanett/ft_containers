#pragma once
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include "iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef ft::random_access_iterator<value_type>					iterator;
		typedef ft::random_access_iterator<const value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef typename allocator_type::size_type						size_type;
	private:
		allocator_type  _alloc;
		pointer         _start;
		pointer         _end;
		pointer         _end_cap;
	public:
		explicit vector (const allocator_type& alloc = allocator_type()) :
		_alloc(alloc),
		_start(NULL),
		_end(NULL),
		_end_cap(NULL) {}

		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_start = _alloc.allocate(n);
			_end = _start;
			_end_cap = _start + n;
			while(_end != _end_cap)
			{
				_alloc.construct(_end, val);
				_end++;
			}
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
		{
			difference_type n = ft::distance(first, last);
			_alloc = alloc;
			_start = _alloc.allocate(n);
			_end = _start;
			_end_cap = _start + n;
			while(_end != _end_cap)
			{
				_alloc.construct(_end, *first);
				first++;
				_end++;
			}
		}

		vector (const vector& x) :
		_alloc(x._alloc),
		_start(NULL),
		_end(NULL),
		_end_cap(NULL)
		{
			this->operator=(x);
		}

		vector& operator= (const vector& x)
		{
			if (this == &x)
				return (*this);
			clear();
			this->_start = this->_alloc.allocate(x.size());
			this->_end = this->_start;
			this->_end_cap = this->_start + x.size();
			for (const_iterator it = x.begin(); it != x.end(); it++)
			{
				this->_alloc.construct(this->_end, *it);
				this->_end++;
			}
			return (*this);
		}

		~vector()
		{
			clear();
			if (capacity() > 0)
				_alloc.deallocate(_start, capacity());
		}

		size_type capacity (void) const { return (this->_end_cap - this->_start); }

		size_type size(void) const { return (this->_end - this->_start); }

		size_type max_size() const { return (allocator_type().max_size()); }

		bool empty() const { return (size() == 0); }

		allocator_type get_allocator() const { return (_alloc); }

		iterator begin() { return (iterator(_start)); };

		const_iterator begin() const { return (const_iterator(_start)); }

		iterator end() { return (iterator(_end)); };

		const_iterator end() const { return (const_iterator(_end)); }

		reverse_iterator rbegin() { return (reverse_iterator(_end)); }

		const_reverse_iterator rbegin() const { return (const_reverse_iterator(_end)); }

		reverse_iterator rend() { return (reverse_iterator(_start)); }

		const_reverse_iterator rend() const { return (const_reverse_iterator(_start)); }

		void resize (size_type n, value_type val = value_type ())
		{
			if (n > max_size())
			{
				throw std::length_error("error vector::max_size");
				return ;
			}
			if (n < size())
			{
				while (size() > n)
				{
					_end--;
					_alloc.destroy(_end);
				}
			}
			else
			{
				if (capacity() < n)
					reserve(n);
				while (size() != n)
				{
					_alloc.construct(_end, val);
					_end++;
				}
			}
		}

		iterator erase (iterator position)
		{
			pointer pos = position.base();
			if (pos == _end)
				_alloc.destroy(pos - 1);
			else
			{
				_alloc.destroy(pos);
				for (pointer tmp = pos + 1; tmp + 1 <= _end; tmp++)
				{
					_alloc.construct(tmp - 1, *tmp);
					_alloc.destroy(tmp);
				}
			}
			_end--;
			return (position);
		}

		iterator erase (iterator first, iterator last)
		{
			iterator tmp;
			difference_type n = ft::distance(first, last);

			tmp = erase(first);
			while (--n)
				tmp = erase(tmp);
			return (tmp);
		}

		iterator insert (iterator position, const value_type& val)
		{
			difference_type ret = distance(begin(), position);
			if (size() < capacity())
			{
				iterator it;
				if (_end + 1 != _end_cap)
					it = _end + 1;
				else
					it = _end;
				for (; it != position; it--)
					_alloc.construct(it.base(), *(it - 1));
				_alloc.construct(position.base(), val);
				_end++;
			}
			else
			{
				size_type new_cap;
				if (size() == 0)
					new_cap = 1;
				else
					new_cap = size() * 2;
				pointer new_start = _alloc.allocate(new_cap);
				pointer new_end = new_start;
				iterator it;
				for (it = begin(); it != position; it++, new_end++)
					_alloc.construct(new_end, *it);
				_alloc.construct(new_end, val);
				new_end++;
				for (; it != _end; it++, new_end++)
					_alloc.construct(new_end, *it);
				clear();
				_alloc.deallocate(_start, capacity());
				_start = new_start;
				_end = new_end;
				_end_cap = _start + new_cap;
			}
			return (ret + _start);
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			if (n > max_size())
			{
				throw std::length_error("error vector::max_size");
				return;
			}
			if (n == 0)
				return;
			if (size() + n <= capacity())
			{
				iterator it;
				if (_end + n != _end_cap)
					it = _end + n;
				else
					it = _end_cap - 1;
				for (; it >= position + n; it--)
					_alloc.construct(it.base(), *(it - n));
				while (n--)
				{
					_alloc.construct(position.base(), val);
					position++;
					_end++;
				}
			}
			else
			{
				size_type new_cap;
				if (size() == 0)
					new_cap = 1;
				else
					new_cap = size() + n;
				pointer new_start = _alloc.allocate(new_cap);
				pointer new_end = new_start;
				iterator it;
				for (it = begin(); it != position; it++, new_end++)
					_alloc.construct(new_end, *it);
				for (int i = 0; i != n; i++, new_end++)
					_alloc.construct(new_end, val);
				for (; it != _end; it++, new_end++)
					_alloc.construct(new_end, *it);
				clear();
				_alloc.deallocate(_start, capacity());
				_start = new_start;
				_end = new_end;
				_end_cap = _start + new_cap;
			}
		}

		template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
						 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			difference_type range = distance(first, last);
			if (range == 0)
				return;
			if (size() + range < capacity())
			{
				iterator it;
				if (_end + range != _end_cap)
					it = _end + range;
				else
					it = _end_cap - 1;
				for (; it >= position + range; it--)
					_alloc.construct(it.base(), *(it - range));
				while (first != last)
				{
					_alloc.construct(position.base(), *first);
					position++;
					first++;
					_end++;
				}
			}
			else
			{
				size_type new_cap;
				if (size() == 0)
					new_cap = 1;
				else
					new_cap = size() + range;
				pointer new_start = _alloc.allocate(new_cap);
				pointer new_end = new_start;
				iterator it;
				for (it = begin(); it != position; it++, new_end++)
					_alloc.construct(new_end, *it);
				for (;first != last; first++, new_end++)
					_alloc.construct(new_end, *first);
				for (; it != _end; it++, new_end++)
					_alloc.construct(new_end, *it);
				clear();
				_alloc.deallocate(_start, capacity());
				_start = new_start;
				_end = new_end;
				_end_cap = _start + new_cap;
			}
		}

		void clear()
		{
			for (pointer i = _start; i != _end; i++)
				_alloc.destroy(i);
			_end = _start;
		}

		void reserve (size_type n)
		{
			if (n > max_size())
			{
				throw std::length_error("error vector::max_size");
				return ;
			}
			if (n > this->capacity())
			{
				pointer	old_start = _start;
				pointer	old_end = _end;
				size_type old_cap = capacity();
				size_type old_size = size();
				_start = _alloc.allocate(n);
				_end = _start;
				_end_cap = _start + n;
				if (old_end != NULL)
				{
					while (old_start != old_end)
					{
						_alloc.construct(_end, *old_start);
						_end++;
						old_start++;
					}
					_alloc.deallocate(old_start - old_size, old_cap);
				}
			}
		}

		void push_back (const value_type& val)
		{
			if(_end_cap == _end)
			{
				if (this->size() == 0)
					reserve(1);
				else
					reserve(this->size() * 2);
			}
			_alloc.construct(_end, val);
			_end++;
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
					 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			difference_type range = distance(first, last);
			clear();
			if (range <= capacity())
			{
				_end = _start;
				for (; first != last; first++, _end++)
					_alloc.construct(_end, *first);
			}
			else
			{
				_alloc.deallocate(_start, capacity());
				_start = _alloc.allocate(range);
				_end = _start;
				_end_cap = _start + range;
				for (; first != last; first++, _end++)
					_alloc.construct(_end, *first);
			}
		}

		void assign (size_type n, const value_type& val)
		{
			if (n > max_size())
			{
				throw std::length_error("error vector::max_size");
				return ;
			}
			clear();
			if (n <= capacity())
			{
				_end = _start;
				for (; _end != _start + n; _end++)
					_alloc.construct(_end, val);
			}
			else
			{
				_alloc.deallocate(_start, capacity());
				pointer new_start = _alloc.allocate(n);
				pointer new_end = new_start;
				iterator it;
				for (; new_end != new_start + n; new_end++)
					_alloc.construct(new_end, val);
				_start = new_start;
				_end = new_end;
				_end_cap = _start + n;
			}
		}

		void pop_back()
		{
			_alloc.destroy(_end - 1);
			_end--;
		}

		void swap (vector& x)
		{
			allocator_type  _alloc_tmp = x._alloc;
			pointer         _start_tmp = x._start;
			pointer         _end_tmp = x._end;
			pointer         _end_cap_tmp = x._end_cap;

			x._alloc = this->_alloc;
			x._start = this->_start;
			x._end = this->_end;
			x._end_cap = this->_end_cap;
			this->_alloc = _alloc_tmp;
			this->_start = _start_tmp;
			this->_end = _end_tmp;
			this->_end_cap = _end_cap_tmp;
		}
		reference operator[] (size_type n) { return (*(_start + n)); }

		const_reference operator[] (size_type n) const { return (*(_start + n)); }

		reference at (size_type n)
		{
			if (n > size())
				throw std::out_of_range("vector::_M_range_check");
			return (*(_start + n));
		}

		const_reference at (size_type n) const
		{
			if (n > size())
				throw std::out_of_range("vector::_M_range_check:" );
			return (*(_start + n));
		}

		reference front() { return (*_start); }

		const_reference front() const { return (*_start); }

		reference back() { return (*(_end - 1)); }

		const_reference back() const { return (*(_end - 1)); }

	};

	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }

	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T,Alloc>::const_iterator it_lhs = lhs.begin();
		typename ft::vector<T,Alloc>::const_iterator it_rhs = rhs.begin();
		while (true)
		{
			if (it_rhs == rhs.end() && it_lhs == lhs.end())
				break;
			if (*it_rhs != *it_lhs || (it_rhs == rhs.end() && it_lhs != lhs.end()))
				return (false);
			it_rhs++;
			it_lhs++;
		}
		return (true);
	}

	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }

	template <class T, class Alloc>
		bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
		bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif // VECTOR_HPP