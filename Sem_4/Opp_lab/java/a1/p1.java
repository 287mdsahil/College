import java.util.*;

//System.out.print("\033\143");
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
		System.out.println("-----------------------------------------------------------");
		System.out.println("Roll :" + roll);
		System.out.println("Name :" + name);
		System.out.println("Course :" + course);
		System.out.println("Admission Date :" + adm_date);
		System.out.println("-----------------------------------------------------------");
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

// -----------------------------------------------------------------------------------------
class StudentList {
	public int count = 0;
	public Student list[] = new Student[100];
	public Student meritList[] = new Student[100];
	String dept;
	String sub[] = new String[5];
	String sub1;

	public void setSub() {
		Scanner s = new Scanner(System.in);
		for (int i = 0; i < 5; ++i) {
			System.out.print("Enter Subject Name :" + "(" + (i + 1) + ")");
			sub[i] = s.nextLine();
		}
		;
	};

	public void setDept(String s) {
		dept = s;
	}

	public void admitStudent() {
		String choice;
		Scanner s = new Scanner(System.in);
		System.out.print("\033\143");
		while (true) {
			System.out.println("Enter following student details");
			Student obj = new Student();
			obj.setData();
			obj.setCourse(dept);
			String r = dept + "/";
			Calendar c = Calendar.getInstance();
			r = r + c.get(Calendar.YEAR) % 2000;
			if (count + 1 < 10) {
				r = r + "00" + (count + 1);
			} else if (count + 1 >= 10 && count + 1 <= 99) {
				r = r + "0" + (count + 1);
			} else {
				r = r + (count + 1);
			}
			;
			obj.setRoll(r);
			list[count] = obj;
			count++;
			System.out.print("Do you wish to exit(y/n)? ");
			choice = s.nextLine();
			if (choice.equals("y") || choice.equals("Y")) {
				return;
			} else {
				System.out.print("\033\143");
				System.out.println("Admiting next student");
			}
			;
		}
	};

	public void displayAll() {
		Scanner s = new Scanner(System.in);
		System.out.println("\033\143");
		System.out.println("-----------------------------------------------------------");
		System.out.println(dept);
		System.out.println("-----------------------------------------------------------");
		for (int i = 0; i < count; ++i) {
			list[i].displayData();
			System.out.println("-----------------------------------------------------------");
			System.out.print("\n");
		}
		;
		s.nextLine();
		s.nextLine();
	};

	public void prepareMarksheet(int id) {
		Scanner s = new Scanner(System.in);
		System.out.print("\033\143");
		list[id].displayName();
		for (int i = 0; i < 5; ++i) {
			System.out.print("Enter marks in " + sub[i] + ": ");
			list[id].returnMarks()[i] = s.nextInt();
		}
		;
		list[id].setCGPA();
	};

	public void displayMarksheet(int id) {
		System.out.println("\033\143");
		list[id].displayData();
		System.out.println("Subject Marks");
		System.out.println("-----------------------------------------------------------");
		for (int i = 0; i < 5; ++i) {
			System.out.println(sub[i] + " :" + list[id].returnMarks()[i]);
		}
		;
		System.out.println("-----------------------------------------------------------");
		list[id].displayCGPA();
		System.out.println("-----------------------------------------------------------");
		// s.next();s.next();
	};

	public void prepareRanklist() {
		meritList = list.clone();
		float max;
		Student dummy = new Student();
		for (int i = 0; i < count; ++i) {
			max = meritList[i].cgpa;
			for (int j = i + 1; j < count; ++j) {
				if (meritList[j].cgpa > max) {
					dummy = meritList[i];
					meritList[i] = meritList[j];
					meritList[j] = dummy;
					max = list[j].cgpa;
				}
				;
			}
			;
		}
		;
	};

	public void displayRanklist() {
		System.out.println("-----------------------------------------------------------");
		for (int i = 0; i < count; ++i) {
			meritList[i].displayName();
			meritList[i].displayCGPA();
			System.out.println("-----------------------------------------------------------");
		}
		;
		Scanner s = new Scanner(System.in);
		s.nextLine();
	}

};

class Engineering {
	int count = 4;
	StudentList BCSE = new StudentList();
	StudentList ETCE = new StudentList();
	StudentList CIVL = new StudentList();
	StudentList ARCH = new StudentList();

	public void setDept() {
		String s;
		System.out.println("-----------------------------------------------------------");
		System.out.println("Please add the necessary subject information");
		System.out.println("-----------------------------------------------------------");

		System.out.println("-----------------------------------------------------------");
		s = "Computer Science and Engineering";
		System.out.println(s);
		BCSE.setDept("BCSE");
		System.out.println("-----------------------------------------------------------");
		BCSE.setSub();

		s = "Electronincs and Telecommunication";
		System.out.println("-----------------------------------------------------------");
		System.out.println(s);
		ETCE.setDept("ETCE");
		System.out.println("-----------------------------------------------------------");
		ETCE.setSub();

		s = "Civil Engineering";
		System.out.println("-----------------------------------------------------------");
		System.out.println(s);
		CIVL.setDept("CIVL");
		System.out.println("-----------------------------------------------------------");
		CIVL.setSub();

		s = "Architecture";
		System.out.println("-----------------------------------------------------------");
		System.out.println(s);
		ARCH.setDept("ARCH");
		System.out.println("-----------------------------------------------------------");
		ARCH.setSub();
		System.out.print("\033\143");

	};

