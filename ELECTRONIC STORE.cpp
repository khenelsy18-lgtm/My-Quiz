#include <iostream>
using namespace std;

class ElectronicDevice{
  private:
   string deviceID;
   string brand;
   double price;
  public:
      // Setters
    void setdeviceID(string id) {
      id = deviceID;
    }
     void setbrand(string b){
      b = brand;
    }
     void  setprice(double p) {
      p = price;
    }
      //Getters
    string getdeviceID() {return deviceID;}

    string getbrand() const {return brand;}

    double getprice() const {return price;}

    //parameterised constructor
    ElectronicDevice( string Id, string b, double p){
          this->deviceID = Id;
          this->brand = b;
          this->price = p;
    }
    //default constructor
    ElectronicDevice(){
      deviceID = "453";
      brand = "NOKIA";
      price = 40000;
    }
    //destructor
    ~ElectronicDevice(){
      cout << "Object Destroyed" << endl;
    }
     //function Overloading
   double calculateWarranty(double years){
       return years;
   }
   double calculateWarranty(double years, double time){
        return years * time;
   }
};
class smartPhone: public ElectronicDevice{
    // single Inheritance
    string cameraResolution;

};
class laptop: public ElectronicDevice{
    //single inheritance
    string ramSize;
};
class smartWatch : public smartPhone{
    //multilevel inheritance
    string batteryLife;

};

int main(){
    //Objects
   ElectronicDevice device1;
   smartPhone phone1;
   laptop laptop1;
   smartWatch watch1;

   device1.calculateWarranty(4);
   device1.calculateWarranty(5, 3);

    return 0;
}
