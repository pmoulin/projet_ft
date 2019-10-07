/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:39:25 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 17:51:03 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <iostream>

#include "FL/Fl_Box.H"
#include "FL/Fl_Group.H"

class IMonitorModule {
    public:
        virtual ~IMonitorModule() {}
        virtual void update() = 0;
        virtual Fl_Group *getGroup() const = 0;
        virtual void display_ncurses() const = 0;
        virtual void display_fltk() const = 0;
};

#endif /* IMONITORMODULE_HPP */
