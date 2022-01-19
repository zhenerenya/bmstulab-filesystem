#pragma once
#include "boost/filesystem.hpp"
#include <string>

namespace fs = boost::filesystem;

class aboutAccounts
{
private:
	unsigned int countoffiles = 0;
	std::string lastdate;

public:
	aboutAccounts();
	aboutAccounts(const std::string& b);

	std::string get_lastdate() const;
	void set_lastdate(const std::string& s);
	size_t get_countoffiles() const;
};
