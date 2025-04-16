import java.time.LocalDate;
import java.time.Period;

public class Rent {
    private Bike bike;
    private LocalDate dateOfRent;
    private String renter;

    public Rent(String renter, LocalDate d, Bike b) {
        this.renter = renter;
        dateOfRent = d;
        bike = b;
    }

    @Override
    public String toString() {
        return "Rent{" +
                "bike=" + bike +
                ", dateOfRent=" + dateOfRent +
                ", renter='" + renter + '\'' +
                '}';
    }

    public String returnBike(LocalDate d) {
        /** return
         * the number of days between d and dateOfRent
         */
        int days = Period.between(dateOfRent,d).getDays();
        float charge = days * bike.getDailyRate();
        String r = String.format(" You rent for %d days bike: %s\n -- You have been charged %f Euros",days,bike.toString(),charge);

        return r;
    }

    public static void main(String[] args) {
        Rent r01 = new Rent(
                "George Washington",
                LocalDate.of(2025,3,20),
                new Bike(
                        "graziella",
                        25,Bike.bikeType.CITY
                        )
                );

        System.out.println(r01);

        String r = r01.returnBike(LocalDate.now());
        System.out.println(r);
    }
}
