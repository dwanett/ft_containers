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
		typedef	Alloc																	allocator_type;
		typedef typename allocator_type::reference										reference;
		typedef typename allocator_type::const_reference								const_reference;
		typedef typename allocator_type::pointer										pointer;
		typedef typename allocator_type::const_pointer									const_pointer;
		typedef ft::map_iterator<value_type, ft::binary_tree<value_type> >				iterator;
		typedef ft::map_iterator<const value_type, const ft::binary_tree<value_type> >	const_iterator;
		typedef ft::reverse_iterator<iterator>											reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type					difference_type;
		typedef typename allocator_type::size_type										size_type;
	private:
		typedef binary_tree<value_type>				b_tree;
		allocator_type                          	_alloc;
		key_compare                                 _comp;
		size_type									_size;
		std::allocator<b_tree> 						_alloc_tree;
		b_tree										*_root;
		b_tree										*_max_node;
		b_tree										*_null_node;

		b_tree *findnode (const key_type& k) const
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
					  const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _size(0), _root(), _max_node(), _null_node() {}

		//template <class InputIterator>
		//map (InputIterator first, InputIterator last,
		//	 const key_compare& comp = key_compare(),
		//	 const allocator_type& alloc = allocator_type());

		//map (const map& x);

		//map& operator= (const map& x) {}

		//~map() {}

		iterator							begin()
		{
			b_tree	*tmp;

			tmp = _root;
			while (tmp->_left_node != _null_node)
				tmp = tmp->_left_node;
			return (iterator(tmp));
		}

		const_iterator						begin() const
		{
			b_tree	*tmp;

			tmp = _root;
			while (tmp->_left_node != _null_node)
				tmp = tmp->_left_node;
			return (const_iterator(tmp));
		}

		iterator							end()
		{
			return (iterator(_max_node->_right_node, _max_node));
		}

		const_iterator						end() const
		{
			return (const_iterator(_max_node->_right_node, _max_node));
		}

		reverse_iterator					rbegin() { return(reverse_iterator(end())); }

		const_reverse_iterator				rbegin() const { return(const_reverse_iterator(end())); }

		reverse_iterator					rend() { return(reverse_iterator(begin())); }

		const_reverse_iterator				rend() const { return(const_reverse_iterator(begin())); }

		iterator							find(const key_type& k)
		{
			b_tree *res = findnode(k);
			if (!_comp(res->_value.first, k))
				return (iterator(res));
			return (end());
		}

		const_iterator						find(const key_type& k) const
		{
			b_tree *res = findnode(k);
			if (!_comp(res->_value.first, k))
				return (const_iterator(res));
			return (end());
		}

		size_type							count(const key_type& k) const
		{
			if (find(k) != end())
				return (1);
			return (0);
		}

		iterator							lower_bound (const key_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (!_comp(it->first, k))
					break;
				it++;
			}
			return (it);
		}

		const_iterator						lower_bound (const key_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (!_comp(it->first, k))
					break;
				it++;
			}
			return (it);
		}

		iterator							upper_bound (const key_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (_comp(k, it->first))
					break;
				it++;
			}
			return (it);
		}

		const_iterator						upper_bound (const key_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (_comp(k, it->first))
					break;
				it++;
			}
			return (it);
		}

		pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
		{

		}

		pair<iterator,iterator>				equal_range (const key_type& k)
		{

		}

		bool								empty() const { return (_size == 0); }

		size_type							size() const { return (_size); }

		size_type							max_size() const { return (_alloc_tree.max_size()); }

		key_compare							key_comp() const { return (_comp); }

		value_compare						value_comp() const { return (value_compare(_comp)); }

		ft::pair<iterator,bool>				insert(const value_type& val)
		{
			b_tree		*ret;
			b_tree		tmp;
			bool		r = true;

			if (_root == _null_node)
			{

				_root = _alloc_tree.allocate(1);
				_alloc.construct(&tmp._value, val);
				_alloc_tree.construct(_root, tmp);
				_max_node = _root;
				ret = _root;
				_size++;

			}
			else
			{
				b_tree *input_node;
				input_node = findnode(val.first);
				_alloc.construct(&tmp._value, val);
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
					_size++;
				}
				else
				{
					input_node->_right_node = _alloc_tree.allocate(1);
					_alloc_tree.construct(input_node->_right_node, tmp);
					input_node->_right_node->_parent_node = input_node;
					ret = input_node->_right_node;
					_size++;
				}
			}
			if (!_comp(ret->_value.first, _max_node->_value.first))
				_max_node = ret;
			return (ft::make_pair(iterator(ret), r));
		}

		//iterator							insert(iterator position, const value_type& val);

		//template <class InputIterator>
		//void								insert (InputIterator first, InputIterator last);

		allocator_type						get_allocator() const {return (_alloc); }
	};
}


#endif // MAP_HPP
