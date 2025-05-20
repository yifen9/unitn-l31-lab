using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

const int MAXLEN = 64;

struct contact{
    char name[MAXLEN] = "Yifeng";
    char surname[MAXLEN] = "Li";
    int phone = 3929952282;
    char email[MAXLEN] = "yifeng.li@unitn.it";
    contact *next;
};

int N=0;
contact C;

void line();

void printAllRecords();

void newRecords();

void copyRecord();

void editRecord();

void readDataFromFile();

void saveDataToFile();

void sortByName();

void printVCARD();

void searchByName();

int main(){
    int choice;
    while(true){
        line();
        cout << "Please choose:" << endl;
        cout << endl;
        cout << " 0 - quit" << endl;
        cout << " 1 - print all records" << endl;
        cout << " 2 - new records" << endl;
        cout << " 3 - copy a record" << endl;
        cout << " 4 - edit a record" << endl;
        cout << " 5 - read data from file" << endl;
        cout << " 6 - save data to file" << endl;
        cout << " 7 - sort by name" << endl;
        cout << " 8 - print a record to the VCARD format" << endl;
        cout << " 9 - search by name (exact match)" << endl;
        cout << endl;
        cout << "Please input your choice: ";
        cin >> choice;
        line();

        switch(choice){
            case 0: return 0; break;
            case 1: printAllRecords(); break;
            case 2: newRecords(); break;
            case 3: copyRecord(); break;
            case 4: editRecord(); break;
            case 5: readDataFromFile(); break;
            case 6: saveDataToFile(); break;
            case 7: sortByName(); break;
            case 8: printVCARD(); break;
            case 9: searchByName(); break;

            default: cout << "Invalid input!" << endl;
        }
    }
}

void line(){cout << "--------------------------------" << endl;}

void printAllRecords(){
    contact *p = &C;
    cout << N << " Records in Total" << endl;
    for(int i=0; i<N; i++){
        cout << endl;
        cout << " - ID:        " << i << endl;
        cout << "   - name:    " << p->name << endl;
        cout << "   - surname: " << p->surname << endl;
        cout << "   - phone:   " << p->phone << endl;
        cout << "   - email:   " << p->email << endl;
        p = p->next;
    }
    cout << endl;
    cout << "Successfully printed!" << endl;
}

void newRecords(){
    char input[MAXLEN];
    bool judge = true;
    contact *p;
    while(judge){
        p = &C;
        for(int i=0; i<(N-1); i++){p = p->next;}
        if(N>0){
            p->next = new contact();
            p = p->next;
        }

        cout << "Please input:" << endl;
        cout << endl;
        cout << " - name:    "; cin >> p->name;
        cout << " - surname: "; cin >> p->surname;
        cout << " - phone:   "; cin >> p->phone;
        cout << " - email:   "; cin >> p->email;
        cout << endl;
        cout << "Successfully recorded!" << endl;

        N++;

        cout << endl;
        cout << "More records? (0 to exit): ";
        cin >> input;
        if(input[0]=='0'){judge=false;}
        else{cout << endl;}
    }
}

void copyRecord(){
    int i1,i2;
    cout << "Copy to (ID):   ";
    cin >> i1;
    cout << "Copy from (ID): ";
    cin >> i2;

    if(i1>=N || i2>=N){
        cout << endl;
        cout << "Invalid input!" << endl;
    }
    else{
        contact *p1=&C, *p2=&C;
        for(int i=0; i<i1; i++){p1 = p1->next;}
        for(int i=0; i<i2; i++){p2 = p2->next;}

        strncpy(p1->name,p2->name,MAXLEN);
        strncpy(p1->surname,p2->surname,MAXLEN);
        p1->phone = p2->phone;
        strncpy(p1->email,p2->email,MAXLEN);

        cout << endl;
        cout << " - name:    " << p1->name << endl;
        cout << " - surname: " << p1->surname << endl;
        cout << " - phone:   " << p1->phone << endl;
        cout << " - email:   " << p1->email << endl;
        cout << endl;
        cout << "Successfully copied!" << endl;
    }
}

void editRecord(){
    int index;
    cout << "Please input the ID: ";
    cin >> index;

    contact *p=&C; for(int i=0; i<index; i++){p = p->next;}

    bool judge = true;
    while(judge){
        cout << endl;
        cout << " 1 - name:    " << p->name << endl;
        cout << " 2 - surname: " << p->surname << endl;
        cout << " 3 - phone:   " << p->phone << endl;
        cout << " 4 - email:   " << p->email << endl;

        cout << endl;
        cout << "Index of the value (0 to exit): ";
        cin >> index;

        switch(index){
            case 0: judge = false; break;

            case 1: cout << endl << "new name: "; cin >> p->name; break;
            case 2: cout << endl << "new surname: "; cin >> p->surname; break;
            case 3: cout << endl << "new phone: "; cin >> p->phone; break;
            case 4: cout << endl << "new email: "; cin >> p->email; break;

            default: cout << "Invalid input! ";
        }
    }
}

