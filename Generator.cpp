#include "Generator.hpp"


Generator::Generator(std::vector<std::string> user_columns, std::vector<int> size_by_column) {
    columns = user_columns;

    calculate_size(size_by_column);
}

void Generator::calculate_size(std::vector<int> size_by_column) {
    int total_titles_size = 0;
    int rows_width = 0;
    int index = 0;
    columns_size = {};

    for(std::string title: columns) {
        columns_size.push_back(size_by_column[index]);
        total_titles_size += title.size();
        rows_width += size_by_column[index];
        index += 1;
    }

    width = rows_width + columns_size.size();
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
    std::string result = "";
    bool redraw = false;

    calculate_size(columns_size);


    /*DRAW THE COLUMNS HEADERS*/

    result += std::string(width, '_') + "\n";

    int column_index = 0;

    for(std::string title: columns) {
        int to_fill_with_space = columns_size[column_index] - title.size();

        result += '|' + title + std::string(to_fill_with_space, ' ');
        column_index ++;
    }

    result += '|';
    result += "\n" + std::string(width, '~') + "\n";



    /*DRAW THE CONTENT*/
    column_index = 0;

    for(std::vector<std::string> row: contents) {
        if(redraw) {
            break;
        }

        for(std::string value: row) {
            int to_fill_with_space = columns_size[column_index] - value.size();

            if(to_fill_with_space >= 0) {
                result += '|' + value + std::string(to_fill_with_space, ' ');
            }
            else {
                columns_size[column_index] += -(to_fill_with_space);
                redraw = true;
                break;
            }
            column_index++;
        }

        column_index = 0;
        result += '|';
        result += "\n" + std::string(width, '-') + "\n";
    }

    if(redraw) {
        draw();
    }
    else {
        std::cout << result;
    }
}
