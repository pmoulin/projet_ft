/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:13:33 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 23:09:48 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicDisplay.hpp"
#include "NcurseDisplay.hpp"

void callback(void* a){
    reinterpret_cast<GraphicDisplay*>(a)->automaticUpdate();
    reinterpret_cast<GraphicDisplay*>(a)->display();
}

int main(int argc, char **argv){

    if (argc <= 1 || (argc > 1 && argv[1][0] == '1'))
    {
        GraphicDisplay a;

        Fl::scheme("gleam");
        a.display();
        Fl::add_idle(callback, &a);
        while (Fl::wait()){
            a.automaticUpdate();
            Fl::check();
        }
    }else if (argv[1][0] == '2'){
        NcurseDisplay n;
        n.start();
    } else {
        std::cout << "error param" << std::endl;
    }

    return 0;
}