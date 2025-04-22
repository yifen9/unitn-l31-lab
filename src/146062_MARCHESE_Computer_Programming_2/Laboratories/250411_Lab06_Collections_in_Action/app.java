import data.Bike;
import data.EBike;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.*;


public class app {
    /** demonstrate Java Collection mechanism
     *
     * @param argv
     */
    public static void main(String[] argv){
		//Create an arrayList of Bike
        List <Bike> catalog = new ArrayList<Bike>();

        catalog.add(new Bike());
        catalog.add(new Bike( "Pinarello","scorpiom",28,4500, Bike.bikeType.ROAD));
        catalog.add(new Bike("Coppi","dragon",29,6500, Bike.bikeType.MTB));
        catalog.add(new Bike("Campagnolo","Marilu",26,500, Bike.bikeType.CITYBIKE));
        catalog.add(new Bike("Coppi","dragon",26,4000, Bike.bikeType.MTB));
        catalog.add(new EBike("FOCUS","wind",29,5500, Bike.bikeType.EBIKE,600));
        catalog.add(new EBike("GIANT","ECITY",27,4500, Bike.bikeType.EBIKE,600));
        catalog.add(new Bike("Campagnolo","Aldebaran",28,500, Bike.bikeType.CITYBIKE));
        catalog.add(new Bike( "Pinarello","Dogma2",28,4500, Bike.bikeType.ROAD));
        catalog.add(new Bike( "Pinarello","Dogma",28,2500, Bike.bikeType.ROAD));


        // shuffle the collection randomly 
        Collections.shuffle(catalog);
        System.out.println("Before the sorting");
        for(Bike b: catalog){
            System.out.println(b);
        }

        Collections.sort(catalog);


        System.out.println("After the sorting");
        for (int i=0; i<catalog.size(); i++){
            System.out.println("Index:"+i+" "+ catalog.get(i));
        }


        Collections.sort(catalog,
                new Comparator<Bike>() {
                    public int compare(Bike obj1, Bike obj2) {
                        return (int) (obj1.getWheelSize()-obj2.getWheelSize());
                    }
                });

        System.out.println("Sorting by wheel size");
        for (int i=0; i<catalog.size(); i++){
            System.out.println("Index:"+i+" "+ catalog.get(i));
        }

        Collections.sort(catalog,
                new Comparator<Bike>() {
                    public int compare(Bike obj1, Bike obj2) {
                        int c = (int) (obj2.getWheelSize()-obj1.getWheelSize());

                        if(c != 0) return c;
                        c = (int) (obj1.getCost()- obj2.getCost());
                        return c;
                    }
                });

        System.out.println("Sorting by wheel size (descending) and cost");
        for (int i=0; i<catalog.size(); i++){
            System.out.println("Index:"+i+" "+ catalog.get(i));
        }

        Collections.sort(catalog,
                new Comparator<Bike>() {
                    public int compare(Bike obj1, Bike obj2) {

                        int c = obj1.getModel().compareToIgnoreCase(obj2.getModel());
                        if(c != 0) return c;
                        c = (int) (obj1.getCost()- obj2.getCost());
                        return c;
                    }
                });

        System.out.println("Sorting by model and cost");
        for (int i=0; i<catalog.size(); i++){
            System.out.println("Index:"+i+" "+ catalog.get(i));
        }





    }
}
