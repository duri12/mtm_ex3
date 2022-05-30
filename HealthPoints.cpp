#include "HealthPoints.h"
#include "iostream"
HealthPoints::HealthPoints(const HealthPoints& health2 )
{
    this->m_currentHealth = health2.m_currentHealth;
    this->m_maxHealth = health2.m_maxHealth;
}

const HealthPoints& HealthPoints::operator+=(int num)
{
    if(this->m_currentHealth + num <= 0)
    {
        this->m_currentHealth =0 ;
    }
    else if (this->m_currentHealth + num >= this->m_maxHealth)
    {
        this->m_currentHealth =this->m_maxHealth;
    }
    else
    {
        this->m_currentHealth += num;
    }
    return *this ;
}

HealthPoints operator+( const HealthPoints& HP,int num )
{
    HealthPoints newHP = HP;
    newHP += num;
    return newHP ;
}

HealthPoints operator-(const HealthPoints& HP , int num )
{
    HealthPoints newHP = HP;
    newHP -= num;
    return newHP ;
}
const HealthPoints& HealthPoints::operator-=(int num)
{
    if(this->m_currentHealth - num <= 0)
    {
        this->m_currentHealth =0 ;
        return *this ;
    }
    else if (this->m_currentHealth - num >= this->m_maxHealth)
    {
        this->m_currentHealth =this->m_maxHealth;
        return *this ;
    }
    else
    {
        this->m_currentHealth -= num;
    }
    return *this ;
}

const HealthPoints& HealthPoints::operator=(const HealthPoints& HP)
{
    if(this == &HP)
    {
        return *this;
    }
    this->m_currentHealth = HP.m_currentHealth;
    this->m_maxHealth = HP.m_maxHealth;
    return *this;
}
bool operator!=(const HealthPoints& HP1 ,const HealthPoints& HP2)
{
    return !(HP1==HP2);
}
bool operator==(const HealthPoints& HP1 ,const HealthPoints& HP2 )
{
    return HP1.m_currentHealth == HP2.m_currentHealth;
}
bool operator<=(const HealthPoints& HP1 ,const HealthPoints& HP2)
{
    return ((HP1==HP2)||(HP1 < HP2));
}
bool operator<(const HealthPoints& HP1 ,const HealthPoints& HP2)
{
    return HP1.m_currentHealth < HP2.m_currentHealth;
}
bool operator>=(const HealthPoints& HP1 ,const HealthPoints& HP2)
{
    return !(HP1 < HP2);
}
bool operator>(const HealthPoints& HP1 ,const HealthPoints& HP2)
{
    return !(HP1 < HP2) && !(HP1==HP2);
}
std::ostream & operator<<(std::ostream &os , const HealthPoints &other)
{
    os << other.m_currentHealth << "(" << other.m_maxHealth << ")";
    return os;
}

HealthPoints::HealthPoints(int maxHealth)
{
    if(maxHealth <= 0)
    {
        throw(HealthPoints::InvalidArgument());
    }
    this->m_maxHealth = maxHealth;
    this->m_currentHealth = maxHealth;
}

HealthPoints operator-(int num , const HealthPoints& HP)
{
    HealthPoints newHP = HP;
    newHP -= num;
    return newHP ;

}
HealthPoints operator+(int num, const HealthPoints &HP)
{
    HealthPoints newHP = HP;
    newHP += num;
    return newHP ;
}

