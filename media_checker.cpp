#include <iostream>
#include <fstream>
#include <vector>
#include "media_checker.h"
#include "file_entry.h"

media_checker::audio_type media_checker::detect_audio_type(const std::string& filepath){
    std::ifstream file(filepath, std::ios::binary);
    if(!file){
        std::cerr << "can't open file" << std::endl;
        return audio_type::UNKNOWN;
    }
    std::vector<unsigned char> buffer(12);
    file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());
    size_t bytes_read = file.gcount();

    if(bytes_read < 4) return audio_type::UNKNOWN;
    if(bytes_read >=4 && buffer[0] == 'f' && buffer[1] == 'L' && 
        buffer[2] == 'a' && buffer[3] == 'C'){
            return audio_type::FLAC;
        }
    if(bytes_read >= 12 && buffer[0] == 'R' && buffer[1] == 'I' &&
        buffer[2] == 'F' && buffer[3] == 'F'){
            return audio_type::WAV;
        }
    if(bytes_read >= 3 && buffer[0] == 'I' && buffer[1] == 'D' &&
        buffer[2] == '3'){
            return audio_type::MP3;
        }
    
    return audio_type::UNKNOWN;
}

std::string media_checker::audio_type_tostring(audio_type type){
    switch (type)
    {
    case audio_type::FLAC:
        return std::string("FLAC");
    case audio_type::MP3:
        return std::string("MP3");
    case audio_type::WAV:
        return std::string("WAV");
    default:
        return std::string("unknown format");
    }
}

int main(int argc, char const *argv[])
{
    std::string filepath;
    if(argc > 1){
        filepath = argv[1];
    }else{
        std::cout << "pass filepath as command line argument" <<std::endl;
        return 1;
    }

    media_checker::audio_type type =  media_checker::detect_audio_type(filepath);
    std::cout << media_checker::audio_type_tostring(type) << std::endl;
    return 0;
}
