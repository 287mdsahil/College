
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.time.*;

class student1 {
    protected StringBuilder roll;
    protected String name;
    protected Date date;
    protected int[] marks = new int[5];
    protected int[] grade = new int[5];
    protected float total;
    protected int chk;
    protected int pass;
    protected float sgpa;

    student1() {
        roll = new StringBuilder();
        roll.append("XXXX18000");
        total = 0;
        chk = 0;
        pass = 1;
        sgpa = 0;
    }

    void grade_s(int g) {
        if (g == 10)
            System.out.println("S");
        if (g == 9)
            System.out.println("A");
        if (g == 8)
            System.out.println("B");
        if (g == 7)
            System.out.println("C");
        if (g == 6)
            System.out.println("D");
        if (g == 5)
            System.out.println("E");
        if (g == 4)
            System.out.println("X");
        if (g < 4) {
            System.out.println("X");
            pass = 0;
        }
    }

    static LocalDate get_adm_Date() {
        return LocalDate.now();
    }

    int input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Name:");
        name = br.readLine();
        return 0;
    }

    void gen_roll(int dep_code, int std_no) {
        if (dep_code == 1)
            roll.replace(0, 9, "BCSE18000");
        else if (dep_code == 2)
            roll.replace(0, 9, "BCHE18000");
        else if (dep_code == 3)
            roll.replace(0, 9, "ELEC18000");
        else if (dep_code == 4)
            roll.replace(0, 9, "MECH18000");
        else {
            System.out.println("Error code!!");
            return;
        }
        roll.setCharAt(6, (char) ((std_no / 100) + 48));
        roll.setCharAt(7, (char) (((std_no / 10) % 10) + 48));
        roll.setCharAt(8, (char) ((std_no % 10) + 48));
        System.out.println("Roll:" + roll);
        date = java.sql.Date.valueOf(get_adm_Date());
        System.out.println("Date of registration: " + date);
    }

    void show_stud(int i) {
        System.out.println(i + "\t" + roll + "\t" + name);
    }

    void show_stud_grade(int i) {
        System.out.println(i + "\t" + roll + "\t" + name + "\t" + sgpa/5);
    }
}

class student_adm extends student1 {
    int input() throws IOException {
        System.out.println("------------------------------------------------------------------");
        System.out.println("Department      Subjects Code");
        System.out.println("                1. English  2. Maths 3. Sociology");
        System.out.println("01. CSE         4. Etech    5. Physics     ");
        System.out.println("02. CHE       ");
        System.out.println("03. ELE          ");
        System.out.println("02. MECH       ");
        System.out.println("------------------------------------------------------------------");
        super.input();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Department Code:");
        int temp = Integer.parseInt(br.readLine());
        return temp;
    }

    void set_marks() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        if (chk == 1) {
            System.out.println("Input already taken!!");
            return;
        }
        String[] sub = { "English", "Maths", "Socio", "E.Tech", "Physics" };
        System.out.println("Name: " + name);
        System.out.println("Enter the marks:-");
        for (int i = 0; i < 5; i++) {
            int a;
            System.out.print(sub[i] + " :");
            a = Integer.parseInt(bf.readLine());
            while (a > 100 || a < 0) {
                System.out.println("Wrong Input!! Try again.");
                a = Integer.parseInt(bf.readLine());
            }
            marks[i] = a;
            total += marks[i];
            double x = (double) marks[i];
            x = x / 10;
            grade[i] = (int) java.lang.Math.ceil(x);
            sgpa += grade[i];
            if (grade[i] < 4)
                pass = 0;
        }
        chk = 1;
        System.out.println("Marks entered successfully.");
    }

    int print_marksheet() {
        if (chk == 0) {
            System.out.println("Marks not entered for the student yet.");
            return 0;
        }
        System.out.println("Name: " + name + "\nRoll: " + roll);
        System.out.println("------------------------------------");
        System.out.println("Subject         Marks          Grade");
        String[] sub = { "English", "Maths", "Socio", "E.Tech", "Physics" };
        for (int i = 0; i < 5; i++) {
            System.out.print(sub[i] + "\t\t" + marks[i] + "\t    ");
            grade_s(grade[i]);
        }
        System.out.println("------------------------------------");
        if (pass == 1)
            System.out.println("                    SGPA: " + sgpa / 5);
        else
            System.out.println("                      SGPA:");
        System.out.println("------------------------------------");
        return 1;
    }

    static ArrayList<student_adm> sort_list(ArrayList<student_adm> s) {
        ArrayList<student_adm> temp = new ArrayList();
        student_adm temp2 = new student_adm();
        temp = s;
        for (int i = 0; i < temp.size(); i++) {
            for (int j = 0; j < temp.size() - 1 - i; j++) {
                if (temp.get(j).total < temp.get(j + 1).total) {
                    Collections.swap(temp, j, j + 1);
                }
            }
        }
        return temp;
    }

    static int check_entry(ArrayList<student_adm> s) {
        for (int i = 0; i < s.size(); i++) {
            if (s.get(i).chk == 0)
                return 0;
        }
        return 1;
    }
}

