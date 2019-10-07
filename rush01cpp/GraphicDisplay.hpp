/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:20:40 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 18:29:45 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICDISPLAY_HPP
#define GRAPHICDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "NameModule.hpp"
#include "DateModule.hpp"
#include "RAMModule.hpp"
#include "cpuModule.hpp"
#include "osModule.hpp"
#include "netModule.hpp"

#include <thread>

#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Choice.H"
#include "FL/Fl_Group.H"

#define NB_DISPLAY 4
#define NB_MODULE 6

class GraphicDisplay : public IMonitorDisplay{
    private:
        Fl_Window *window;
        Fl_Choice *menu[NB_DISPLAY];
        IMonitorModule *module[NB_DISPLAY];
        
        GraphicDisplay(GraphicDisplay const &a);
        GraphicDisplay &operator=(GraphicDisplay const &a);

    public:
        GraphicDisplay();
        ~GraphicDisplay();

		void automaticUpdate();
        void updateModules();
        void display() const;
};

typedef IMonitorModule* (*moduleCreator)(size_t position, int type);

#endif /* GRAPHICDISPLAY_HPP */
