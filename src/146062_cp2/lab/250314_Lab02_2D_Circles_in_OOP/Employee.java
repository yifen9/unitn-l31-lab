import java.util.Objects;

public class Employee {
    private double salary;
    private String lastName;
    private String firstName;

    public Employee(String firstName, String lastName, double salary) {
        this.setSalary(salary);
        this.setLastName(lastName);
        this.setFirstName(firstName);
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        if(salary < 0){
            this.salary = 0;
        }
        else{
            this.salary = salary;
        }
    }

    @Override
    public String toString() {
        return "Employee{" +
                "salary=" + salary +
                ", lastName='" + lastName + '\'' +
                ", firstName='" + firstName + '\'' +
                '}';
    }

    public void renameLastName(String newName){
        this.setLastName(newName);
    }

    public void renameFirstName(String newName){
        this.setFirstName(newName);
    }

    public void rename(String newLastName, String newFirstName){
        this.renameLastName(newLastName);
        this.renameFirstName(newFirstName);
    }

    public void increaseSalary(double incrementValue, double incrementPercentage){
        this.setSalary(((incrementPercentage + 1) * this.getSalary()) + incrementValue);
    }

    public boolean checkLastName(String newLastName){
        return (Objects.equals(this.getLastName(), newLastName));
    }

    public boolean checkFirstName(String newFirstName){
        return (Objects.equals(this.getFirstName(), newFirstName));
    }

    public boolean checkName(String newName){
        return (this.checkLastName(newName) || this.checkFirstName(newName));
    }

    public boolean checkFullName(String newLastName, String newFirstName){
        return (this.checkLastName(newLastName) && this.checkFirstName(newFirstName));
    }
}