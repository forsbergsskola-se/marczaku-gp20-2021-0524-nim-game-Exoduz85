#pragma once
#include <string>

class StringToIntChecker final{
public:
    static bool IsIntOrNot(const string & myParam)
    {
        try
        {
            stoi(myParam);
        }
        catch (const std::exception&)
        {
            return false;
        }
        return true;
    }
};