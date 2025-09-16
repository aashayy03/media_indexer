#include <iostream>
#include <fstream>
#include "media_checker.h"
#include "file_entry.h"

media_checker::audio_type media_checker::detect_audio_type(const std::string& filepath){
    std::ifstream file(filepath, std::ios::binary);
    if(!file){
        std::cerr << "can't open file" << std::endl;
        return audio_type::UNKNOWN;
    }
}