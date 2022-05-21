#ifndef MTM_EX3_HEALTHPOINTS_H
#define MTM_EX3_HEALTHPOINTS_H
class HealthPoints {
    private:
        int m_currentHealth;
        int m_maxHealth;
    private:
        explicit HealthPoints(int maxHealth = 100);

};

#endif //MTM_EX3_HEALTHPOINTS_H
