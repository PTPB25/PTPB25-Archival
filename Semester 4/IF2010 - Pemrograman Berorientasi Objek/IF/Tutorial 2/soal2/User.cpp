#include "User.hpp"

User::User(const string &username, const string &password) : username(username), password(password) {}

User::~User() {}

string User::getUsername() const
{
  return username;
}

bool User::checkPassword(const string &password) const
{
  return this->password == password;
}

bool User::isAdmin() const
{
  return false; // RegularUser default bukan admin
}