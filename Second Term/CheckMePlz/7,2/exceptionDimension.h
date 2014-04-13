#include <iostream>

class ExceptionDimension {
public:
    ExceptionDimension(const char *msg): name(msg) { }
    void show(){
        std::cout<< name << std::endl;
    }

private:
    const char *name;
};
