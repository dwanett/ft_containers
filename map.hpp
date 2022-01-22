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
		b_tree										*_null_node;

		b_tree *findnode (const key_type& k, b_tree *start) const
		{
			b_tree	*tmp;

			tmp = start;
			if (tmp != _null_node && tmp->_value.first == k)
				return tmp;
			while (tmp != _null_node)
			{
				if (!_comp(tmp->_value.first, k) && tmp->_value.first != k)
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
			return _null_node;
		}

		b_tree	*find_max_node() const
		{
			b_tree	*tmp;

			tmp = _root;
			if (tmp != _null_node)
			{
				while (tmp->_right_node != _null_node)
					tmp = tmp->_right_node;
			}
			return (tmp);
		}
	public:
		explicit map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _size(0), _root(), _null_node() {}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _size(0), _root(), _null_node()
		{
			insert(first, last);
		}

		map (const map& x) : _size(0), _root(), _null_node()
		{
			_alloc = x._alloc;
			_comp = x._comp;
			_alloc_tree = x._alloc_tree;
			insert(x.begin(), x.end());
		}

		map& operator=(const map& x)
		{
			if (*this == x)
				return (*this);
			clear();
			_alloc = x._alloc;
			_comp = x._comp;
			_alloc_tree = x._alloc_tree;
			insert(x.begin(), x.end());
			return (*this);
		}

		~map()
		{
			clear();
		}

		iterator							begin()
		{
			b_tree	*tmp;

			tmp = _root;
			if (_root != _null_node)
			{
				while (tmp->_left_node != _null_node)
					tmp = tmp->_left_node;
			}
			return (iterator(tmp));
		}

		const_iterator						begin() const
		{
			b_tree	*tmp;

			tmp = _root;
			if (_root != _null_node)
			{
				while (tmp->_left_node != _null_node)
					tmp = tmp->_left_node;
			}
			return (const_iterator(tmp));
		}

		iterator							end()
		{
			b_tree	*tmp = find_max_node();
			if (tmp != _null_node)
				return (iterator(tmp->_right_node, tmp));
			return (iterator(tmp));
		}

		const_iterator						end() const
		{
			b_tree	*tmp = find_max_node();
			if (tmp != _null_node)
				return (const_iterator(tmp->_right_node, tmp));
			return (iterator(tmp));
		}

		reverse_iterator					rbegin() { return(reverse_iterator(end())); }

		const_reverse_iterator				rbegin() const { return(const_reverse_iterator(end())); }

		reverse_iterator					rend() { return(reverse_iterator(begin())); }

		const_reverse_iterator				rend() const { return(const_reverse_iterator(begin())); }

		iterator							find(const key_type& k)
		{
			b_tree *res = findnode(k, _root);
			if (res->_value.first == k)
				return (iterator(res));
			return (end());
		}

		const_iterator						find(const key_type& k) const
		{
			b_tree *res = findnode(k, _root);
			if (res->_value.first == k)
				return (const_iterator(res));
			return (end());
		}

		size_type							count(const key_type& k) const
		{
			if (find(k) != end())
				return (1);
			return (0);
		}

		iterator							lower_bound(const key_type& k)
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

		const_iterator						lower_bound(const key_type& k) const
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

		iterator							upper_bound(const key_type& k)
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

		const_iterator						upper_bound(const key_type& k) const
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

		pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (!_comp(it->first, k))
					break;
				it++;
			}
			if (it != end() && !_comp(it->first, k) && !_comp(k, it->first))
				return (make_pair(it, ++it));
			return (make_pair(it, it));
		}

		pair<iterator, iterator>				equal_range(const key_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (!_comp(it->first, k))
					break;
				it++;
			}
			if (!_comp(it->first, k) && !_comp(k, it->first))
				return (make_pair(it, ++it));
			return (make_pair(it, it));
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
				ret = _root;
				_size++;

			}
			else
			{
				b_tree *input_node;
				input_node = findnode(val.first, _root);
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
			return (ft::make_pair(iterator(ret), r));
		}

		iterator							insert(iterator position, const value_type& val)
		{
			iterator	it = position;
			b_tree		*input_node;
			b_tree		tmp;

			_alloc.construct(&tmp._value, val);
			if (_root == _null_node)
			{
				insert(val);
				return (_root);
			}
			if (position.base() != NULL && position.base() != _null_node
				&& _comp(position->first, val.first) && _comp(val.first, (++it)->first))
				input_node = findnode(val.first, position.base());
			else
				input_node = findnode(val.first, _root);
			if (val.first == input_node->_value.first)
				return (input_node);
			if (!_comp(input_node->_value.first, val.first))
			{
				input_node->_left_node = _alloc_tree.allocate(1);
				_alloc_tree.construct(input_node->_left_node, tmp);
				input_node->_left_node->_parent_node = input_node;
				_size++;
				return (input_node->_left_node);
			}
			else
			{
				input_node->_right_node = _alloc_tree.allocate(1);
				_alloc_tree.construct(input_node->_right_node, tmp);
				input_node->_right_node->_parent_node = input_node;
				_size++;
				return (input_node->_right_node);
			}
		}

		template <class InputIterator>
		void								insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		void								erase(iterator position)
		{
			b_tree *node = position.base();

			if (_root != node)
			{
				if (node->_right_node == _null_node && node->_left_node == _null_node)
				{
					if (node->_parent_node->_left_node == node)
						node->_parent_node->_left_node = _null_node;
					else
						node->_parent_node->_right_node = _null_node;
				}
				else if (node->_right_node == _null_node && node->_left_node != _null_node)
				{
					node->_left_node->_parent_node = node->_parent_node;
					if (node->_parent_node->_left_node == node)
						node->_parent_node->_left_node = node->_left_node;
					else
						node->_parent_node->_right_node = node->_left_node;
				}
				else if (node->_left_node == _null_node && node->_right_node != _null_node)
				{
					node->_right_node->_parent_node = node->_parent_node;
					if (node->_parent_node->_left_node == node)
						node->_parent_node->_left_node = node->_right_node;
					else
						node->_parent_node->_right_node = node->_right_node;
				}
				else if (node->_right_node != _null_node && node->_left_node != _null_node)
				{
					b_tree *tmp;

					tmp = node->_right_node;
					node->_right_node->_parent_node = node->_parent_node;
					if (node->_parent_node->_left_node == node)
						node->_parent_node->_left_node = node->_right_node;
					else
						node->_parent_node->_right_node = node->_right_node;
					while (tmp->_left_node != _null_node)
						tmp = tmp->_left_node;
					tmp->_left_node = node->_left_node;
					node->_left_node->_parent_node = tmp;
				}
			}
			else
			{
				if (node->_right_node != _null_node)
				{
					if (node->_left_node != _null_node)
					{
						b_tree *tmp;

						tmp = node->_right_node;
						while (tmp->_left_node != _null_node)
							tmp = tmp->_left_node;
						node->_left_node->_parent_node = tmp;
						tmp->_left_node = node->_left_node;

					}
					_root = node->_right_node;
					_root->_parent_node = _null_node;
				}
				else if (node->_left_node != _null_node)
				{
					_root = node->_left_node;
					_root->_parent_node = _null_node;
				}
			}
			node->_left_node = _null_node;
			node->_right_node = _null_node;
			node->_parent_node = _null_node;
			_alloc_tree.destroy(node);
			_alloc_tree.deallocate(node, 1);
			_size--;
			if (_size == 0)
				_root = _null_node;
		}

		size_type							erase(const key_type& k)
		{
			b_tree *tmp = findnode(k, _root);
			if (tmp->_value.first == k)
			{
				erase(tmp);
				return (1);
			}
			return (0);
		}

		void								erase(iterator first, iterator last)
		{
			iterator tmp;

			while (first != last)
			{
				tmp = first;
				first++;
				erase(tmp);
			}
		}

		void								swap(map& x)
		{
			allocator_type          tmp_alloc;
			key_compare				tmp_comp;
			size_type				tmp_size;
			std::allocator<b_tree> 	tmp_alloc_tree;
			b_tree					*tmp_root;
			b_tree					*tmp_null_node;

			tmp_alloc = x._alloc;
			tmp_comp = x._comp;
			tmp_size = x._size;
			tmp_alloc_tree = x._alloc_tree;
			tmp_root = x._root;
			tmp_null_node = x._null_node;
			x._alloc = this->_alloc;
			x._comp = this->_comp;
			x._size = this->_size;
			x._alloc_tree = this->_alloc_tree;
			x._root = this->_root;
			x._null_node = this->_null_node;
			this->_alloc = tmp_alloc;
			this->_comp = tmp_comp;
			this->_size = tmp_size;
			this->_alloc_tree = tmp_alloc_tree;
			this->_root = tmp_root;
			this->_null_node = tmp_null_node;
		}

		void								clear() { erase(begin(), end()); }

		mapped_type& operator[] (const key_type& k)
		{
			return ((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
		}

		allocator_type						get_allocator() const {return (_alloc); }
	};

	template <class Key, class T, class Compare, class Alloc>
		void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) { x.swap(y); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}
}

#endif // MAP_HPP
