#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include <string>
#include <iostream>

class Activity {
protected:
    std::string name;
public:
    Activity(const std::string& activityName) : name(activityName) {}
    
    virtual ~Activity()=default;

    virtual int complete() = 0;
    virtual std::string getStatus() const = 0;
    
    std::string getName() const {
        return name;
    }
};

#endif