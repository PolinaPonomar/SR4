#include <iostream>
class isotop {
private:
    double A;
    double Z;
    std::string name;
public:

    double getA(){
        return A;
    }
    double getZ(){
        return Z;
    }
    std::string getname(){
        return name;
    }

    void setA(int a){
        A = a;
    }

    void setZ(int a){
        Z = a;
    }

    void setname(std::string a){
        name = a;
    }

    void print( isotop a){
        std::cout << a.getA() << std::endl;
        std::cout << a.getZ() << std::endl;
        std::cout << a.getname() << std::endl;

    }

    isotop (double a, double b, const std::string& c): A(a), Z(b), name(c){
        if (Z>A)
            std::cout << "ERROR!" << std::endl;
    };


};

int main() {
    isotop x(12, 6, "C");
    x.print(x);
    x.setA(14);
    x.setZ(7);
    x.setname("N");
    x.print(x);

    return 0;
}