void readDataFromFile(){
    string fName;
    cout << "Please input the filename: ";
    cin >> fName;

    fstream fIn;
    fIn.open(fName, ios::in);

    if(!(fIn.is_open())) {cout << endl << "Missing file name!" << endl;}
    else{
        contact *p = &C;
        for(int i=0; i<(N-1); i++){p = p->next;}
        if(N>0){
            p->next = new contact();
            p = p->next;
        }

        string line;
        char c;
        int len, count, n=0;

        cout << endl;
        cout << "Read from File: " << endl;

        while(!fIn.eof()){
            getline(fIn,line);

            cout << endl;
            cout << " - line ID: " << n << endl;

            c = line[0];
            len = 0;
            while(c){
                len++;
                c = line[len];
            }

            c = 0;
            count = 0;
            char *word = new char[MAXLEN];
            for(int i=0; i<len; i++){
                if(line[i]==' '){
                    word[c] = '\0';
                    switch(count){
                        case 0:
                            strcpy(p->name,word);
                            cout << "     - name:    " << word << endl; break;
                        case 1:
                            strcpy(p->surname,word);
                            cout << "     - surname: " << word << endl; break;
                        case 2:
                            p->phone = stoi(word);
                            cout << "     - phone:   " << word << endl; break;
                    }
                    c = 0;
                    count++;
                    delete[] word;
                    char *word = new char[MAXLEN];
                }
                else{
                    word[c]=line[i];
                    c++;
                }
            }
            word[c] = '\0';
            strcpy(p->email,word);
            cout << "     - email:   " << word << endl;
            delete[] word;

            N++;

            if(!fIn.eof()){
                p->next = new contact();
                p = p->next;
            }

            n++;
        }

        cout << endl;
        cout << "Successfully read!" << endl;
    }

    fIn.close();
}

void saveDataToFile(){
    string fName;
    cout << "Please input the filename: ";
    cin >> fName;

    fstream fOut;
    fOut.open(fName, ios::out | ios::app);

    cout << endl;
    cout << "Save to File: " << endl;

    contact *p = &C;
    for(int i=0; i<N; i++){
        cout << endl;
        cout << " - ID: " << i << endl;

        cout << "   - name:    " << p->name << endl;
        fOut << p->name << ' ';

        cout << "   - surname: " << p->surname << endl;
        fOut << p->surname << ' ';

        cout << "   - phone:   " << p->phone << endl;
        fOut << p->phone << ' ';

        cout << "   - email:   " << p->email << endl;
        fOut << p->email << endl;

        p = p->next;
    }

    cout << endl;
    cout << "Successfully saved!" << endl;
}

void sortByName(){
    if(N<=1){cout << "Successfully sorted!" << endl;}
    else{
        contact *p1,*p2;
        bool judge = true;
        while(judge){
            judge = false;
            p1 = &C; p2 = p1->next;
            while(p2->next!=NULL){
                if(strcmp(p1->name,p2->name)>0){
                    judge = true;

                    contact *p3 = new contact();

                    strcpy(p3->name,p2->name);
                    strcpy(p3->surname,p2->surname);
                    p3->phone = p2->phone;
                    strcpy(p3->email,p2->email);

                    strcpy(p2->name,p1->name);
                    strcpy(p2->surname,p1->surname);
                    p2->phone = p1->phone;
                    strcpy(p2->email,p1->email);

                    strcpy(p1->name,p3->name);
                    strcpy(p1->surname,p3->surname);
                    p1->phone = p3->phone;
                    strcpy(p1->email,p3->email);

                    delete p3;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        cout << "Successfully sorted!" << endl;
    }
}

void printVCARD(){
    int index;
    string input;
    contact *p;
    bool judge = true;
    while(judge){
        cout << "Please input the ID: ";
        cin >> index;

        p=&C; for(int i=0; i<index; i++){p = p->next;}

        cout << endl;
        cout << "BEGIN:VCARD" << endl;
        cout << " VERSION:4.0" << endl;
        cout << " FN:" << p->name << " " << p->surname << endl;
        cout << " N:" << p->surname << ";" << p->name << ";;;" << endl;
        cout << " EMAIL:" << p->email << endl;
        cout << " TEL:" << p->phone << endl;
        cout << "END:VCARD" << endl;

        cout << endl;
        cout << "More prints? (0 to exit): ";
        cin >> input;
        if(input[0]=='0'){judge=false;}
        else{cout << endl;}
    }
}

void searchByName(){
    char input[MAXLEN];
    cout << "Please input the name: ";
    cin >> input;

    int index=0;
    bool find=false;
    contact *p = &C;
    while((p->next!=NULL)&&(!find)){
        if(strcmp(p->name,input)==0){find = true;}
        else{p = p->next;index++;}
    }

    if(find){
        cout << endl;
        cout << " - ID: " << index << endl;
        cout << "   - name:    " << p->name << endl;
        cout << "   - surname: " << p->surname << endl;
        cout << "   - phone:   " << p->phone << endl;
        cout << "   - email:   " << p->email << endl;
        cout << endl;
        cout << "Successfully found!" << endl;
    }
    else{
        cout << endl;
        cout << "Not found!" << endl;
    }
}
