package consoleApp;

import model.*;

public class StoreConsole {

    // this object is for reading the ascii file of the proce list
    // and store in an Arraylist
    static  ReadFile myStore;
    // This object is for storing the logging of all the sales done
    //static Sales logSales;

    public static void main(String[] args) {

        myStore = new ReadFile(
                "src/it/unitn/cp2/esebike/files/bike.txt"
        );
        System.out.println(myStore.toString());


    }

}
