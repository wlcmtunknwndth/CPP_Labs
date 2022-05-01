#include <iostream>

using namespace std;
struct tovar{
    string name;
    float price;
    int amount;
    tovar* next;
};

int main() {
    tovar* bufet=NULL;
    tovar* tmp = new tovar;
    tmp ->name="cake";
    tmp ->price=60.2;
    tmp->amount=25;
    tmp->next=NULL;
    bufet=tmp;
    
    tmp=new tovar;
    tmp->name="milkshake";
    tmp->price=300;
    tmp->amount=10;
    tmp->next=bufet; //добавление
    bufet=tmp; //добавление
    
    tmp=new tovar;
    tmp->name="banana vegan bread";
    tmp->price=400;
    tmp->amount=5;
    tmp->next=bufet; //добавление
    bufet=tmp; //добавление
    
if (bufet->name=="cake"){
    tmp=bufet;
    bufet=bufet->next;
    delete tmp;
}
else{
    tovar* prev=bufet;
    tmp=bufet->next;
    while((tmp->name!="cake")&&(tmp!=NULL)) {
        prev=tmp;
        tmp=tmp->next;
    }
    
    if (tmp!=NULL){ 
    prev->next=tmp->next;
    delete tmp;
}
}
tmp=bufet;
while (tmp!=NULL){
    cout<<tmp->name<<" "<<tmp->price<<"RUB"<<endl;
    tmp=tmp->next;
}
    return 0;
}