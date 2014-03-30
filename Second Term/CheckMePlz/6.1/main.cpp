/**
@brief testing 2 classes. Destructor will have not worked.
*/
#include <iostream>
#include <cstdlib>

using namespace std;

class InstanceFirst{
public:
    InstanceFirst() {
        cout << "constructor Instance First\n";
    }
    ~InstanceFirst() {
        cout << "destructor Instance First\n";
    }
};

class InstanceSecond {
public:
    InstanceSecond() {
        cout << "constructor Instance Second\n";
    }
    ~InstanceSecond() {
        cout << "destructor Instance Second\n";
    }
};

class MyError
{
public:
   MyError(const char *msg = 0) : mData(msg) {}

private:
   const char * const mData;
};

int main()
{
    try {
        InstanceFirst first;
        InstanceSecond second;
        throw MyError("name");
    }
    catch (MyError &) {
        cout << "error!\nexception found!\n";
        return -1;
    }
}
