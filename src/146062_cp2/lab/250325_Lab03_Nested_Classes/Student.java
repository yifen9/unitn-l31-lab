public class Student {
    private String name;
    private String surname;
    private int id;
    private Career myCareer;

    public Student(String n, String s, int id) {
        name = n;
        surname = s;
        this.id = id;
        myCareer = new Career();
    }

    public void insertExam(Exam e) {
        myCareer.insertExam(e);
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", surname='" + surname + '\'' +
                ", id=" + id +
                ", myCareer=" + myCareer +
                '}';
    }

    public static void main(String[] args) {
        Exam e01 = new Exam();
        Exam e02 = new Exam("CP2",27,"2025-01-03");
        Exam e03 = new Exam("CP3",18,"2025-02-03");
        Exam e04 = new Exam("CP4",23,"2025-03-03");
        Exam e05 = new Exam("CP5",30,"2025-05-07");

        Student s01 = new Student("Gigino","Gigetto",123456);
        s01.insertExam(e02);
        s01.insertExam(e03);
        s01.insertExam(e05);

        System.out.println(s01);
    }
}
