/*
    For initialize your table, you should call Generator class constructor with the parameters below:

    vector<string> columns: all the columns titles;
    int header_spacing: it says the columns size;

*/



#ifndef GENERATOR_HPP_INCLUDED
#define GENERATOR_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <cmath>


class Generator {
    private:
        std::vector<std::string> columns;
        std::vector<int> columns_size;
        std::vector<std::vector<std::string>> contents;
        int headers_spacing;
        int width;
    public:
        Generator(std::vector<std::string> user_columns, int spacing_size);
        void insert_row(std::vector<std::string> row);
        void draw();
};


#endif // GENERATOR_HPP_INCLUDED
