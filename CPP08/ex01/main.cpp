/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:38:11 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/07 23:42:13 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span test(6);

    for(unsigned int i = 0; i < test.getSize(); i++)
    {
        test.addNumber(i);
    }
    std::vector<int> myvec;  // Ensure this is big enough
    Span plouf(1000);  // Make sure `plouf` has enough space
    for(int i = 0; i < 1000; i++)
    {
        myvec.push_back(i);
    }
    plouf.iteratorNumber(myvec.begin(), myvec.end());
    plouf.print_vector();    
}