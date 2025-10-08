package data;

public class Bike implements Comparable<Bike>{
    protected String manufacturer;

    public String getManufacturer() {
        return manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }

    public bikeType getType() {
        return type;
    }

    public void setType(bikeType type) {
        this.type = type;
    }

    public double getCost() {
        return cost;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    public double getWheelSize() {
        return wheelSize;
    }

    public void setWheelSize(double wheelSize) {
        this.wheelSize = wheelSize;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    @Override
    public int compareTo(Bike o) {
        return (this.getManufacturer().compareToIgnoreCase(o.getManufacturer()));
        //  return compare(this.getCost(), o.getCost());
    }

    public static int compare(int x, int y) {
        return x < y ? -1 : (x == y ? 0 : 1);
    }
    public static int compare(double x, double y) {
        return x < y ? -1 : (x == y ? 0 : 1);
    }


    static public enum bikeType {
        MTB,
        ROAD,
        CITY,
        UNKNOWN,
        EBIKE,
    }
    protected bikeType type;
    protected double cost;
    protected double wheelSize;
    protected String model;
    protected int id;


    public Bike(){
        this.cost=-1;
        this.type= bikeType.UNKNOWN;
        this.wheelSize=0;
        this.manufacturer="NA";
        this.model="NA";
        this.id = 0;
    }
    public Bike(int id, String m,String model, double ws, double c, bikeType t){
        this.cost=c;
        this.id = id;
        this.type= t;
        this.wheelSize=ws;
        this.manufacturer=m;
        this.model=model;
        if(t == bikeType.EBIKE){
            this.cost=-1;
            this.type= bikeType.UNKNOWN;
            this.wheelSize=0;
            this.manufacturer="Shouldnotarrive here";
            this.model="shoudl not be there";
        }
    }
    public String toString(){
        return String.format(" Bike id %4d: %10s Model %20s Type: %6s Cost: %7.2f WheelSize: %4.1f",
                this.id,this.manufacturer, this.getModel(),this.type.toString(), this.cost,this.wheelSize);

    }

//    public Bike cloneBike(){
//        Bike bike = new Bike(  this.getId(), this.getManufacturer(),this.getModel(),
//                this.getWheelSize(), this.getCost()
//             , this.getType());
//        return bike;
//
//    }


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public static void main(String[] argv){

        Bike b01 = new Bike(110,"Pinarello","Dogma3",28,6400,bikeType.ROAD);
//        Bike b02 = b01.cloneBike();

        Bike [] catalog = {
                new Bike(),
                new Bike(101,"Pinarello","scorpiom",28,4500,bikeType.ROAD),
                new Bike(102,"Coppi","dragon",29,6500,bikeType.MTB),
                new Bike(103,"Campagnolo","Marilu",26,500,bikeType.CITY),
                b01,
//                b02
                // new Bike("Campagnolo","goldfinger",26,9500,bikeType.EBIKE),


        };


        for (Bike b:catalog){
            System.out.println(b);
        }
    }


}

