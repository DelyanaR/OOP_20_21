#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template <typename T>

class Optional {
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;

    void setMessage(std::string new_message);//
    std::string getMessage()const;
    Optional<T>& operator=(const Optional<T>& rhs);

private:
    T object;
    bool empty;
    std::string message;
};

template <typename T>
Optional<T>::Optional() {
    this->object = T();//an object is empty if we don't give a parameter in the constructor
    this->empty = true;
}

template <typename T>
Optional<T>::Optional(const T& value) {
    this->object = value;
    this->empty= false;
}

template <typename T>
bool Optional<T>::is_none() const {
    if (this->empty) {
        return true;
    }
    return false;
}

template <typename T>
T Optional<T>::get_value() const {
    return this->object;
}

template<typename T>
void Optional<T>::setMessage(std::string new_message) {
    this->message=new_message;
    this->empty = false;
}

template<typename T>
std::string Optional<T>::getMessage()const {
    return this->message;
}

template<typename T>
inline Optional<T>& Optional<T>::operator=(const Optional<T>& rhs){
    this->object = rhs.object;
    this->empty = rhs.empty;
    return *this;
}



