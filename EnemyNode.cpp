/* 
 * File:   EnemyNode.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:26 PM
 */

#include "EnemyNode.h"

EnemyNode::EnemyNode()
{
}

EnemyNode::EnemyNode(const EnemyNode& orig)
{
}

EnemyNode::~EnemyNode()
{
}

void EnemyNode::SetTime(int time)
{
        this->time = time;
}

int EnemyNode::GetTime() const
{
        return time;
}

void EnemyNode::SetNext(EnemyNode* next)
{
        this->next = next;
}

EnemyNode* EnemyNode::GetNext() const
{
        return next;
}

void EnemyNode::SetEnemy(Enemy* enemy)
{
        this->enemy = enemy;
}

Enemy* EnemyNode::GetEnemy() const
{
        return enemy;
}

