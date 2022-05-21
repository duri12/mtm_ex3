#ifndef MTM_EX3_HEALTHPOINTS_H
#define MTM_EX3_HEALTHPOINTS_H
class HealthPoints {
    private:
        int m_currentHealth;
        int m_maxHealth;
    public:
        explicit HealthPoints(int maxHealth = 100);
        ~HealthPoints() = default;
        HealthPoints(const HealthPoints& );
        class InvalidArgument{};
        const HealthPoints* operator+(int num);
        const HealthPoints* operator+=(int num);
        const HealthPoints* operator-(int num);
        const HealthPoints* operator-=(int num);
};

#endif //MTM_EX3_HEALTHPOINTS_H
