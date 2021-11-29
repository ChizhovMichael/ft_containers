/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:38:35 by tgildero          #+#    #+#             */
/*   Updated: 2021/11/29 21:38:52 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

/**
 * libstdc++
 * https://github.com/gcc-mirror/gcc/blob/master
 * Most of the classes are taken from the gcc stl compiler
 */
namespace ft
{
   /**
    * Iterator Tags
    * These are empty types, used to distinguish different iterators.  The
    * distinction is not made by what they contain, but simply by what they
    * are.  Different underlying algorithms can then be used based on the
    * different operations supported by different iterator types.
    * stl_iterator_base_types.h
    * raws 93 - 107
    */
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

   
   /**
    * Common iterator class
    * stl_iterator_base_types.h
    * raws 125 - 139
    */
   template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
           typename _Pointer = _Tp*, typename _Reference = _Tp&>
   struct iterator
   {
      typedef _Category  iterator_category;
      typedef _Tp        value_type;
      typedef _Distance  difference_type;
      typedef _Pointer   pointer;
      typedef _Reference reference;
   };

   /**
    * Iterator traits
    * Headers: https://en.cppreference.com/w/cpp/iterator/iterator_traits
    * stl_iterator_base_types.h
    * raws 181 - 189
    */
   template<typename _Iterator>
   struct iterator_traits
   {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type        value_type;
      typedef typename _Iterator::difference_type   difference_type;
      typedef typename _Iterator::pointer           pointer;
      typedef typename _Iterator::reference         reference;
   };

   /**
    * stl_iterator_base_types.h
    * raws 209 - 217
    */
   template<typename _Tp>
   struct iterator_traits<_Tp*>
   {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef _Tp*                        pointer;
      typedef _Tp&                        reference;
   };

   /**
    * stl_iterator_base_types.h
    * raws 220 - 228
    */
   template<typename _Tp>
   struct iterator_traits<const _Tp*>
   {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef const _Tp*                  pointer;
      typedef const _Tp&                  reference;
   };

   /**
    * advance
    * https://en.cppreference.com/w/cpp/iterator/advance
    */
   template<class It>
   void advance(It& it, typename ft::iterator_traits<It>::difference_type n)
   {
       while (n > 0) {
           --n;
           ++it;
       }
   }

   template<typename _Iter>
   typename iterator_traits<_Iter>::iterator_category _iterator_category(const _Iter&)
   {
      return typename iterator_traits<_Iter>::iterator_category();
   }

   /**
    * distance
    * https://en.cppreference.com/w/cpp/iterator/distance
    */
   template<typename _InputIterator>
   typename iterator_traits<_InputIterator>::difference_type distance(
      _InputIterator first, 
      _InputIterator last)
   {
      typename iterator_traits<_InputIterator>::difference_type n = 0;
      while (first != last)
      {
         ++first;
         ++n;
      }
      return n;
   }

   /**
    * stl_iterator.h
    * raws 126 - 657
    */
   template<typename _Iterator>
   class reverse_iterator
    : public iterator<typename iterator_traits<_Iterator>::iterator_category,
                      typename iterator_traits<_Iterator>::value_type,
                      typename iterator_traits<_Iterator>::difference_type,
                      typename iterator_traits<_Iterator>::pointer,
                      typename iterator_traits<_Iterator>::reference>
   {
   protected:
      _Iterator current;

      typedef iterator_traits<_Iterator>              __traits_type;

   public:
      typedef _Iterator                               iterator_type;
      typedef typename __traits_type::pointer         pointer;
      typedef typename __traits_type::difference_type difference_type;
      typedef typename __traits_type::reference       reference;

      reverse_iterator(): current()
      {}

      reverse_iterator(iterator_type __x): current(__x)
      {}

      reverse_iterator(const reverse_iterator& __x): current(__x.current)
      {}

      template<typename _Iter>
      reverse_iterator(const reverse_iterator<_Iter>& __x): current(__x.current)
      {}

      iterator_type base() const 
      { 
         return current; 
      }

      reference operator*() const
      {
         _Iterator __tmp = current;
         return *--__tmp;
      }

      pointer operator->() const
      {
         _Iterator __tmp = current;
         --__tmp;
         return _S_to_pointer(__tmp);
      }

      reverse_iterator& operator++()
      {
         --current;
         return *this;
      }

      reverse_iterator operator++(int)
      {
         reverse_iterator __tmp = *this;
         --current;
         return __tmp;
      }

      reverse_iterator& operator--()
      {
         ++current;
         return *this;
      }

      reverse_iterator operator--(int)
      {
         reverse_iterator __tmp = *this;
         ++current;
         return __tmp;
      }

      reverse_iterator operator+(difference_type __n) const
      { 
         return reverse_iterator(current - __n);
      }

      reverse_iterator& operator+=(difference_type __n)
      {
         current -= __n;
         return *this;
      }

      reverse_iterator operator-(difference_type __n) const
      { 
         return reverse_iterator(current + __n);
      }

      reverse_iterator& operator-=(difference_type __n)
      {
         current += __n;
         return *this;
      }

      reference operator[](difference_type __n) const
      {
         return *(*this + __n);
      }

   private:
      template<typename _Tp>
      static _Tp* _S_to_pointer(_Tp* __p)
      {
         return __p;
      }

      template<typename _Tp>
      static pointer _S_to_pointer(_Tp __t)
      { 
         return __t.operator->();
      }
   };

