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
}

#endif
