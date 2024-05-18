/* 
for example we have created a CLASS PAIR with two private int variables and provided
getter and setter variable for them but now we need it for  double and char variables
also so we have to create 2 another classes for them which will be very lengthy work for us

SO THAT'S WHY WE USES TEMPLATES;

IN THIS WE WILL DECLARE THE VARIABLE AS
T x;
T y;
here T is the temporary datatype we can change it according to are needs
SYNTAX : template <typename T>
(declaring template)
so now when we are declaring the object of the class
there we also have to declare what size is of variables x,y
i.e. relaces T with a datatype.

DECLARING SYNTAX: Pair<int> p1;
                  Pair<double> p2;
    So, here Pair is the class name and <int> is datatype and p1 and p2 are
    our objects.  

we can also declare two different datatypes with templates
and call it as Pair<int, double> p1;            
*/
#include<iostream>
using namespace std;
template <typename T, typename V>
class Pair{
    T x;
    V y;
    public :
    void setX(T x){
        this->x = x;
    }
    T getX(){
        return x;
    }
    void setY(V y){
        this->y = y;
    }
    V getY(){
        return y;
    }
};
int main(){
    Pair<int, int> p1;
    p1.setX(2);
    p1.setY(3);
    cout << p1.getX() << " " << p1.getY() << endl; 
    Pair<double, double> p2;
    p2.setX(2.21);
    p2.setY(3.42);
    cout << p2.getX() << " " << p2.getY() << endl;
    Pair<char, char> p3;
    p3.setX('f');
    p3.setY('y');
    cout << p3.getX() << " " << p3.getY() << endl;
    Pair<int, double> p4;
    p4.setX(16);
    p4.setY(3.42);
    cout << p4.getX() << " " << p4.getY() << endl;
    Pair<Pair<int,int>, int> p5; // using three variable from two variables
    Pair<int,int> p6;
    p5.setY(5);
    p6.setX(10);
    p6.setY(20);
    p5.setX(p6);
    cout << p5.getX().getX() << " " << p5.getX().getY() << " " << p5.getY();
}