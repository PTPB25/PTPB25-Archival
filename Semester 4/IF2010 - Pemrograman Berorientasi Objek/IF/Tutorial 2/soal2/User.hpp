#ifndef __USER_HPP__
#define __USER_HPP__

#include <string>
using namespace std;

class User
{
protected:
  string username;
  string password;

public:
  User(const string &username, const string &password);
  virtual ~User();

  string getUsername() const;
  bool checkPassword(const string &password) const;

  virtual bool isAdmin() const; // Default false, hanya akan override oleh AdminUser
};

#endif