#pragma once
#include "boost/filesystem.hpp"
#include <string>

namespace fs = boost::filesystem;

class aboutAccounts
{
private:
	unsigned int countoffiles = 0;
	std::string lastdate;
	std::string broker;

public:
	aboutAccounts();
	aboutAccounts(const std::string& b, const std::string& ld);

	std::string get_lastdate() const;
	void set_lastdate(const std::string& s);
	std::string get_broker() const;
	size_t get_countoffiles() const;
};
