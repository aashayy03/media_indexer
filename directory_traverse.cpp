#include <iostream>
#include <dirent.h>
#include "file_entry.h"
#include "directory_scanner.h"

void directory_scanner::scan(const std::string& directory_path, 
                            std::vector<file_entry>& file_list, 
                            std::vector<file_entry>& dir_list)
{
    DIR* opened_dir = opendir(directory_path.c_str());

    if(opened_dir == nullptr){
        std::cerr << "can't open directory " << directory_path << std::endl;
        return;
    }

    struct dirent* entry;
    while((entry = readdir(opened_dir)) != nullptr){
        if(std::string(entry->d_name) == "." || std::string(entry->d_name) == ".."){
            continue;
        }

        file_entry file;
        file.filename = entry->d_name;
        file.inode = entry->d_ino;
        file.path = directory_path + "/" + entry->d_name;
        if(entry->d_type == DT_DIR){
            file.isDirectory = true;
            dir_list.push_back(file);
        }else {
            file.isDirectory = false;
            file_list.push_back(file);
        }
    }
    closedir(opened_dir);
    return;
}


int main(int argc, char const *argv[])
{
    std::string path;
    if(argc > 1){
        path = argv[1];
    } else{
        std::cout << "enter path: ";
        std::cin >> path;
    }

    //directory_scanner scanner;
    std::vector<file_entry> dir_list;
    std::vector<file_entry> file_list;
    directory_scanner::scan(path, file_list, dir_list);
    while(!dir_list.empty()){
        file_entry dir = dir_list.back();
        dir_list.pop_back();

        std::string new_path = dir.path;
        directory_scanner::scan(new_path, file_list, dir_list);
    }


    for(file_entry f: file_list){
        std::cout << "File" << "\n" 
                  << "name: " << f.filename << "\n"
                  << "inode: " << f.inode << "\n"
                  << "path: "  << f.path << "\n"
                  << std::endl;
    }
    
    return 0;
}

