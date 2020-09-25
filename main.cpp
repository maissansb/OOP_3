#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
const int r = 6372.79;
const int p = 3.141;
struct location{
    int deg,min,sec;
};

class city{
private:
    string name;
    int pop;
    location lat,lon;

public:
    void set(string,int,location,location); // This member function might change *this
    void get(string &, int &, location &, location &)const; //  A member function that inspects (rather than mutates) its object.


    void print()const; // This member promises NOT to change *this
    double findDistance(city)const;

};
//END OF CLASS

void city::set(string n, int p, location lt, location ln){

    name = n;
    pop = p;
    lat.deg = lt.deg;
    lat.min = lt.min;
    lat.sec = lt.sec;

    lon.deg = ln.deg;
    lon.min = ln.min;
    lon.sec = ln.sec;

}

void city::get(string &n, int &p, location &lt, location &ln)const{
    n=name;
    p=pop;

    lt.deg = lat.deg;
    lt.min =lat.min;
    lt.sec = lat.sec;

    ln.deg =  lon.deg;
    ln.min = lon.min;
    ln.sec = lon.sec;
}

void city::print()const{
    cout<<"City "<<name<<" located latitude; "<<lat.deg<<" "<<lat.min
    <<" "<<lat.sec<<" and longtidue "<<lon.deg<<" "<<lon.min<<" "<<lon.sec<<endl;
    cout<<"has population "<<pop<<endl;
}
double city::findDistance(city a)const{




    // double distance,o,latf,lats,latdiff,longdiff,longf,longs;
    // distance=r*o;

    // latf=((degree + (minute + second/60)/60) )* p / 180;
    // lats=((degree + (minute + second/60)/60) )* p / 180;
    // longf=((degree + (minute + second/60)/60) )* p / 180;
    // longs=((degree + (minute + second/60)/60) )* p / 180;

    // longdiff=longf-longs;
    // latdiff=latf-lats;
    // y=pow(sin(latdiff/2),2);
    // z=cos(lats)*cos(latf)*pow(sin(longdiff)/2,2);
    // o=2*asin(sqrt(y+z));

    // distance=r*o;

    return 1.0;
}

int main() {
    
    ifstream fin;
    fin.open("city.txt");

    string x1;
    int x2,x3,x4,x5,x6,x7,x8;

    int counter = 0;
    

    while(fin >> x1 >> x2>>x3>>x4>>x5>>x6>>x7>>x8){
        // cout << x1 << "  " << x2 <<" "<<x3 << "  " << x4 << "  " << x5<< "  " << x6<< "  " << x7<< "  " << x8<< endl;
        counter+=1;
    }


    //Now, we know how many cities we have, so we can declare an array of cities:
    city ca[counter];

    fin.close();
    fin.open("city.txt"); //reopening city.txt because we have reached the end of file

    for(int i=0;i<counter;i++){

        fin >>x1>>x2>>x3>>x4>>x5>>x6>>x7>>x8;

        location a, b;
        a.deg=x3;
        a.min=x4;
        a.sec =x5;

        b.deg=x6;
        b.min=x7;
        b.sec = x8;

        ca[i].set(x1,x2,a,b);

        ca[i].print();
}



    return 0;
}














    // int c[5];
    // ifstream in;
    // in.open("city.txt");
    // for(int i=0;i<5;i++){
    //     in>>name>>pop>>lat.deg>>lat.min>>lat.sec>>lon.deg>>lon.min>>lon.sec;
    // }
    // in.close( );
    // ^^^ Maissan's friends stupid code









