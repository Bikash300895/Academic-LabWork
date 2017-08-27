/*
 * Recursive descent parser for the grammer
 *  E -> iE'
 *  E' -> +iE' / e (epsilon)
*/


#include <iostream>
using namespace std;

void decide(char l){
    if(l == '\n'){
        cout<<"Parsing suffessful"<<endl;
    } else {
        cout<<"Parsing error"<<endl;
    }
}

// Defining the E_()
void E_(){
    char l = getchar();

    if(l == '+'){
        l = getchar();

        if(l == 'i'){
            E_();
        }
    }
    else
        decide(l);

}


// Defining the E()
void E(){
    char l = getchar();
    if (l == 'i'){
        E_();
    }
    // If this condition is not true it will simply return and give error on next character read
}




int main()
{
    E();
}
