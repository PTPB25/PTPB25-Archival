#include "MesinHitungException.hpp"
using namespace std;

MesinHitungException::MesinHitungException(const string& message)
    : message(message) {}

const char* MesinHitungException::what() const noexcept {
    return message.c_str();
}

InvalidTokenException::InvalidTokenException(const string& token)
    : MesinHitungException("Token tidak valid: " + token), token_(token) {}

string InvalidTokenException::getToken() const {
    return token_;
}

InsufficientOperandException::InsufficientOperandException()
    : MesinHitungException("Operand tidak mencukupi untuk operasi.") {}

DivisionByZeroException::DivisionByZeroException()
    : MesinHitungException("Pembagian dengan nol tidak diperbolehkan.") {}

InvalidExpressionException::InvalidExpressionException()
    : MesinHitungException("Ekspresi tidak valid.") {}