#pragma once
#include <string>
class Error {
public:
    Error(const std::string& message = "");
    std::string get_message() const;

    void setMessage(std::string new_message);
private:
    std::string message;
};
