import java.util.*;
import java.util.Scanner;

class Stack {
    char ARR[];
    int HEAD;
    int MAX;

    public Stack() {
        MAX = 100;
        ARR = new char[MAX];
        HEAD = -1;
    }

    private boolean underflow() {
        if (HEAD < 0)
            return true;
        else
            return false;
    }

    private boolean overflow() {
        if (HEAD > MAX)
            return true;
        else
            return false;
    }

    char pop() {
        if (underflow()) {
            System.out.println("Underflow");
            System.exit(0);
        }
        HEAD = HEAD - 1;
        return ARR[HEAD + 1];
    }

    void push(char e) {
        if (overflow()) {
            System.out.println("Overflow");
            System.exit(0);
        }
        HEAD = HEAD + 1;
        ARR[HEAD] = e;
        return;
    }

    int size() {
        return HEAD + 1;
    }

    void show() {
        for (int i = 0; i <= HEAD; i++)
            System.out.print(ARR[i]);
    }

}

public class parentheses {
    public static void main(String args[]) {
        Stack st = new Stack();
        String s = new String();
        boolean correctSyntax = true;
        Scanner cin = new Scanner(System.in);
        s = cin.nextLine();
        //System.out.println(s);
        
        for (int i = 0; i < s.length(); i++) {
            char dum = s.charAt(i);
            //System.out.println(dum);
            if (dum == '(' || dum == '[' || dum == '{')
                st.push(dum);
            
            if (dum == ')' || dum == ']' || dum == '}') {
                char dum2 = st.pop();
                if (st.size() == -1) {
                    correctSyntax = false;
                    //System.out.print("1 ");
                    break;
                }
                switch (dum) {
                case ')': {
                    if (dum2 != '(') {
                        correctSyntax = false;
                        //System.out.print("2 ");
                    }
                    break;
                }
                case '[': {
                    if (dum2 != ']') {
                        correctSyntax = false;
                        //System.out.print("3 ");
                    }
                    break;
                }
                case '{': {
                    if (dum2 != '}') {
                        correctSyntax = false;
                        //System.out.print("4 ");
                    }
                    break;
                }
                }
            }
            // st.show();
            // System.out.println(correctSyntax);
            // System.out.println("" + dum + dum2);
            
        }

        //System.out.println(correctSyntax+""+ st.size());
        if (!correctSyntax || st.size() != 0)
            System.out.println("Incorrect syntax");
        else
            System.out.println("Correct syntax");
        cin.close();
        return;
    }
}