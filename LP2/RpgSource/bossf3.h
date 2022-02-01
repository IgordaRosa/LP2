#ifndef BOSSF3_H
#define BOSSF3_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Bossf3: public QObject, public QGraphicsPixmapItem
{
 Q_OBJECT
public:
 Bossf3();
 QTimer *DMG;
 QTimer *skill;
 void bossDMG();
 void LancarSkill();
 int getSkillCD();

public slots:
 void move();
 void BossDMG();
 void BossS();
private:
 int sprint = 0;
 int temp = 0;
 int temps = 0;
 int posS = 0;
 int skillCD = 0;
};

#endif // BOSSF3_H
