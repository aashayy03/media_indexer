#include <iostream>
#include <string>
#include "file_entry.h"
#include "directory_scanner.h"
#include "media_checker.h"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cerr << "Error: Please provide a path as a command-line argument." << std::endl;
        return 1;
    }
    
    std::string root_path = argv[1];
    std::vector<file_entry> dir_list;
    std::vector<file_entry> file_list;
    directory_scanner::scan(root_path, file_list, dir_list);
    while(!dir_list.empty()){
        file_entry dir = dir_list.back();
        dir_list.pop_back();

        std::string new_path = dir.path;
        directory_scanner::scan(new_path, file_list, dir_list);
    }

    for(file_entry file: file_list){
        media_checker::audio_type type = media_checker::detect_audio_type(file.path);
        std::cout << "name: " << file.filename << std:: endl 
        << "type: " << media_checker::audio_type_tostring(type) << std::endl << std::endl;
    }

    return 0;
}
