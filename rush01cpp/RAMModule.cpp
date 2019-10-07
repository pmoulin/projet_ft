/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 10:39:29 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 23:20:35 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMModule.hpp"

RAMModule::RAMModule(){}

RAMModule::RAMModule(size_t position, int type) {
    if (type == 0) {
        group = new Fl_Group(10, 40 + 240 * position, 980, 200);
        group->begin();
        group->box(FL_UP_BOX);
        Fl_Box *box2 = new Fl_Box(10, 40 + 240 * position, 980, 200);
        box2->box(FL_UP_BOX);
        Fl_Box *box3 = new Fl_Box(20, 50 + 240 * position, 200, 25);
        box3->box(FL_DOWN_BOX);
        group->end();
    }
}

RAMModule::~RAMModule() {
    delete group;
}

RAMModule::RAMModule(RAMModule const &a) { *this = a; }

RAMModule &RAMModule::operator=(RAMModule const &a){
    static_cast<void>(a);
    return *this;
}

void RAMModule::update() {
    FILE *              stream;
    char                buffer3[500];
    size_t              buffer3len(500);
    
    if (_memory == "") {
        stream = popen("system_profiler SPHardwareDataType | grep Memory:", "r");
        if (stream) {
            while (!feof(stream))
                if (fgets(buffer3, buffer3len, stream) != NULL)
                    _memory = buffer3;
        }
        pclose(stream);
    }
}

void RAMModule::display_ncurses() const {
    std::cout << "---RAM " << std::endl << this->_memory << std::endl;
}

void RAMModule::display_fltk() const {
    group->child(0)->label("");
    group->child(1)->copy_label(_memory.c_str());
}

Fl_Group *RAMModule::getGroup() const { return group; }