#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
const double r = 6372.795;
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
    double findDistance(city)const; //takes in a class

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

    double distance,o,latf,lats,latdiff,longdiff,longf,longs,y,z;

    // forepoint is *this
    // standpoint is passed in as a city variable
    double p=4*atan(1);  //formula for pi

    latf=((lat.deg + (lat.min + lat.sec/60.0)/60.0) )* p / 180.0;
    lats=((a.lat.deg + (a.lat.min + a.lat.sec/60.0)/60.0) )* p / 180.0;
    longf=((lon.deg + (lon.min + lon.sec/60.0)/60.0) )* p / 180.0;
    longs=((a.lon.deg + (a.lon.min + a.lon.sec/60.0)/60.0) )* p / 180.0;

    longdiff= longf-longs;
    latdiff= latf-lats;
    y=pow(sin(latdiff/2),2);
    z=cos(lats)*cos(latf)*pow(sin(longdiff/2),2);
    o=2*asin(sqrt(y+z));

    distance=r*o;

    // cout << "lat.deg = " << lat.deg << endl;
    // cout << "a.lat.leg = " << a.lat.deg << endl;

    // cout << "lon.deg = " << lon.deg << endl;
    // cout << "a.lon.deg = " << a.lon.deg << endl;

    // cout << "longf = " << longf << endl;
    // cout << "longs = " <<longs <<endl;

    // cout<<"longdiff is = " << longdiff << endl;
    // cout<<"latdiff is = " << latdiff << endl;

    return distance;
}

int main() {
    
    ifstream fin;
    fin.open("city.txt");

    string x1,x0;
    int x2,x3,x4,x5,x6,x7,x8;
    double td=0;
    int counter = 0;
    

    while(fin >> x1 >> x2>>x3>>x4>>x5>>x6>>x7>>x8){
        counter+=1;
    }


    //Now, we know how many cities we have, so we can declare an array of cities:
    city ca[counter];

    fin.close();
    fin.open("city.txt"); //reopening city.txt because we have reached the end of file

    for(int i=0;i<counter;i++){

        fin >>x1>>x2>>x3>>x4>>x5>>x6>>x7>>x8;
        //reading file and takes in values
    

        location a, b;
        a.deg=x3;
        a.min=x4;
        a.sec =x5;

        b.deg=x6;
        b.min=x7;
        b.sec = x8;

        ca[i].set(x1,x2,a,b);

        ca[i].print();
        if( i!=0){
        cout<<endl<<"The distance between "<<x1<<" and "<<x0<<" is: ";
        cout<<ca[i].findDistance(ca[i-1])<<endl;
        td+=ca[i].findDistance(ca[i-1]); //a sum that add total distances
    }
        x0=x1; //new variable to save previous city name

}
cout<<endl<<"Total distance between all cities is: "<<td;

    return 0;
}
