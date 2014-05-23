
class Cmp {
public:
    Cmp();
    virtual ~Cmp() = 0;
    virtual bool bigger() = 0;
    virtual bool smaller() = 0;
};


class CmpInt: public Cmp {
public:
    CmpInt() {}
    ~CmpInt() {}
    bool bigger(int a, int b) {
        if (a > b)
            return true;
        else
            return false;
    }
    bool smaller(int a, int b) {
        if (a < b)
            return true;
        else
            return false;
    }
};


Cmp::Cmp()
{

}

Cmp::~Cmp()
{

}
