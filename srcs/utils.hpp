/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:39:01 by tgildero          #+#    #+#             */
/*   Updated: 2021/11/29 21:40:16 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	// std::copy
	template<class InputIt, class OutputIt>
	OutputIt copy(InputIt first, InputIt last, 
	              OutputIt d_first)
	{
	    while (first != last) {
	        *d_first++ = *first++;
	    }
	    return d_first;
	}

	// std::copy_if
	template<class InputIt, class OutputIt, class UnaryPredicate>
	OutputIt copy_if(InputIt first, InputIt last, 
	                 OutputIt d_first, UnaryPredicate pred)
	{
	    while (first != last) {
	        if (pred(*first))
	            *d_first++ = *first;
	        first++;
	    }
	    return d_first;
	}

	// std::_Destroy
	template<typename _ForwardIterator, typename _Alloc>
	void _destroy(_ForwardIterator __first, _ForwardIterator __last, _Alloc __alloc)
	{
		for (; __first != __last; ++__first)
			__alloc.destroy(__builtin_addressof(*__first));
	}

	// std::fill
	template <class ForwardIterator, class T>
	void fill (ForwardIterator first, ForwardIterator last, const T& val)
	{
		while (first != last) {
			*first = val;
			++first;
		}
	}

	// std::fill_n
	template <class OutputIterator, class Size, class T>
	OutputIterator fill_n(OutputIterator first, Size n, const T& val)
	{
		while (n > 0) {
			*first = val;
			++first;
			--n;
		}
		return first;
	}

	// std::max
	template <class T>
	const T& max (const T& a, const T& b)
	{
		return (a < b) ? b : a;
	}

	// std::copy_backward
	template<class BidirectionalIterator1, class BidirectionalIterator2>
  	BidirectionalIterator2 copy_backward (
  		BidirectionalIterator1 first,
  		BidirectionalIterator1 last,
  		BidirectionalIterator2 result)
	{
		while (last != first)
			*(--result) = *(--last);
		return result;
	}

	// std::equal
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	// std::lexicographical_compare
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
	                                InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
	    	++first1;
	    	++first2;
	    }
	    return (first2 != last2);
	}

	template<typename arg1, typename arg2, typename result>
	struct binary_function
	{
		typedef arg1 first_argument_type;
		typedef arg2 second_argument_type;
		typedef result result_type;
	};

	// std::less
	template<typename _Tp>
	struct less : public binary_function<_Tp, _Tp, bool>
	{
		bool operator()(const _Tp& x, const _Tp& y) const
		{
			return x < y;
		}
	};

	// std::pair
	template<typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;

		pair()
		: first(), second()
		{}

		pair(const T1& a, const T2& b)
		: first(a), second(b)
		{}

		template<typename U1, typename U2>
		pair(const pair<U1, U2>& p)
		: first(p.first), second(p.second)
		{}
	};

	template<typename _T1, typename _T2>
	bool operator==(const ft::pair<_T1, _T2>& x, const ft::pair<_T1, _T2>& y)
	{
		return x.first == y.first && x.second == y.second;
	}

	template<typename _T1, typename _T2>
	bool operator<(const ft::pair<_T1, _T2>& x, const ft::pair<_T1, _T2>& y)
	{
		return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template<typename _T1, typename _T2>
	bool operator!=(const ft::pair<_T1, _T2>& x, const ft::pair<_T1, _T2>& y)
	{
		return !(x == y);
	}

	template<typename _T1, typename _T2>
	bool operator>(const ft::pair<_T1, _T2>& x, const ft::pair<_T1, _T2>& y)
	{
		return y < x;
	}

	template<typename _T1, typename _T2>
	bool operator<=(const ft::pair<_T1, _T2>& x, const ft::pair<_T1, _T2>& y)
	{
		return !(y < x);
	}

	template<typename _T1, typename _T2>
	bool operator>=(const ft::pair<_T1, _T2>& x, const ft::pair<_T1, _T2>& y)
	{
		return !(x < y);
	}

	// std::unary_function
	template<typename arg, typename result>
	struct unary_function
	{
		typedef arg			argument_type;
		typedef result		result_type;
	};

	// _Select1st
	template<typename _Pair>
	struct select1st
	: public unary_function<_Pair, typename _Pair::first_type>
	{
		typename _Pair::first_type& operator()(_Pair& x) const
		{
			return x.first;
		}

		const typename _Pair::first_type& operator()(const _Pair& x) const
		{
			return x.first;
		}
	};

	// std::swap
	template<typename _Tp>
	void swap(_Tp& a, _Tp& b)
	{
		_Tp tmp = a;
		a = b;
		b = tmp;
	}

	template<typename _Tp>
	struct _identity
	: public unary_function<_Tp, _Tp>
	{
		_Tp& operator()(_Tp& x) const
		{
			return x;
		}

		const _Tp& operator()(const _Tp& x) const
		{
			return x;
		}
	};
}

#endif
