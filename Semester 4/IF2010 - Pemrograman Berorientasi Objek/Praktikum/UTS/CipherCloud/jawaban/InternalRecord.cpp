#include "InternalRecord.hpp"

int InternalRecord::peekSecurity() const{
    return calculateClearance() * 2;
}