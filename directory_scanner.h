#ifndef DIRECTORY_SCANNER_H
#define DIRECTORY_SCANNER_H

#include <vector>
#include "file_entry.h"

class directory_scanner{
    public:
    static void scan(const std::string& directory_path, 
        std::vector<file_entry>& file_list, 
        std::vector<file_entry>& dir_list);

};

#endif