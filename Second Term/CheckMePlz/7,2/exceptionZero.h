class ExceptionZero {
public:
    ExceptionZero(const char *msg): name(msg) {}
    void show(){
        std::cout<< name << std::endl;
    }
private:
    const char *name;
};
