#ifndef MTM_EX3_HEALTHPOINTS_H
#define MTM_EX3_HEALTHPOINTS_H
#include <iostream>

class HealthPoints
{
    private:
        int m_currentHealth;
        int m_maxHealth;
        friend bool operator==(const HealthPoints& HP1 ,const HealthPoints& HP2 );
        friend bool operator<(const HealthPoints& HP1 ,const HealthPoints& HP2);
        friend std::ostream& operator<<(std::ostream& os , const HealthPoints& points);
    public:
        HealthPoints(int maxHealth = 100);
        ~HealthPoints() = default;
        HealthPoints(const HealthPoints& );
        class InvalidArgument{};
        const HealthPoints& operator=(const HealthPoints&);
        const HealthPoints& operator+=(int num);
        const HealthPoints& operator-=(int num);


};

HealthPoints operator-( const HealthPoints& HP , int  num);
HealthPoints operator+( const HealthPoints& HP , int  num);
HealthPoints operator+(int num , const HealthPoints& HP);
HealthPoints operator-(int num , const HealthPoints& HP);
bool operator==(const HealthPoints& HP1 ,const HealthPoints& HP2 );
bool operator!=(const HealthPoints& HP1 ,const HealthPoints& HP2);
bool operator<=(const HealthPoints& HP1 ,const HealthPoints& HP2);
bool operator<(const HealthPoints& HP1 ,const HealthPoints& HP2);
bool operator>=(const HealthPoints& HP1 ,const HealthPoints& HP2);
bool operator>(const HealthPoints& HP1 ,const HealthPoints& HP2);
#endif //MTM_EX3_HEALTHPOINTS_H
