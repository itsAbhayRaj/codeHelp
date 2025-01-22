#include<iostream>
#include <string.h>
using namespace std;
// #include "Hero.cpp"
// class Hero { cheking size :: 1 for empty class
// //  int n;   
// //  int f;   
// //  char d;
// // char arr[7];
// };
class Hero{
    
    private:
    int health;
    
    public:
    char level;
char *name;
    Hero(){
        cout<<"constructor called !!!"<<endl;
        name = new char[100];
    }
    
    Hero(int health){
      this->health =  health;  
    }
    
    Hero(char name[],char level,int health){
        this->name = new char[100];
        strcpy(this->name,name);
        this->level = level;
        this-> health = health;
    }
    // copy constructor 
    // Hero(Hero &temp){
    //     char *ch = new char[100];
    //     strcpy(ch,temp.name);
    //     this->name = ch;
    //     this->level = temp.level;
    //     this->health = temp.health;
    // }
    int getHealth(){
        return health;
    }
    void setName(char name[]){
        strcpy(this->name,name);
    }
    void setHealth(int h){
        health = h;
    }
    void print(){
        cout<<"[ "<<this->name<<" , "<<this->health<<" , "<<this->level<<" ]"<<endl;
    }
};

int main(){
    // Hero h1;// including from other file 
    // cout<<sizeof(h1)<<endl; //checking size with different variables
    // Hero Abhay;
    // Abhay.health = 70;
    // Abhay.level = 'A';
    // cout<<Abhay.level<<endl;
    // cout<<Abhay.health<<endl;
    // Abhay.setHealth(6);
    // int h = Abhay.getHealth();
    // cout<<h<<endl;
    // Hero *p  = new Hero;
    // cout<<(*p).getHealth()<<endl;  //two ways of accessing 
    // cout<<(*p).level<<endl;        // with pointers
    // cout<<p->getHealth()<<endl;
    // cout<<p->level<<endl;
    // Hero he(9);
    // cout<<he.getHealth()<<endl;
    // Hero h(2);
    // cout<<h.getHealth()<<endl;
    // char name[6] = "Abhay";
    // Hero j(name,'A',4);
    // j.setName(name);
    // j.print();
    // Hero s(j);
    // s.print();
    // s.name[0]='K';   // showing shallow copying by default in copy constructor
    // s.print();
    // j.print();
    // deep copying 
    // Hero k = j;
    // j.print();
    // k.print();
    // j.level = 'B';
    // k.setHealth(7);
    // j.print();
    // k.print();


    return 0;
}