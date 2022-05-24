#include "HealthPoints.h"
#include "iostream"
HealthPoints::HealthPoints(const HealthPoints& health2 ){
    this->m_currentHealth = health2.m_currentHealth;
    this->m_maxHealth = health2.m_maxHealth;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& h) {
    os << h.m_currentHealth << "(" << h.m_maxHealth << ")";
    return os;
}

const HealthPoints& Healthpoints::operator+=(int num) {
    if(this->m_currentHealth + num >= 0)
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

const HealthPoints& Healthpoints::operator+(int num) {
    HealthPoints* h = new HealthPoints::HealthPoints(this);
    return *h +=num;
}

const HealthPoints& HealthPoints::operator-(int num){
    if(this->m_currentHealth - num >= 0)
    {
        this->m_currentHealth =0 ;
    }
    else if (this->m_currentHealth - num >= this->m_maxHealth)
    {
        this->m_currentHealth =this->m_maxHealth;
    }
    else
    {
        this->m_currentHealth -= num;
    }
    return *this ;
}
const HealthPoints& HealthPoints::operator-=(int num){
    return *(this - num) ;
}

bool HealthPoints::operator!=(const HealthPoints& other) const{
    return this->m_currentHealth != other.m_currentHealth;
}
bool HealthPoints::operator==(const HealthPoints& other) const{
    return this->m_currentHealth == other.m_currentHealth;
}
bool HealthPoints::operator<=(const HealthPoints& other) const{
    return this->m_currentHealth <= other.m_currentHealth;
}
bool HealthPoints::operator<(const HealthPoints& other) const{
    return this->m_currentHealth < other.m_currentHealth;
}
bool HealthPoints::operator>=(const HealthPoints& other) const{
    return this->m_currentHealth >= other.m_currentHealth;
}
bool HealthPoints::operator>(const HealthPoints& other) const{
    return this->m_currentHealth > other.m_currentHealth;
}