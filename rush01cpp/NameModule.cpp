/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NameModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:45:15 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 22:53:18 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NameModule.hpp"

NameModule::NameModule() {}

NameModule::NameModule(size_t position, int type) {
    update();
    if (type == 0){
        group = new Fl_Group(10, 40 + 240 * position, 980, 200);
        group->begin();
        group->box(FL_UP_BOX);
        Fl_Box *host = new Fl_Box(20, 50 + 240 * position, 100, 30);
        Fl_Box *user = new Fl_Box(20, 90 + 240 * position, 100, 30);
        host->labelfont(FL_BOLD);
        user->labelfont(FL_BOLD);
        host->labelsize(15);
        user->labelsize(15);
        Fl_Box *box1 = new Fl_Box(130, 50 + 240 * position, 200, 30);
        Fl_Box *box2 = new Fl_Box(130, 90 + 240 * position, 200, 30);
        box1->box(FL_DOWN_BOX);
        box2->box(FL_DOWN_BOX);
        box1->labelsize(15);
        box2->labelsize(15);
        new Fl_Box(10, 40 + 240 * position, 980, 200);
        group->end();
    }
}

NameModule::~NameModule() {
    delete group;
}

NameModule::NameModule(NameModule const &a) { *this = a; }

NameModule &NameModule::operator=(NameModule const &a){
    hostname = a.hostname;
    username = a.username;
    return *this;
}

void NameModule::update() {
    char _hostname[LENGTH_NAME_MAX];
    char _username[LENGTH_NAME_MAX];
    gethostname(_hostname, LENGTH_NAME_MAX);
    getlogin_r(_username, LENGTH_NAME_MAX);
    hostname = _hostname;
    username = _username;
}

void    NameModule::getName(void) {


}

void NameModule::display_ncurses() const {
     std::cout << this->username << " " << this->hostname<< std::endl;
}

void NameModule::display_fltk() const {
    group->child(0)->label("Hostname");
    group->child(1)->label("Username");
    group->child(2)->copy_label(hostname.c_str());
    group->child(3)->copy_label(username.c_str());
    group->child(4)->label("");
}

Fl_Group *NameModule::getGroup() const { return group; }