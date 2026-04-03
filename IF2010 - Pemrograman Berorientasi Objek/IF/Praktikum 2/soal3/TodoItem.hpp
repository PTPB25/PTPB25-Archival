#ifndef TODOITEM_HPP
#define TODOITEM_HPP

#include "Activity.hpp"

class TodoItem : public Activity {
private:
    bool isDone;
public:
    TodoItem(const std::string& name);
    
    // Override metode dari base class
    int complete() override;
    std::string getStatus() const override;

    ~TodoItem() override;
};

#endif