class University {
    int[] count = new int[4];
    ArrayList<student_adm>[] s = new ArrayList[4];

    University() {
        Arrays.fill(count, 0);
        for (int i = 0; i < 4; i++) {
            s[i] = new ArrayList<student_adm>();
        }
    }

    void admin_interface() throws IOException {
        while (true) {
            String s;
            int i;
            System.out.println("Press any key to continue");
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            // Integer.parseInt(bf.readLine());
            Scanner in = new Scanner(System.in);
            in.nextLine();
            System.out.print("\033[H\033[2J");
            System.out.flush();
            System.out.println(
                    "Enter your choice\n1. New admission\n2. Receive marks\n3. Generate marksheet\n4. Print department list\n5. Print department result sheet\n6. Print the total number of students.\n7. Remove a student.\n8. Exit");
            int ch;
            ch = Integer.parseInt(bf.readLine());
            switch (ch) {
            case 1:
                admission();
                break;
            case 2:
                rcv_marks();
                break;
            case 3:
                marksheet();
                break;
            case 4:
                stu_list();
                break;
            case 5:
                sorted_list();
                break;
            case 6:
                show_num_stud();
                break;
            case 7:
                removeStud();
                break;
            case 8:
                System.gc();
                return;
            default:
                break;
            }
        }
    }

    void show_num_stud() {
        System.out.println("Total number of students who have taken admission is "
                + (s[0].size() + s[1].size() + s[2].size() + s[3].size()));
    }

    void admission() throws IOException {
        student_adm stu = new student_adm();
        int dep_code;
        System.out.println("\t\tADMISSION ROLL");
        dep_code = stu.input();
        ++count[dep_code - 1];
        stu.gen_roll(dep_code, count[dep_code - 1]);
        s[dep_code - 1].add(stu);
        System.out.println("Admission Complete.");
    }

    void rcv_marks() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String rl;
        int dep_code;
        while (true) {
            System.out.println("Enter roll number");
            rl = bf.readLine();
            if (rl.length() != 9)
                System.out.println("Error! Try Again.");
            else
                break;
        }

