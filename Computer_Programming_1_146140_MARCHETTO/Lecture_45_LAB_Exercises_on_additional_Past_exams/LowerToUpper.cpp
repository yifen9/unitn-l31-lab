using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

char text_correction(bool &judge, char c){
    if(judge){
        if((c >= 'a')
        && (c <= 'z')){
            c += ('A' - 'a');
            judge = false;
        }
    }
    else{
        if((c == '.')
        || (c == ',')
        || (c == '?')
        || (c == '!')){judge = true;}
    }
    return c;
}

void text_up(string fInName, string fOutName){
    fstream fIn, fOut;
    fIn.open(fInName, ios::in);
    fOut.open(fOutName, ios::out | ios::app);

    bool judge = true;
    char c;
    while(!fIn.eof()){
        c = fIn.get();
        if(!fIn.eof()){fOut.put(text_correction(judge,c));}
    }
}

int main(int argc, char *argv[]){
    string fInName="LowerToUpper-input.txt", fOutName="LowerToUpper-output.txt";
    
    if(argc - 1){
        fInName = argv[1];
        if(argc - 2){fOutName = argv[2];}
    }

    text_up(fInName,fOutName);

    return 0;
}