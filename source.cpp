#include "source.h"

void iterate(const fs::path& path_to_ftp) {
	std::cout << "\n" << path_to_ftp;
	if (fs::exists(path_to_ftp)) {
		std::map<std::string, aboutAccounts>accs;
		for (const fs::directory_entry& x :
			fs::recursive_directory_iterator{ path_to_ftp }) {
			analyse(x.path(), accs);
		}
		printbroks(accs);
	}
}


bool is_formatfile(const fs::path& p, std::map<std::string, aboutAccounts>&accs) {
	std::string s = p.filename().string();
	if (s.length() == myfiletype.len) {
		size_t it0 = 0;
		size_t it1 = myfiletype.balance.length();
		std::string bal = s.substr(it0, it1);
		it0 += it1;
		it1 = myfiletype.acc.length();
		std::string acc = s.substr(it0, it1);
		it0 += it1 + 1;
		it1 = myfiletype.ldate.length();
		std::string l = s.substr(it0, it1);
		std::string e = p.extension().string();
		if ((bal == myfiletype.balance) &&
			is_number(acc) &&
			is_number(l) &&
			(e == myfiletype.e)) {
			//�������� ���������� � ���������
			set_acc(p, accs);
			return true;
		}
	}
	return false;
}

bool comparelastdate(const std::string& old_date, const std::string& new_date) {
	unsigned int d1 = stoi(old_date);
	unsigned int d2 = stoi(new_date);
	if (d1 <= d1) return true;
	return false;
}


void analyse(const fs::path& p, std::map<std::string, aboutAccounts>&accs) {
	try {
		if (fs::exists(p)) {
			if (fs::is_regular_file(p)) {
				if (is_formatfile(p, accs))
				printfiles(p);
			}
		}
		else {
			if (fs::is_symlink(p)) {
				fs::path symlink_x = fs::read_symlink(p);
				analyse(symlink_x, accs);
			}
		}
	}
	catch (fs::filesystem_error ex) {
		std::cout << ex.what() << "\n";
	}
}

void printfiles(const fs::path& p) {
	std::string fname = p.filename().string();
			std::cout << p.parent_path().filename().string() << " " << p.filename().string() << "\n";
}

void set_acc(const fs::path& p, std::map<std::string, aboutAccounts>& accs) {
	std::string s = p.filename().string();
	std::string broker = p.parent_path().filename().string();
	size_t it0 = myfiletype.balance.length();
	size_t it1 = myfiletype.acc.length();
	std::string acc = s.substr(it0, it1);
	it0 += 1 + it1;
	it1 = myfiletype.ldate.length();
	std::string date = s.substr(it0, it1);

	if (accs.find(acc) == accs.end()) {
		accs[acc] = { broker, date };
	}
	else {
		if(comparelastdate(accs[acc].get_lastdate(), date))
			accs[acc].set_lastdate(date);
	}
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

void printbroks(std::map<std::string, aboutAccounts>& accs) {
	for (const auto& i : accs) {
		std::cout <<"account: "<<i.first << " broker: " << i.second.get_broker() <<
			" files: "<<i.second.get_countoffiles()<<" last date: "<<
			i.second.get_lastdate()<<"\n";
	}
}
