#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace csv {

    class Row {
    private:
        vector<string> values;

    public:
        Row(string line) {
            stringstream s(line);
            string field;

            while (getline(s, field, ',')) {
                values.push_back(field);
            }
        }

        string operator[](size_t index) const {
            return index < values.size() ? values[index] : "";
        }
    };

    class Parser {
    private:
        vector<Row> rows;

    public:
        Parser(string filename) {
            ifstream file(filename);
            string line;

            if (!file.is_open()) {
                cerr << "Error opening file: " << filename << endl;
                return;
            }

            getline(file, line); // skip header

            while (getline(file, line)) {
                rows.emplace_back(Row(line));
            }

            file.close();
        }

        Row operator[](size_t index) const {
            return rows.at(index);
        }

        size_t rowCount() const {
            return rows.size();
        }
    };

}

#endif
