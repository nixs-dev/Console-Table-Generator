/*Code to show how this should  be used*/

#include <iostream>
#include "Generator.hpp"


int main() {
    std::vector<std::string> columns = {"User", "Idade", "Email"};
    std::vector<int> columns_size = {5, 5, 5};
    std::vector<std::string> content = {"Eu", "18", "assaasasadadas"};
    Generator table_generator(columns, columns_size);

    for(int i = 0; i < 10; i++) {
        table_generator.insert_row(content);
    }
    table_generator.draw();

}
