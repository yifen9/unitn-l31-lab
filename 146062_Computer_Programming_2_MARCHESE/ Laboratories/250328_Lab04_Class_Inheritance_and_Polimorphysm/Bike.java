public class Bike {
    /**
     * Bike model
     */
    protected String model;
    /**
     * bike daily rate
     */
    protected float dailyRate;

    /** global type of bike
     *
     */
    public enum bikeType {
        MTB,
        CITY,
        ROAD,
        RACE
    }

    /** bike type
     * to be chosen from the catalog before
     */
    protected bikeType type;

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public float getDailyRate() {
        return dailyRate;
    }

    public void setDailyRate(float dailyRate) {
        this.dailyRate = dailyRate;
    }

    public bikeType getType() {
        return type;
    }

    public void setType(bikeType type) {
        this.type = type;
    }

    /**
     * default constructor
     * initialize variables in order
     * to check if I call it by mistake
     */
    public Bike() {
        dailyRate = -1;
        model = "NA";
        type = bikeType.CITY;
    }

    /** Bike constructor
     *
     */
    public Bike(String m, float d, bikeType t) {
        model = m;
        dailyRate = d;
        type = t;
    }

    @Override
    public String toString() {
//        return "Bike{" +
//                "model='" + model + '\'' +
//                ", dailyRate=" + dailyRate +
//                ", type=" + type +
//                '}';
        String r = String.format(
                "Bike: %-30s - DailyRate: %5.1f [Euro/day] - Type: %-4s",
                model,
                dailyRate,
                type
                );
        return r;
    }

    public static void main(String [] args) {
        Bike b01 = new Bike();
        Bike b02 = new Bike("Pinarello Dogma",45,bikeType.RACE);
        Bike b03 = new Bike("Graziella",12,bikeType.CITY);

        System.out.println(b01);
        System.out.println(b02);
        System.out.println(b03);
    }
}