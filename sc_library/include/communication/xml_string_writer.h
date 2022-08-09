#pragma once

#include <string>
#include "pugixml.hpp"

namespace MessageHandling {
    struct xml_string_writer : pugi::xml_writer
    {
        std::string result;

        virtual void write (const void* data, size_t size);
    };
    
}