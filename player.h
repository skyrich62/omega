/**
The MIT License (MIT)

Copyright (c) 2020 Rich Newman

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <memory>
#include <list>

class Object;

struct position
{
   int x;
   int y;
};

class Player
{
public:
    struct stats {
        unsigned int str;
        unsigned int con;
        unsigned int dex;
        unsigned int agi;
        unsigned int iq;
        unsigned int pow;
        unsigned int hp;
        unsigned int mana;
        unsigned int weight;
    };
private:
    stats cur;
    stats max;
    long  xp;
    int   level;
    int   hit;
    int   dmg;
    int   absorbtion;
    int   speed;
    int   click;
    int   defense;
    int   food;
    int   alignment;
    long  cash;
    int   patron;
    int   birthday;
    position pos;
    position sanctuary;
    std::string name;
    std::list<std::unique_ptr<Object>> pack;
};
