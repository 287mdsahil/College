import java.util.*;

class Student {
    String roll;
    String name;
    String course;
    String adm_date;
    public float cgpa;
    int marks[] = new int[5];

    public void setData() {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter Name: ");
        name = s.nextLine();
        Calendar c = Calendar.getInstance();
        adm_date = c.get(Calendar.DATE) + "/" + c.get(Calendar.MONTH) + "/" + c.get(Calendar.YEAR);
    };

    public void displayData() {
        System.out.println();
        System.out.println("Roll :" + roll);
        System.out.println("Name :" + name);
        System.out.println("Course :" + course);
        System.out.println("Admission Date :" + adm_date);
        System.out.println();
    };

    public void setRoll(String r) {
        roll = r;
    }

    public int[] returnMarks() {
        return marks;
    }

    public void setCourse(String c) {
        course = c;
    }

    public void setCGPA() {
        float t = 0;
        for (int i = 0; i < 5; ++i) {
            t = t + marks[i] / 10;
        }
        ;
        t = t / 5;
        cgpa = t;
    };

    public void displayName() {
        System.out.println("Name :" + name);
    }

    public void displayCGPA() {
        System.out.println("CGPA :" + cgpa);
    }

};

public class student {
    public static void main(String[] args) {

    }
}