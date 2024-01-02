#include "include/properties.h"

#include <iostream>
#include "cpptoml/include/cpptoml.h"
#include <string>

Properties::Properties() {}

char* get_property(const char* property_name) {
    try {
        auto config_pages = cpptoml::parse_file("pages.toml");
        auto value_string = config_pages->get_as<std::string>(property_name);
        if (value_string) {
            char* cstr = new char[value_string->size() + 1];
            std::strcpy(cstr, value_string->c_str());
            return cstr;
        } else {
            return nullptr;
        }
    } catch (const cpptoml::parse_exception& e) {
        return nullptr;
    }
}
