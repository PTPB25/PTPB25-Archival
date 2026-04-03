#ifndef BANNER_HPP
#define BANNER_HPP

#include <string>

class Banner {
private:
    std::string name;
    int expiryDate; // Format: YYYYMMDD, misal: 20261231 (Asumsi format selalu benar)
    int itemCount;

    void validateExpiryDate(int currentDate) const;
    void validateItemAvailability() const;

public:
    Banner(std::string name, int expiryDate, int itemCount);

    std::string getName() const;
    int getExpiryDate() const;
    int getItemCount() const;

    void pullItem(int currentDate);
};

#endif
