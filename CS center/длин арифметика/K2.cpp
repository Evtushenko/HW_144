#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

// длинная арифметика в тч Карацуба

class Long{
    public:
        Long(string &);
        Long();
        void GetLong();
        Long operator=(int &);
        Long operator+(Long &);
        Long operator-(Long &);
        Long operator*(Long &);
        friend int max(int &,int &);
        friend Long Karatsuba(Long &,Long &);
    private:
        vector<int> arr;
};

int max(int &a,int &b){
    return (a>b)?a:b;
}

Long::Long(){
}

Long::Long(string &a){
    //  интовое число в векторе , цифры в обратном порядке
    for(int i = 0; i < a.size(); i++)
        arr.push_back(a[a.size()-1-i]-'0');
}

void Long::GetLong(){
    for(int i= arr.size()-1 ; i>=0 ; i-- )
        cout<< arr[i];
    cout<< endl;
}

Long Long::operator=(int &a){
    // оператор присваивания интового числа в вектор
    do{
        (*this).arr.push_back(a%10);
        a=a/10;
    }while(a>0);
    return (*this);
}

Long Long::operator+(Long &a){
    Long result(*this);
    int temp=0;
    int k;
    for (int i=0 ;i < max(a.arr.size(),(*this).arr.size()) ; i++){
        k = (i < result.arr.size() ? result.arr[i] : 0) + temp + ( i < a.arr.size() ? a.arr[i] : 0);
        if (i < arr.size())
            result.arr[i]=k%10;
        else
            result.arr.push_back(k%10);
        //i < arr.size() ? result.arr[i]=k%10 : result.arr.push_back(k%10);
        temp = k/10;
    }
    if( k >= 10)
        result.arr.push_back(temp);
return result;
}

Long Long::operator-(Long &a){
    Long Temp(*this);
    int c=0;
    for(int i=0;i<(int)arr.size();++i){
            Temp.arr[i] -= c+(i<(int)a.arr.size() ? a.arr[i] : 0);
            c=(Temp.arr[i]<0);
            if(c)
                Temp.arr[i]+=10;
    }
    while (Temp.arr.size() > 1 && Temp.arr.back() == 0)
        Temp.arr.pop_back();
return Temp;
}

Long Long:: operator*(Long &a){
    Long result;
    for(int i=0;i<arr.size()+a.arr.size();i++)
        result.arr.push_back(0);
    for (int i=0; i<arr.size(); ++i)
        for (int j=0, carry=0; j<(int)a.arr.size() || carry; ++j) {
            int cur = result.arr[i+j] + arr[i] *  (j < (int)a.arr.size() ? a.arr[j] : 0) + carry;
            result.arr[i+j] = int (cur % 10);
            carry = int (cur / 10);
        }
    while (result.arr.size() > 1 && result.arr.back() == 0)
        result.arr.pop_back();
return result;
}

Long Karatsuba(Long &A,Long &B){
    Long result;
    if(A.arr.size()<2 || B.arr.size()<2)
        return A*B;
    int i = (A.arr.size() + B.arr.size()) / 4;
    if (i >= A.arr.size())
        i = A.arr.size() / 2;
    if (i >= B.arr.size())
        i = B.arr.size() / 2;
    Long a; a.arr.insert(a.arr.begin(),A.arr.begin()+i,A.arr.end());
    Long b; b.arr.insert(b.arr.begin(),A.arr.begin(),A.arr.begin()+i);
    Long c; c.arr.insert(c.arr.begin(),B.arr.begin()+i,B.arr.end());
    Long d; d.arr.insert(d.arr.begin(),B.arr.begin(),B.arr.begin()+i);
    Long ac=Karatsuba(a,c);
    Long bd=Karatsuba(b,d);
    Long a_b=a+b;
    Long c_d=c+d;
    Long ab_cd=Karatsuba(a_b,c_d);

    Long x1 = (ac+bd);
    Long x2 = ab_cd - x1;
    Long ad_bc = x2;
    ad_bc.arr.insert(ad_bc.arr.begin(),i,0);
    ac.arr.insert(ac.arr.begin(),i+i,0);
return ac+bd+ad_bc;
}


int main() {

       //string s;
       //cin>>s;
       string x("239030239030566179");
       string y("56617956617923930");
       Long a(x);
       //cin>>s;
       Long b(y);
       double t1=(double)clock();
       Long c=Karatsuba(a,b);
       double t2=((double)clock()-t1)/CLOCKS_PER_SEC;
       cout<<t2<<endl;
       c.GetLong();
       double t3=(double)clock();
       Long d=a*b;
       double t4=((double)clock()-t3)/CLOCKS_PER_SEC;
       cout<<t4<<endl;
       d.GetLong();

    return 0;
}