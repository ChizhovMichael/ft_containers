/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:30:59 by tgildero          #+#    #+#             */
/*   Updated: 2021/12/08 21:31:03 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>

void test_vector();
void test_map();
void test_set();
void test_stack();

void test_compare(bool v);

struct more
{
	bool operator() (const int& lhs, const int& rhs) const
	{
		return lhs > rhs;
	}
};

struct less
{
	bool operator() (const int& lhs, const int& rhs) const
	{
		return lhs < rhs;
	}
};

bool fnmore(int lhs, int rhs);
bool fnless(int lhs, int rhs);

#endif
