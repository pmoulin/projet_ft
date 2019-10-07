#include <sys/sysctl.h>
#include <iostream>
#include "osModule.hpp"


osModule::osModule(void) {}

osModule::osModule(const osModule & cp)
{
	static_cast<void>(cp);
}

osModule::~osModule(void)
{
}

osModule::osModule(size_t position, int type) {
    if (type == 0) {
        group = new Fl_Group(10, 40 + 240 * position, 980, 200);
        group->begin();
        group->box(FL_UP_BOX);
		Fl_Box *host = new Fl_Box(20, 50 + 240 * position, 100, 30);
        host->labelfont(FL_BOLD);
        host->labelsize(15);
        Fl_Box *box1 = new Fl_Box(130, 50 + 240 * position, 830, 30);
        box1->box(FL_DOWN_BOX);
        box1->labelsize(15);
        new Fl_Box(10, 40 + 240 * position, 980, 200);
        group->end();
    }
}

osModule &	osModule::operator=(const osModule & cp)
{
	this->_type = cp._type;
	return (*this);
}

void		osModule::update(void) {
	int type[2];
	char 	*p;

	type[0] = CTL_KERN;
	type[1] = KERN_VERSION;

	size_t len = 0;
	p = new char[len];
	sysctl(type, 2, NULL, &len, NULL, 0);
	delete [] p; 

	p = new char[len];
	sysctl(type, 2, p, &len , NULL, 0);
	this->_type = p;
	delete [] p;
}

void osModule::display_fltk() const {
	group->child(0)->label("Type");
	group->child(1)->copy_label(_type.c_str());
    group->child(2)->label("");
}

void		osModule::display_ncurses() const {
	std::cout << this->_type << std::endl;
}

Fl_Group *osModule::getGroup() const { return group; }
