import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Exam {
    /**
     * The mark of an exam
     */
    private int mark;
    /**
     * Course name
     */
    private String course;
    /**
     * date of the exam
     */
    private LocalDate dataOfExam;

    public int getMark() {
        return mark;
    }

    public void setMark(int mark) {
        this.mark = mark;
    }

    public String getCourse() {
        return course;
    }

    public void setCourse(String course) {
        this.course = course;
    }

    public LocalDate getDataOfExam() {
        return dataOfExam;
    }

    public void setDataOfExam(LocalDate dataOfExam) {
        this.dataOfExam = dataOfExam;
    }

    public Exam() {
        mark = 0;
        course = "NA";
        dataOfExam = LocalDate.of(1970,01,01);
    }

    public Exam(String n, int m, int year, int month, int day) {
        mark = m;
        course = n;
        dataOfExam = LocalDate.of(year,month,day);
    }

    public Exam(String n, int m, String strDate) {
        mark = m;
        course = n;
        DateTimeFormatter format = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        dataOfExam = LocalDate.parse(strDate,format);
    }

    public static void main(String[] args) {
        Exam esame01 = new Exam();
        Exam esame02 = new Exam("Computer Programming 2",30,2025,06,18);
        Exam esame03 = new Exam("Service and Design",29,"2025-05-12");

        System.out.println(esame01);
        System.out.println(esame02);
        System.out.println(esame03);
    }

    @Override
    public String toString() {
        return "Exam{" +
                "mark=" + mark +
                ", course='" + course + '\'' +
                ", dataOfExam=" + dataOfExam +
                '}';
    }
}