   template<typename _Iterator>
   bool operator==(const reverse_iterator<_Iterator>& __x,
      const reverse_iterator<_Iterator>& __y)
   {
      return __x.base() == __y.base();
   }

   template<typename _Iterator>
   bool operator<(const reverse_iterator<_Iterator>& __x,
      const reverse_iterator<_Iterator>& __y)
   {
      return __y.base() < __x.base();
   }

   template<typename _Iterator>
   bool operator!=(const reverse_iterator<_Iterator>& __x,
      const reverse_iterator<_Iterator>& __y)
   {
      return !(__x == __y);
   }

   template<typename _Iterator>
   bool operator>(const reverse_iterator<_Iterator>& __x,
      const reverse_iterator<_Iterator>& __y)
   {
      return __y < __x;
   }

   template<typename _Iterator>
   bool operator<=(const reverse_iterator<_Iterator>& __x,
      const reverse_iterator<_Iterator>& __y)
   {
      return !(__y < __x);
   }

   template<typename _Iterator>
   bool operator>=(const reverse_iterator<_Iterator>& __x,
      const reverse_iterator<_Iterator>& __y)
   {
      return !(__x < __y); 
   }

   /**
    * Comparison of reverse_iterator to const reverse_iterator.
    */
   template<typename _IteratorL, typename _IteratorR>
   bool operator==(const reverse_iterator<_IteratorL>& __x,
      const reverse_iterator<_IteratorR>& __y)
   {
      return __x.base() == __y.base();
   }

   template<typename _IteratorL, typename _IteratorR>
   bool operator<(const reverse_iterator<_IteratorL>& __x,
      const reverse_iterator<_IteratorR>& __y)
   {
      return __x.base() > __y.base();
   }

   template<typename _IteratorL, typename _IteratorR>
   bool operator!=(const reverse_iterator<_IteratorL>& __x,
      const reverse_iterator<_IteratorR>& __y)
   { 
      return __x.base() != __y.base();
   }

   template<typename _IteratorL, typename _IteratorR>
   bool operator>(const reverse_iterator<_IteratorL>& __x,
      const reverse_iterator<_IteratorR>& __y)
   {
      return __x.base() < __y.base();
   }

   template<typename _IteratorL, typename _IteratorR>
   bool operator<=(const reverse_iterator<_IteratorL>& __x,
      const reverse_iterator<_IteratorR>& __y)
   {
      return __x.base() >= __y.base();
   }

   template<typename _IteratorL, typename _IteratorR>
   bool operator>=(const reverse_iterator<_IteratorL>& __x,
      const reverse_iterator<_IteratorR>& __y)
   {
      return __x.base() <= __y.base();
   }

   template<typename _Iterator>
   typename reverse_iterator<_Iterator>::difference_type operator-(
      const reverse_iterator<_Iterator>& __x,
      const reverse_iterator<_Iterator>& __y)
   {
      return __y.base() - __x.base();
   }

   template<typename _IteratorL, typename _IteratorR>
   typename reverse_iterator<_IteratorL>::difference_type operator-(
      const reverse_iterator<_IteratorL>& __x,
      const reverse_iterator<_IteratorR>& __y)
   {
      return __y.base() - __x.base();
   }

   template<typename _Iterator>
   reverse_iterator<_Iterator> operator+(
      typename reverse_iterator<_Iterator>::difference_type __n,
      const reverse_iterator<_Iterator>& __x)
   {
      return reverse_iterator<_Iterator>(__x.base() - __n);
   }

   /**
    * stl_iterator.h
    * raws 1017 - 1300
    */
   template<typename _Iterator, typename _Container>
   class __normal_iterator
   {
   protected:
      _Iterator _M_current;

      typedef ft::iterator_traits<_Iterator>      __traits_type;

   public:
      typedef _Iterator                                  iterator_type;
      typedef typename __traits_type::iterator_category  iterator_category;
      typedef typename __traits_type::value_type         value_type;
      typedef typename __traits_type::difference_type    difference_type;
      typedef typename __traits_type::reference          reference;
      typedef typename __traits_type::pointer            pointer;

      __normal_iterator(): _M_current(_Iterator())
      {}

      __normal_iterator(const _Iterator& __i): _M_current(__i)
      {}

      reference operator*() const
      {
         return *_M_current;
      }

