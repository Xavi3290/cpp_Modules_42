/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:17:29 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/10 18:51:43 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    ClapTrap clap1("RX-9000");
    ClapTrap clap2("AA-1000");
    ClapTrap defaultClap;
    ClapTrap copyClap(clap1);
    ClapTrap assignedClap = clap2;
    
    std::cout << std::endl;
    
    clap1.attack("AA-1000");
    clap2.takeDamage(5);
    
    clap2.attack("RX-9000");
    clap1.takeDamage(3);

    clap1.beRepaired(4);
    clap2.beRepaired(2);

    for (int i = 0; i < 12; i++) {
        clap1.attack("AA-1000");
    }
    clap2.takeDamage(20);
    clap2.takeDamage(11);
    
    clap1.beRepaired(10);
    clap2.beRepaired(10);
    clap2.attack("RX-9000");

    std::cout << std::endl;
    
    FragTrap frag1("RX-9001");
    FragTrap frag2("AA-1001");
    FragTrap defaultFrag;
    FragTrap copyFrag(frag1);
    FragTrap assignedFrag = frag2;
    
    std::cout << std::endl;
    
    frag1.attack("AA-1001");
    frag2.takeDamage(30);
    
    frag2.attack("RX-9001");
    frag1.takeDamage(30);

    frag1.beRepaired(4);
    frag2.beRepaired(2);
    frag1.highFivesGuys();

    for (int i = 0; i < 101; i++) {
        frag1.attack("AA-1001");
    }
    frag2.takeDamage(30);
    frag2.takeDamage(600);
    
    frag1.beRepaired(10);
    frag2.beRepaired(10);
    frag2.attack("RX-9001");

    std::cout << std::endl;


    return 0;
}