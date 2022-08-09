#include "xml_string_writer.h"

namespace MessageHandling
{
    void xml_string_writer::write(const void* data, size_t size) {
        result.append(static_cast<const char*>(data), size);
    }
} // namespace MessageHandling
