#ifndef MTM_EX3_HEALTHPOINTS_H
#define MTM_EX3_HEALTHPOINTS_H
#include <iostream>

class HealthPoints {
    private:
        int m_currentHealth;
        int m_maxHealth;
    public:
        HealthPoints(int maxHealth = 100);
        ~HealthPoints() = default;
        HealthPoints(const HealthPoints& );
        class InvalidArgument{}; // a subclass for error handling

        operator int() const;
        const HealthPoints& operator+(int num);
        const HealthPoints& operator+=(int num);
        const HealthPoints& operator-(int num);
        const HealthPoints& operator-=(int num);
        bool operator==(const HealthPoints&) const;
        bool operator!=(const HealthPoints&) const;
        bool operator<=(const HealthPoints&) const;
        bool operator<(const HealthPoints&) const;
        bool operator>=(const HealthPoints&) const;
        bool operator>(const HealthPoints&) const;
        friend std::ostream& operator<<(std::ostream& os , const HealthPoints& points);
};

#endif //MTM_EX3_HEALTHPOINTS_H
