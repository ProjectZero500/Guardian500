#include "entropy.h"
#include "exceptions.h"
#include "consts.h"

double calculateFileEntropy(const Resource& fileResource) {
    const std::string& filePath = fileResource.getPath();
    std::ifstream fileStream(filePath, std::ios::binary);

    if (fileStream.fail()) {
        std::cerr << "Failed to calculate entropy for : " << filePath << std::endl;
        throw FailedCalculateFileEntropyException();
    }

    std::array<size_t, BYTE_RANGE_SIZE> frequencyArray = {0};
    unsigned char byte_value;
    size_t totalBytes = 0;

    while (fileStream.read(reinterpret_cast<char*>(&byte_value), sizeof(unsigned char))) {
        frequencyArray[byte_value]++;
        totalBytes++;
    }

    fileStream.close();

    if (totalBytes == 0) {
        std::cerr << "File is empty: " << filePath << std::endl;
        throw FailedCalculateFileEntropyException();
    }

    double entropy = 0.0;
    for(const auto& byteOccurences: frequencyArray){
        if(!byteOccurences){
            continue;
        }
        double byteFrequency = static_cast<double>(byteOccurences) / totalBytes;
        entropy -= byteFrequency * std::log2(byteFrequency);
    }

    return entropy;
}