#ifndef DAILYHABIT_HPP
#define DAILYHABIT_HPP

#include "Activity.hpp"

class DailyHabit : public Activity {
private:
    int streak;
public:
    DailyHabit(const std::string& name);
    
    int complete() override;
    std::string getStatus() const override;

    ~DailyHabit() override;
};

#endif