using namespace std;
#include <iostream>
#include <string>

int ind=0;
int A[100] = {0};

void push(int);

int pop();

int main(int argc, char *argv[]){
    if(string(argv[1])=="rpn"){
        for(int i=2; i<argc; i++){
            try{push(stoi(argv[i]));}
            catch(invalid_argument){
                if(string(argv[i])=="+"){push(pop()+pop());}
                else if(string(argv[i])=="#"){push(pop()*pop());}
            }
        }
        cout << "Result: " << pop() << endl;
    }

    return 0;
}

void push(int n){
    A[ind] = n;
    ind++;
}

int pop(){
    if(ind < 1){cout << "ERROR" << endl;}
    else{ind--;}

    return A[ind];
}