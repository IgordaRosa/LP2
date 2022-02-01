#include "biblioteca.hpp"
#include "biblioteca.cpp"


#define debug 1

int main(){
    string arquivo;
    if(debug)cout << "Digite o input: ";
    cin >> arquivo;
    ifstream input(arquivo);
    vector<string> vetorIN;
    string tmp;
    while(getline(input, tmp)){
        vetorIN.push_back(tmp);
    }
    size_t m=0;
    cout << setprecision(2)<< fixed << endl;

for(size_t i=0; i<vetorIN.size();i++){

    if(vetorIN.at(i) == "circle"){
    i++;
    m++;
    float a1=stof(vetorIN.at(i));
    Circle sh1(a1);
    if(debug)cout <<"Object #"<<m <<" is circle ->";
    cout << sh1.CalcArea()<< endl;
    }
    
    if(vetorIN.at(i) == "square"){
    i++;
    m++;
    float a1=stof(vetorIN.at(i));
    Square sh2(a1);
    if(debug)cout <<"Object #"<< m <<" is square ->";
    cout << sh2.CalcArea()<< endl;
    }

    if(vetorIN.at(i) == "sphere"){
    i++;
    m++;
    float a1=stof(vetorIN.at(i));
    Sphere sh3(a1);
    if(debug)cout <<"Object #"<< m <<" is sphere ->";
    cout << sh3.CalcArea()<< endl;
    }

    if(vetorIN.at(i) == "cube"){
    i++;
    m++;
    float a1=stof(vetorIN.at(i));
    Cube sh4(a1);
    if(debug)cout << "Object #"<< m <<" is cube ->"; 
    cout << sh4.CalcArea() << endl;
    }

    if(vetorIN.at(i) == "triangle"){
    size_t j=0;
    i++;
    m++;
    
    float a1;
    float a2;
    size_t p=0;
    p=vetorIN.at(i).find(",");
    if(p>0&& p <= vetorIN.at(i).size()){
        a1 = ConverterL2d(vetorIN.at(i),0);
        a2 = ConverterL2d(vetorIN.at(i),1); 
        j++;
    }
    else{
        a1=stof(vetorIN.at(i));
        a2=0;
    }
    
    i++;
    float b1;
    float b2;
    p=vetorIN.at(i).find(",");
    if(p>0&& p <= vetorIN.at(i).size()){
        b1 = ConverterL2d(vetorIN.at(i),0);
        b2 = ConverterL2d(vetorIN.at(i),1);
        j++;
    }
    else{
        b1=stof(vetorIN.at(i));
        b2=0;
    }

    i++;
    float c1;
    float c2;
    p=vetorIN.at(i).find(",");
    if(p>0&& p <= vetorIN.at(i).size()){
        c1 = ConverterL2d(vetorIN.at(i),0);
        c2 = ConverterL2d(vetorIN.at(i),1);
        j++;
    }
    else{
        c1=stof(vetorIN.at(i));
        c2=0;
    }
    
    if(j!=3){
        Triangle sh5(a1,b1,c1);
        if(debug)cout << "Object #"<< m <<" is triangle ->"; 
        cout << sh5.CalcArea()<< endl;
    }
    else{
        Triangle sh5(Point2d(a1,a2),Point2d(b1,b2),Point2d(c1,c2));
        if(debug)cout << "Object #"<< m <<" is triangle ->"; 
        cout << sh5.CalcArea()<< endl;
        }
    }

    if(vetorIN.at(i) == "tetrahedron"){
    m++;
    i++;
    float a1 = ConverterL3d(vetorIN.at(i),0);
    float b1 = ConverterL3d(vetorIN.at(i),1);
    float c1 = ConverterL3d(vetorIN.at(i),2);

    i++;
    float a2 = ConverterL3d(vetorIN.at(i),0);
    float b2 = ConverterL3d(vetorIN.at(i),1);
    float c2 = ConverterL3d(vetorIN.at(i),2);

    i++;
    float a3 = ConverterL3d(vetorIN.at(i),0);
    float b3 = ConverterL3d(vetorIN.at(i),1);
    float c3 = ConverterL3d(vetorIN.at(i),2);

    i++;
    float a4 = ConverterL3d(vetorIN.at(i),0);
    float b4 = ConverterL3d(vetorIN.at(i),1);
    float c4 = ConverterL3d(vetorIN.at(i),2);

    Tetrahedron sh6(Point3d(a1,b1,c1),Point3d(a2,b2,c2),Point3d(a3,b3,c3),Point3d(a4,b4,c4));
    if(debug)cout << "Object #"<< m <<" is tetrahedron ->";
    cout<< sh6.CalcArea()<< endl;
    }
}
    return 0;
}