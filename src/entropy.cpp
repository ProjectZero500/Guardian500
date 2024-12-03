#include "entropy.h"


double calculateEntropy(const Resource& resource) {
    std::string filePath = resource.getPath();
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return -1.0;
    }

    std::unordered_map<unsigned char, size_t> frequencyMap;
    unsigned char value;
    size_t totalBytes = 0;

    while (file.read(reinterpret_cast<char*>(&value), sizeof(unsigned char))) {
        frequencyMap[value]++;
        totalBytes++;
    }

    file.close();

    if (totalBytes == 0) {
        return 0.0;
    }

    double entropy = 0.0;
    for (const auto& pair : frequencyMap) {
        double frequency = static_cast<double>(pair.second) / totalBytes;
        entropy -= frequency * std::log2(frequency);
    }

    return entropy;
}