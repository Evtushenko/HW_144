#pragma once

class ElementList {
public:
    ~ElementList() {
        delete[] data;
    }
    ElementList* next;
    char *data;
};
