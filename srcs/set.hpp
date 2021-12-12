/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:29:06 by tgildero          #+#    #+#             */
/*   Updated: 2021/12/12 18:29:10 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <iostream>
# include <memory>
# include "iterator.hpp"
# include "utils.hpp"
# include "traits.hpp"
# include "tree.hpp"

namespace ft
{
	template<typename _Key, typename _Compare = ft::less<_Key>,
           typename Allocator = std::allocator<_Key> >
    class set
	{
	public:
		typedef _Key     	key_type;
		typedef _Key     	value_type;
		typedef _Compare 	key_compare;
		typedef _Compare 	value_compare;
		typedef Allocator   allocator_type;

	private:
		typedef typename Allocator::template rebind<_Key>::other key_alloc_type;
		typedef rb_tree<key_type, value_type, ft::_identity<value_type>,
                       key_compare, key_alloc_type> rep_type;

		rep_type m_t;
		key_alloc_type _alloc;
	public:
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename rep_type::const_iterator				iterator;
		typedef typename rep_type::const_iterator				const_iterator;
		typedef typename rep_type::const_reverse_iterator		reverse_iterator;
		typedef typename rep_type::const_reverse_iterator		const_reverse_iterator;
		typedef typename rep_type::size_type					size_type;
		typedef typename rep_type::difference_type				difference_type;

		set() : m_t()
		{}

		explicit set(const _Compare& comp, const allocator_type& a = allocator_type())
		: m_t(comp, key_alloc_type(a))
		{}

		template<typename _InputIterator>
        set(_InputIterator first, _InputIterator last)
        : m_t()
        {
        	m_t.insert_unique(first, last);
        }

        template<typename _InputIterator>
        set(_InputIterator first, _InputIterator last, const _Compare& comp,
            const allocator_type& a = allocator_type())
        : m_t(comp, key_alloc_type(a))
        {
        	m_t.insert_unique(first, last);
        }

        set(const set& x)
        : m_t(x.m_t)
        {}

        ~set()
		{
			clear();
		}

        set& operator=(const set& x)
        {
        	m_t = x.m_t;
        	return *this;
        }

        iterator begin() const
        {
        	return m_t.begin();
        }

        iterator end() const
        {
        	return m_t.end();
        }

        reverse_iterator rbegin() const
        {
        	return m_t.rbegin();
        }

        reverse_iterator rend() const
        {
        	return m_t.rend();
        }

        bool empty() const
        {
        	return m_t.empty();
        }

        size_type size() const
        {
        	return m_t.size();
        }

        size_type max_size() const
        {
        	return m_t.max_size();
        }

        ft::pair<iterator, bool> insert(const value_type& x)
        {
        	ft::pair<typename rep_type::iterator, bool> p = m_t.insert_unique(x);
        	return ft::pair<iterator, bool>(p.first, p.second);
        }

        iterator insert(const_iterator position, const value_type& x)
        {
        	return m_t._insert_unique(position, x);
        }

        template<typename _InputIterator>
        void insert(_InputIterator first, _InputIterator last)
        {
        	m_t.insert_unique(first, last);
        }

        void erase (iterator position)
		{
			m_t.erase(position);
		}

		size_type erase(const key_type& x)
		{
			return m_t.erase(x);
		}

		void erase (iterator first, iterator last)
		{
			m_t.erase(first, last);
		}

        void swap(set& x)
        {
        	m_t.swap(x.m_t);
        }

        void clear()
        {
        	m_t.clear();
        }

        key_compare key_comp() const
        {
        	return m_t.key_comp();
        }

        value_compare value_comp() const
        {
        	return m_t.key_comp();
        }

        iterator find(const key_type& x)
	    {
	    	return m_t.find(x);
	    }
	    const_iterator find(const key_type& x) const
	    {
	    	return m_t.find(x);
	    }

        size_type count(const key_type& x) const
        {
        	return m_t.find(x) == m_t.end() ? 0 : 1;
        }

        iterator lower_bound(const key_type& x)
	    {
	    	return m_t.lower_bound(x);
	    }

	    const_iterator lower_bound(const key_type& x) const
	    {
	    	return m_t.lower_bound(x);
	    }
 
	    iterator upper_bound(const key_type& x)
	    {
	    	return m_t.upper_bound(x);
	    }

	    const_iterator upper_bound(const key_type& x) const
	    {
	    	return m_t.upper_bound(x);
	    }

	    pair<iterator, iterator> equal_range(const key_type& x)
	    {
	    	return m_t.equal_range(x);
	    }
	    
	    pair<const_iterator, const_iterator>   equal_range(const key_type& x) const
	    {
	    	return m_t.equal_range(x);
	    }

        allocator_type get_allocator() const
        {
        	return allocator_type(m_t.get_allocator());
        }

        template<typename _K1, typename _C1, typename _A1>
        friend bool operator==(const set<_K1, _C1, _A1>&, const set<_K1, _C1, _A1>&);
      
      	template<typename _K1, typename _C1, typename _A1>
        friend bool operator<(const set<_K1, _C1, _A1>&, const set<_K1, _C1, _A1>&);
	};

	template<typename _Key, typename _Compare, typename _Alloc>
    bool operator==(
    	const set<_Key, _Compare, _Alloc>& x,
    	const set<_Key, _Compare, _Alloc>& y)
    {
    	return x.m_t == y.m_t;
    }

    template<typename _Key, typename _Compare, typename _Alloc>
    bool operator<(
    	const set<_Key, _Compare, _Alloc>& x,
    	const set<_Key, _Compare, _Alloc>& y)
    {
    	return x.m_t < y.m_t;
    }

    template<typename _Key, typename _Compare, typename _Alloc>
    bool operator!=(
    	const set<_Key, _Compare, _Alloc>& x,
    	const set<_Key, _Compare, _Alloc>& y)
    {
    	return !(x == y);
    }

    template<typename _Key, typename _Compare, typename _Alloc>
    bool operator>(
    	const set<_Key, _Compare, _Alloc>& x,
    	const set<_Key, _Compare, _Alloc>& y)
    {
    	return y < x;
    }

    template<typename _Key, typename _Compare, typename _Alloc>
    bool operator<=(
    	const set<_Key, _Compare, _Alloc>& x,
    	const set<_Key, _Compare, _Alloc>& y)
    {
    	return !(y < x);
    }

    template<typename _Key, typename _Compare, typename _Alloc>
    bool operator>=(
    	const set<_Key, _Compare, _Alloc>& x,
    	const set<_Key, _Compare, _Alloc>& y)
    {
    	return !(x < y);
    }

    template<typename _Key, typename _Compare, typename _Alloc>
    void swap(
    	set<_Key, _Compare, _Alloc>& x,
    	set<_Key, _Compare, _Alloc>& y)
    {
    	x.swap(y);
    }
}

#endif
