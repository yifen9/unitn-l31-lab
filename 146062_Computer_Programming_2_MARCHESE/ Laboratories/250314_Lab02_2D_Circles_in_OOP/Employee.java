public class Employee {
    private double salary;
    private String lastName;
    private String firstName;

    public Employee(String firstName, String lastName, double salary) {
        this.salary = salary;
        this.lastName = lastName;
        this.firstName = firstName;
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
        this.salary = salary;
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

    public void changeSalary(double newSalary){
        this.setSalary(newSalary);
    }

    public void increaseSalary(double salaryIncrement){
        this.setSalary(this.getSalary() + salaryIncrement);
    }

    private boolean checkLastName(String newName){
        return (this.getLastName() == newName);
    }

    private boolean checkFirstName(String newName){
        return (this.getFirstName() == newName);
    }

    public boolean checkName(String newLastName, String newFirstName){
        return (checkLastName(newLastName) && checkFirstName(newFirstName));
    }
}
