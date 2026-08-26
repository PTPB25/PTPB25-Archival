#ifndef BASE_RECORD_HPP
#define BASE_RECORD_HPP

#include <string>

class BaseRecord {
protected:
    std::string author;

private:
    int encryptionKey;

public:
    virtual ~BaseRecord() = default;
    BaseRecord(std::string author, int key) : author(author), encryptionKey(key) {}

    int getKey() const { return encryptionKey; }
    virtual int calculateClearance() const { return encryptionKey % 10; }
};

#endif
