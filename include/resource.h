#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <utility>

class Resource {
public:
    enum class ResourceType {
        File,
        Process
    };

    // Constructor
    Resource(std::string path, ResourceType type);

    // Destructor
    ~Resource();

    // Copy constructor
    Resource(const Resource& other);

    // Copy assignment operator
    Resource& operator=(const Resource& other);

    // Move constructor
    Resource(Resource&& other) noexcept;

    // Move assignment operator
    Resource& operator=(Resource&& other) noexcept;

    // Getters
    const std::string& getPath() const;
    size_t getSize() const;
    ResourceType getType() const;

private:
    std::string _path;
    size_t _size;
    ResourceType _type;

    size_t calculateFileSize();
};

#endif // RESOURCE_H
