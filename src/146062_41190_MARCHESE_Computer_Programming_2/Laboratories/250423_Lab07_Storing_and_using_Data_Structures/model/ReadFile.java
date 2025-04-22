package model;

import data.Bike;
import data.EBike;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ReadFile {
    List<Bike> catalog;


    public ReadFile(String s) {
        // Initialize the ArrayList
        catalog = new ArrayList<Bike>();
        try {
            //Read the file
            read(catalog, s);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public ReadFile() {
            catalog = new ArrayList<Bike>();
    }

    @Override
    public String toString() {
        String s="";
        for ( Bike b: catalog){
            s += b+"\n";
        }
        return s;
    }

    public Bike getElement(int i){

        return catalog.get(i);
    }

    // Return the size of the catalog
    public int getLength(){
       return catalog.size();
    }

    /** Find an element in the list by ID
     *
     * @param id
     * @return the Bike object or null
     */
    public Bike findElement(int id){
        Bike b = null;
        for (Bike i:catalog){
            if (i.getId() == id){
                return i;
            }
        }
        return b;
    }

    public void sortWheelModel(){
        Collections.sort(catalog, new Comparator<Bike>() {
            //Sort based on ascending order of dataLimit
            @Override
            public int compare(Bike obj1, Bike obj2) {

                int c = (int) (obj1.getWheelSize()-obj2.getWheelSize());
                if (c != 0) return c;
                return (int) (obj1.getModel().compareToIgnoreCase(obj2.getModel()));

            }
        });
    }

    public static String printFound(Bike a){
        if( a == null){
            return "The element was not found";
        } else {
            return a.toString();
        }
    }
    public static void main(String[] args) throws IOException {
        //Readfile r = new Readfile();

        ReadFile r = new ReadFile(
                "src/it/unitn/cp2/esebike/files/bike.txt"
        );

        System.out.println("\nIteration through the list with Efor");
        System.out.println(r);


        r.sortWheelModel();
        System.out.println("\nonthefly Sort: by WHEEL and modelCatalog");
        System.out.println(r);

        System.out.println("For to test getElement");
        for(int i=0;i<r.getLength();i++){
            System.out.println(r.getElement(i));
        }

        System.out.println("Test search");
        Bike aa = r.findElement(101);
        System.out.println(printFound(aa));
        aa = r.findElement(202);
        System.out.println(printFound(aa));
        aa = r.findElement(301);
        System.out.println(printFound(aa));
    }



    private void read(List <Bike> cat, String csvFilePath) throws Exception {

        String line = null;
        BufferedReader bufferedReader = null;

        try {
            String path = new File(csvFilePath).getAbsolutePath();
            File csvFile = new File(path);
            FileReader fileReader = new FileReader(csvFile);

            bufferedReader = new BufferedReader(fileReader);

            while ((line = bufferedReader.readLine()) != null) {

                        String[] csvLineElements = line.split(",");
//
//                for (int i = 0; i < csvLineElements.length; i++) {
//                    System.out.print(csvLineElements[i] + " , ");
//                }
//                System.out.println("");

                //Provide an object for storing data read
                Bike nb;

                // If the number of fields is 6 then it is a bike
                if (csvLineElements.length == 6) {
                    double ws = (double) Double.parseDouble(csvLineElements[4]);
                    double c = (double) Double.parseDouble(csvLineElements[5]);
                    int id = (int) Integer.parseInt(csvLineElements[0]);
                    switch (csvLineElements[3].toLowerCase().trim()) {
                        case "road":
                            nb = new Bike(id, csvLineElements[1],csvLineElements[2], ws, c, Bike.bikeType.ROAD);
                            break;
                        case "city":
                            nb = new Bike(id, csvLineElements[1],csvLineElements[2], ws, c, Bike.bikeType.CITY);
                            break;
                        case "mtb":
                            nb = new Bike(id, csvLineElements[1], csvLineElements[2],ws, c, Bike.bikeType.MTB);
                            break;
                        default:
                            nb = new Bike();
                            break;
                    }
                    cat.add(nb);

                }
                // if the number of fileds is 7 then it is a EBike
                if (csvLineElements.length == 7) {
                    double ws = (double) Double.parseDouble(csvLineElements[4]);
                    double c = (double) Double.parseDouble(csvLineElements[5]);
                    double batt = (double) Double.parseDouble(csvLineElements[6]);
                    int id = (int) Integer.parseInt(csvLineElements[0]);

                    switch (csvLineElements[3].toLowerCase().trim()) {
                        case "ebike":
                            nb = new EBike(id, csvLineElements[1], csvLineElements[2],ws, c, Bike.bikeType.ROAD, batt);
                            break;
                        default:
                            nb = new EBike();
                            break;
                    }
                    cat.add(nb);
                }
            }
        }
        catch (IOException e) {
            System.out.println("Error Occured while parsing csv file.");
            e.printStackTrace();
        }
        catch (NumberFormatException e){
            System.out.println("Error Occured while parsing csv file numberformat");
            e.printStackTrace();
        }
        finally {
            bufferedReader.close();
        }

    }





}


