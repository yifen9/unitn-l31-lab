package data;

import java.time.LocalDateTime;

public class Sale {
    static int id0 = 1; // Initial ID, this is static so it will start from 1 each time I run the application
    int id; // Sale Id
    int nb; // Number of items
    Bike bike;
    double total; // Total amount
    LocalDateTime ldt; //Date of sell

    public Sale(int n,Bike b){
      //provide code
    }

//    public Bike getBike(){
//        // provide code
//    }
//
//    public double getTotal() {
//
//        // provide code
//    }

    @Override
    public String toString() {
        return "Sale{" +
                "id=" + id +
                ", nb=" + nb +
                ", bike=" + bike +
                ", total=" + total +
                ", ldt=" + ldt +
                '}';
    }
}
