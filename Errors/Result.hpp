#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(T& rhs);
    template<typename U>
    bool operator==(const U& rhs);

private:
    Optional<T> result;
    bool have_message = false;
};

template<typename T>
Result<T>::Result() {
    this->result = Optional<T>();
}

template<typename T>
Result<T>::Result(const T& result) {
    this->result = result;
}

template<>
Result<Error>::Result(const Error& result) {
    this->result = result;
    this->have_message = true;
}

template<typename T>
Result<T>::Result(const std::string& error_message) {
    this->result.setMessage(error_message);
    this->have_message = true;
}

template<typename T>
Optional<T> Result<T>::get_result() const {
    return this->result;

}

template<typename T>
inline Optional<Error> Result<T>::get_error() const {   
    Error err(this->result.getMessage());
    Optional<Error>to_return(err);
    return to_return;
}

template<>
inline Optional<Error> Result<Error>::get_error() const{
    Optional<Error> to_return(this->result.get_value());
    return to_return;
}

template<typename T>
bool Result<T>::operator==(T& rhs) {
    if (!(this->result.is_none()) || this->have_message) { 
        return true;
    } 
    return false;
}

template<typename T> template<typename U>
bool Result<T>::operator==(const U& rhs1) {
    if (typeid(this->get_result().get_value()) == typeid(rhs1)) {
        return true;
    }
    else if (this->have_message && !(this->result.is_none())) {
        return true;
    }
    return false;
}

