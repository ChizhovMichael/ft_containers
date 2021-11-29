/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:45:11 by tgildero          #+#    #+#             */
/*   Updated: 2021/11/29 22:10:39 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include "iterator.hpp"
# include "utils.hpp"
# include "traits.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	struct vector_base
	{
		typedef typename Allocator::template rebind<T>::other	alloc_type;
		typedef typename Allocator::pointer						pointer;
		typedef Allocator										allocator_type;

		struct impl: public alloc_type
		{
			pointer _start;
	        pointer _finish;
	        pointer _end_of_storage;

	        impl()
	        : alloc_type(), _start(), _finish(), _end_of_storage()
	        {}

	        impl(alloc_type const& a)
	        : alloc_type(a), _start(), _finish(), _end_of_storage()
	        {}
	        // _M_swap_data
	        void _swap_data(impl& x)
	        {
	        	impl tmp;
				tmp._copy_data(*this);
				_copy_data(x);
				x._copy_data(tmp);
	        }

	        // _M_copy_data
	        void _copy_data(impl const& x)
			{
				_start = x._start;
				_finish = x._finish;
				_end_of_storage = x._end_of_storage;
			}
		};

	public:
		impl 		_impl;
		alloc_type 	_alloc;

		// constructor/destructor
		vector_base()
		: _impl(), _alloc(get_tp_allocator())
		{}

		vector_base(const allocator_type& a)
		: _impl(a), _alloc(get_tp_allocator())
		{}

		vector_base(size_t n): _impl(), _alloc(get_tp_allocator())
		{
			create_storage(n);
		}

		vector_base(size_t n, const allocator_type& a)
		: _impl(a), _alloc(get_tp_allocator())
		{
			create_storage(n);
		}

		// getter/setter
		alloc_type& get_tp_allocator()
      	{
      		// _M_get_Tp_allocator
	      	return *static_cast<alloc_type*>(&this->_impl);
      	}

      	const alloc_type& get_tp_allocator() const
    	{
 			return *static_cast<const alloc_type*>(&this->_impl);
		}

	    allocator_type get_allocator() const
      	{
      		return allocator_type(get_tp_allocator());
	    }

    	// _M_allocate
	    pointer _allocate(size_t n)
    	{
    		return n != 0 ? _alloc.allocate(n) : pointer();
	    }
    	//  _M_deallocate
	    void _deallocate(pointer ptr, size_t n)
    	{
    		if (ptr)
    			_alloc.deallocate(ptr, n);
	    }
	private:
    	// _M_create_storage
		void create_storage(size_t n)
		{
			_impl._start = _allocate(n);
			_impl._finish = _impl._start;
			_impl._end_of_storage = _impl._start + n;
		}
	};

	template<class T, class Allocator = std::allocator<T> >
	class vector : protected vector_base<T, Allocator>
	{
	private:
		typedef vector_base<T, Allocator>                   		base;
		typedef typename base::alloc_type                		alloc_type;

	public:
		// types
		typedef T							value_type;
		typedef Allocator						allocator_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::reference			reference;
	      	typedef typename allocator_type::const_reference		const_reference;
		typedef size_t							size_type;
		typedef ptrdiff_t						difference_type;
		typedef ft::__normal_iterator<pointer, vector>			iterator;
		typedef ft::__normal_iterator<const_pointer, vector>		const_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	 	typedef ft::reverse_iterator<iterator>				reverse_iterator;

	protected:
      	using base::_allocate;
		using base::_deallocate;
		using base::_impl;
		using base::_alloc;
	public:
		/**
		 * http://www.cplusplus.com/reference/vector/vector/vector/
		 * @param  alloc
		 */
		vector()
		: base() { }

		explicit vector (const allocator_type& alloc)
		: base(alloc) { }

		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) : base(n, alloc)
		{
			fill_initialize(n, val);
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type())
    	: base(alloc)
    	{
        	typedef typename ft::__is_integer<InputIterator>::__type _Integral;
    		fill_range_initialize(first, last, _Integral());
   		}

        vector (const vector& x)
    	: base(x.size(), x._alloc)
        {
    		_impl._finish = copy_initialize(x.begin(), x.end(), _impl._start);
        }

	 	/**
	 	 * http://www.cplusplus.com/reference/vector/vector/~vector/
	 	 */
	    ~vector()
	    {
			while (_impl._finish-- != _impl._start)
				_alloc.destroy(_impl._finish);
			_alloc.deallocate(_impl._start, capacity());
	    }
	    
	    vector& operator=(const vector& x)
	    {
			if (&x != this)
    		{
    			const size_type xlen = x.size();
      		
      			if (xlen > capacity())
            	{
            		pointer tmp = allocate_and_copy(xlen, x.begin(), x.end());
	            	_destroy(_impl._start, _impl._finish, _alloc);
	            	_deallocate(_impl._start, _impl._end_of_storage - _impl._start);
        	    	_impl._start = tmp;
            		_impl._end_of_storage = _impl._start + xlen;
	            }
	            else if (size() >= xlen)
        	    {
            		_destroy(ft::copy(x.begin(), x.end(), begin()), end(), _alloc);
	            }
	            else
        	    {
            		ft::copy(x._impl._start, x._impl._start + size(), _impl._start);
	            	copy_initialize(x._impl._start + size(), x._impl._finish, _impl._finish);
	            }
        	    _impl._finish = _impl._start + xlen;
    		}
			return *this;
	    }

	    template<class InputIt>
	    void assign(InputIt first, InputIt last)
	    {
	    	const size_type len = ft::distance(first, last);

	    	if (len > capacity())
	    	{
    			pointer tmp(allocate_and_copy(len, first, last));
            	_destroy(_impl._start, _impl._finish, _alloc);
            	_deallocate(_impl._start, _impl._end_of_storage - _impl._start);
            	_impl._start = tmp;
            	_impl._finish = _impl._start + len;
    			_impl._end_of_storage = _impl._finish;
			}
			else if (size() >= len)
            	erase_at_end(ft::copy(first, last, _impl._start));
    		else
    		{
    			InputIt mid = first;
            	ft::advance(mid, size());
    			ft::copy(first, mid, _impl._start);
            	_impl._finish = copy_initialize(mid, last, _impl._finish);
      		}
    	}

    	void assign(size_type n, const value_type& u)
    	{
    		fill_assign(n, u);
    	}
		
		iterator begin()
    	{
    		return iterator(_impl._start);
    	}

    	const_iterator begin() const
    	{
    		return const_iterator(_impl._start);
    	}

    	iterator end()
    	{
    		return iterator(_impl._finish);
    	}

	   	const_iterator end() const
    	{
    		return const_iterator(_impl._finish);
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
			return begin() == end();
		}

    	size_type size() const
    	{
    		return size_type(_impl._finish - _impl._start);
    	}

    	size_type max_size() const
    	{
    		return _alloc.max_size();
    	}

    	size_type capacity() const
    	{
    		return size_type(_impl._end_of_storage - _impl._start);
    	}

    	void resize(size_type sz, value_type c = value_type())
    	{
    		if (sz > size())
    			fill_insert(end(), sz - size(), c);
	    	else if (sz < size())
	    		erase_at_end(_impl._start + sz);
    	}

		void reserve(size_type n)
    	{
    		if (n > max_size())
    			throw std::out_of_range("vector::reserve");

    		if (capacity() < n)
        	{
        		const size_type old_size = size();
	        	pointer tmp = allocate_and_copy(n, _impl._start, _impl._finish);

	        	_destroy(_impl._start, _impl._finish, _alloc);
        		_deallocate(_impl._start, _impl._end_of_storage - _impl._start);
        	
        		_impl._start = tmp;
	        	_impl._finish = tmp + old_size;
	        	_impl._end_of_storage = _impl._start + n;
        	}	
    	}

		// element access
    	reference operator[](size_type n)
    	{
    		return *(_impl._start + n);
    	}

    	const_reference operator[](size_type n) const
    	{
    		return *(_impl._start + n);
    	}

    	const_reference at(size_type n) const
    	{
    		if (n >= this->size())
			throw std::out_of_range("vector::at: n >= size()");
		return (*this)[n];
    	}

    	reference at(size_type n)
    	{
    		if (n >= this->size())
			throw std::out_of_range("vector::at: n >= size()");
		return (*this)[n];
    	}

    	reference front()
    	{
    		return *begin();
    	}

    	const_reference front() const
    	{
    		return *begin();
    	}

    	reference back()
    	{
    		return *(end() - 1);
    	}
    
    	const_reference back() const
    	{
    		return *(end() - 1);
    	}

    	value_type* data()
    	{
    		return data_ptr(_impl._start);
    	}

    	const value_type* data() const
    	{
    		return data_ptr(_impl._start);
    	}


    	void push_back(const T& x)
    	{
    		if (_impl._finish != _impl._end_of_storage)
    		{
	            	_alloc.construct(_impl._finish, x);
        			++_impl._finish;
      		}
    		else
    			realloc_insert(end(), x);
    	}

    	void pop_back()
    	{
        	--_impl._finish;
	        _alloc.destroy(_impl._finish);
		}
	
    	iterator insert(iterator position, const value_type& x)
    	{
    		const size_type n = position - begin();

    		if (_impl._finish != _impl._end_of_storage)
    		{
    			if (position == end())
      			{
        				_alloc.construct(_impl._finish, x);
        				++_impl._finish;
      			}
      			else
      			{
        				insert_aux(position, x);
        			}
        		}
        		else
    			realloc_insert(position, x);
    		return iterator(_impl._start + n);
    	}

    	void insert(iterator position, size_type n, const value_type& x)
    	{
    		fill_insert(position, n, x);
    	}
	    
    	template<class InputIt>
	   	void insert(iterator position, InputIt first, InputIt last)
	   	{
	   		typedef typename ft::__is_integer<InputIt>::__type _Integral;
	   		insert_dispatch(position, first, last, _Integral());
	   	}

    	iterator erase(iterator position)
    	{
    		return _erase(position);
    	}

    	iterator erase(iterator first, iterator last)
    	{
    		return _erase(first, last);
    	}
    
    	void swap(vector& x)
    	{
    		_impl._swap_data(x._impl);
    	}

    	void clear()
	   	{
    		erase_at_end(_impl._start);
    	}

	protected:
		// _M_fill_initialize
		void fill_initialize(size_type n, const value_type& value)
		{
			pointer cur = _impl._start;
	      
			for (; n > 0; --n, ++cur)
				_alloc.construct(__builtin_addressof(*cur), value);	
			_impl._finish = cur;
		}

		// _M_range_initialize
		template<typename _ForwardIterator>
		void fill_range_initialize(
    		_ForwardIterator first,
            _ForwardIterator last,
    	    ft::__false_type)
    	{
			const size_type n = ft::distance(first, last);
	
        	_impl._start = _allocate(n);
    		_impl._end_of_storage = _impl._start + n;
    		_impl._finish = copy_initialize(first, last, _impl._start);
    	}

        template<typename _Integer>
    	void fill_range_initialize(_Integer n, _Integer value, ft::__true_type)
    	{
    		_impl._start = _allocate(static_cast<size_type>(n));
        	_impl._end_of_storage = _impl._start + static_cast<size_type>(n);
    		fill_initialize(static_cast<size_type>(n), value);
    	}

        // __uninitialized_copy_a
    	// __uninitialized_move_a
        //  __uninitialized_move_if_noexcept_a
    	template<typename _CopyIterator, typename _ResultIterator>
		_ResultIterator copy_initialize(
    		_CopyIterator first,
            _CopyIterator last,
    	    _ResultIterator result
    	)
    	{
    		_ResultIterator cur = result;

        	try
    		{
    			for (; first != last; ++first, (void)++cur)
    				_alloc.construct(__builtin_addressof(*cur), *first);
        		return cur;
    		}
        	catch(...)
    		{
    			_destroy(result, cur, _alloc);
    			throw;
        	}
    	}

        // __uninitialized_fill_n_a
    	template<typename _ForwardIterator>
        _ForwardIterator uninitialized_fill_n_a(
    		_ForwardIterator first,
    		size_type n,
        	const value_type& x)
    	{
    		_ForwardIterator cur = first;

        	try
    		{
    			for (; n > 0; --n, ++cur)
    				_alloc.construct(__builtin_addressof(*cur), x);
        		return cur;
    		}
    		catch(...)
    		{
    			_destroy(first, cur, _alloc);
        		throw;
    		}
        }

    	// Called by erase(q1,q2), clear(), resize(), _M_fill_assign,
      	// _M_erase_at_end.
  		void erase_at_end(pointer pos)
  		{
    		if (size_type n = _impl._finish - pos)
			{
				_destroy(pos, _impl._finish, _alloc);
				_impl._finish = pos;
			}
        }

    	// _M_allocate_and_copy.
    	template<typename _Iterator>
        pointer allocate_and_copy(size_type n, _Iterator first, _Iterator last)
    	{
    		pointer result = _allocate(n);
        	copy_initialize(first, last, result);
    		return result;
    	}

        // _M_fill_insert
    	void fill_insert(iterator pos, size_type n, const value_type& x)
    	{
    		if (n != 0)
    		{
    			if (size_type(_impl._end_of_storage - _impl._finish) >= n)
    			{
    				value_type x_copy = x;

    				const size_type elems_after = end() - pos;
					pointer old_finish(_impl._finish);

					if (elems_after > n)
					{
						copy_initialize(_impl._finish - n, _impl._finish, _impl._finish);
						_impl._finish += n;
						ft::fill(pos.base(), pos.base() + n, x_copy);
					}
					else
					{
						_impl._finish = uninitialized_fill_n_a(_impl._finish, n - elems_after, x_copy);
						copy_initialize(pos.base(), old_finish, _impl._finish);
						_impl._finish += elems_after;
						ft::fill(pos.base(), old_finish, x_copy);
					}
				}
				else
				{
					const size_type len = check_len(n);
					const size_type elems_before = pos - begin();
					pointer new_start(_allocate(len));
					pointer new_finish(new_start);

					try
					{
                  		uninitialized_fill_n_a(new_start + elems_before, n, x);
        		  		new_finish = pointer();
          				new_finish = copy_initialize(_impl._start, pos.base(), new_start);
                  		new_finish += n;
        		  		new_finish = copy_initialize(pos.base(), _impl._finish, new_finish);
          			}
                  	catch(...)
        		  	{
          				if (!new_finish)
          					_destroy(new_start + elems_before, new_start + elems_before + n, _alloc);
                  		else
        		  			_destroy(new_start, new_finish, _alloc);
          				_deallocate(new_start, len);
                  	}
        		  	_destroy(_impl._start, _impl._finish, _alloc);
                  	_deallocate(_impl._start, _impl._end_of_storage - _impl._start);
                  	
        		  	_impl._start = new_start;
                  	_impl._finish = new_finish;
        		  	_impl._end_of_storage = new_start + len;
        		}
			}
    	}

	   	// _M_check_len
    	size_type check_len(size_type n) const
    	{
    		if (max_size() - size() < n)
    			std::out_of_range("vector::check_len");
    	
	        const size_type len = size() + ft::max(size(), n);
    		return (len < size() || len > max_size()) ? max_size() : len;
  		}

  		// _M_insert_aux
  		void insert_aux(iterator position, const value_type& x)
  		{
  			_alloc.construct(_impl._finish, *(_impl._finish - 1));
      		++_impl._finish;

  			value_type x_copy = x;

  			ft::copy_backward(position.base(), _impl._finish - 2, _impl._finish - 1);
      		*position = x_copy;
  		}

      	// _M_realloc_insert
  		void realloc_insert(iterator position, const value_type& x)
  		{
  			const size_type len = check_len(size_type(1));
      		pointer old_start = _impl._start;
  			pointer old_finish = _impl._finish;
  			const size_type elems_before = position - begin();
  			pointer new_start(_allocate(len));
  			pointer new_finish(new_start);

      		try
  			{
  				_alloc.construct(new_start + elems_before, x);
  				new_finish = pointer();
  				new_finish = copy_initialize(old_start, position.base(), new_start);
  				++new_finish;
  				new_finish = copy_initialize(position.base(), old_finish, new_finish);
  			}
      		catch(...)
  			{
  				if (!new_finish)
  					_alloc.destroy(new_start + elems_before);
      			else
  					_destroy(new_start, new_finish, _alloc);
  				_deallocate(new_start, len);
  				throw;
  			}
      		_destroy(old_start, old_finish, _alloc);
  			_deallocate(old_start, _impl._end_of_storage - old_start);

      		_impl._start = new_start;
  			_impl._finish = new_finish;
  			_impl._end_of_storage = new_start + len;
  		}

    	// _M_fill_assign  	
  		void fill_assign(size_t n, const value_type& val)
  		{
  			if (n > capacity())
  			{
  				vector tmp(n, val);
      			tmp._impl._swap_data(_impl);
  			}
  			else if (n > size())
  			{
  				ft::fill(begin(), end(), val);
      			_impl._finish = uninitialized_fill_n_a(_impl._finish, n - size(), val);
  			}
  			else
  				erase_at_end(ft::fill_n(_impl._start, n, val));
  		}

      	// _M_erase
  		iterator _erase(iterator position)
  		{
  			if (position + 1 != end())
    			ft::copy(position + 1, end(), position);
      		--_impl._finish;
  			_alloc.destroy(_impl._finish);
  			return position;
		}

	  	iterator _erase(iterator first, iterator last)
    	{
			if (first != last)
			{
      			if (last != end())
        				ft::copy(last, end(), first);
      			erase_at_end(first.base() + (end() - last));
    		}
  			return first;
		}

    	// _M_insert_dispatch
		template<typename _Integer>
        void insert_dispatch(iterator pos, _Integer n, _Integer val, __true_type)
    	{ 
    		fill_insert(pos, n, val);
    	}

      	template<typename _InputIterator>
    	void insert_dispatch(iterator pos, _InputIterator first, _InputIterator last, __false_type)
    	{
    		range_insert(pos, first, last);
    	}

        // _M_range_insert
  		template<typename _InputIterator>
        void range_insert(
    		iterator pos,
    		_InputIterator first,
        	_InputIterator last)
    	{
    		if (first != last)
    		{
    			const size_type n = ft::distance(first, last);
            	if (size_type(_impl._end_of_storage - _impl._finish) >= n)
      			{
                	const size_type elems_after = end() - pos;
        			pointer old_finish(_impl._finish);
                	if (elems_after > n)
        		  	{
          				copy_initialize(_impl._finish - n, _impl._finish, _impl._finish);
						_impl._finish += n;
	                    ft::copy(first, last, pos);
          			}
                	else
        		  	{
            	    	_InputIterator mid = first;
    		    		ft::advance(mid, elems_after);
        	
                    	copy_initialize(mid, last, _impl._finish);
        				_impl._finish += n - elems_after;
                    	copy_initialize(pos.base(), old_finish, _impl._finish);
        				_impl._finish += elems_after;
                    	ft::copy(first, mid, pos);
          			}
              	}
    			else
      			{
                	const size_type len = check_len(n);
        			pointer new_start(_allocate(len));
                	pointer new_finish(new_start);
        			try
          			{
                    	new_finish = copy_initialize(_impl._start, pos.base(), new_start);
        				new_finish = copy_initialize(first, last, new_finish);
                    	new_finish = copy_initialize(pos.base(), _impl._finish, new_finish);
          			}
                	catch(...)
        		  	{
                    	_destroy(new_start, new_finish, _alloc);
        				_deallocate(new_start, len);
                    	throw;
          			}
                	_destroy(_impl._start, _impl._finish, _alloc);
        			_deallocate(_impl._start, _impl._end_of_storage - _impl._start);
        	
                	_impl._start = new_start;
        			_impl._finish = new_finish;
                	_impl._end_of_storage = new_start + len;
      			}
      		}
    	}

    	template<typename _Up>
    	_Up* data_ptr(_Up* ptr) const
    	{
    		return ptr;
    	}

    	template<typename _Up>
    	_Up* data_ptr(_Up* ptr)
    	{
    		return ptr;
        }
  
  		template<typename _Ptr>
        value_type* data_ptr(_Ptr ptr)
    	{
    		return empty() ? (value_type*)0 : ptr.operator->();
    	}
  	
      	template<typename _Ptr>
    	const value_type* data_ptr(_Ptr ptr) const
    	{
    		return empty() ? (const value_type*)0 : ptr.operator->();
    	}
	};

	template<typename _Tp, typename _Alloc>
	bool operator==(const vector<_Tp, _Alloc>& x, const vector<_Tp, _Alloc>& y)
	{
		return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
	}

	template<typename _Tp, typename _Alloc>
	bool operator<(const vector<_Tp, _Alloc>& x, const vector<_Tp, _Alloc>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template<typename _Tp, typename _Alloc>
	bool operator!=(const vector<_Tp, _Alloc>& x, const vector<_Tp, _Alloc>& y)
	{
		return !(x == y);
	}

	template<typename _Tp, typename _Alloc>
	bool operator>(const vector<_Tp, _Alloc>& x, const vector<_Tp, _Alloc>& y)
	{
		return y < x;
	}

	template<typename _Tp, typename _Alloc>
	bool operator<=(const vector<_Tp, _Alloc>& x, const vector<_Tp, _Alloc>& y)
	{
		return !(y < x);
	}

	template<typename _Tp, typename _Alloc>
	bool operator>=(const vector<_Tp, _Alloc>& x, const vector<_Tp, _Alloc>& y)
	{
		return !(x < y);
	}

	template<typename _Tp, typename _Alloc>
	void swap(vector<_Tp, _Alloc>& x, vector<_Tp, _Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
