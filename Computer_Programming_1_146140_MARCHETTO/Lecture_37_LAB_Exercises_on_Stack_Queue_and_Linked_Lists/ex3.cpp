using namespace std;
#include "stack.h"
#include "queue.h"
#include <string>

void line();

int str_to_int(string);

int main(){
    Stack *S = new Stack();

    line();
    cout << " Please input integers (input non-int to exit): " << endl << endl;
    cout << "  - stack index: " << endl;

    bool judge = true;
    int count = 0;
    string input;
    while(judge){
        cout << "    - " << count << ": ";
        cin >> input;
        
        try{S->Stack_push(str_to_int(input));}
        catch(invalid_argument){judge = false;}

        count++;
    }

    Queue *Q = new Queue();

    int len = S->Stack_length();
    for(int i=0; i<len; i++){Q->Queue_push(S->Stack_pop());}

    cout << endl << "  - queue index: " << endl;

    count = 0;
    len = Q->Queue_length();
    for(int i=0; i<len; i++){
        cout << "    - " << count << ": " << Q->Queue_pop() << endl;

        count++;
    }

    cout << endl << " Successfully reverted!" << endl;

    line();

    return 0;
}

void line(){cout << "--------------------------------" << endl;}

int str_to_int(string fWord){
    int len=0;
    while(fWord[len]!='\0'){len++;}
    
    char fNum[len+1];
    for(int i=0; i<len; i++){fNum[i] = fWord[i];}
    fNum[len] = '\0';

    return stoi(fNum);
}