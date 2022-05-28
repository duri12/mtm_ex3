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

const HealthPoints& HealthPoints::operator+(int num)
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

const HealthPoints& HealthPoints::operator-(int num)
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
    return *this;
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

const HealthPoints& HealthPoints::operator=(const HealthPoints& HP){
    if(this == &HP){
        return *this;
    }
    this->m_currentHealth = HP.m_currentHealth;
    this->m_maxHealth = HP.m_maxHealth;
    return *this;
}
bool HealthPoints::operator!=(const HealthPoints& other) const
{
    return this->m_currentHealth != other.m_currentHealth;
}
bool HealthPoints::operator==(const HealthPoints& other) const
{
    return this->m_currentHealth == other.m_currentHealth;
}
bool HealthPoints::operator<=(const HealthPoints& other) const
{
    return this->m_currentHealth <= other.m_currentHealth;
}
bool HealthPoints::operator<(const HealthPoints& other) const
{
    return this->m_currentHealth < other.m_currentHealth;
}
bool HealthPoints::operator>=(const HealthPoints& other) const
{
    return this->m_currentHealth >= other.m_currentHealth;
}
bool HealthPoints::operator>(const HealthPoints& other) const
{
    return this->m_currentHealth > other.m_currentHealth;
}
std::ostream & operator<<(std::ostream &os , const HealthPoints &other)
{
    os << other.m_currentHealth << "(" << other.m_maxHealth << ")";
    return os;
}
HealthPoints::operator int() const{
    return this->m_currentHealth;
}
HealthPoints::HealthPoints(int maxHealth) {
    if(maxHealth < 0){
        throw(HealthPoints::InvalidArgument());
    }
    this->m_maxHealth = maxHealth;
    this->m_currentHealth = maxHealth;
}

const HealthPoints& operator-(int num , const HealthPoints& HP){
    HealthPoints* newHP = new HealthPoints(HP);
    if(newHP->m_currentHealth - num <= 0)
    {
        newHP->m_currentHealth =0 ;
        return *newHP ;
    }
    else if (newHP->m_currentHealth - num >= newHP->m_maxHealth)
    {
        newHP->m_currentHealth =newHP->m_maxHealth;
        return *newHP ;
    }
    else
    {
        newHP->m_currentHealth -= num;
    }
    return *newHP;

}
const HealthPoints& operator+(int num, const HealthPoints &HP) {
    HealthPoints* newHP = new HealthPoints(HP);
    if(newHP->m_currentHealth + num <= 0)
    {
        newHP->m_currentHealth = 0 ;
    }
    else if (newHP->m_currentHealth + num >= newHP->m_maxHealth)
    {
        newHP->m_currentHealth =newHP->m_maxHealth;
    }
    else
    {
        newHP->m_currentHealth += num;
    }
    return *newHP ;
}

