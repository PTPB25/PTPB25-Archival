#include "AdminUser.hpp"

AdminUser::AdminUser(const string &username, const string &password) : User(username, password) {}

bool AdminUser::isAdmin() const
{
  return true; // Override untuk admin
}