#ifndef MEDIA_CHECKER_H
#define MEDIA_CHECKER_H

#include <string>

class media_checker{
    public:
    bool is_audio_file(const std::string& file_path);
};

#endif