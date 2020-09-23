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

#include <functional>
#include <memory>
#include <string>
#include <vector>

struct Symbol
{
    char display;
    char attributes;
};

class Object
{
public:
    using Ptr = std::unique_ptr<Object>;
    using Vec = std::vector<Object>;

    enum Uniqueness { COMMON, UNMADE, MAKE, TAKEN };

    static Ptr make_random(int itemLevel);
    static Ptr make_food(int quality);
    static Ptr make_scroll(int which);
    static Ptr make_potion(int which);
    static Ptr make_weapon(int which);
    static Ptr make_armor(int which);
    static Ptr make_shield(int which);
    static Ptr make_stick(int which);
    static Ptr make_boots(int which);
    static Ptr make_cloak(int which);
    static Ptr make_ring(int which);
    static Ptr make_artifact(int which);
    static Ptr make_cash(int value);

    static void init(bool reset);

    Ptr clone();

    Object(int id_,
           int weight_,
           int plus_,
           int charge_,
           int hit_,
           int aux_,
           int fragility_,
           long baseValue_,
           int  blessing_,
           unsigned char type_,
           unsigned char uniqueness_,
           std::function<void(Object)> use_f_,
           unsigned char level_,
           Symbol symbol_,
           const std::string &name_) :
        name(name_),
        use_f(use_f_),
        symbol(symbol_),
        baseValue(baseValue_),
        id(id_),
        weight(weight_),
        plus(plus_),
        charge(charge_),
        dmg(0),
        hit(hit_),
        aux(aux_),
        number(1),
        fragility(fragility_),
        blessing(blessing_),
        level(level_),
        known(0),
        used(0),
        type(type_),
        uniqueness(uniqueness_)
    { }

    Object(int id_,
           int weight_,
           int plus_,
           int charge_,
           int hit_,
           int aux_,
           int fragility_,
           long baseValue_,
           int  blessing_,
           unsigned char type_,
           unsigned char uniqueness_,
           std::function<void(Object)> use_f_,
           unsigned char level_,
           Symbol symbol_,
           const std::string &name_,
           const std::string &true_name_) :
        Object(id_, weight_, plus_, charge_, hit_, aux_, fragility_,
               baseValue_, blessing_, type_, uniqueness_, use_f_,
               level_, symbol_, name_)
        
        { 
            true_name = true_name_;
        }

    Object(int id_,
           int weight_,
           int plus_,
           int charge_,
           int hit_,
           int aux_,
           int fragility_,
           long baseValue_,
           int  blessing_,
           unsigned char type_,
           unsigned char uniqueness_,
           std::function<void(Object)> use_f_,
           unsigned char level_,
           Symbol symbol_,
           const std::string &name_,
           const std::string &true_name_,
           const std::string &cursed_name_) :
        Object(id_, weight_, plus_, charge_, hit_, aux_, fragility_,
               baseValue_, blessing_, type_, uniqueness_, use_f_,
               level_, symbol_, name, true_name_)
        { 
            cursed_name = cursed_name_;
        }
        
private:
    std::string           name;
    std::string           true_name;
    std::string           cursed_name;
    std::function<void(Object)> use_f;
    Symbol                symbol;
    long                  baseValue;
    int                   id;
    int                   weight;
    int                   plus;
    int                   charge;
    int                   dmg;
    int                   hit;
    int                   aux;
    int                   number;
    int                   fragility;
    int                   blessing;
    unsigned int          level;
    unsigned int          known:1;
    unsigned int          used:1;
    unsigned char         type;
    unsigned char         uniqueness;

private:
    static Vec _commonItems;
    static Vec _scrolls;
    static Vec _potions;
    static Vec _sticks;
    static Vec _boots;
    static Vec _rings;
};
