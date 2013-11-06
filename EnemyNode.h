#ifndef ENEMYNODE_H
#define	ENEMYNODE_H

class EnemyNode{
public:
    EnemyNode();
    EnemyNode(const EnemyNode& orig);
    virtual ~EnemyNode();
    Enemy* enemy;
    EnemyNode* next;
    int time;
};

#endif	/* ENEMYNODE_H */

