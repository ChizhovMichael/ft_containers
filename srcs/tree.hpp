/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:45:08 by tgildero          #+#    #+#             */
/*   Updated: 2021/12/12 18:45:10 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <iostream>
# include <typeinfo>
# include "utils.hpp"
# include "iterator.hpp"

namespace ft
{
	// _Rb_tree_color
	enum tree_color { _red = false, _black = true };

	// tree_node_base
	struct tree_node_base
	{
	    typedef tree_node_base*			base_ptr;
	    typedef const tree_node_base*	const_base_ptr;
	    tree_color 						_color;
	    base_ptr 						_parent;
	    base_ptr						_left;
	    base_ptr						_right;

	    static base_ptr _S_minimum(base_ptr x)
	    {
	    	while (x->_left != 0) x = x->_left;
	    	return x;
	    }
    	static const_base_ptr _S_minimum(const_base_ptr x)
    	{
			while (x->_left != 0) x = x->_left;
			return x;
    	}
    	static base_ptr _S_maximum(base_ptr x)
    	{
    		while (x->_right != 0) x = x->_right;
    		return x;
    	}
    	static const_base_ptr _S_maximum(const_base_ptr x)
    	{
    		while (x->_right != 0) x = x->_right;
    		return x;
    	}
    };

    // _Rb_tree_key_compare
    template<typename _Key_compare>
    struct tree_key_compare
    {
    	_Key_compare                key_compare;
    	tree_key_compare()
    	: key_compare()
    	{}

    	tree_key_compare(const _Key_compare& comp)
    	: key_compare(comp)
    	{}
    };

    // _Rb_tree_node
    template<typename val>
    struct tree_node : public tree_node_base
    {
    	typedef tree_node<val>* link_type;
    	val 					value_field;

    	val* valptr()
    	{
    		return __builtin_addressof(value_field);
    	}
    	const val* valptr() const
    	{
    		return __builtin_addressof(value_field);
    	}
    };

    // _Rb_tree_header
    struct tree_header
    {
    	tree_node_base        _header;
    	size_t                _node_count;

    	tree_header()
    	{
    		_header._color = _red;
    		_reset();
    	}

    	// _M_move_data
    	void _move_data(tree_header& from)
    	{
    		_header._color = from._header._color;
    		_header._parent = from._header._parent;
    		_header._left = from._header._left;
    		_header._right = from._header._right;
    		_header._parent->_parent = &_header;
    		_node_count = from._node_count;

    		from._reset();
    	}

    	// _M_reset
    	void _reset()
    	{
    		_header._parent = 0;
    		_header._left = &_header;
    		_header._right = &_header;
    		_node_count = 0;
    	}
    };

    // _Rb_tree_iterator
    template<typename _Tp>
    struct tree_iterator
    {
    	typedef _Tp  							value_type;
    	typedef _Tp& 							reference;
    	typedef _Tp* 							pointer;
    	typedef bidirectional_iterator_tag		iterator_category;
    	typedef ptrdiff_t						difference_type;
    	typedef tree_iterator<_Tp>				self;
    	typedef tree_node_base::base_ptr		base_ptr;
    	typedef tree_node<_Tp>*					link_type;

    	tree_iterator()
    	: _node()
    	{}

    	explicit tree_iterator(base_ptr __x)
    	: _node(__x)
    	{}

    	reference operator*() const
    	{
    		return *static_cast<link_type>(_node)->valptr();
    	}

    	pointer operator->() const
    	{
    		return static_cast<link_type> (_node)->valptr();
    	}

    	self& operator++()
    	{
    		// NOT OK
    		_node = tree_increment(_node);
    		return *this;
    	}

    	self operator++(int)
    	{
    		self tmp = *this;
    		_node = tree_increment(_node);
    		return tmp;
    	}

    	self& operator--()
    	{
    		_node = tree_decrement(_node);
    		return *this;
    	}

    	self operator--(int)
    	{
    		self tmp = *this;
    		_node = tree_decrement(_node);
    		return tmp;
    	}

    	bool operator==(const self& x) const
    	{
    		return _node == x._node;
    	}

    	bool operator!=(const self& x) const
    	{
    		return _node != x._node;
    	}
    	base_ptr _node;
    };

    // _Rb_tree_const_iterator
    template<typename _Tp>
    struct tree_const_iterator
    {
    	typedef _Tp									value_type;
    	typedef const _Tp&							reference;
    	typedef const _Tp*							pointer;
    	typedef tree_iterator<_Tp>					iterator;
    	typedef bidirectional_iterator_tag			iterator_category;
    	typedef ptrdiff_t							difference_type;
    	typedef tree_const_iterator<_Tp>			self;
    	typedef tree_node_base::const_base_ptr		base_ptr;
    	typedef const tree_node<_Tp>*				link_type;

    	tree_const_iterator()
    	: _node() { }

    	explicit tree_const_iterator(base_ptr __x)
    	: _node(__x) { }

    	tree_const_iterator(const iterator& __it)
    	: _node(__it._node) { }

    	// _M_const_cast
    	iterator _const_cast() const
    	{
    		return iterator(const_cast<typename iterator::base_ptr>(_node));
    	}

    	reference operator*() const
    	{
    		return *static_cast<link_type>(_node)->valptr();
    	}

    	pointer operator->() const
    	{
    		return static_cast<link_type>(_node)->valptr();
    	}

    	self& operator++()
    	{
    		_node = tree_increment(_node);
    		return *this;
    	}

    	self operator++(int)
    	{
    		self __tmp = *this;
    		_node = tree_increment(_node);
    		return __tmp;
    	}

    	self& operator--()
    	{
    		_node = tree_decrement(_node);
    		return *this;
    	}

    	self operator--(int)
    	{
    		self __tmp = *this;
    		_node = tree_decrement(_node);
    		return __tmp;
    	}

    	bool operator==(const self& __x) const
    	{
    		return _node == __x._node;
    	}

    	bool operator!=(const self& __x) const
    	{
    		return _node != __x._node;
    	}

    	base_ptr _node;
    };

    template<typename _Val>
    bool operator==(const tree_iterator<_Val>& x, const tree_const_iterator<_Val>& y)
    {
    	return x._node == y._node;
    }

    template<typename _Val>
    bool operator!=(const tree_iterator<_Val>& x, const tree_const_iterator<_Val>& y)
    {
    	return x._node != y._node;
    }

    // local_Rb_tree_increment
    template <typename _Tp>
    static _Tp* local_tree_increment(_Tp* x) throw ()
    {
    	if (x->_right != 0)
    	{
    		x = x->_right;
    		while (x->_left != 0)
    			x = x->_left;
    	}
    	else
    	{
    		_Tp* y = x->_parent;
    		while (x == y->_right)
    		{
    			x = y;
    			y = y->_parent;
    		}
    		if (x->_right != y)
    			x = y;
    	}
    	return x;
    }

    // _Rb_tree_increment
    template <typename _Tp>
    _Tp* tree_increment(_Tp* x) throw ()
    {
    	return local_tree_increment(x);
    }

    template <typename _Tp>
    const _Tp* tree_increment(const _Tp* x) throw ()
    {
    	return local_tree_increment(const_cast<_Tp*>(x));
    }

    // local_Rb_tree_decrement
    template <typename _Tp>
    static _Tp* local_tree_decrement(_Tp* x) throw ()
    {
    	if (x->_color == _red && x->_parent->_parent == x)
    		x = x->_right;
    	else if (x->_left != 0)
    	{
    		_Tp* y = x->_left;
    		while (y->_right != 0)
    			y = y->_right;
    		x = y;
    	}
    	else
    	{
    		_Tp* y = x->_parent;
    		while (x == y->_left)
    		{
    			x = y;
    			y = y->_parent;
    		}
    		x = y;
    	}
    	return x;
    }

    // _Rb_tree_decrement
    template <typename _Tp>
    _Tp* tree_decrement(_Tp* x) throw ()
    {
    	return local_tree_decrement(x);
    }

    template <typename _Tp>
    const _Tp* tree_decrement(const _Tp* x) throw ()
    {
    	return local_tree_decrement(const_cast<_Tp*>(x));
    }
  	

	template<typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename Allocator = std::allocator<_Val> >
	// _Rb_tree
	class rb_tree
    {
    	// _Node_allocator
		typedef typename
		Allocator::template rebind<tree_node<_Val> >::other 	node_allocator;
      	node_allocator											_alloc;
      	
    protected:
      	typedef tree_node_base*                 		base_ptr;
      	typedef const tree_node_base*         			const_base_ptr;
      	typedef tree_node<_Val>*                 		link_type;
      	typedef const tree_node<_Val>*        			const_link_type;

	private:
		// _Reuse_or_alloc_node
		struct reuse_or_alloc_node
		{
			reuse_or_alloc_node(rb_tree& t)
			: _root(t._root()), _nodes(t.rightmost()), m_t(t)
			{
				if (_root)
				{
					_root->_parent = 0;
					if (_nodes->_left)
						_nodes = _nodes->_left;
				}
				else
					_nodes = 0;
			}

			~reuse_or_alloc_node()
			{
				m_t._erase(static_cast<link_type>(_root));
			}

			template<typename _Arg>
			link_type operator()(const _Arg& arg)
			{
				link_type node = static_cast<link_type>(_extract());
				if (node)
				{
					m_t.destroy_node(node);
					m_t.construct_node(node, arg);
					return node;
				}
				return m_t.create_node(arg);
			}
		private:
			// _M_extract
			base_ptr _extract()
			{
				if (!_nodes)
					return _nodes;
				base_ptr node = _nodes;
				_nodes = _nodes->_parent;
				if (_nodes)
				{
					if (_nodes->_right == node)
					{
						_nodes->_right = 0;
						if (_nodes->_left)
						{
							_nodes = _nodes->_left;
							while (_nodes->_right)
								_nodes = _nodes->_right;
							if (_nodes->_left)
								_nodes = _nodes->_left;
						}
					}
					else
						_nodes->_left = 0;
				}
				else
					_root = 0;
				return node;
			}
			base_ptr _root;
	        base_ptr _nodes;
	        rb_tree& m_t;
		};

		// _Alloc_node
		struct alloc_node
		{
			alloc_node(rb_tree& t)
			: m_t(t)
			{}

			template<typename _Arg>
			link_type operator()(const _Arg& arg) const
          	{
          		return m_t.create_node(arg);
          	}
        private:
        	rb_tree& m_t;
      	};

    public:
    	typedef _Key									key_type;
    	typedef _Val									value_type;
    	typedef value_type*								pointer;
    	typedef const value_type*						const_pointer;
    	typedef value_type&								reference;
    	typedef const value_type&						const_reference;
    	typedef size_t									size_type;
    	typedef ptrdiff_t								difference_type;
    	typedef Allocator								allocator_type;
    	typedef tree_iterator<value_type>				iterator;
      	typedef tree_const_iterator<value_type>			const_iterator;
      	typedef ft::reverse_iterator<iterator>			reverse_iterator;
      	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

    	//  _M_get_Node_allocator
    	node_allocator& get_node_allocator()
    	{
    		return this->_impl;
    	}

    	const node_allocator& get_node_allocator() const
    	{
    		return this->_impl;
    	}

    	allocator_type get_allocator() const
    	{
    		return allocator_type(get_node_allocator());
    	}

	protected:
		// _M_get_node
		link_type get_node()
		{
			return _alloc.allocate(1);
		}
		// _M_put_node
		void put_node(link_type p)
		{
			_alloc.deallocate(p, 1);
		}

		// _M_construct_node
		void construct_node(link_type node, const value_type& x)
		{
			try
			{
				get_allocator().construct(node->valptr(), x);
			}
			catch(...)
			{
				put_node(node);
				throw;
			}
		}

		// _M_create_node
		link_type create_node(const value_type& x)
		{
			link_type tmp = get_node();
        	construct_node(tmp, x);
        	return tmp;
		}

		// _M_destroy_node
		void destroy_node(link_type p)
		{
			get_allocator().destroy(p->valptr());
		}

		// _M_drop_node
		void drop_node(link_type p)
		{
			destroy_node(p);
			put_node(p);
		}

		// _M_clone_node
		template<typename _NodeGen>
        link_type clone_node(const_link_type x, _NodeGen& node_gen)
        {
        	link_type tmp = node_gen(*x->valptr());
        	tmp->_color = x->_color;
        	tmp->_left = 0;
        	tmp->_right = 0;
        	return tmp;
        }

        // _Rb_tree_impl
        template<typename _Key_compare>
        struct tree_impl
        : public node_allocator, public tree_key_compare<_Key_compare>
        , public tree_header
        {
        	typedef tree_key_compare<_Key_compare> base_key_compare;

        	tree_impl()
        	: node_allocator()
        	{}

        	tree_impl(const tree_impl& x)
        	: node_allocator(),
        	  base_key_compare(x.key_compare)
        	{}

			tree_impl(const _Key_compare& comp, const node_allocator& a)
			: node_allocator(a), base_key_compare(comp)
			{}
		};

        tree_impl<_Compare> _impl;

        // _S_value
        static const_reference _s_value(const_link_type x)
        {
        	return *x->valptr();
        }

        static const_reference _s_value(const_base_ptr x)
        {
        	return *static_cast<const_link_type>(x)->valptr();
        }

        // _S_key
        static const key_type& _s_key(const_link_type x)
        {
        	return _KeyOfValue()(_s_value(x));
        }

        static const key_type& _s_key(const_base_ptr x)
        {
        	return _KeyOfValue()(_s_value(x));
        }

        // _S_left
        static link_type _s_left(base_ptr x)
        {
        	return static_cast<link_type>(x->_left);
        }

        static const_link_type _s_left(const_base_ptr x)
        {
        	return static_cast<const_link_type>(x->_left);
        }

        // _S_right
        static link_type _s_right(base_ptr x)
        {
        	return static_cast<link_type>(x->_right);
        }

        static const_link_type _s_right(const_base_ptr x)
        {
        	return static_cast<const_link_type>(x->_right);
        }

        // _S_minimum
        static base_ptr _s_minimum(base_ptr x)
        {
        	return tree_node_base::_S_minimum(x);
        }

        static const_base_ptr _s_minimum(const_base_ptr x)
        {
        	return tree_node_base::_S_minimum(x);
        }

        // _S_maximum
        static base_ptr _s_maximum(base_ptr x)
        {
        	return tree_node_base::_S_maximum(x);
        }

        static const_base_ptr _s_maximum(const_base_ptr x)
        {
        	return tree_node_base::_S_maximum(x);
        }

        // _M_insert_
        template<typename _NodeGen>
        iterator _insert(base_ptr x, base_ptr p, const value_type& v, _NodeGen& node_gen)
        {
        	bool insert_left = (x != 0 || p == _end() ||
        		_impl.key_compare(_KeyOfValue()(v), _s_key(p)));
        	link_type z = node_gen(v);
        	tree_insert_and_rebalance(insert_left, z, p, _impl._header);
        	++_impl._node_count;
        	return iterator(z);
        }

        // _M_begin
    	link_type _begin()
    	{
    		return static_cast<link_type>(this->_impl._header._parent);
    	}

    	const_link_type _begin() const
    	{
    		return static_cast<const_link_type>(this->_impl._header._parent);
    	}

    	// _M_end
    	base_ptr _end()
    	{
    		return &this->_impl._header;
    	}

    	const_base_ptr _end() const
    	{
    		return &this->_impl._header;
    	}

    	// _Rb_tree_insert_and_rebalance
    	void tree_insert_and_rebalance(
    		const bool __insert_left,
    		tree_node_base* x,
    		tree_node_base* p,
    		tree_node_base& header) throw ()
    	{
    		tree_node_base *& root = header._parent;
    		x->_parent = p;
    		x->_left = 0;
    		x->_right = 0;
    		x->_color = _red;

    		if (__insert_left)
    		{
    			p->_left = x;
	    		if (p == &header)
	    		{
	    			header._parent = x;
	    			header._right = x;
	    		}
	    		else if (p == header._left)
	    			header._left = x;
	    	}
	    	else
	    	{
	    		p->_right = x;
	    		if (p == header._right)
	    			header._right = x;
	    	}
	    	while (x != root && x->_parent->_color == _red)
	    	{
	    		tree_node_base* const xpp = x->_parent->_parent;
	    		if (x->_parent == xpp->_left)
	    		{
	    			tree_node_base* const __y = xpp->_right;
	    			if (__y && __y->_color == _red)
	    			{
	    				x->_parent->_color = _black;
	    				__y->_color = _black;
	    				xpp->_color = _red;
	    				x = xpp;
	    			}
	    			else
	    			{
	    				if (x == x->_parent->_right)
	    				{
	    					x = x->_parent;
	    					local_tree_rotate_left(x, root);
	    				}
	    				x->_parent->_color = _black;
	    				xpp->_color = _red;
	    				local_tree_rotate_right(xpp, root);
	    			}
	    		}
	    		else
	    		{
	    			tree_node_base* const __y = xpp->_left;
	    			if (__y && __y->_color == _red)
	    			{
	    				x->_parent->_color = _black;
	    				__y->_color = _black;
	    				xpp->_color = _red;
	    				x = xpp;
	    			}
	    			else
	    			{
	    				if (x == x->_parent->_left)
	    				{
	    					x = x->_parent;
	    					local_tree_rotate_right(x, root);
	    				}
	    				x->_parent->_color = _black;
	    				xpp->_color = _red;
	    				local_tree_rotate_left(xpp, root);
	    			}
	    		}
	    	}
	    	root->_color = _black;
	    }

	    // _Rb_tree_rebalance_for_erase
		tree_node_base* tree_rebalance_for_erase(
			tree_node_base* const z,
			tree_node_base& header) throw ()
		{
			tree_node_base *& root = header._parent;
			tree_node_base *& leftmost = header._left;
			tree_node_base *& rightmost = header._right;
			tree_node_base* y = z;
			tree_node_base* x = 0;
			tree_node_base* x_parent = 0;
			if (y->_left == 0)
			{
				x = y->_right;
			}
			else
			{
				if (y->_right == 0)
					x = y->_left;
				else
				{
					y = y->_right;
					while (y->_left != 0)
						y = y->_left;
					x = y->_right;
				}
			}
			if (y != z)
			{
				z->_left->_parent = y;
				y->_left = z->_left;
				if (y != z->_right)
				{
					x_parent = y->_parent;
					if (x)
						x->_parent = y->_parent;
					y->_parent->_left = x;
					y->_right = z->_right;
					z->_right->_parent = y;
				}
				else
					x_parent = y;
				if (root == z)
					root = y;
				else if (z->_parent->_left == z)
					z->_parent->_left = y;
				else
					z->_parent->_right = y;
				y->_parent = z->_parent;
				ft::swap(y->_color, z->_color);
				y = z;
			}
			else
			{
				x_parent = y->_parent;
				if (x)
					x->_parent = y->_parent;
				if (root == z)
					root = x;
				else
					if (z->_parent->_left == z)
						z->_parent->_left = x;
					else
						z->_parent->_right = x;
				if (leftmost == z)
				{
					if (z->_right == 0)
						leftmost = z->_parent;
					else
						leftmost = tree_node_base::_S_minimum(x);
				}
				if (rightmost == z)
				{
					if (z->_left == 0)
						rightmost = z->_parent;
					else
						rightmost = tree_node_base::_S_maximum(x);
				}
			}
			if (y->_color != _red)
			{
				while (x != root && (x == 0 || x->_color == _black))
					if (x == x_parent->_left)
					{
						tree_node_base* w = x_parent->_right;
						if (w->_color == _red)
						{
							w->_color = _black;
							x_parent->_color = _red;
							local_tree_rotate_left(x_parent, root);
							w = x_parent->_right;
						}
						if ((w->_left == 0 || w->_left->_color == _black) &&
							(w->_right == 0 || w->_right->_color == _black))
						{
							w->_color = _red;
							x = x_parent;
							x_parent = x_parent->_parent;
						}
						else
						{
							if (w->_right == 0 || w->_right->_color == _black)
							{
								w->_left->_color = _black;
								w->_color = _red;
								local_tree_rotate_right(w, root);
								w = x_parent->_right;
							}
							w->_color = x_parent->_color;
							x_parent->_color = _black;
							if (w->_right)
								w->_right->_color = _black;
							local_tree_rotate_left(x_parent, root);
							break;
						}
					}
					else
					{
						tree_node_base* w = x_parent->_left;
						if (w->_color == _red)
						{
							w->_color = _black;
							x_parent->_color = _red;
							local_tree_rotate_right(x_parent, root);
							w = x_parent->_left;
						}
						if ((w->_right == 0 || w->_right->_color == _black) &&
							(w->_left == 0 || w->_left->_color == _black))
						{
							w->_color = _red;
							x = x_parent;
							x_parent = x_parent->_parent;
						}
						else
						{
							if (w->_left == 0 || w->_left->_color == _black)
							{
								w->_right->_color = _black;
								w->_color = _red;
								local_tree_rotate_left(w, root);
								w = x_parent->_left;
							}
							w->_color = x_parent->_color;
							x_parent->_color = _black;
							if (w->_left)
								w->_left->_color = _black;
							local_tree_rotate_right(x_parent, root);
							break;
						}
					}
        		if (x)
        			x->_color = _black;
        	}
        	return y;
        }

	    // local_Rb_tree_rotate_left
	    static void local_tree_rotate_left(tree_node_base* const x, tree_node_base*& root)
	    {
	    	tree_node_base* const y = x->_right;
	    	x->_right = y->_left;
	    	if (y->_left != 0)
	    		y->_left->_parent = x;
	    	y->_parent = x->_parent;
	    	if (x == root)
	    		root = y;
	    	else if (x == x->_parent->_left)
	    		x->_parent->_left = y;
	    	else
	    		x->_parent->_right = y;
	    	y->_left = x;
	    	x->_parent = y;
	    }

	    // local_Rb_tree_rotate_right
	    static void local_tree_rotate_right(tree_node_base* const x, tree_node_base*& root)
	    {
	    	tree_node_base* const y = x->_left;
	    	x->_left = y->_right;
	    	if (y->_right != 0)
	    		y->_right->_parent = x;
	    	y->_parent = x->_parent;
	    	if (x == root)
	    		root = y;
	    	else if (x == x->_parent->_right)
	    		x->_parent->_right = y;
	    	else
	    		x->_parent->_left = y;
	    	y->_right = x;
	    	x->_parent = y;
	    }

	    // _M_root
	    base_ptr& _root()
	    {
	    	return _impl._header._parent;
	    }

	    const_base_ptr _root() const
	    {
	    	return _impl._header._parent;
	    }

	    // _M_rightmost
	    base_ptr& rightmost()
	    {
	    	return _impl._header._right;
	    }

      	const_base_ptr rightmost() const
      	{
      		return _impl._header._right;
      	}

      	// _M_leftmost
      	base_ptr& leftmost()
      	{
      		return _impl._header._left;
      	}

      	const_base_ptr leftmost() const
      	{
      		return _impl._header._left;
      	}

      	// _M_copy
      	template<typename _NodeGen>
        link_type _copy(const_link_type x, base_ptr p, _NodeGen& node_gen)
        {
        	link_type top = clone_node(x, node_gen);
        	top->_parent = p;
        	try
        	{
        		if (x->_right)
        			top->_right = _copy(_s_right(x), top, node_gen);
        		p = top;
        		x = _s_left(x);
        		while (x != 0)
        		{
        			link_type y = clone_node(x, node_gen);
        			p->_left = y;
        			y->_parent = p;
        			if (x->_right)
        				y->_right = _copy(_s_right(x), y, node_gen);
        			p = y;
        			x = _s_left(x);
        		}
        	}
        	catch(...)
        	{
        		_erase(top);
        		throw;
        	}
        	return top;
        }
      
		template<typename _NodeGen>
        link_type _copy(const rb_tree& x, _NodeGen& gen)
        {
        	link_type root = _copy(x._begin(), _end(), gen);
        	leftmost() = _s_minimum(root);
        	rightmost() = _s_maximum(root);
        	_impl._node_count = x._impl._node_count;
        	return root;
        }

        link_type _copy(const rb_tree& x)
        {
        	alloc_node an(*this);
        	return _copy(x, an);
        }

        // _M_get_insert_unique_pos
        ft::pair<base_ptr, base_ptr> get_insert_unique_pos(const key_type& k)
        {
        	typedef pair<base_ptr, base_ptr> ret;
        	link_type x = _begin();
			base_ptr y = _end();
			bool comp = true;

			while (x != 0)
			{
				y = x;
				comp = _impl.key_compare(k, _s_key(x));
				x = comp ? _s_left(x) : _s_right(x);
			}
			iterator j = iterator(y);
			if (comp)
			{
				if (j == begin())
					return ret(x, y);
				else
					--j;
			}
			if (_impl.key_compare(_s_key(j._node), k))
				return ret(x, y);
			return ret(j._node, 0);
		}

		// _M_get_insert_hint_unique_pos
		ft::pair<base_ptr, base_ptr> get_insert_hint_unique_pos(const_iterator pos, const key_type& k)
		{
			iterator p = pos._const_cast();
			typedef ft::pair<base_ptr, base_ptr> ret;
			if (p._node == _end())
			{
				if (size() > 0 && _impl.key_compare(_s_key(rightmost()), k))
					return ret(0, rightmost());
				else
					return get_insert_unique_pos(k);
			}
			else if (_impl.key_compare(k, _s_key(p._node)))
			{
				iterator before = p;
				if (p._node == leftmost())
					return ret(leftmost(), leftmost());
				else if (_impl.key_compare(_s_key((--before)._node), k))
				{
					if (_s_right(before._node) == 0)
						return ret(0, before._node);
					else
						return ret(p._node, p._node);
				}
				else
					return get_insert_unique_pos(k);
			}
			else if (_impl.key_compare(_s_key(p._node), k))
			{
				iterator after = p;
				if (p._node == rightmost())
					return ret(0, rightmost());
				else if (_impl.key_compare(k, _s_key((++after)._node)))
				{
					if (_s_right(p._node) == 0)
						return ret(0, p._node);
					else
						return ret(after._node, after._node);
				}
				else
					return get_insert_unique_pos(k);
			}
			else
				return ret(p._node, 0);
		}

		// _M_lower_bound
		iterator _lower_bound(link_type x, base_ptr y, const key_type& k)
		{
			while (x != 0)
			{
				if (!_impl.key_compare(_s_key(x), k))
				{
					y = x;
					x = _s_left(x);
				}
				else
					x = _s_right(x);
			}
			return iterator(y);
		}
  
    	const_iterator _lower_bound(const_link_type x, const_base_ptr y, const key_type& k) const
    	{
    		while (x != 0)
    		{
    			if (!_impl.key_compare(_s_key(x), k))
    			{
    				y = x;
    				x = _s_left(x);
    			}
    			else
    				x = _s_right(x);
    		}
    		return const_iterator(y);
    	}

    	// _M_upper_bound
    	iterator _upper_bound(link_type x, base_ptr y, const key_type& k)
    	{
    		while (x != 0)
    			if (_impl.key_compare(k, _s_key(x)))
    			{
    				y = x;
    				x = _s_left(x);
    			}
    			else
    				x = _s_right(x);
    		return iterator(y);
    	}

    	const_iterator _upper_bound(const_link_type x, const_base_ptr y, const key_type& k) const
    	{
    		while (x != 0)
    			if (_impl.key_compare(k, _s_key(x)))
    			{
    				y = x;
    				x = _s_left(x);
    			}
    			else
    				x = _s_right(x);
    		return const_iterator(y);
    	}

    	// _M_erase
    	void _erase(link_type x)
    	{
    		while (x != 0)
    		{
          		_erase(_s_right(x));
          		link_type y = _s_left(x);
          		drop_node(x);
          		x = y;
          	}
        }

        // _M_erase_aux
		void _erase_aux(const_iterator position)
		{
			link_type y = static_cast<link_type>(tree_rebalance_for_erase(
				const_cast<base_ptr>(position._node),
				_impl._header));
			drop_node(y);
			--_impl._node_count;
		}

		void _erase_aux(const_iterator first, const_iterator last)
		{
			if (first == begin() && last == end())
				clear();
			else
			{
				while (first != last)
					_erase_aux(first++);
			}
		}
    
    public:
    	
    	// _M_insert_unique
    	ft::pair<iterator, bool> insert_unique(const value_type& x)
    	{
    		typedef ft::pair<iterator, bool> ret;
    		
    		ft::pair<base_ptr, base_ptr> res = get_insert_unique_pos(_KeyOfValue()(x));

    		if (res.second)
    		{
    			alloc_node an(*this);
    			return ret(_insert(res.first, res.second, x, an), true);
    		}
    		return ret(iterator(res.first), false);
    	}

    	template<typename _InputIterator>
        void insert_unique(_InputIterator first, _InputIterator last)
        {
        	alloc_node an(*this);
        	for (; first != last; ++first)
        		_insert_unique(end(), *first, an);
        }

        // _M_insert_unique_
        template<typename _NodeGen>
        iterator _insert_unique(const_iterator pos, const value_type& x, _NodeGen& node_gen)
        {
        	ft::pair<base_ptr, base_ptr> res = get_insert_hint_unique_pos(pos, _KeyOfValue()(x));
        	if (res.second)
        		return _insert(res.first, res.second, x, node_gen);
        	return iterator(res.first);
        }

        iterator _insert_unique(const_iterator pos, const value_type& x)
        {
        	alloc_node an(*this);
        	return _insert_unique(pos, x, an);
        }

        _Compare key_comp() const
        {
        	return _impl.key_compare;
        }

    	iterator begin()
    	{
    		return iterator(this->_impl._header._left);
    	}

    	const_iterator begin() const
    	{
    		return const_iterator(this->_impl._header._left);
    	}

    	iterator end()
    	{
    		return iterator(&_impl._header);
    	}

    	const_iterator end() const
    	{
    		return const_iterator(&_impl._header);
    	}

    	reverse_iterator rbegin()
    	{
    		return reverse_iterator(end());
    	}

    	const_reverse_iterator rbegin() const
    	{
    		return const_reverse_iterator(end());
    	}

    	reverse_iterator rend()
    	{
    		return reverse_iterator(begin());
    	}

    	const_reverse_iterator rend() const
    	{
    		return const_reverse_iterator(begin());
    	}

    	bool empty() const
    	{
    		return _impl._node_count == 0;
    	}

    	size_type size() const
    	{
    		return _impl._node_count;
    	}

    	size_type max_size() const
    	{
    		return _alloc.max_size();
    	}

    	iterator lower_bound(const key_type& k)
    	{
    		return _lower_bound(_begin(), _end(), k);
    	}

    	const_iterator lower_bound(const key_type& k) const
    	{
    		return _lower_bound(_begin(), _end(), k);
    	}

    	iterator upper_bound(const key_type& k)
    	{
    		return _upper_bound(_begin(), _end(), k);
    	}

    	const_iterator upper_bound(const key_type& k) const
    	{
    		return _upper_bound(_begin(), _end(), k);
    	}

    	void clear()
    	{
    		_erase(_begin());
    		_impl._reset();
    	}

    	iterator find(const key_type& k)
    	{
    		iterator j = _lower_bound(_begin(), _end(), k);
    		return (j == end() || _impl.key_compare(k, _s_key(j._node))) ? end() : j;
    	}
  		
  		const_iterator find(const key_type& k) const
  		{
  			const_iterator j = _lower_bound(_begin(), _end(), k);
  			return (j == end() || _impl.key_compare(k, _s_key(j._node))) ? end() : j;
  		}

  		// constructor
  		rb_tree()
  		{}

  		rb_tree(const _Compare& comp, const allocator_type& a = allocator_type())
  		: _impl(comp, node_allocator(a))
  		{}

      	rb_tree(const rb_tree& x)
      	: _impl(x._impl)
      	{
      		if (x._root() != 0)
      			_root() = _copy(x);
      	}

      	~rb_tree()
      	{
      		_erase(_begin());
      	}

     
	    rb_tree operator=(const rb_tree& x)
	    {
	    	if (this != &x)
        	{
        		reuse_or_alloc_node roan(*this);
        		_impl._reset();
        		_impl.key_compare = x._impl.key_compare;
        		if (x._root() != 0)
        			_root() = _copy(x, roan);
        	}
        	return *this;
	    }
	    
	    void erase(iterator position)
	    {
	    	_erase_aux(position);
	    }

	    void erase(const_iterator position)
	    {
	    	_erase_aux(position);
	    }

	    size_type erase(const key_type& x)
	    {
	    	pair<iterator, iterator> p = equal_range(x);
	    	const size_type old_size = size();
	    	_erase_aux(p.first, p.second);
	    	return old_size - size();
	    }

	    void erase(iterator first, iterator last)
	    {
	    	_erase_aux(first, last);
	    }

	    void erase(const_iterator first, const_iterator last)
	    {
	    	_erase_aux(first, last);
	    }

	    void erase(const key_type* first, const key_type* last);

	    pair<iterator, iterator> equal_range(const key_type& k)
	    {
	    	link_type x = _begin();
	    	base_ptr y = _end();

	    	while (x != 0)
	    	{
	    		if (_impl.key_compare(_s_key(x), k))
	    			x = _s_right(x);
	    		else if (_impl.key_compare(k, _s_key(x)))
	    		{
	    			y = x;
	    			x = _s_left(x);
	    		}
	    		else
	    		{
	    			link_type xu(x);
	    			base_ptr yu(y);
	    			y = x;
	    			x = _s_left(x);
	    			xu = _s_right(xu);
	    			return pair<iterator, iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k));
	    		}
	    	}
	    	return pair<iterator, iterator>(iterator(y), iterator(y));
	    }

	    pair<const_iterator, const_iterator> equal_range(const key_type& k) const
	    {
	    	const_link_type x = _begin();
	    	const_base_ptr y = _end();

	    	while (x != 0)
	    	{
	    		if (_impl.key_compare(_s_key(x), k))
	    			x = _S_right(x);
	    		else if (_impl.key_compare(k, _s_key(x)))
    			{
    				y = x;
    				x = _s_left(x);
    			}
    			else
    			{
    				const_link_type xu(x);
    				const_base_ptr yu(y);
    				y = x;
    				x = _s_left(x);
    				xu = _s_right(xu);
    				return pair<const_iterator, const_iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k));
    			}
    		}
    		return pair<const_iterator, const_iterator>(const_iterator(y), const_iterator(y));
    	}

    	void swap(rb_tree& t)
    	{
    		if (_root() == 0)
    		{
    			if (t._root() != 0)
    				_impl._move_data(t._impl);
    		}
    		else if (t._root() == 0)
    			t._impl._move_data(_impl);
    		else
    		{
    			ft::swap(_root(),t._root());
    			ft::swap(leftmost(),t.leftmost());
    			ft::swap(rightmost(),t.rightmost());
    			_root()->_parent = _end();
    			t._root()->_parent = t._end();
    			ft::swap(_impl._node_count, t._impl._node_count);
    		}

    		ft::swap(_impl.key_compare, t._impl.key_compare);
    	}
	};

	template<typename _K, typename _V, typename _KOfV, typename _C, typename _A>
    bool operator==(
    	const rb_tree<_K, _V, _KOfV, _C, _A>& x,
    	const rb_tree<_K, _V, _KOfV, _C, _A>& y)
    {
    	return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
    }

    template<typename _K, typename _V, typename _KOfV, typename _C, typename _A>
    bool operator<(
    	const rb_tree<_K, _V, _KOfV, _C, _A>& x,
    	const rb_tree<_K, _V, _KOfV, _C, _A>& y)
    {
    	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }

    template<typename _K, typename _V, typename _KOfV, typename _C, typename _A>
    bool operator!=(
    	const rb_tree<_K, _V, _KOfV, _C, _A>& x,
    	const rb_tree<_K, _V, _KOfV, _C, _A>& y)
    {
    	return !(x == y);
    }

    template<typename _K, typename _V, typename _KOfV, typename _C, typename _A>
    bool operator>(
    	const rb_tree<_K, _V, _KOfV, _C, _A>& x,
    	const rb_tree<_K, _V, _KOfV, _C, _A>& y)
    {
    	return y < x;
    }

    template<typename _K, typename _V, typename _KOfV, typename _C, typename _A>
    bool operator<=(
    	const rb_tree<_K, _V, _KOfV, _C, _A>& x,
    	const rb_tree<_K, _V, _KOfV, _C, _A>& y)
    {
    	return !(y < x);
    }

	template<typename _K, typename _V, typename _KOfV, typename _C, typename _A>
    bool operator>=(
    	const rb_tree<_K, _V, _KOfV, _C, _A>& x,
    	const rb_tree<_K, _V, _KOfV, _C, _A>& y)
    {
    	return !(x < y);
    }

    template<typename _Key, typename _V, typename _KOfV, typename _C, typename _A>
    void swap(rb_tree<_Key, _V, _KOfV, _C, _A>& x,
         rb_tree<_Key, _V, _KOfV, _C, _A>& y)
    {
    	x.swap(y);
    }  
}

#endif
