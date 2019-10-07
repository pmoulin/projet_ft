/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:06:36 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/02 22:52:19 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpuModule.hpp"

cpuModule::cpuModule()
{
	this->update();
}

cpuModule::cpuModule(const cpuModule & cp)
{
	(void)cp;
}

cpuModule::~cpuModule()
{
}

cpuModule &		cpuModule::operator=(const cpuModule & cp)
{
	(void)cp;
	return (*this);
}

cpuModule::cpuModule(size_t position, int type) {
    update();
    if (type == 0){
        group = new Fl_Group(10, 40 + 240 * position, 980, 200);
        group->begin();
        group->box(FL_UP_BOX);
        Fl_Box *host = new Fl_Box(20, 50 + 240 * position, 100, 30);
        host->labelfont(FL_BOLD);
        host->labelsize(15);
        Fl_Box *box1 = new Fl_Box(120, 50 + 240 * position, 300, 30);
        box1->box(FL_DOWN_BOX);
        box1->labelsize(15);
        new Fl_Box(10, 40 + 240 * position, 980, 200);
		Fl_Chart *chart = new Fl_Chart(450, 50 + 240 * position, 520, 180);
        chart->type(FL_LINE_CHART);
		chart->bounds(0, 100);
		chart->maxsize(100);
		chart->box(FL_EMBOSSED_BOX);
		Fl_Chart *chart2 = new Fl_Chart(40, 90 + 240 * position, 180, 120);
        chart2->type(FL_PIE_CHART);
		chart2->maxsize(3);
		chart2->box(FL_SHADOW_BOX);
        group->end();
    }
}

void	cpuModule::update(void) {

	char				buffer[500];
	size_t				bufferlen(500);
    std::stringstream	ss;
	std::string			trash;
	long long           buffer2(0);
	float				tmp2(0.0f);



	sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
	this->_model = buffer;
	bzero(&buffer, bufferlen);

	ss.str("");
	ss.clear();
	
	sysctlbyname("hw.cpufrequency",&buffer2,&bufferlen,NULL,0);
	tmp2 = buffer2;
	ss << (tmp2 /1000000000) << " Ghz"; //pour mettre en Ghz
	this->_freq = ss.str();
	ss.str("");
	ss.clear();

	sysctlbyname("machdep.cpu.core_count",&buffer2,&bufferlen,NULL,0);
	ss << buffer2;
	this->_nbCore = ss.str();
	ss.str("");
	ss.clear();

	ss << _activity;

	ss >> _usedUsr;
	ss >> trash >> trash;
	ss >> _usedSys;
	ss >> trash >> trash;
	ss >> _free;

    std::string 		data;
    FILE *              stream;
    char                buffer3[500];
    size_t              buffer3len(500);
    int i(0);

    stream = popen("top -l 1 -n 0 -s 0", "r");
    if (stream) {
        while (!feof(stream))
        {
            i++;
            if (fgets(buffer3, buffer3len, stream) != NULL && i == 4) 
                data.append(buffer3);
        }
        pclose(stream);
        try {
		this->_activity = data.substr(11, data.size() - 13);
        this->_activity += "   ";
    	}catch(std::exception & e ){
    		std::cout << e.what() << std::endl;
    	}
        // std::cout << this->_activity << std::endl;

	}
}


std::vector<std::string>	cpuModule::get(void) {
	this->update();

	std::vector<std::string> tmp;
	std:: string core;

	core = _nbCore + "core";
	tmp.push_back(core);
	tmp.push_back(_model);
	tmp.push_back(_activity);
	return tmp;

}

void cpuModule::display_ncurses() const {
	std::cout << "-- cpu : " << _model << std::endl;
	std::cout << _nbCore << "core(s)" << std::endl;
	std::cout << _model << std::endl;
	std::cout << _activity << std::endl;
}

void cpuModule::display_fltk(void) const {
	group->child(0)->label("Model");
    group->child(1)->copy_label(_activity.c_str());
    group->child(2)->label("");
	static_cast<Fl_Chart*>(group->child(3))->add(_usedUsr);
	static_cast<Fl_Chart*>(group->child(4))->clear();
	static_cast<Fl_Chart*>(group->child(4))->add(_usedUsr, "user", 0xFFAA55);
	static_cast<Fl_Chart*>(group->child(4))->add(_usedSys, "sys", 0x55FFAA);
	static_cast<Fl_Chart*>(group->child(4))->add(_free, "idle", 0xAA55FF);
}

Fl_Group *cpuModule::getGroup() const { return group; }