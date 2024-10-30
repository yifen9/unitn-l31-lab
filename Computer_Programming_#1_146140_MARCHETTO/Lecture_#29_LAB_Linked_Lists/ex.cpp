using namespace std;
#include <iostream>

struct LL{
    int value = 0;
    LL *next;
};

int N=0;
LL A;

void line();

void print_all_nodes();

void insert_node();

void insert_first();

void insert_last();

void delete_node();

void same_node();

void delete_first();

void delete_specific_node();

void sorted_insertion();

void closest();

void reversal();

void rReversal(LL*,LL*);

int main(){
    int choice;
    while(true){
        line();
        cout << "Please choose:" << endl;
        cout << endl;
        cout << "  0 - quit" << endl;
        cout << " 99 - print all nodes" << endl;
        cout << "  1 - insert node" << endl;
        cout << "  2 - insert first" << endl;
        cout << "  3 - insert last" << endl;
        cout << "  4 - delete node" << endl;
        cout << "  5 - same node" << endl;
        cout << "  6 - delete first" << endl;
        cout << "  7 - delete specific node" << endl;
        cout << "  8 - sorted insertion" << endl;
        cout << "  9 - search closest" << endl;
        cout << " 10 - reversal" << endl;
        cout << endl;
        cout << "Please input your choice: ";
        cin >> choice;
        line();

        switch(choice){
            case 0: return 0;
            case 99: print_all_nodes(); break;
            case 1: insert_node(); break;
            case 2: insert_first(); break;
            case 3: insert_last(); break;
            case 4: delete_node(); break;
            case 5: same_node(); break;
            case 6: delete_first(); break;
            case 7: delete_specific_node(); break;
            case 8: sorted_insertion(); break;
            case 9: closest(); break;
            case 10: reversal(); break;

            default: cout << "Invalid input!" << endl;
        }
    }

    return 0;
}

void line(){cout << "--------------------------------" << endl;}

void print_all_nodes(){
    LL *p = &A;
    cout << N << " Nodes in Total" << endl;
    for(int i=0; i<N; i++){
        cout << endl;
        cout << " - index: " << i << endl;
        cout << "   - value: " << p->value << endl;
        p = p->next;
    }
    cout << endl;
    cout << "Successfully printed!" << endl;
}

void insert_node(){
    char input;
    bool judge = true;
    LL *p1,*p2,*p3;
    int index;

    while(judge){
        cout << "Current length: " << N << endl;
        cout << "Please input the index: ";
        cin >> index;

        if(index>N){
            cout << endl;
            cout << "Invalid input!" << endl;

            judge=false;
        }
        else{
            p1 = &A;

            if(index>0){for(int i=0; i<index; i++){p1 = p1->next;}}

            p2 = new LL();
            p3 = p1->next;

            p1->next = p2;
            p2->next = p3;
            p2->value = p1->value;

            cout << "Please input the value: ";
            cin >> p1->value;
            cout << endl;
            cout << "Successfully inserted!" << endl;

            N++;

            cout << endl;
            cout << "More insertions? (0 to exit): ";
            cin >> input;
            if(input=='0'){judge=false;}
            else{line();}
        }
    }
}

void insert_first(){
    char input;
    bool judge = true;
    LL *p1,*p2,*p3;

    while(judge){
        p1 = &A;

        if(N>0){
            p2 = new LL();
            p3 = A.next;

            p1->next = p2;
            p2->next = p3;
            p2->value = p1->value;
        }

        cout << "Current length: " << N << endl;
        cout << "Please input the value: ";
        cin >> p1->value;
        cout << endl;
        cout << "Successfully inserted to the first!" << endl;

        N++;

        cout << endl;
        cout << "More insertions? (0 to exit): ";
        cin >> input;
        if(input=='0'){judge=false;}
        else{line();}
    }
}

void insert_last(){
    char input;
    bool judge = true;
    LL *p;

    while(judge){
        p = &A;
        for(int i=0; i<(N-1); i++){p = p->next;}
        if(N>0){p->next = new LL();p = p->next;}

        cout << "Current length: " << N << endl;
        cout << "Please input the value: ";
        cin >> p->value;
        cout << endl;
        cout << "Successfully inserted to the last!" << endl;

        N++;

        cout << endl;
        cout << "More insertions? (0 to exit): ";
        cin >> input;
        if(input=='0'){judge=false;}
        else{line();}
    }
}

