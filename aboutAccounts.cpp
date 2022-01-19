#include "aboutAccounts.h"

aboutAccounts::aboutAccounts() {
	lastdate = "";
}

aboutAccounts::aboutAccounts(const std::string& b) {
	lastdate = b;
	++countoffiles;
}

std::string aboutAccounts::get_lastdate() const{
	return lastdate;
}

void aboutAccounts::set_lastdate(const std::string& s) {
	lastdate = s;
	++countoffiles;
}

size_t aboutAccounts::get_countoffiles() const{
	return countoffiles;
}
