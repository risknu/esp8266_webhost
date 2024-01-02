#ifndef PROPERTIES_H
#define PROPERTIES_H

class Properties {
    public:
        Properties();

        char* get_property(const char* property_name);
};

#endif