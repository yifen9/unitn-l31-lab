import java.util.Arrays;

/**
 * This class represent a career of a student
 * contacting a vector of Exam and
 * compute the mean of the marks
 */
public class Career {
    static final int MAX_EXAM = 5;

    private Exam [] listOfExams = new Exam[MAX_EXAM];
    private int nbOfExams;
    private float mean;

    public Career() {
        nbOfExams = 0;
        mean = 0;
    }

    public void insertExam(Exam e) {
        if(nbOfExams >= MAX_EXAM) {
            System.out.println("Hey keep calm, too much exams!!!");
        }
        else {
            listOfExams[nbOfExams] = e;
            nbOfExams++;

            /**
             * Compute the mean mark
             */
            mean = 0;
            for(int i=0; i<nbOfExams; i++) {
                mean += listOfExams[i].getMark();
            }
            mean /= nbOfExams;
        }
    }

    @Override
    public String toString() {
        String r = "";
        for(int i=0; i<nbOfExams; i++) {
            r = r + listOfExams[i] + "\n";
        }
        return "Career{" + r + "\n the mean mark is:" + mean + "}";
    }

    public static void main(String[] args) {
        Exam e01 = new Exam();
        Exam e02 = new Exam("CP2",27,"2025-01-03");
        Exam e03 = new Exam("CP3",18,"2025-02-03");
        Exam e04 = new Exam("CP4",23,"2025-03-03");
        Exam e05 = new Exam("CP5",30,"2025-05-07");

        Career myCareer = new Career();

        //myCareer.insertExam(e01);
        myCareer.insertExam(e02);
        myCareer.insertExam(e03);
        myCareer.insertExam(e04);
        myCareer.insertExam(e05);
        myCareer.insertExam(new Exam("CP77",30,"2025-02-27"));

        System.out.println(myCareer);
    }
}
