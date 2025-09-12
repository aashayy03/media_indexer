#ifndef FILE_ENTRY_H
#define FILE_ENTRY_H

#include <string>
struct file_entry{
    std::string filename;
    unsigned int inode;
    std::string path;
    bool isDirectory;
};

#endif