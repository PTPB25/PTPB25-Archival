#include "VaultException.hpp"

VaultException::VaultException(int code, string type): errorCode(code), errorMessage(type) {}
int VaultException::getErrorCode() {
    return errorCode;
}
string VaultException::getErrorMessage() {
    return errorMessage;
}
const char* VaultException::what() const noexcept {
    return errorMessage.c_str();
}

EmptyVaultException::EmptyVaultException(): VaultException(1, "Error: Vault kosong") {}
FullVaultException::FullVaultException(size_t capacity): VaultException(2, "Error: Vault sudah penuh"), capacity(capacity) {}
size_t FullVaultException::getCapacity() const {
    return capacity;
}
InvalidRelicException::InvalidRelicException(string name, int type): VaultException(3, "Error: Nama relic tidak valid"), name(name) {
    if(type == 1) errorMessage += " - nama terlalu pendek";
    else errorMessage += " - mengandung angka";
}
string InvalidRelicException::getRelicName() const {
    return name;
}