      pointer operator->() const
      {
         return _M_current;
      }

      __normal_iterator& operator++()
      {
         ++_M_current;
         return *this;
      }

      __normal_iterator operator++(int)
      {
         return __normal_iterator(_M_current++);
      }

      // Bidirectional iterator requirements
      __normal_iterator& operator--()
      {
         --_M_current;
         return *this;
      }

      __normal_iterator operator--(int)
      {
         return __normal_iterator(_M_current--);
      }

      // Random access iterator requirements
      reference operator[](difference_type __n) const
      {
         return _M_current[__n];
      }

      __normal_iterator& operator+=(difference_type __n)
      {
         _M_current += __n;
         return *this;
      }

      __normal_iterator operator+(difference_type __n) const
      {
         return __normal_iterator(_M_current + __n);
      }

      __normal_iterator& operator-=(difference_type __n)
      {
         _M_current -= __n; return *this;
      }

      __normal_iterator operator-(difference_type __n) const
      {
         return __normal_iterator(_M_current - __n);
      }

      const _Iterator& base() const
      {
         return _M_current;
      }
   };

   // Forward iterator requirements
   template<typename _IteratorL, typename _IteratorR, typename _Container>
   bool operator==(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs)
   {
      return __lhs.base() == __rhs.base();
   }

   template<typename _Iterator, typename _Container>
   bool operator==(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs)
   {
      return __lhs.base() == __rhs.base();
   }

   template<typename _IteratorL, typename _IteratorR, typename _Container>
   bool operator!=(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs)
   {
      return __lhs.base() != __rhs.base();
   }

   template<typename _Iterator, typename _Container>
   bool operator!=(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs)
   {
      return __lhs.base() != __rhs.base();
   }

   // Random access iterator requirements
   template<typename _IteratorL, typename _IteratorR, typename _Container>
   bool operator<(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs)
   {
      return __lhs.base() < __rhs.base();
   }

   template<typename _Iterator, typename _Container>
   bool operator<(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs)
   {
      return __lhs.base() < __rhs.base();
   }

   template<typename _IteratorL, typename _IteratorR, typename _Container>
   bool operator>(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs)
   {
      return __lhs.base() > __rhs.base();
   }

   template<typename _Iterator, typename _Container>
   bool operator>(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs)
   {
      return __lhs.base() > __rhs.base();
   }

   template<typename _IteratorL, typename _IteratorR, typename _Container>
   bool operator<=(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs)
   {
      return __lhs.base() <= __rhs.base();
   }

   template<typename _Iterator, typename _Container>
   bool  operator<=(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs)
   {
      return __lhs.base() <= __rhs.base();
   }

   template<typename _IteratorL, typename _IteratorR, typename _Container>
   bool operator>=(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs)
   {
      return __lhs.base() >= __rhs.base();
   }

   template<typename _Iterator, typename _Container>
   bool operator>=(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs)
   {
      return __lhs.base() >= __rhs.base();
   }

   template<typename _IteratorL, typename _IteratorR, typename _Container>
   typename __normal_iterator<_IteratorL, _Container>::difference_type operator-(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs)
   {
      return __lhs.base() - __rhs.base();
   }

   template<typename _Iterator, typename _Container>
   typename __normal_iterator<_Iterator, _Container>::difference_type operator-(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs)
   {
      return __lhs.base() - __rhs.base();
   }

   template<typename _Iterator, typename _Container>
   __normal_iterator<_Iterator, _Container> operator+(
      typename __normal_iterator<_Iterator, _Container>::difference_type __n,
      const __normal_iterator<_Iterator, _Container>& __i)
   {
      return __normal_iterator<_Iterator, _Container>(__i.base() + __n);
   }

   template<typename _InputIterator, typename _Distance>
   void __advance(_InputIterator& __i, _Distance __n, input_iterator_tag)
   {
      while (__n--)
         ++__i;
   }

   template<typename _BidirectionalIterator, typename _Distance>
   void __advance(_BidirectionalIterator& __i, _Distance __n,
              bidirectional_iterator_tag)
   {
      if (__n > 0)
         while (__n--)
            ++__i;
      else
         while (__n++)
            --__i;
   }

   template<typename _RandomAccessIterator, typename _Distance>
   void __advance(_RandomAccessIterator& __i, _Distance __n,
              random_access_iterator_tag)
   {
      if (__builtin_constant_p(__n) && __n == 1)
         ++__i;
      else if (__builtin_constant_p(__n) && __n == -1)
         --__i;
      else
         __i += __n;
   }

   // std::advance
   template<typename _InputIterator, typename _Distance>
   void advance(_InputIterator& __i, _Distance __n)
   {
      // concept requirements -- taken care of in __advance
      typename iterator_traits<_InputIterator>::difference_type __d = __n;
      ft::__advance(__i, __d, _iterator_category(__i));
   }
}

#endif
