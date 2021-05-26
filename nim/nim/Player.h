#pragma once
#include <iostream>
#include <string>
using namespace std;

 class Player{
 private:
	 string name = "";
	 int score = 0;
 public:
	 void setName(string n){
		 this->name = n;
	 };
	 string getName() {
		 return this->name;
	 };
	 void setScore(int s) {
		 this->score = s;
	 };
	 int getScore() {
		 return this->score;
	 };
};