/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:31:12 by tgildero          #+#    #+#             */
/*   Updated: 2021/12/08 21:31:15 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void test_compare(bool v)
{
	if (v)
		std::cout << "\033[0;32m[OK]\033[0m";
	else
		std::cout << "\033[0;31m[💥]\033[0m";
}

bool fnmore(int lhs, int rhs)
{
	return lhs > rhs;
}

bool fnless(int lhs, int rhs)
{
	return lhs < rhs;
}