#ifndef MEDIA_CHECKER_H
#define MEDIA_CHECKER_H

#include <string>

class media_checker{    
    public:

    enum class audio_type{
        UNKNOWN,
        MP3,
        WAV,
        FLAC
    };

    static audio_type detect_audio_type(const std::string& filepath);

    static std::string audio_type_tostring(audio_type type);

};

#endif