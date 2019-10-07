/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:26:51 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 22:55:25 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicDisplay.hpp"

IMonitorModule *createNameModule(size_t position, int type) { return new NameModule (position, type); }
IMonitorModule *createDateModule(size_t position, int type) { return new DateModule (position, type); }
IMonitorModule *createRAMModule (size_t position, int type) { return new RAMModule  (position, type); }
IMonitorModule *createcpuModule (size_t position, int type) { return new cpuModule  (position, type); }
IMonitorModule *createosModule  (size_t position, int type) { return new osModule   (position, type); }
IMonitorModule *createnetModule (size_t position, int type) { return new netModule  (position, type); }

moduleCreator module_tab[NB_MODULE] = {
    &createNameModule,
    &createDateModule,
    &createRAMModule,
    &createcpuModule,
    &createosModule,
    &createnetModule
};

const char *module_name[NB_MODULE] = {
    "Name",
    "Date",
    "RAM",
    "CPU",
    "OS",
    "Network"
};

void cb(Fl_Widget* o, void* a){
    static_cast<void>(o);
    reinterpret_cast<GraphicDisplay*>(a)->updateModules();
}

void GraphicDisplay::updateModules(){
    for (size_t i = 0; i < NB_DISPLAY; i++){
        if (menu[i]->value() != -1 && menu[i]->changed()){
            delete module[i];
            module[i] = module_tab[menu[i]->value()](i, 0);
            window->add(module[i]->getGroup());
            display();
        }
    }
}

GraphicDisplay::GraphicDisplay() {
    window = new Fl_Window(1000, 970, "ft_gkrellm");
    for (size_t i = 0; i < NB_DISPLAY; i++){
        menu[i] = new Fl_Choice(10, 8 + i * 240, 200, 25);
        for (size_t j = 0; j < NB_MODULE; j++){
            menu[i]->add(module_name[j]);
            menu[i]->callback(cb, this);
        }
    }
    for (size_t i = 0; i < 4; i++){
        module[i] = NULL;
    }
}

GraphicDisplay::~GraphicDisplay() {
    delete window;
}

GraphicDisplay::GraphicDisplay(GraphicDisplay const &a) { *this = a; }

GraphicDisplay &GraphicDisplay::operator=(GraphicDisplay const &a) {
    static_cast<void>(a);
    return *this;
}

void GraphicDisplay::automaticUpdate() {
    for (size_t i = 0; i < 4; i++){
        if (module[i]){
            module[i]->update();
        }
    }
}

void GraphicDisplay::display() const {
    for (size_t i = 0; i < 4; i++){
        if (module[i]){
            module[i]->display_fltk();
        }
    }
    window->show();
}
