/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:28:35 by tgildero          #+#    #+#             */
/*   Updated: 2021/12/08 21:28:58 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <memory>
# include "vector.hpp"

namespace ft
{
	template<typename _Tp, typename _Sequence = ft::vector<_Tp> >
    class stack
    {
	public:
		typedef typename _Sequence::value_type			value_type;
		typedef typename _Sequence::reference			reference;
		typedef typename _Sequence::const_reference		const_reference;
		typedef typename _Sequence::size_type			size_type;
		typedef _Sequence								container_type;

	protected:
		_Sequence c;

	public:
		explicit stack(const _Sequence& __c = _Sequence())
      	: c(__c)
      	{}

		bool empty() const
		{
			return c.empty();
		}
		
		size_type size() const
		{
			return c.size();
		}

		reference top()
		{
			return c.back();
		}
		void push(const value_type& x)
		{
			c.push_back(x);
		}

		void pop()
		{
			c.pop_back();
		}

		template<typename _T, typename _S>
		friend bool operator==(const stack<_T, _S>& x, const stack<_T, _S>& y);

		template<typename _T, typename _S>
		friend bool operator<(const stack<_T, _S>& x, const stack<_T, _S>& y);

		template<typename _T, typename _S>
		friend bool operator!=(const stack<_T, _S>& x, const stack<_T, _S>& y);

		template<typename _T, typename _S>
		friend bool operator>(const stack<_T, _S>& x, const stack<_T, _S>& y);

		template<typename _T, typename _S>
		friend bool operator<=(const stack<_T, _S>& x, const stack<_T, _S>& y);

		template<typename _T, typename _S>
		friend bool operator>=(const stack<_T, _S>& x, const stack<_T, _S>& y);
	};

	template<typename _Tp, typename _Seq>
    bool operator==(const stack<_Tp, _Seq>& x, const stack<_Tp, _Seq>& y)
    {
    	return x.c == y.c;
    }

    template<typename _Tp, typename _Seq>
    bool operator<(const stack<_Tp, _Seq>& x, const stack<_Tp, _Seq>& y)
    {
    	return x.c < y.c;
    }

    template<typename _Tp, typename _Seq>
    bool operator!=(const stack<_Tp, _Seq>& x, const stack<_Tp, _Seq>& y)
    {
    	return !(x == y);
    }

    template<typename _Tp, typename _Seq>
    bool operator>(const stack<_Tp, _Seq>& x, const stack<_Tp, _Seq>& y)
    {
    	return y < x;
    }

    template<typename _Tp, typename _Seq>
    bool operator<=(const stack<_Tp, _Seq>& x, const stack<_Tp, _Seq>& y)
    {
    	return !(y < x);
    }

    template<typename _Tp, typename _Seq>
    bool operator>=(const stack<_Tp, _Seq>& x, const stack<_Tp, _Seq>& y)
    {
    	return !(x < y);
    }
}

#endif
