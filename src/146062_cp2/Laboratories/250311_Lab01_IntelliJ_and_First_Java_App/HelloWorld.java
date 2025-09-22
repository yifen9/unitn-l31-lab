public class HelloWorld{
    public void print(){
        for(int i=0; i<10; i++){
            System.out.println("The number is " + i);
        }
    }
    public static void main(String[] args){
        System.out.println("Hello World");
        HelloWorld a = new HelloWorld();
        a.print();
    }
}