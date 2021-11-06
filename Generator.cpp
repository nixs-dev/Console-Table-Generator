#include "Generator.hpp"


Generator::Generator(std::vector<std::string> user_columns, int spacing_size) {
    columns = user_columns;
    headers_spacing = round(spacing_size/2);

    int total_titles_size = 0;

    for(std::string title: columns) {
        columns_size.push_back(title.size() + (headers_spacing*2));
        total_titles_size += title.size();
    }

    width = total_titles_size + ((headers_spacing * 2) * columns.size()) + columns.size();
}

void Generator::insert_row(std::vector<std::string> row) {
    if(row.size() == columns.size()) {
        contents.push_back(row);
    }
    else {
        std::cout << "The content to be inserted MUST have the same size as the columns";
        exit(-1);
    }
}

void Generator::draw() {

    /*DRAW THE COLUMNS HEADERS*/

    std::cout << std::string(width, '_') << std::endl;

    for(std::string title: columns) {
        std::cout << '|' << std::string(headers_spacing, ' ') << title << std::string(headers_spacing, ' ');
    }
    std::cout << '|' << std::endl;

    std::cout << std::string(width, '~') << std::endl;



    /*DRAW THE CONTENT*/
    int column_index = 0;

    for(std::vector<std::string> row: contents) {
        for(std::string value: row) {
            int to_fill_with_space = columns_size[column_index] - value.size();

            if(to_fill_with_space >= 0) {
                std::cout << '|' << value << std::string(to_fill_with_space, ' ');
            }
            else {
                //ARRUMA ISSOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
                std::cout << '|' << value;
            }
            column_index++;
        }

        column_index = 0;
        std::cout << '|' << std::endl;
        std::cout << std::string(width, '-') << std::endl;
    }

}
