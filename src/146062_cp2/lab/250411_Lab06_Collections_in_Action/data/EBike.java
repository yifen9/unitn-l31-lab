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
    public EBike(String m,String model, double ws, double c, bikeType t,double b){
        super(m,model,ws,c,bikeType.UNKNOWN);
        this.setType(t);
        this.setBatterySize(b);
    }
    public String toString(){
        return String.format("EBike: %15s Model %10s Type: %10s Cost: %7.2f WheelSize: %4.1f Battery: %4.0f",
                this.manufacturer, this.getModel(),this.type.toString(), this.cost,this.wheelSize,
                this.batterySize);

    }

    public static void main(String[] argv){

        Bike [] catalog = {
                new Bike(),
                new Bike("Pinarello","scorpiom",28,4500,bikeType.ROAD),
                new Bike("Coppi","dragon",29,6500,bikeType.MTB),
                new Bike("Campagnolo","Marilu",26,500,bikeType.CITYBIKE),
                new Bike("Campagnolo","goldfinger",26,9500,bikeType.EBIKE),
                new EBike("FOCUS","wind",29,12500,bikeType.EBIKE,600),


        };

        for (Bike b:catalog){
            System.out.println(b);
        }
    }

}