        if ("BCSE".equals(rl.substring(0, 4)))
            dep_code = 1;
        else if (rl.substring(0, 4).equals("BCHE"))
            dep_code = 2;
        else if (rl.substring(0, 4).equals("ELEC"))
            dep_code = 3;
        else if (rl.substring(0, 4).equals("MECH"))
            dep_code = 4;
        else {
            System.out.println("Error Input1!!!");
            return;
        }
        if (!rl.substring(4, 6).equals("18")) {
            System.out.println("Error Input2!!!");
        }
        int cnt = (rl.charAt(6) - 48) * 100 + (rl.charAt(7) - 48) * 10 + (rl.charAt(8) - 48);
        // System.out.println(cnt + " " + s[dep_code].size());
        if (s[dep_code - 1].size() >= cnt) {
            student_adm stud = s[dep_code - 1].get(cnt - 1);
            stud.set_marks();
        } else {
            System.out.println("Error Input!!!");
        }
    }

    void marksheet() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String rl;
        int dep_code;
        while (true) {
            System.out.println("Enter roll number");
            rl = bf.readLine();
            if (rl.length() != 9)
                System.out.println("Error! Try Again.");
            else
                break;
        }
        if (rl.substring(0, 4).equals("BCSE"))
            dep_code = 1;
        else if (rl.substring(0, 4).equals("BCHE"))
            dep_code = 2;
        else if (rl.substring(0, 4).equals("ELEC"))
            dep_code = 3;
        else if (rl.substring(0, 4).equals("MECH"))
            dep_code = 4;
        else {
            System.out.println("Error Input1!!!");
            return;
        }

        int cnt = (rl.charAt(6) - 48) * 100 + (rl.charAt(7) - 48) * 10 + (rl.charAt(8) - 48);

        if (s[dep_code - 1].size() >= cnt) {
            student_adm stud = new student_adm();
            for (int i = 0; i < s[dep_code - 1].size(); i++) {
                if (s[dep_code - 1].get(i).roll.toString().equals(rl.toString())) {
                    stud = s[dep_code - 1].get(i);
                    break;
                }
            }
            // System.out.println(stud.roll);
            if (stud.roll.substring(8).equals("0"))
                return;
            int ch = stud.print_marksheet();
            if (ch == 0) {
                System.out.println(
                        "Marks not yet entered.\nPress 1 to enter marks.\nPress any other button to return to prev menu.");
                int a;
                a = Integer.parseInt(bf.readLine());
                if (a == 1)
                    rcv_marks();
                else
                    return;
            }
        } else {
            System.out.println("Error Input!!!");
        }
    }

    void stu_list() throws IOException {
        int dpt;
        System.out.println("Enter Department Code\n1.BCSE  2.BCHE  3.ELEC   4.MECH");
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        dpt = Integer.parseInt(bf.readLine());
        System.out.print("\033[H\033[2J");
        System.out.flush();
        if (dpt == 1)
            System.out.println("COMPUTER SCIENCE & ENGINEERING");
        if (dpt == 2)
            System.out.println("CHEMICAL ENGINEERING");
        if (dpt == 3)
            System.out.println("ELECTRICAL ENGINEERING");
        if (dpt == 4)
            System.out.println("MECHANICAL ENGINEERING");
        for (int itr = 0; itr < s[dpt - 1].size(); itr++) {
            student_adm st = s[dpt - 1].get(itr);
            st.show_stud(itr + 1);
        }
    }

    void sorted_list() throws IOException {
        int dpt;
        System.out.println("Enter Department Code\n1.BCSE  2.BCHE  3.ELEC   4.MECH");
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        dpt = Integer.parseInt(bf.readLine());
        System.out.print("\033[H\033[2J");
        System.out.flush();
        if (dpt == 1)
            System.out.println("COMPUTER SCIENCE & ENGINEERING");
        if (dpt == 2)
            System.out.println("CHEMICAL ENGINEERING");
        if (dpt == 3)
            System.out.println("ELECTRICAL ENGINEERING");
        if (dpt == 4)
            System.out.println("MECHANICAL ENGINEERING");
        int flag = student_adm.check_entry(s[dpt - 1]);
        if (flag == 1) {
            ArrayList<student_adm> s_sorted = new ArrayList();
            s_sorted = student_adm.sort_list(s[dpt - 1]);
            for (int itr = 0; itr < s[dpt - 1].size(); itr++) {
                student_adm st = s_sorted.get(itr);
                st.show_stud_grade(itr + 1);
            }
        } else {
            System.out.println("Marks not entered for all the students of the department.");
            return;
        }
    }

    void removeStud() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int dep_code;
        String rl;
        System.out.println("Enter roll number.");
        rl = bf.readLine();
        if (rl.substring(0, 4).equals("BCSE"))
            dep_code = 1;
        else if (rl.substring(0, 4).equals("BCHE"))
            dep_code = 2;
        else if (rl.substring(0, 4).equals("ELEC"))
            dep_code = 3;
        else if (rl.substring(0, 4).equals("MECH"))
            dep_code = 4;
        else {
            System.out.println("Error Input1!!!");
            return;
        }
        long mem;
        Runtime run = Runtime.getRuntime();
        //System.out.print("Memory presently allocated : ");
        mem = run.totalMemory() - run.freeMemory();
        //System.out.println(mem);
        student_adm stud = new student_adm();
        for (int i = 0; i < s[dep_code - 1].size(); i++) {
            if (s[dep_code - 1].get(i).roll.toString().equals(rl.toString())) {
                stud = s[dep_code - 1].get(i);
                break;
            }
        }
        if (stud.roll.substring(8).equals("0"))
            return;
        s[dep_code - 1].remove(stud);
        System.gc();

        //System.out.println("List Updated Successfully.");
        //System.out.print("Memory allocated now : ");
        mem = run.totalMemory() - run.freeMemory();
        //System.out.println(mem);
        //stu_list();
    }

    public void finalize() {
        System.out.println("Garbage Collector Running.");
    }
}

class student {
    public static void main(String[] args) throws IOException {
        University u = new University();
        u.admin_interface();
        System.gc();
    }

    public void finalize() {
        System.out.println("Garbage Collector Running.");
    }
}