void delete_node(){
    char input;
    int index,value;
    bool judge=true, find;
    LL *p1,*p2,*p3;

    while(judge){
        if(N==0){cout << "Invalid deleting!" << endl;judge=false;}
        else if(N==1){
            N--;

            cout << endl;
            cout << "Info about deleted node:" << endl;
            cout << endl;
            cout << " - index: 0" << endl;
            cout << "   - value: " << A.value << endl;
            cout << endl;
            cout << "Successfully deleted!" << endl;

            judge = false;
        }
        else{
            cout << "Current length: " << N << endl;
            cout << "Please input the value: ";
            cin >> value;

            find = false;
            p1 = &A;
            if(p1->value == value){
                cout << endl;
                cout << "Info about deleted node:" << endl;
                cout << endl;
                cout << " - index: 0" << endl;
                cout << "   - value: " << p1->value << endl;

                N--;

                if(N>0){
                    p1 = p1->next;

                    A.value = p1->value;
                    A.next = p1->next;

                    delete p1;
                }

                cout << endl;
                cout << "Successfully deleted!" << endl;
            }
            else{
                p2 = p1->next;
                for(index=1; index<N; index++){
                    if(p2->value == value){find=true;break;}
                    else{
                        p1 = p1->next;
                        p2 = p2->next;
                    }
                }

                if(find){
                    p3 = p2->next;

                    cout << endl;
                    cout << "Info about deleted node:" << endl;
                    cout << endl;
                    cout << " - index: " << index << endl;
                    cout << "   - value: " << p2->value << endl;
                    cout << endl;
                    cout << "Successfully deleted!" << endl;

                    N--;
                    p1->next = p3;
                    delete p2;
                }
                else{
                    cout << endl;
                    cout << "Invalid input!" << endl;

                    judge = false;
                }
            }

            cout << endl;
            cout << "More deletion? (0 to exit): ";
            cin >> input;
            if(input=='0'){judge=false;}
            else{line();}
        }
    }
}

void same_node(){
    int i1, i2;
    cout << "Please input index 1: "; cin >> i1;
    cout << "Please input index 2: "; cin >> i2;

    if(i1>=N || i2>=N){
        cout << endl;
        cout << "Invalid input!" << endl;
    }
    else{
        LL *p1=&A, *p2=&A;
        for(int i=0; i<i1; i++){p1 = p1->next;}
        for(int i=0; i<i2; i++){p2 = p2->next;}

        cout << endl;
        cout << "Info about node 1:" << endl;
        cout << endl;
        cout << " - index: " << i1 << endl;
        cout << "   - value: " << p1->value << endl;

        cout << endl;
        cout << "Info about node 2:" << endl;
        cout << endl;
        cout << " - index: " << i2 << endl;
        cout << "   - value: " << p2->value << endl;

        if(p1 == p2){
            cout << endl;
            cout << "They are the same nodes!" << endl;
        }
        else{
            cout << endl;
            cout << "They are not the same nodes!" << endl;
        }
    }
}

void delete_first(){
    if(N==0){cout << "Invalid deleting!" << endl;}
    else{
        cout << N << " Nodes in Total" << endl;
        cout << endl;
        cout << "Info about deleted node:" << endl;
        cout << endl;
        cout << " - index: 0" << endl;
        cout << "   - value: " << A.value << endl;

        N--;

        if(N>0){
            LL *p = &A;
            p = p->next;

            A.value = p->value;
            A.next = p->next;

            delete p;
        }

        cout << endl;
        cout << "Successfully deleted the first!" << endl;
    }
}

