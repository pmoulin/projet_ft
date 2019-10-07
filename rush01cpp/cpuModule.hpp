#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include <unistd.h>
# include <sys/sysctl.h>
# include <iostream>
#include <vector>
# include <sstream>
#include <string>
#include "FL/Fl_Group.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Chart.H"

#include "IMonitorModule.hpp"

class cpuModule : public IMonitorModule {
	private:
		std::string		_nbCore;
		std::string		_arch;
		std::string		_model;
		std::string		_activity;
		std::string		_freq;

		float			_usedUsr;
		float			_usedSys;
		float			_free;

		Fl_Group 		*group;

		cpuModule(const cpuModule & cp);
		cpuModule & operator=(const cpuModule & cp);

	public:
		cpuModule();
		~cpuModule();
		cpuModule(size_t position, int type);
		std::vector<std::string>	get(void);
		void update();
		Fl_Group *getGroup() const;
		void display_ncurses() const;
		void display_fltk() const;
};

#endif