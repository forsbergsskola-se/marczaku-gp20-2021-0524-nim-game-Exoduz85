#pragma once
#include <string>
using namespace std;

class ExtensionMethods final{
public:
    static bool IsIntOrNot(const string & myParam)    {
        try        {
            stoi(myParam);
        }         catch(const exception &)        {
            return false;
        }
        return true;
    }
    static bool IsInRange(const int & myParam, int rangeStart, int rangeEnd){
        if(myParam < rangeStart || myParam > rangeEnd) return false;
        return true;
    }
};