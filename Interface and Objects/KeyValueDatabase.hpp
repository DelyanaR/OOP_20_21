#pragma once
#include "Object.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

class KeyValueDatabase: public Object {
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    Object* clone()const override;
    bool operator==(const Comparable* rhs)const override;
    bool operator!=(const Comparable* rhs)const override;
    std::string to_string()const override;
    void from_string(const std::string&)override;
    std::string debug_print()const override;

private:
    std::vector<std::pair<std::string, int>> pairs;
    std::pair<std::string, int> p;
};

