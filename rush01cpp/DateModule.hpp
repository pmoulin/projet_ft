/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 21:40:42 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 22:55:02 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATEMODULE_HPP
#define DATEMODULE_HPP

#include "IMonitorModule.hpp"
#include <time.h>
#include <chrono>
#include <ctime>
#include "FL/Fl_Clock.H"
class DateModule : public IMonitorModule {
    private:
        std::string date;
        Fl_Group    *group;
        
        DateModule(DateModule const &a);
        DateModule &operator=(DateModule const &a);

    public:
        DateModule();

        ~DateModule();
        DateModule(size_t position, int type);

        std::string     getDate(void);
        void update();
        Fl_Group *getGroup() const;
        void display_ncurses() const;
        void display_fltk() const;
};

#endif /* DATEMODULE_HPP */
