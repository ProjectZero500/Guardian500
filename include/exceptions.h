#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class GuardianException : public std::exception {};

class ScannerException : public GuardianException {};

class EntropyException : public ScannerException {};

class FailedCalculateFileEntropyException : public EntropyException {};

#endif //EXCEPTIONS_H