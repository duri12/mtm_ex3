#ifndef MTM_EX3_HEALTHPOINTS_H
#define MTM_EX3_HEALTHPOINTS_H
#include <iostream>

class HealthPoints {
    private:
        int m_currentHealth;
        int m_maxHealth;
    public:
        explicit HealthPoints(int maxHealth = 100);
        ~HealthPoints() = default;
        HealthPoints(const HealthPoints& );
        class InvalidArgument{}; // a subclass for error handling

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
        std::ostream& operator<<(std::ostream& os) const;
};

#endif //MTM_EX3_HEALTHPOINTS_H
