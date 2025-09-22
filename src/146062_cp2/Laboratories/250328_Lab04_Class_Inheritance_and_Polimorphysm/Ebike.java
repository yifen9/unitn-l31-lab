public class Ebike extends Bike {
    /**
     * Additional parameter from Bike: km per charge
     */
    protected float kmPerCharge;

    public Ebike() {
        super();
        kmPerCharge = -1;
    }

    public Ebike(String m, float d, bikeType t, float k){
        super(m,d,t);
        kmPerCharge = k;
    }

    @Override
    public String toString() {
        String r = String.format(" km/Charge: %7.0f", kmPerCharge);

        return super.toString() + r;
    }

    public static void main(String[] args) {
        Ebike eb01 = new Ebike();
        Ebike eb02 = new Ebike("Pinarello Gravel performance",80.0f,bikeType.ROAD,200.0f);

        System.out.println(eb01);
        System.out.println(eb02);
    }
}