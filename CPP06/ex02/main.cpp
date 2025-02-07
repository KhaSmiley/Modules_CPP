/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:14:27 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/05 18:09:43 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base *ok = generate();
    std::cout << "identify from pointer : " << std::endl;
    identify(ok);
    std::cout << "identify from reference : " << std::endl;
    identify(*ok);
    delete ok;
    return 0;
}