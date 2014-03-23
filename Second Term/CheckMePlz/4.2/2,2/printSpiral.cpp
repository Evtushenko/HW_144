#include "printSpiral.h"

using namespace std;

PrintSpiral:: PrintSpiral() {
    for (int i = amountElements / 2; i >= 0; i--) {
        maxDistCentr[amountElements / 2 - i] = dist(i, i);
    }
}

PrintSpiral:: ~PrintSpiral() {
}

double PrintSpiral::dist(int Xa, int Ya) const{
    double midDistance = 0;
    midDistance = sqrt((amountElements / 2 - Xa) * (amountElements / 2 - Xa) + (amountElements / 2 - Ya) * (amountElements / 2 - Ya));
    return midDistance;
}

void PrintSpiral::printIn() const {
    cout << "Matrix from file:\n";
    for (int i = 0; i < amountElements ; i++ ) {
        for (int j = 0; j < amountElements; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int PrintSpiral::readFromFile() {
    ifstream inFile;
    char nameFile[]="matrix.txt";
    inFile.open(nameFile, ios::in);
    if (!(inFile.is_open())) {
        cout << "Where is your file ???" << endl;
        return 1;
    }
    for (int i = 0; i < amountElements; i++) {
        for (int j = 0; j < amountElements; j++) {
            inFile >> matrix[i][j];
        }
    }
    inFile.close();
    //this->printIn();
    return -1;
}

int *PrintSpiral::returnMatrix() {
    int *output = new int[amountElements*amountElements];
    int counter = 0;
    for (int i = 0; i < amountElements; i++)
        for (int j = 0; j < amountElements; j++) {
            output[counter++] = matrix[i][j];
        }
    return output;
}

int *PrintSpiral::returnSpiralOrder() {
    return queuePrinting;
}

void PrintSpiral::spiralOrder() {
    int static Xc = amountElements/2;
    int static Yc = amountElements/2;
    int static textPosition = 0;
    int static raz = 1;
    if (raz ==  1)
        queuePrinting[textPosition++] = matrix[Xc][Yc];
    Yc--;
    queuePrinting[textPosition++] = matrix[Xc][Yc];
    while (dist(Xc, Yc) < maxDistCentr[raz]) {
        Xc--;
        queuePrinting[textPosition++] = matrix[Xc][Yc];
    }
    Yc++;
    queuePrinting[textPosition++] = matrix[Xc][Yc];
    while (dist(Xc, Yc) < maxDistCentr[raz]) {
        Yc++;
        queuePrinting[textPosition++] = matrix[Xc][Yc];
    }
    Xc++;
    queuePrinting[textPosition++] = matrix[Xc][Yc];
    while (dist(Xc, Yc) < maxDistCentr[raz]) {
        Xc++;
        queuePrinting[textPosition++] = matrix[Xc][Yc];
    }
    Yc--;
    queuePrinting[textPosition++] = matrix[Xc][Yc];
    while (dist(Xc, Yc) < maxDistCentr[raz]) {
        Yc--;
        queuePrinting[textPosition++] = matrix[Xc][Yc];
    }
    raz++;
    if (raz <= amountElements/2)
        spiralOrder();
    else {
        Xc = amountElements/2;
        Yc = amountElements/2;
        textPosition = 0;
        raz = 1;
    }
}
