#ifndef OSMODULE_HPP
# define OSMODULE_HPP

#include "IMonitorModule.hpp"

#include <iostream>
#include "FL/Fl_Group.H"
#include "FL/Fl_Box.H"

class osModule : public IMonitorModule {
	private:
		std::string		_type;
		osModule(const osModule & cp);
		osModule & operator=(const osModule & cp);

		Fl_Group *group;

	public:
		osModule(void);
		~osModule(void);
		osModule(size_t position, int type);

        void update();
        Fl_Group *getGroup() const;
        void display_ncurses() const;
        void display_fltk() const;
};

#endif