#include "resource.h"
#include <iostream>
#include <filesystem>

// Constructor
Resource::Resource(std::string path, ResourceType type)
    : _path(std::move(path)), _type(type) {
        calculateFileSize();
}

// Destructor
Resource::~Resource() = default;

// Copy constructor
Resource::Resource(const Resource& other)
    : _path(other._path), _size(other._size), _type(other._type) {}

// Copy assignment operator
Resource& Resource::operator=(const Resource& other) {
    if (this != &other) {
        _path = other._path;
        _size = other._size;
        _type = other._type;
    }
    return *this;
}

// Move constructor
Resource::Resource(Resource&& other) noexcept
    : _path(std::move(other._path)), _size(other._size), _type(other._type) {
    other._size = 0;
    other._type = ResourceType::File; // Default value
}

// Move assignment operator
Resource& Resource::operator=(Resource&& other) noexcept {
    if (this != &other) {
        _path = std::move(other._path);
        _size = other._size;
        _type = other._type;
        other._size = 0;
        other._type = ResourceType::File; // Default value
    }
    return *this;
}

// Getters
const std::string& Resource::getPath() const { return _path; }
size_t Resource::getSize() const { return _size; }
Resource::ResourceType Resource::getType() const { return _type; }

// Private functions
void Resource::calculateFileSize() {
    try {
        this->_size = std::filesystem::file_size(this->_path);
    } catch (const std::filesystem::filesystem_error& e) {
        this->_size = 0;
    }
}