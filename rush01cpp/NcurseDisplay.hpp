#ifndef NCURSEDISPLAY_HPP
# define NCURSEDISPLAY_HPP


#include "NameModule.hpp"
#include "DateModule.hpp"
#include "RAMModule.hpp"
#include "cpuModule.hpp"
#include "osModule.hpp"
#include "netModule.hpp"

#include <vector>
class NcurseDisplay {
	private:
		

	public:
		NcurseDisplay(/* args */);
		NcurseDisplay(const NcurseDisplay & cp);
		~NcurseDisplay(/* args */);
		NcurseDisplay & operator=(const NcurseDisplay & cp);

		void		start(void);
};

#endif