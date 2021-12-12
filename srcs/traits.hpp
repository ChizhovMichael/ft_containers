/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traits.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:44:43 by tgildero          #+#    #+#             */
/*   Updated: 2021/11/29 21:44:45 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
# define TRAITS_HPP

namespace ft
{
	struct __true_type { };
	struct __false_type { };
  
	//
	// Integer types
	//
	template<typename _Tp>
	struct __is_integer
	{
		enum { __value = 0 };
		typedef __false_type __type;
	};
	// Thirteen specializations (yes there are eleven standard integer
	// types; <em>long long</em> and <em>unsigned long long</em> are
	// supported as extensions).  Up to four target-specific __int<N>
	// types are supported as well.
	template<>
	struct __is_integer<bool>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<char>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<signed char>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<unsigned char>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<wchar_t>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<short>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<unsigned short>
	{
		enum { __value = 1 };
    		typedef __true_type __type;
	};
	template<>
	struct __is_integer<int>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<unsigned int>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<long>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<unsigned long>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
	template<>
	struct __is_integer<long long>
	{
		enum { __value = 1 };
    		typedef __true_type __type;
	};
	template<>
	struct __is_integer<unsigned long long>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<typename _Tp, _Tp __v>
	struct integral_constant
	{
		static const _Tp                  	value = __v;
      	typedef _Tp							value_type;
      	typedef integral_constant<_Tp, __v>	type;
		operator value_type() const
		{
			return value;
		}
    };

	typedef integral_constant<bool, true>     true_type;
	typedef integral_constant<bool, false>    false_type;

	template<typename>
	struct __is_integral_helper
	: public false_type
	{};
  	
  	template<>
  	struct __is_integral_helper<bool>
  	: public true_type
  	{};
  	
  	template<>
    struct __is_integral_helper<char>
    : public true_type
    {};
  	
  	template<>
    struct __is_integral_helper<signed char>
    : public true_type
    {};
  	
  	template<>
    struct __is_integral_helper<unsigned char>
    : public true_type
    {};

  	template<>
    struct __is_integral_helper<wchar_t>
    : public true_type
    {};
  	
  	template<>
    struct __is_integral_helper<short>
    : public true_type
    {};
	
	template<>
    struct __is_integral_helper<unsigned short>
    : public true_type
    {};
  	
  	template<>
    struct __is_integral_helper<int>
    : public true_type
    {};
	
	template<>
    struct __is_integral_helper<unsigned int>
    : public true_type
    {};
	
	template<>
    struct __is_integral_helper<long>
    : public true_type
    {};
	
	template<>
    struct __is_integral_helper<unsigned long>
    : public true_type
    {};
	
	template<>
    struct __is_integral_helper<long long>
    : public true_type
    {};
	
	template<>
    struct __is_integral_helper<unsigned long long>
    : public true_type
    {};

    template<typename _Tp>
    struct remove_const
    {
    	typedef _Tp     type;
    };

    template<typename _Tp>
    struct remove_const<_Tp const>
    {
    	typedef _Tp     type;
    };

    template<typename _Tp>
    struct remove_volatile
    {
    	typedef _Tp     type;
    };

    template<typename _Tp>
    struct remove_volatile<_Tp volatile>
    {
    	typedef _Tp     type;
    };

    template<typename _Tp>
    struct remove_cv
    {
    	typedef typename
    	remove_const<typename remove_volatile<_Tp>::type>::type     type;
    };

    template<typename _Tp>
    struct is_integral
    : public __is_integral_helper<typename remove_cv<_Tp>::type>::type
    {};
}

#endif
