/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 21:41:20 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 22:54:56 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateModule.hpp"

DateModule::DateModule() {}

DateModule::DateModule(size_t position, int type) {
    update();
    if (type == 0){
        group = new Fl_Group(10, 40 + 240 * position, 980, 200);
        group->begin();
        group->box(FL_UP_BOX);
        Fl_Box *host = new Fl_Box(20, 50 + 240 * position, 100, 30);
        host->labelfont(FL_BOLD);
        host->labelsize(15);
        Fl_Box *box1 = new Fl_Box(130, 50 + 240 * position, 200, 30);
        box1->box(FL_DOWN_BOX);
        box1->labelsize(15);
        new Fl_Box(10, 40 + 240 * position, 980, 200);
        new Fl_Clock(800, 50 + 240 * position, 180, 180);
        group->end();
    }
}

DateModule::~DateModule() {
    delete group;
}

DateModule::DateModule(DateModule const &a) { *this = a; }

DateModule &DateModule::operator=(DateModule const &a){
    date = a.date;
    return *this;
}

void DateModule::update() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [19];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 19,"%e/%m/%Y",timeinfo);
    date = std::string(buffer);
}

std::string     DateModule::getDate(void) {
 
    return this->date;
}

void DateModule::display_ncurses() const {
    std::cout << date << std::endl;
}

void DateModule::display_fltk() const {
    group->child(0)->label("Date");
    group->child(1)->copy_label(date.c_str());
    group->child(2)->label("");
    static_cast<Fl_Clock*>(group->child(3))->value(time(0));
}

Fl_Group *DateModule::getGroup() const { return group; }