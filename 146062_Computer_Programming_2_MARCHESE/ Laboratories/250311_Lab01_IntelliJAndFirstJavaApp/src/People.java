public class People{
    int age;
    String name;

    public People(String n, int a){
        age = a;
        name = n;
    }
    public void print(){
        System.out.println("This is " + name + " it is " + age + " years old");
    }
    public int getMonths(){
        return age*12;
    }
    public String toString(){
        return "This is " + name + " it is " + age + " years old";
    }
    public static void main(String[] args){
        People friend01 = new People("Francis", 34);
        People friend02 = new People("Barack", 23);

        friend02.print();
        friend01.print();

        System.out.println(friend01.getMonths());

        System.out.println(friend02.toString() + " that means " + friend02.getMonths()+ " months");
    }
}