#include <iostream>
#include "entropy.h"
#include "resource.h"

const std::string FILE_PATH = "src/entropy.cpp";

int main() {
    Resource::ResourceType type = Resource::ResourceType::File;
    Resource fileResource(FILE_PATH, type);
    
    double entropy = calculateFileEntropy(fileResource);
    if (entropy >= 0.0) {
        std::cout << "Entropy of the file " << fileResource.getPath() << " is "
            << entropy << std::endl;
    }
    return 0;
}