	public void admission() {
		int choice;
		Scanner s = new Scanner(System.in);
		System.out.println("Select department for conducting admission :\n" + "(1)Computer Science and Engineering");
		System.out.println("(2)Electronincs and Telecommunication\n" + "(3)Civil Engineering\n" + "(4)Architecture");
		choice = s.nextInt();
		if (choice == 1)
			BCSE.admitStudent();
		else if (choice == 2)
			ETCE.admitStudent();
		else if (choice == 3)
			CIVL.admitStudent();
		else if (choice == 4)
			ARCH.admitStudent();
		else
			return;
	};

	public void enquiry() {
		int choice, roll;
		Scanner s = new Scanner(System.in);
		System.out.print("\033\143");
		System.out.println("Select department for conducting Enquiry :\n" + "(1)Computer Science and Engineering");
		System.out.println("(2)Electronincs and Telecommunication\n" + "(3)Civil Engineering\n" + "(4)Architecture");
		choice = s.nextInt();
		System.out.print("\033\143");
		System.out.print("Enter roll:");
		roll = s.nextInt() - 1;
		if (choice == 1) {
			BCSE.list[roll].displayData();
			s.nextLine();
			s.nextLine();
		} else if (choice == 2) {
			ETCE.list[roll].displayData();
			s.nextLine();
			s.nextLine();
		} else if (choice == 3) {
			CIVL.list[roll].displayData();
			s.nextLine();
			s.nextLine();
		} else if (choice == 4) {
			ARCH.list[roll].displayData();
			s.nextLine();
			s.nextLine();
		} else
			return;
	};

	public void marksheet() {
		System.out.print("\033\143");
		int choice, roll;
		Scanner s = new Scanner(System.in);
		System.out.println("Select department for preparing marksheet:\n" + "(1)Computer Science and Engineering");
		System.out.println("(2)Electronincs and Telecommunication\n" + "(3)Civil Engineering\n" + "(4)Architecture");
		choice = s.nextInt();
		String st;
		if (choice == 1) {
			for (int i = 0; i < BCSE.count; ++i) {
				BCSE.prepareMarksheet(i);
				BCSE.displayMarksheet(i);
				s.nextLine();
				s.nextLine();
			}
			;
		} else if (choice == 2) {
			for (int i = 0; i < ETCE.count; ++i) {
				ETCE.prepareMarksheet(i);
				ETCE.displayMarksheet(i);
				s.nextLine();
				s.nextLine();
			}
			;
		} else if (choice == 3) {
			for (int i = 0; i < CIVL.count; ++i) {
				CIVL.prepareMarksheet(i);
				CIVL.displayMarksheet(i);
				s.nextLine();
				s.nextLine();
			}
			;
		} else if (choice == 4) {
			for (int i = 0; i < ARCH.count; ++i) {
				ARCH.prepareMarksheet(i);
				ARCH.displayMarksheet(i);
				s.nextLine();
				s.nextLine();
			}
			;
		} else
			return;
	}

	public void ranklist() {
		int choice, roll;
		Scanner s = new Scanner(System.in);
		System.out.print("\033\143");
		System.out.println("Select department for viewing meritlist:\n" + "(1)Computer Science and Engineering");
		System.out.println("(2)Electronincs and Telecommunication\n" + "(3)Civil Engineering\n" + "(4)Architecture");
		choice = s.nextInt();
		System.out.print("\033\143");
		if (choice == 1) {
			BCSE.prepareRanklist();
			BCSE.displayRanklist();
		} else if (choice == 2) {
			ETCE.prepareRanklist();
			ETCE.displayRanklist();
		} else if (choice == 3) {
			CIVL.prepareRanklist();
			CIVL.displayRanklist();
		} else if (choice == 4) {
			ARCH.prepareRanklist();
			ARCH.displayRanklist();
		} else
			return;
	}

}

public class p1 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int choice;
		Engineering obj = new Engineering();
		System.out.print("\033\143");
		obj.setDept();
		obj.admission();
		obj.marksheet();
		while (true) {
			System.out.print("\033\143");
			System.out.println("Choose\n(1)Enquiry\n(2)Merit List\n(3)Exit");
			choice = s.nextInt();
			if (choice == 1)
				obj.enquiry();
			else if (choice == 2)
				obj.ranklist();
			else {
				System.out.print("\033\143");
				System.out.println("THANK YOU");
				break;
			}
			;
		}
		;

	};
};
