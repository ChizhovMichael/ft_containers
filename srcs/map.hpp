#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include "iterator.hpp"
# include "utils.hpp"
# include "traits.hpp"
# include "tree.hpp"

namespace ft
{
	template <typename _Key, typename _Tp, typename _Compare = ft::less<_Key>,
	    typename Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{
	public:
		typedef _Key						key_type;
		typedef _Tp							mapped_type;
		typedef ft::pair<const _Key, _Tp>	value_type;
		typedef _Compare					key_compare;
		typedef Allocator					allocator_type;

		class value_compare: public ft::binary_function<value_type, value_type, bool>
		{
			friend class map<_Key, _Tp, _Compare, Allocator>;
		
		protected:
			_Compare comp;
			value_compare(_Compare c)
			: comp(c)
			{}
		
		public:
			bool operator()(const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};
	private:
		// _Pair_alloc_type
		typedef typename 
		Allocator::template rebind<value_type>::other pair_alloc_type;

		// _Rep_type
		typedef rb_tree<key_type, value_type,
		select1st<value_type>, key_compare, pair_alloc_type> rep_type;

		rep_type 		m_t;
		pair_alloc_type _alloc;

	public:
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename rep_type::iterator					iterator;
		typedef typename rep_type::const_iterator			const_iterator;
		typedef typename rep_type::size_type				size_type;
		typedef typename rep_type::difference_type			difference_type;
		typedef typename rep_type::reverse_iterator			reverse_iterator;
		typedef typename rep_type::const_reverse_iterator	const_reverse_iterator;

		map()
		: m_t()
		{}

		explicit map(const _Compare& comp,
          const allocator_type& a = allocator_type())
      	: m_t(comp, pair_alloc_type(a))
      	{}

      	template<typename _InputIterator>
      	map(_InputIterator first, _InputIterator last)
        : m_t()
        {
        	m_t.insert_unique(first, last);
        }

        template<typename _InputIterator>
        map(_InputIterator first, _InputIterator last,
            const _Compare& comp,
            const allocator_type& a = allocator_type())
        : m_t(comp, pair_alloc_type(a))
        {
        	m_t.insert_unique(first, last);
        }

        map(const map& x)
      	: m_t(x.m_t)
      	{}

		~map()
		{
			clear();
		}
    	
    	map& operator=(const map& x)
    	{
    		m_t = x.m_t;
        	return *this;
    	}
    
    	allocator_type get_allocator() const
    	{
    		return allocator_type(m_t.get_allocator());
    	}

    	iterator begin()
    	{
    		return m_t.begin();
    	}

    	const_iterator begin() const
    	{
    		return m_t.begin();
    	}

    	iterator end()
    	{
    		return m_t.end();
    	}

    	const_iterator end() const
    	{
    		return m_t.end();
    	}

    	reverse_iterator rbegin()
    	{
    		return m_t.rbegin();
    	}

    	const_reverse_iterator rbegin() const
    	{
    		return m_t.rbegin();
    	}

    	reverse_iterator rend()
    	{
    		return m_t.rend();
    	}

    	const_reverse_iterator rend() const
    	{
    		return m_t.rend();
    	}
 
	    // capacity
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
 
	    // element access
		mapped_type& operator[](const key_type& k)
		{
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				i = insert(i, value_type(k, mapped_type()));
			return (*i).second;
		}
 
    	// modifiers
    	ft::pair<iterator, bool> insert(const value_type& x)
    	{
    		return m_t.insert_unique(x);
    	}

    	iterator insert(const_iterator position, const value_type& x)
    	{
    		return m_t._insert_unique(position, x);
    	}

    	template<class InputIt>
    	void insert(InputIt first, InputIt last)
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
    	
    	void swap(map& x)
    	{
    		m_t.swap(x.m_t);
    	}
    	
    	void clear()
    	{
    		m_t.clear();
    	}
 
	    // observers
	    key_compare key_comp() const
	    {
	    	return m_t.key_comp();
	    }

	    value_compare value_comp() const
	    {
	    	return value_compare(m_t.key_comp()); 
	    }
 
	    // map operations
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
	    
	    template<typename _K, typename _T, typename _C, typename _A>
		friend bool operator==(const map<_K, _T, _C, _A>& x, const map<_K, _T, _C, _A>& y);

		template<typename _K, typename _T, typename _C, typename _A>
		friend bool operator<(const map<_K, _T, _C, _A>& x, const map<_K, _T, _C, _A>& y);
	};

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	bool operator==(const map<_Key, _Tp, _Compare, _Alloc>& x,
               const map<_Key, _Tp, _Compare, _Alloc>& y)
	{
		return x.m_t == y.m_t;
	}

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator<(const map<_Key, _Tp, _Compare, _Alloc>& x,
              const map<_Key, _Tp, _Compare, _Alloc>& y)
    {
    	return x.m_t < y.m_t;
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator!=(const map<_Key, _Tp, _Compare, _Alloc>& x,
               const map<_Key, _Tp, _Compare, _Alloc>& y)
    {
    	return !(x == y);
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator>(const map<_Key, _Tp, _Compare, _Alloc>& x,
              const map<_Key, _Tp, _Compare, _Alloc>& y)
    {
    	return y < x;
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator<=(const map<_Key, _Tp, _Compare, _Alloc>& x,
               const map<_Key, _Tp, _Compare, _Alloc>& y)
    {
    	return !(y < x);
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator>=(const map<_Key, _Tp, _Compare, _Alloc>& x,
               const map<_Key, _Tp, _Compare, _Alloc>& y)
    {
    	return !(x < y);
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    void swap(map<_Key, _Tp, _Compare, _Alloc>& x,
         map<_Key, _Tp, _Compare, _Alloc>& y)
    {
    	x.swap(y);
    }
}

#endif