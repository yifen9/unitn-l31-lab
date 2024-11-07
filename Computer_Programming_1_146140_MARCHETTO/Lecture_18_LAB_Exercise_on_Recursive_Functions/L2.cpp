using namespace std;
#include <iostream>

int free(int[]);

int add_node(int,int,int,int[]);

bool is_allocated(int,int[]);

int get_node_value(int,int[]);

int get_left_child(int,int[]);

int get_right_child(int,int[]);

void in_order_visit(int,int[]);

int main(){
    int memory[4*1000] = {0};

    int leaf1 = add_node(10, 0, 0, memory);
    int leaf2 = add_node(30, 0, 0, memory);
    int leaf3 = add_node(30, leaf1, leaf2, memory);
    int leaf4 = add_node(40, leaf3, 0, memory);

    cout << "In order visit: " << endl;
    in_order_visit(16,memory);

    return 0;
}

int free(int memory[]){
    int i=4;
    while(memory[i]){i+=4;}

    return i;
}

int add_node(int value, int left_child, int right_child, int memory[]){
    int i = free(memory);

    memory[i] = 1;
    memory[i+1] = value;
    memory[i+2] = left_child;
    memory[i+3] = right_child;

    return i;
}

bool is_allocated(int index_of_node, int memory[]){return memory[index_of_node];}

int get_node_value(int index_of_node, int memory[]){return memory[index_of_node+1];}

int get_left_child(int index_of_node, int memory[]){return memory[index_of_node+2];}

int get_right_child(int index_of_node, int memory[]){return memory[index_of_node+3];}

void in_order_visit(int node, int memory[]){
    if(is_allocated(node,memory)){
        in_order_visit(get_left_child(node,memory),memory);
        cout << " - leaf " << node/4 << " value is: " << get_node_value(node,memory) << endl;
        in_order_visit(get_right_child(node,memory),memory);
    }
}
