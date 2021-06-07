#pragma once
#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"

class Object: public Comparable, public Serializable, public Debug {
public:
    Object(const std::string& name, const std::string& location, const std::string& extension);
    virtual ~Object() = default;
    virtual Object* clone()const=0;

    virtual std::string get_name() const;
    virtual std::string get_location() const;
    virtual std::string get_extension() const;
    virtual std::string get_fullpath() const;

    bool operator==(const Comparable* rhs)const override;
    bool operator!=(const Comparable* rhs)const override;
    std::string to_string()const override;
    void from_string(const std::string&)override;
    std::string debug_print()const override;

protected:
    std::string name;
    std::string location;
    std::string extension;
};

