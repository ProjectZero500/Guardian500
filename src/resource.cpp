#include "resource.h"
#include <iostream>
#include <filesystem>

// Constructor
Resource::Resource(std::string path, ResourceType type)
    : _path(std::move(path)), _type(type) {
        _size = calculateFileSize();
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
}

// Move assignment operator
Resource& Resource::operator=(Resource&& other) noexcept {
    if (this != &other) {
        _path = std::move(other._path);
        _size = other._size;
        _type = other._type;
    }
    return *this;
}

// Getters
const std::string& Resource::getPath() const { return _path; }
size_t Resource::getSize() const { return _size; }
Resource::ResourceType Resource::getType() const { return _type; }

// Private functions
/**
 * @brief Calculates the size of the file.
 * 
 * @return size_t The size of the file in bytes.
 * 
 * @throws std::filesystem::filesystem_error If an error occurs while accessing the file.
 */
size_t Resource::calculateFileSize() {
    return std::filesystem::file_size(this->_path);
}