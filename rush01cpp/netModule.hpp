#ifndef NETMODULE_CPP
# define NETMODULE_CPP

#include "IMonitorModule.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include "FL/Fl_Chart.H"
#include "FL/Fl_Group.H"
#include "FL/Fl_Box.H"

class netModule : public IMonitorModule {
	private:
		std::string					_packetsOut;
		std::string					_packetsIn;
		int							_oldOut;
		int							_oldIn;
		int							_difIn;
		int							_difOut;

		Fl_Group    *group;

		netModule(const netModule & cp);
		netModule & operator=(const netModule & cp);

	public:
		netModule();
		
		~netModule();
		netModule(size_t position, int type);

        void update();
        Fl_Group *getGroup() const;
        void display_ncurses() const;
        void display_fltk() const;
};

#endif