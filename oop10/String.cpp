#include "String.h"
#include <cstring>

String::String(){
    str = NULL;
    len = 0;
}

String::String(char *s){

    len = strlen(s)+1;
    str = new char[len];
    strcpy(str,s);
}

String::String(const String &s){
    this->len = s.len;
    this->str = new char[len];
    strcpy(this->str,s.str);
}

String& String::operator=(const String &s){
    if(str!=NULL) delete []str;
    this->len = s.len;
    this->str = new char[len];
    strcpy(this->str,s.str);
    return *this;
}

String String::operator+(const String &s){
    char *temp = new char[len+s.len-1];
    strcpy(temp,str);
    strcat(temp,s.str);
    String ret = String(temp);
    delete []temp;
    return ret;
}

String& String::operator+=(const String &s){
    len += s.len-1;
    char *temp = new char[len];
    strcpy(temp,str);
    strcat(temp,s.str);
    if(str!=NULL) delete []str;
    str = temp;
    return *this;
}

bool String::operator==(const String &s){
    return strcmp(str,s.str) ? false : true;
}

ostream& operator<<(ostream& os,const String &s){
    os << s.str;
    return os;
}

istream& operator>>(istream& is, String &s){
    char temp[100];
    is >> temp;
    s = String(temp);
    return is;
}

String::~String(){
    delete []str;
}