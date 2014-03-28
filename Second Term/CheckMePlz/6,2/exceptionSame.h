#pragma once
class UniqueList;

class ExceptionSame {
//friend class UniqueList;
public:
static void throwExceptionSame() {
    throw ExceptionSame();
}
};
