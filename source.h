#pragma once
#include "aboutAccounts.h"
#include "boost/filesystem.hpp"
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <fstream>

struct{ 
	const std::string balance = "balance_";
	const std::string acc = "xxxxxxxx";
	const std::string ldate = "xxxxxxxx";
	const std::string e = ".txt";
	const int len = balance.length() + acc.length()
		+ 1 + ldate.length() + e.length();
} myfiletype;

namespace fs = boost::filesystem;

bool is_number(const std::string& s);

bool comparelastdate(const std::string& old_date, const std::string& new_date);

void set_acc(const fs::path& p, std::map<std::pair<std::string, std::string>, aboutAccounts>& accs);

bool is_formatfile(const fs::path& p, std::map<std::pair<std::string, std::string>, aboutAccounts>&accs);

void printbroks(std::map<std::pair<std::string, std::string>, aboutAccounts>& accs);

void printfiles(const fs::path& p);

void analyse(const fs::path& p, std::map<std::pair<std::string, std::string>, aboutAccounts>&accs);

void iterate(const fs::path& path_to_ftp);

std::ofstream& fprintbroks(std::map<std::pair<std::string, std::string>, aboutAccounts>& accs);

std::ofstream& fprintfiles(const fs::path& p);

