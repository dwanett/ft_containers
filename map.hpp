#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{

	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Compare									key_compare;
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;

		protected:
			Compare comp;

			value_compare(Compare c) : comp(c)
			{}

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};
		typedef	Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef ft::map_iterator<value_type, allocator_type>			iterator;
		typedef ft::map_iterator<const value_type, allocator_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef typename allocator_type::size_type						size_type;
	private:
		typedef binary_tree<value_type>				b_tree;
		allocator_type                          	_alloc;
		Compare                                 	_comp;
		std::allocator<b_tree> 						_alloc_tree;
		b_tree										*_root;
		b_tree										*_max_node;
		b_tree										*_null_node;

		b_tree *findnode (const key_type& k)
		{
			b_tree	*tmp;

			tmp = _root;
			if (tmp->_value.first == k)
				return tmp;
			while (tmp != _null_node)
			{
				if (!_comp(tmp->_value.first, k))
				{
					if ( tmp->_left_node == _null_node)
						return tmp;
					tmp = tmp->_left_node;
					continue;
				}
				else if (_comp(tmp->_value.first, k))
				{
					if ( tmp->_right_node == _null_node)
						return tmp;
					tmp = tmp->_right_node;
					continue;
				}
				else
				{
					return tmp;
				}
			}
			return NULL;
		}
	public:
		explicit map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _root(), _max_node(), _null_node() {}

		//template <class InputIterator>
		//map (InputIterator first, InputIterator last,
		//	 const key_compare& comp = key_compare(),
		//	 const allocator_type& alloc = allocator_type());

		//map (const map& x);

		iterator begin()
		{
			b_tree	*tmp;

			tmp = _root;
			while (tmp->_left_node != _null_node)
				tmp = tmp->_left_node;
			return (iterator(tmp));
		}

		const_iterator begin() const
		{
			b_tree	*tmp;

			tmp = _root;
			while (tmp->_left_node != _null_node)
				tmp = tmp->_left_node;
			return (const_iterator(tmp));
		}

		iterator end()
		{
			return (iterator(_max_node->_right_node, _max_node));
		}

		const_iterator end() const
		{
			return (const_iterator(_max_node->_right_node, _max_node));
		}

		iterator find (const key_type& k)
		{
			b_tree *res = findnode(k);
			if (!_comp(res->_value.first, k))
				return (iterator(res));
			return (end());
		}

		const_iterator find (const key_type& k) const
		{
			b_tree *res = findnode(k);
			if (!_comp(res->_value.first, k))
				return (iterator(res));
			return (end());
		}

		ft::pair<iterator,bool> insert (const value_type& val)
		{
			b_tree		*ret;
			bool		r = true;

			if (_root == _null_node)
			{
				b_tree tmp(val);
				_root = _alloc_tree.allocate(1);
				_alloc_tree.construct(_root, tmp);
				_max_node = _root;
				ret = _root;
			}
			else
			{
				b_tree tmp(val);
				b_tree *input_node;
				input_node = findnode(val.first);
				if (val.first == input_node->_value.first)
				{
					ret = input_node;
					r = false;
				}
				else if (!_comp(input_node->_value.first, val.first))
				{
					input_node->_left_node = _alloc_tree.allocate(1);
					_alloc_tree.construct(input_node->_left_node, tmp);
					input_node->_left_node->_parent_node = input_node;
					ret = input_node->_left_node;
				}
				else
				{
					input_node->_right_node = _alloc_tree.allocate(1);
					_alloc_tree.construct(input_node->_right_node, tmp);
					input_node->_right_node->_parent_node = input_node;
					ret = input_node->_right_node;
				}
			}
			if (!_comp(ret->_value.first, _max_node->_value.first))
				_max_node = ret;
			return (ft::make_pair(iterator(ret), r));
		}

		//iterator insert (iterator position, const value_type& val);

		//template <class InputIterator>
		//void insert (InputIterator first, InputIterator last);
	};
}


#endif // MAP_HPP
