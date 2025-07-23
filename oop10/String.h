#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommonDecl.h"

class String{
    private:
        char *str;
        int len;
    public:
        String();
        String(char *s);
        String(const String &s);
        String& operator=(const String &s);
        String operator+(const String &s);
        String& operator+=(const String &s);
        bool operator==(const String &s);
        ~String();
    friend ostream& operator<<(ostream& os,const String &s);
    friend istream& operator>>(istream& is, String &s);
};
#endif