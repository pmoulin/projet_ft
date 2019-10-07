#include "netModule.hpp"

netModule::netModule()
{
	this->_oldIn = 0;
	this->_oldOut = 0;
}

netModule::netModule(const netModule & cp)
{
	(void)cp;
}

netModule::~netModule()
{
}

netModule &	netModule::operator=(const netModule & cp)
{
	this->_packetsOut = cp._packetsOut;
	this->_packetsIn = cp._packetsIn;
	this->_oldIn = cp._oldIn;
	this->_oldOut = cp._oldOut;
	return (*this);
}

netModule::netModule(size_t position, int type) {
    if (type == 0) {
        group = new Fl_Group(10, 40 + 240 * position, 980, 200);
        group->begin();
        group->box(FL_UP_BOX);
        Fl_Chart *chart = new Fl_Chart(250, 50 + 240 * position, 730, 85);
		Fl_Chart *chart2 = new Fl_Chart(250, 145 + 240 * position, 730, 85);
        chart->type(FL_LINE_CHART);
		chart2->type(FL_LINE_CHART);
		chart->bounds(0, 1000);
		chart2->bounds(0, 1000);
        chart->maxsize(100);
		chart2->maxsize(100);
     	new Fl_Box(10, 40 + 240 * position, 980, 200);
        group->end();
    }
}

void		netModule::update() {

	std::string data;
	FILE * stream;

	int		out;
	int		in;

	const int max_buffer = 500;
	int i(0);
	char buffer[max_buffer];

	stream = popen("top -l 1 -n 0 -s 0", "r");
	if (stream) {
		while (!feof(stream))
		{
			i++;
			if (fgets(buffer, max_buffer, stream) != NULL && i == 9) 
				data.append(buffer);
		}
		pclose(stream);
		

			// get online number (int and out )
		if (!data.empty())
		{
			std::istringstream iss(data);
			std::vector<std::string> results((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
			this->_packetsIn = results[2];
			this->_packetsOut = results[4];


			in = std::stoi(results[2]);
			out = std::stoi(results[4]);
			this->_difOut = out - this->_oldOut;
			this->_difIn = in - this->_oldIn;
			this->_oldIn = in;
			this->_oldOut = out;
		}
	}
}

void netModule::display_ncurses() const {
	std::cout << "--- Network" << std::endl;
    std::cout << " packet in : " << this->_packetsIn << " | packet out : " << this->_packetsOut <<  std::endl;
}

void netModule::display_fltk() const {
    static_cast<Fl_Chart*>(group->child(0))->add(_difIn);
    static_cast<Fl_Chart*>(group->child(1))->add(_difOut);
    group->child(2)->label("");
}

Fl_Group *netModule::getGroup() const { return group; }