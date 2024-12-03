#include <iostream>
#include "entropy.h"
#include "resource.h"

int main() {
    std::string path = "/home/shavit/Projects/Guardian500/src/entropy.cpp";
    Resource::ResourceType type = Resource::ResourceType::File;
    Resource fileResource(path, type);
    
    double entropy = calculateEntropy(fileResource);
    if (entropy >= 0.0) {
        std::cout << "Entropy of the file " << fileResource.getPath() << " is "
            << entropy << std::endl;
    }
    return 0;
}