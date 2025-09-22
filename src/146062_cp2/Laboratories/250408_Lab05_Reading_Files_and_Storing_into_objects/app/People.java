package app;

import java.time.LocalDate;

public class People {
    private String name;
    private String surname;
    private String sex;
    private String city;
    private String ssn;
    private LocalDate dateOfBirth;

    public People(){
        name = "Not Available";
        dateOfBirth = LocalDate.now();
    }

    public People(String n, String surname, String sex, String c, String ssn, LocalDate d){
        this.surname = surname;
        this.sex = sex;
        this.ssn = ssn;
        name = n;
        city = c;
        dateOfBirth = d;
    }

    @Override
    public String toString() {
        String r;
        r = String.format("%15s %15s %2s %10s %15s %15s",
                name,surname,sex,dateOfBirth,city,ssn);
        return r;
    }

    public static void main(String[] args) {
        People p01 = new People();
        People p02 = new People("Robert","Kennedy","M",
                "Whashington",
                "KNDRBT12354677",
                LocalDate.of(1959,12,10)
                );

        System.out.println(p01);
        System.out.println(p02);
    }
}
