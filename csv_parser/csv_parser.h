#pragma once
#include <vector>
#include <string>
#include <ostream>
#include <istream>
#include <fstream>	// ifstream
#include <sstream>	// istringstream
#include <iostream>	// getline
#include <locale>

using namespace std;

template <typename T>
class CsvParser {
public:
	std::vector<std::vector<std::string>> g_data;

public:
	CsvParser(void){
		g_data.clear();
	}
	CsvParser(std::string path, char delim, unsigned int start_row, unsigned int start_col, std::string comment) {
		g_data.clear();
		ReadCsv(path, delim, start_row, start_col, comment);
	}
	~CsvParser(void){
		g_data.clear();
	}

	bool ReadCsv(std::string path, char delim, unsigned int start_row, unsigned int start_col, std::string comment) {
		unsigned int row = 0, col = 0;
		std::vector<std::string> line_vec;
		std::string line;
		bool elm_chk = false;

		ifstream ifs(path);
		if (!ifs.is_open()) { return false; }

		while (std::getline(ifs, line)) {
			std::istringstream iss(line);
			std::string token;

			while (std::getline(iss, token, delim)) {
				elm_chk = (row >= start_row) && (col >= start_col) && (token.find(comment) == std::string::npos);
				if (elm_chk) {
					line_vec.push_back(token);
				}

				col++;
			}
			if (elm_chk) {
				g_data.push_back(line_vec);
				line_vec.clear();
			}
			row++;
		}

		return true;
	}

	size_t GetSize(unsigned int x){
		return g_data.at(x).size();
	}

	size_t GetSize(unsigned int x, unsigned int y){
		return g_data.at(x).at(y).size();
	}

	T GetData(unsigned int x, unsigned int y) {
		T num;
		std::stringstream ss;
		ss << _strtod_l(g_data.at(x).at(y).c_str(), NULL, _get_current_locale());
		ss >> num;
		return num;
	}

	std::string GetLabels(unsigned int x, unsigned int y) {
		return g_data.at(x).at(y);
	}
};