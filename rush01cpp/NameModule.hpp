/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NameModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:41:41 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 22:52:29 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMEMODULE_HPP
#define NAMEMODULE_HPP

#define LENGTH_NAME_MAX 256

#include <unistd.h>
#include <iostream>

#include "IMonitorModule.hpp"

class NameModule : public IMonitorModule {
    private:
        std::string hostname;
        std::string username;
        Fl_Group    *group;
        
        NameModule(NameModule const &a);
        NameModule &operator=(NameModule const &a);

    public:
        NameModule();
        ~NameModule();
        NameModule(size_t position, int type);

        void update();
        Fl_Group *getGroup() const;
        void display_ncurses() const;
        void display_fltk() const;

        void    getName(void);
};

#endif /* NAMEMODULE_HPP */
