#pragma once

// тестовый класс
class Human {
public:
    Human() {}
    Human(int a, int b): age(a), power(b) {}
    ~Human() {}
    int age;
    short int power;
};
