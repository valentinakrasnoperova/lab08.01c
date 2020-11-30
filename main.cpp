#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "func.h"
using namespace std;


char* Change (char* s)
{
    char *t = new char[strlen (s)];
    char *p;
    int pos1 = 0, pos2 = 0;
    *t = 0;
    while (p = strchr (s + pos1, 'w')){
        if (s[p - s + 1] == 'h' && s[p - s + 2] == 'i' && s[p - s + 3] == 'l' && s[p - s + 4] == 'e')
        {
            pos2 = p - s + 5;
            strncat (t, s + pos1, pos2 - pos1 - 5);
            strcat (t, "**");
            pos1 = pos2;
        }
    }
    strcat (t, s + pos1);
    strcpy (s, t);
    return t;
}

int main ()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Check (str) << " 'while'" << endl;
    char *dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}