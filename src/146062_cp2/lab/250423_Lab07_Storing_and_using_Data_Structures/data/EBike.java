package data;


public class EBike extends Bike  {
    protected double batterySize;

    public double getBatterySize() {
        return batterySize;
    }

    public void setBatterySize(double batterySize) {
        this.batterySize = batterySize;
    }
    public EBike(){
        super();
        this.batterySize=0;
    }
    public EBike(int id, String m,String model, double ws, double c, bikeType t,double b){
        super(id,m,model,ws,c,bikeType.UNKNOWN);
        this.setType(t);
        this.setBatterySize(b);
    }
    public String toString(){
        return String.format("EBike id %4d: %10s Model %20s Type: %6s Cost: %7.2f WheelSize: %4.1f Battery: %4.0f",
                this.id,
                this.manufacturer, this.getModel(),this.type.toString(), this.cost,this.wheelSize,
                this.batterySize);
    }
//    public EBike cloneBike(){
//        EBike eb01 = new EBike(this.getId(),this.getManufacturer(),this.getModel(),
//                this.getWheelSize(),this.getCost(),this.getType(),this.getBatterySize());
//        System.out.println("ClonataEBike");
//        return eb01;
//    }

    public static void main(String[] argv){

        Bike b10 = new Bike(121,"Campagnolo","goldfinger",26,9500,bikeType.ROAD);
        EBike b11 = new EBike(231,"FOCUS","wind",29,12500,bikeType.EBIKE,600);
//        Bike b12 = b10.cloneBike();
//        EBike b14 = b11.cloneBike();

        Bike [] catalog = {
                new Bike(),
                new Bike(101,"Pinarello","scorpiom",28,4500,bikeType.ROAD),
                new Bike(131,"Coppi","dragon",29,6500,bikeType.MTB),
                new Bike(141,"Campagnolo","Marilu",26,500,bikeType.CITY),
                b10,
                b11,

//                b12,
//                b14,


        };

        for (Bike b:catalog){
            System.out.println(b);
        }
    }

}
