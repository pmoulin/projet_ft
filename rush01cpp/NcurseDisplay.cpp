#include "NcurseDisplay.hpp"

NcurseDisplay::NcurseDisplay()
{
}

NcurseDisplay::NcurseDisplay(const NcurseDisplay & cp)
{
	(void)cp;
}

NcurseDisplay::~NcurseDisplay()
{
}

NcurseDisplay &	NcurseDisplay::operator=(const NcurseDisplay & cp)
{
	(void)cp;
	return (*this);
}

void		NcurseDisplay::start(void) {

	
	NameModule	name;
	RAMModule	ram;
	cpuModule	cpu;
	osModule	os;
	DateModule	date;
	netModule	net;
	std::string sDate;

	while (1) {
		name.update();
		name.display_ncurses(); // no up
		std::cout << std::endl;
		os.update();
		os.display_ncurses(); // no up
std::cout << std::endl;
		date.update();
		date.display_ncurses(); // up good
std::cout << std::endl;
		cpu.update();
		cpu.display_ncurses(); // up good
		std::cout << std::endl;

		net.update();
		net.display_ncurses();

		ram.update();
		ram.display_ncurses();
		sleep(1);
	}
};