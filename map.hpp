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
		b_tree										*_null_node;
	public:
		explicit map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _root(), _null_node() {}

		//template <class InputIterator>
		//map (InputIterator first, InputIterator last,
		//	 const key_compare& comp = key_compare(),
		//	 const allocator_type& alloc = allocator_type());

		//map (const map& x);

		iterator begin()
		{
			b_tree node(*_root);
			iterator it(node);
			return (it);
		}
		const_iterator begin() const { return (const_iterator(*_root)); }

		//iterator find (const key_type& k)
		//{
		//	iterator it = begin();
		//	if (_node != _null_node && _node._right_node != NULL && _node._left_node != NULL)
		//	{
		//		iterator it =
		//		if (_node._left_node != NULL)
		//		{
//
		//		}
		//	}
		//}
		//const_iterator find (const key_type& k) const;

		ft::pair<iterator,bool> insert (const value_type& val)
		{
			if (_root == _null_node)
			{
				b_tree tmp(val);
				_root = _alloc_tree.allocate(1);
				_alloc_tree.construct(_root, tmp);
				iterator it(*_root);
				return (ft::make_pair(it, true));
			}
			//return (ft::make_pair(0, false));
		}

		//iterator insert (iterator position, const value_type& val);

		//template <class InputIterator>
		//void insert (InputIterator first, InputIterator last);
	};
}


#endif // MAP_HPP
