/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 10:36:35 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 23:04:30 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
#define RAMMODULE_HPP

#include "IMonitorModule.hpp"

#include <iostream>
#include "FL/Fl_Chart.H"
#include "FL/Fl_Group.H"
#include "FL/Fl_Box.H"

class RAMModule : public IMonitorModule {
    private:
        std::string _memory;
        Fl_Group    *group;
        
        RAMModule(RAMModule const &a);
        RAMModule &operator=(RAMModule const &a);

    public:
        RAMModule();
        ~RAMModule();
        RAMModule(size_t position, int type);

        void update();
        Fl_Group *getGroup() const;
        void display_ncurses() const;
        void display_fltk() const;
};

#endif /* RAMMODULE_HPP */
