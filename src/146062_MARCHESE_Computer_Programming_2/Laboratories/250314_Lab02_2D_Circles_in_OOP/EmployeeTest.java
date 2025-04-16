public class EmployeeTest {
    public static void main (String args[]){
        Employee employee1=new Employee ("Yifeng", "Li", 8964.00);
        Employee employee2=new Employee ("Jinping", "Xi", 2952.00);

        System.out.println(employee1);
        System.out.println(employee2);

        employee1.increaseSalary(0, 0.1);
        employee2.increaseSalary(0, 0.1);

        System.out.println(employee1);
        System.out.println(employee2);

        System.out.println("Is Employee1 named Chiara: " + employee1.checkFirstName("Chiara"));
    }
}