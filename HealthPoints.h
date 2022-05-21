#ifndef MTM_EX3_HEALTHPOINTS_H
#define MTM_EX3_HEALTHPOINTS_H
class HealthPoints {
    private:
        int m_currentHealth;
        int m_maxHealth;
    public:
        explicit HealthPoints(int maxHealth = 100);
        class InvalidArgument{};

};

#endif //MTM_EX3_HEALTHPOINTS_H
