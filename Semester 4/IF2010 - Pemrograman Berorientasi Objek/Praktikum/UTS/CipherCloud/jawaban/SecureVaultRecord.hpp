#ifndef SECURE_VAULT_RECORD_HPP
#define SECURE_VAULT_RECORD_HPP

#include "BaseRecord.hpp"

class SecureVaultRecord : private BaseRecord {
    public:
    SecureVaultRecord(std::string author, int key) : BaseRecord(author, key) {}
};

#endif
