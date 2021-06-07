#pragma once
#include "Object.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class Document: public Object {
public:
    Document(const std::string& name, const std::string& location, const std::string& extension);
    void write_line(const std::string& line);
    std::string read_line();
    std::string read_line(const unsigned line);

    Object* clone()const override;
    bool operator==(const Comparable* rhs)const override;
    bool operator!=(const Comparable* rhs)const override;
    std::string to_string()const override;
    void from_string(const std::string&)override;
    std::string debug_print()const override;


private:
    std::vector<std::string>lines;
    size_t pointer;
};


