#pragma once
#include <vector>
#include <typeinfo>
#include <cstring>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <thread>
#include <memory>
class Enemy; 

template <class T>
class Container : public std::vector<T>{
public:
	void add_with_action(T effect, Enemy& en){
		this->push_back(effect);
		effect->action(en);
		//std::thread interval(&Container<T>::expired, this, effect, std::ref(en));
		//interval.detach();
	}
	void expired(T effect, Enemy& en){
		typename std::vector<T>::iterator it = std::find(this->begin(), this->end(), effect);
		effect->expired(en);
		this->erase(it);
	}
	void tick(Enemy& en){
		for(typename std::vector<T>::iterator it = this->begin(); it != this->end();){
			if((*it)->tick(std::ref(en))){
				expired((*it), std::ref(en));
			}
			else{
				it++;
			}
		}
	}
};