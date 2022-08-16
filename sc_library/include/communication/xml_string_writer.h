#pragma once

#include <string>
#include "pugixml.hpp"

namespace MessageHandling {
    struct xml_string_writer : pugi::xml_writer
    {
        /**
         * @brief Stores the xml data as a valid xml string
         */
        std::string result;
        /**
         * @brief Converts a xml object to a string, stored in result field of this class.
         * 
         * @param data Data of the xml object
         * @param size Size of the object
         */
        virtual void write (const void* data, size_t size);
    };
    
}