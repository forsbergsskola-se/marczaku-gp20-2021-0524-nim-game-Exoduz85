#pragma once
#include <iostream>
using namespace std;

 class Player{
 private:
	 string name;
	 int score = 0;
 public:
	 void setName(string n){
		 this->name = n;
	 };
	 string getName() const
	 {
		 return this->name;
	 };
	 void setScore(int s) {
		 this->score += s;
	 };
	 int getScore() const
	 {
		 return this->score;
	 };
};