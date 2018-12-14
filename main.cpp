#include <iostream>
#include <vector>
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
        std::cout << a.getA() << '|'<< a.getZ() << '|'<<a.getname() << std::endl;

    }

    isotop (double a, double b, const std::string& c): A(a), Z(b), name(c){
        if (Z>A) {
            std::cout << "ERROR! Z > A!" << std::endl;

        }
    };


};

class element{
private:
    std::vector<isotop> V;
    int N; //количество изотопов
    std::string nameEl;
public:
    element( std::vector<isotop> a, int b, const std::string& c): V(a), N(b), nameEl(c){};

    std::vector<isotop> getV(){
        return V;
    }
    int getN(){
        return N;
    }
    std::string getnameEl(){
        return nameEl;
    }

    void print( element x) {

        std::cout << "Элемент:" << std::endl;

        std::cout << "Количество изотопов и название элемента:" << std::endl;
        std::cout << x.getN() << '|'<<x.getnameEl() << std::endl;

        std::cout << "Изотопы:" << std::endl;
        for (int i = 0; i < N; i++)
        {std::cout << V[i].getA() <<'|'<< V[i].getZ() << '|'<<V[i].getname() <<'|' << std::endl;}

    }


    void AddIsotope(isotop iso, double fm) {
        V.push_back(iso);
        N = N + 1;
        int M =0;

        for (int i = 0; i < N; i++){
            M = M + V[i].getA();
        }
        M = M/N;
        if ((fm*100/M) >100){
            std::cout << "ERROR!!!" << std::endl;
        }



    }


        /*
         for (int i = 0; i < N; i++){
             M = M + V[i].getA() ;
         }
         M = M/N;

        for (int i = 0; i < N; i++){
            std::vector<double> fm;
            fm (i) = ( V[i].getA()/M);

        }

*/



};

int main() {
    isotop x(12, 6, "C");
    x.print(x);
    x.setA(14);
    x.setZ(7);
    x.setname("N");
    x.print(x);

    isotop y(13, 6, "C");
    isotop z(15, 6, "C");

    /*

    std::vector<isotop> a = {x, y};
    element c(a, 2, "C");
    c.print(c);
     */

    std::vector<isotop> b = {x};
    element c1(b, 1, "C");
    c1.print(c1);

    c1.AddIsotope(y, 5);
    c1.AddIsotope(z, 3);

    c1.print(c1);





    return 0;
}