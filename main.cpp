#include <iostream>
#include <vector>
using namespace std;
class Car{
protected:
    string brand;
    string model;
public:
    Car(){}
    Car(string brand, string model){
        this->brand=brand;
        this->model=model;
    }
    void setBrand(string brand){
        this->brand=brand;
    }
    void setModel(string model){
        this->model=model;
    }
    string getBrand(){
        return brand;
    }
    string getModel(){
        return model;
    }
virtual ~Car(){}
};
class Supersport : public Car{
private:
    bool speed;
    bool luxury;
public:
    Supersport(){}
    Supersport(string brand, string model, bool speed, bool luxury) : Car(brand, model){
    this->brand=brand;
    this->model=model;
    this->speed=speed;
    this->luxury=luxury;
    }
    void setSpeed(bool speed){
        this->speed=speed;
    }
    void setLuxury(bool Luxury){
        this->luxury=luxury;
    }
    bool getSpeed(){
        return speed;
    }
    bool getLuxury(){
        return luxury;
    }
friend ostream &operator << (ostream &out, Supersport &o);
friend istream &operator >> (istream &in, Supersport &i);
};
ostream &operator << (ostream &out, Supersport &o){
out<<"Brand: "<<o.brand<<" Model: "<<o.model<<", ";
if(o.speed==1)
    out<<"Fast Car, ";
else
    out<<"Normal(non fast version), ";
if(o.luxury==1)
    out<<"Luxury Car ";
else
    out<<"Normal(non luxury version) ";
return out;
}
istream &operator >> (istream &in, Supersport &i){
cout<<'\n'<<"Brand: ";in>>i.brand;
cout<<'\n'<<"Model: ";in>>i.model;
cout<<'\n'<<"Fast Car?(Y/N): ";string a;in>>a;if(a=="Y")i.speed=1;else i.speed=0;
cout<<'\n'<<"Luxury(Y/N): ";in>>a;if(a=="Y")i.luxury=1;else i.luxury=0;
return in;
}
class Coupe : public Car{
private:
    bool luxury;
public:
    Coupe(){}
    Coupe(string brand, string model, bool luxury) : Car (brand, model){
    this->brand=brand;
    this->model=model;
    this->luxury=luxury;
    }
    void setLuxury(bool luxury){
        this->luxury=luxury;
    }
    bool getLuxury(){
        return luxury;
    }
friend ostream &operator << (ostream &out, Coupe &o);
friend istream &operator >> (istream &in, Coupe &i);
};
ostream& operator << (ostream &out, Coupe &o){
out<<"Brand: "<<o.brand<<" Model: "<<o.model<<", ";
if(o.luxury==1)
    out<<"Luxury Car ";
else
    out<<"Normal(non luxury version) ";
return out;
}
istream &operator >> (istream &in, Coupe &i){
cout<<'\n'<<"Brand: ";in>>i.brand;
cout<<'\n'<<"Model: ";in>>i.model;
cout<<'\n'<<"Luxury(Y/N): ";string a;in>>a;if(a=="Y")i.luxury=1;else i.luxury=0;
return in;
}
class HotHatch : public Car{
private:
    int doors;
    string engine;
public:
    HotHatch(){}
    HotHatch(string brand, string model, int doors, string engine): Car(brand, model){
        this->brand=brand;
        this->model=model;
        this->doors=doors;
        this->engine=engine;
    }
    void setDoors(int doors){
        this->doors=doors;
    }
    void setEngine(string engine){
        this->engine=engine;
    }
    int getDoors(){
        return doors;
    }
    string getEngine(){
        return engine;
    }
friend ostream &operator << (ostream &out, HotHatch &o);
friend istream &operator >> (istream &in, HotHatch &i);
};
ostream &operator << (ostream &out, HotHatch &o){

out<<"Brand: "<<o.brand<<" Model: "<<o.model<<" Number of doors: "<<o.doors<<" Engine Type: "<<o.engine;
return out;
}
istream &operator >> (istream &in, HotHatch &i){
cout<<'\n'<<"Brand: ";in>>i.brand;
cout<<'\n'<<"Model: ";in>>i.model;
cout<<'\n'<<"Number of doors: ";in>>i.doors;
cout<<'\n'<<"Engine: (Cost-Efficient/Powerful): ";in>>i.engine;
return in;
}
class Cabrio : public Car{
private:
    bool convertible;
    string roof;
public:
    Cabrio(){}
    Cabrio(string brand, string model, bool convertible, string roof): Car(brand, model){
        this->brand=brand;
        this->model=model;
        this->convertible=convertible;
        this->roof=roof;
    }
    void setConvertible(bool convertible){
        this->convertible=convertible;
    }
    void setRoof(string roof){
        this->roof=roof;
    }
    bool getConvertible(){
        return convertible;
    }
    string getRoof(){
        return roof;
    }
friend istream &operator >> (istream &in, Cabrio &i);
friend ostream &operator << (ostream &out, Cabrio &o);
};
istream &operator >> (istream &in, Cabrio &i){
cout<<'\n'<<"Brand: ";in>>i.brand;
cout<<'\n'<<"Model: ";in>>i.model;
cout<<'\n'<<"Convertible(Y/N): ";string a;in>>a;if(a=="Y")i.convertible=1;else i.convertible=0;
cout<<'\n'<<"Roof: ";in>>i.roof;
return in;
}
ostream &operator << (ostream &out, Cabrio &o){
out<<"Brand: "<<o.brand<<" Model: "<<o.model<<", ";
if(o.convertible==0)
    out<<"Non-Convertible, ";
else
    out<<"Convertible, ";
out<<"Roof: "<<o.roof;
return out;
}
int main()
{
    Supersport Car1("Dacia", "Logan", true, true);
    Supersport Car2("Bugatti", "Veyron", true, true);
    Coupe Car3("Renault", "Megane", false);
    HotHatch Car4("Mercedes", "Benz", 2, "Powerful");
    vector <pair<Car*, int > > items;
    items.push_back(std::make_pair(&Car1,-1));
    items.push_back(std::make_pair(&Car2,-1));
    items.push_back(std::make_pair(&Car3,-1));
    items.push_back(std::make_pair(&Car4,-1));

cout<<"TARGUL DE MASINI SPORT AL LUNII MAI"<<'\n'<<'\n';
cout<<"Momentan au fost introduse urmatoarele masini: "<<'\n';
for(int i=0;i<items.size();i++){
    Car *c=items[i].first;
    Cabrio *c1 =NULL;
    Supersport *c2 = NULL;
    Coupe *c3 = NULL;
    HotHatch *c4 = NULL;
    if (c1= dynamic_cast<Cabrio*>(c)){
        cout<<i+1<<". "<<*c1;
                if (items[i].second==-1)
            cout<<", Price:-1 (Unsold)"<<'\n';
                    else
            cout<<", Vandut la: "<<items[i].second;
    }
    if (c2= dynamic_cast<Supersport*>(c)){
        cout<<i+1<<". "<<*c2;
                if (items[i].second==-1)
            cout<<", Price:-1 (Unsold)"<<'\n';
                    else
            cout<<", Vandut la: "<<items[i].second;
    }
    if (c3= dynamic_cast<Coupe*>(c)){
        cout<<i+1<<". "<<*c3;
                if (items[i].second==-1)
            cout<<", Price:-1 (Unsold)"<<'\n';
                    else
            cout<<", Vandut la: "<<items[i].second;
    }
    if (c4= dynamic_cast<HotHatch*>(c)){
        cout<<i+1<<". "<<*c4;
                if (items[i].second==-1)
            cout<<", Price:-1 (Unsold)"<<'\n';
                    else
            cout<<", Vandut la: "<<items[i].second;
    }
}
Coupe co[100];int j1=0;
Cabrio ca[100];int j2=0;
Supersport sa[100];int j3=0;
HotHatch ho[100];int j4=0;
cout<<'\n'<<"Te rugam, adauga masinile noi aduse la expoitie."<<'\n';
cout<<"Cate masini doresti sa adaugi?"<<'\n';int nr; string type;
cin>>nr;
for (int i=1;i<=nr;i++){
    cout<<"Ce tip de masina doresti sa adaugi? Coupe/Cabrio/Supersport/HotHatch"<<'\n';cin>>type;
    if(type=="Coupe")
    {
        cin>>co[j1];
        items.push_back(std::make_pair(&co[j1], -1));
        j1++;
    }
    else

    if(type=="Supersport")
    {
        cin>>sa[j2];
        items.push_back(std::make_pair(&sa[j2], -1));
        j2++;
    }
    else

    if(type=="Cabrio")
    {
        cin>>ca[j3];
        items.push_back(std::make_pair(&ca[j3], -1));
        j3++;
    }
    else

    if(type=="HotHatch")
    {
        cin>>ho[j4];
        items.push_back(std::make_pair(&ho[j4], -1));
        j4++;
    }
}
while(true){
    int choice;
    int introducere;
    int vanzare;
    cout<<'\n'<<"Ce doresti sa faci in continuare?"<<'\n';
    cout<<"[1] Arata toata masinile"<<'\n';
    cout<<"[2] Vinde o masina"<<'\n';
    cout<<"[3] Scoate o masina"<<'\n';
    cout<<"[4] Adauga alta masina"<<'\n';
    cout<<"[5] Iesire"<<'\n';
    cin>>choice;
    if (choice==5)
        break;

    else if (choice==1){

    for(int i=0;i<items.size();i++){
    Car *c=items[i].first;
    Cabrio *c11 =NULL;
    Supersport *c22 = NULL;
    Coupe *c33 = NULL;
    HotHatch *c44 = NULL;
    if (c11= dynamic_cast<Cabrio*>(c)){
        cout<<i+1<<". "<<*c11;
        if (items[i].second==-1)
            cout<<", Price:-1 (Unsold)"<<'\n';
        else
            cout<<", Vandut la: "<<items[i].second<<'\n';
    }
    if (c22= dynamic_cast<Supersport*>(c)){
        cout<<i+1<<". "<<*c22;
                if (items[i].second==-1)
            cout<<", Price:-1 (Unsold)"<<'\n';
                    else
            cout<<", Vandut la: "<<items[i].second<<'\n';
    }
    if (c33= dynamic_cast<Coupe*>(c)){
        cout<<i+1<<". "<<*c33;
                if (items[i].second==-1)
            cout<<", Price:-1 (Unsold)"<<'\n';
                    else
            cout<<", Vandut la: "<<items[i].second<<'\n';
    }
    if (c44= dynamic_cast<HotHatch*>(c)){
        cout<<i+1<<". "<<*c44;
                if (items[i].second==-1)
            cout<<", Price:-1 (Unsold)"<<'\n';
                    else
            cout<<", Vandut la: "<<items[i].second<<'\n';
    }
}

    }
    else if (choice==4){
            cout<<"Ce tip de masina doresti sa adaugi? Coupe/Cabrio/Supersport/HotHatch"<<'\n';cin>>type;
    if(type=="Coupe")
    {
        cin>>co[j1];
        items.push_back(std::make_pair(&co[j1], -1));
        j1++;
    }
    else

    if(type=="Supersport")
    {
        cin>>sa[j2];
        items.push_back(std::make_pair(&sa[j2], -1));
        j2++;
    }
    else

    if(type=="Cabrio")
    {
        cin>>ca[j3];
        items.push_back(std::make_pair(&ca[j3], -1));
        j3++;
    }
    else

    if(type=="HotHatch")
    {
        cin>>ho[j4];
        items.push_back(std::make_pair(&ho[j4], -1));
        j4++;
    }


    }
    else if(choice==3){
        cout<<'\n'<<"Ce masina doresti sa scoti?"<<'\n';cin>>introducere;introducere--;
        items.erase(items.begin()+introducere);

    }
    else if(choice==2){
        cout<<'\n'<<"Ce masina doresti sa vinzi?"<<'\n';cin>>introducere;introducere--;
        cout<<'\n'<<"La ce pret doresti sa vinzi masina? (Lei): ";cin>>vanzare;
        items[introducere].second=vanzare;
    }

}
    return 0;
}