void delete_specific_node(){
    char input;
    bool judge = true;
    LL *p1,*p2,*p3;
    int index;

    while(judge){
        if(N==0){cout << "Invalid deleting!" << endl;judge=false;}
        else if(N==1){
            N--;

            cout << endl;
            cout << "Info about deleted node:" << endl;
            cout << endl;
            cout << " - index: 0" << endl;
            cout << "   - value: " << A.value << endl;
            cout << endl;
            cout << "Successfully deleted!" << endl;

            judge = false;
        }
        else{
            cout << "Current length: " << N << endl;
            cout << "Please input the index: ";
            cin >> index;

            if(index>=N){
                cout << endl;
                cout << "Invalid input!" << endl;

                judge=false;
            }
            else{
                N--;

                if(N==0){
                    cout << endl;
                    cout << "Info about deleted node:" << endl;
                    cout << endl;
                    cout << " - index: 0" << endl;
                    cout << "   - value: " << A.value << endl;
                    cout << endl;
                    cout << "Successfully deleted!" << endl;

                    judge=false;
                }
                else{
                    p1 = &A;

                    if(index>0){for(int i=0; i<(index-1); i++){p1 = p1->next;}}

                    p2 = p1->next;
                    p3 = p2->next;

                    cout << endl;
                    cout << "Info about deleted node:" << endl;
                    cout << endl;
                    cout << " - index: " << index << endl;
                    cout << "   - value: " << p2->value << endl;
                    cout << endl;
                    cout << "Successfully deleted!" << endl;

                    p1->next = p3;
                    delete p2;

                    cout << endl;
                    cout << "More deletion? (0 to exit): ";
                    cin >> input;
                    if(input=='0'){judge=false;}
                    else{line();}
                }
            }
        }
    }
}

void sorted_insertion(){
    char input;
    int index,value;
    bool judge=true;
    LL *p1,*p2,*p3;

    while(judge){
        cout << "Current length: " << N << endl;
        cout << "Please input the value: ";
        cin >> value;

        if(N==0){
            cout << endl;
            cout << "Info about inserted node:" << endl;
            cout << endl;
            cout << " - index: 0" << endl;
            cout << "   - value: " << value << endl;

            A.value = value;
            N++;

            cout << endl;
            cout << "Successfully inserted!" << endl;
        }
        else{
            N++;

            if(value <= A.value){
                index = 0;
                p1 = &A;

                p2 = new LL();
                p3 = A.next;

                p1->next = p2;
                p2->next = p3;
                p2->value = p1->value;

                p1->value = value;
            }
            else{
                index = 1;
                p1 = &A;
                p3 = p1->next;
                for(index=1; index<(N-1); index++){
                    if(value > p3->value){
                        p1 = p1->next;
                        p3 = p3->next;
                    }
                    else{break;}
                }

                p2 = new LL();

                p1->next = p2;
                p2->next = p3;
                p2->value = value;
            }

            cout << endl;
            cout << "Info about inserted node:" << endl;
            cout << endl;
            cout << " - index: " << index << endl;
            cout << "   - value: " << value << endl;
            cout << endl;
            cout << "Successfully inserted!" << endl;
        }

        cout << endl;
        cout << "More insertions? (0 to exit): ";
        cin >> input;
        if(input=='0'){judge=false;}
        else{line();}
    }
}

void closest(){
    if(N==0){cout << "Invalid Operation!" << endl;}
    else{
        int target;
        cout << "Please input the target: ";
        cin >> target;

        int index = 0, v=A.value;
        float m, r;
        r = float(A.value) - float(target);
        if(r>=0){m = r;}
        else{m = -r;}

        LL *p = &A;
        for(int i=0; i<N; i++){
            r = float(p->value) - float(target);

            if(r>=0){if(r<m){v=p->value;m=r;index=i;}}
            else{if((-r)<m){v=p->value;m=-r;index=i;}}

            p = p->next;
        }

        cout << endl;
        cout << "Info about closest node:" << endl;
        cout << endl;
        cout << " - index: " << index << endl;
        cout << "   - value:      " << v << endl;
        cout << "   - difference: " << m << endl;
        cout << endl;
        cout << "Successfully searched!" << endl;
    }
}

void reversal(){
    if(N==0){cout << "Invalid Operation!" << endl;}
    else if(N==1){cout << "Successfully reversed!" << endl;}
    else{
        LL *p1 = &A, *p2 = &A;
        for(int i=0; i<(N-1); i++){p1 = p1->next;}
        p2 = p2->next;
        
        rReversal(&A,A.next);

        p2->next = new LL();
        p2 = p2->next;
        p2->value = A.value;

        A.value = p1->value;
        A.next = p1->next;
        delete p1;

        cout << "Successfully reversed!" << endl;
    }
}

void rReversal(LL *n1, LL *n2){
    if(n2->next != NULL){
        n1->next = NULL;
        rReversal(n2,n2->next);
    }
    
    n2->next = n1;
}