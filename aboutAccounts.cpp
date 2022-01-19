#include "aboutAccounts.h"

aboutAccounts::aboutAccounts() {
	broker = "";
	lastdate = "";
}

aboutAccounts::aboutAccounts(const std::string& b, const std::string& ld) {
	broker = b;
	lastdate = ld;
	++countoffiles;
}

std::string aboutAccounts::get_lastdate() const{
	return lastdate;
}

void aboutAccounts::set_lastdate(const std::string& s) {
	lastdate = s;
	++countoffiles;
}

std::string aboutAccounts::get_broker() const{
	return broker;
}

size_t aboutAccounts::get_countoffiles() const{
	return countoffiles;
}
