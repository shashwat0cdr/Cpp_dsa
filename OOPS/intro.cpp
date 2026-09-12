#include <iostream>
#include <cstring>
using namespace std;

class Hero
{
    // properties
private:
    int health;

public:
    char level;
    char *name;
    static int timeToComplete;
    void print()
    {
        cout << endl;
        cout << "Name: " << this->name << endl;
        cout << "Level" << this->level << endl;
        cout << "Health" << this->health << endl;
        cout << endl;
    }
    // default constructor
    Hero()
    {
        name = new char[100];
        cout << "Constructor called" << endl;
    }

    // parameterized constructor
    Hero(int health, char level)
    {
        cout << "this -> " << this << endl;
        this->health = health;
        this->level = level;
    }

    // copy constructor
    Hero(Hero &temp)
    {
        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    int getHealth()
    {
        return health;
    }
    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char ch)
    {
        level = ch;
    }
    void setName(char name[])
    {
        strcpy(this->name, name);
    }


    static int random(){    
        return timeToComplete;
    }
    // destructor
    ~Hero()
    {
        cout << "destructor bhai called" << endl;
    }
};

int Hero::timeToComplete = 5; // scope resolution parameter "::"

int main()
{
    
    cout << Hero :: random() << endl;
    
    // cout << Hero :: timeToComplete << endl;
    // Hero a;
    // cout << a.timeToComplete << endl;
    // Hero b;
    // b.timeToComplete = 10;
    // cout << a.timeToComplete << endl;
    // cout << b.timeToComplete << endl;

    // statically called object ke liye destructor automatically called hota hai
    // Hero a;
    // // dynamically called object ke liye destructor manually krna pdta hai
    // Hero *b = new Hero();
    // delete b;

    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[9] = "Shashwat";
    // hero1.setName(name);
    // hero1.print();

    // Hero S(10, 'A');
    // S.print();
    // Hero R(S);
    // R.print();

    // // object creation
    // Hero ramesh(10, 'A');
    // cout << "address of ramesh: " << &ramesh << endl;
    // ramesh.getHealth();
    // // dynamically
    // Hero *h2 = new Hero;

    /*
    // static allocation
    Hero ramesh;
    ramesh.setHealth(80);
    ramesh.setLevel('C');
    cout << "level is: " << ramesh.level << endl;
    cout << "health is: " << ramesh.getHealth() << endl;
    // dynamic allocation
    Hero *b = new Hero;
    b ->level = 'B';
    b ->setHealth(70);
    cout << "level is: " << (*b).level << endl;
    cout << "health is: " << (*b).getHealth() << endl;
    cout << "level is: " << b ->level << endl;
    cout << "health is: " << b ->getHealth() << endl;
    // ramesh.setHealth(70);
    // ramesh.setLevel('A');
    // cout << "ramesh health is: " << ramesh.getHealth() << endl;
    // cout << "ramesh level is: " << ramesh.getLevel() << endl;
    // ramesh.health = 70;
    // ramesh.level = 'A';
    // cout << "health is: " << ramesh.health << endl;
    // cout << "level is: " << ramesh.level << endl;
    // cout << "Size of h1: " << sizeof(h1) << endl;
*/
}