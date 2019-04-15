import java.io.*;
import java.sql.Time;
import java.time.LocalDateTime;
import java.util.*;

class MyQueue implements Serializable {
    int[] a;
    int maxLen;
    int end;

    MyQueue(int max) {
        maxLen = max;
        end = 0;
        a = new int[maxLen];
        for (int i = 0; i < maxLen; i++) {
            a[i] = -1;
        }
    }

    void push(int x) {
        a[end] = x;
        end = (end + 1) % maxLen;
    }

    boolean search(int x) {
        for (int i = 0; i < maxLen; i++) {
            if (a[i] == x)
                return true;
        }
        return false;
    }

    void show() {
        for (int i = 0; i < maxLen; i++) {
            if (a[i] != -1) {
                System.out.print(a[i] + " ");
            }
        }
        System.out.println();
    }
}

class Quote {

    // set variables here
    private static final int max = 10;
    private static final int maxq = 20;

    private static final String prev = new String("./quotes/prevQueue");
    MyQueue q;
    String file;

    Quote(String fileString) {
        file = new String(fileString);
        q = new MyQueue(max);
        try {
            ObjectInputStream oin = new ObjectInputStream(new FileInputStream(prev));
            q = (MyQueue) oin.readObject();
            // q.show();
        } catch (FileNotFoundException e) {
            // e.printStackTrace();
        } catch (IOException e) {
            // e.printStackTrace();
        } catch (ClassNotFoundException e) {
            // e.printStackTrace();
        }
    }

    public void showQuote(int quoteNumber) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            String quote = new String();
            for (int i = 0; i < quoteNumber; i++) {
                quote = br.readLine();
            }
            System.out.println(quote);
        } catch (FileNotFoundException nf) {
            System.out.println("File not found");
        } catch (IOException ef) {
            System.out.println("IO exceptio occurred");
        }

        // pushing shown index to queue
        q.push(quoteNumber);

        // updating file
        try {
            ObjectOutputStream oout = new ObjectOutputStream(new FileOutputStream(prev, false));
            oout.writeObject(q);
        } catch (FileNotFoundException e) {
            // e.printStackTrace();
        } catch (IOException e) {
            // e.printStackTrace();
        } // catch (ClassNotFoundException e) {
          // e.printStackTrace();
          // }

    }

    int genId() {
        int random = (int) new Random().nextInt(maxq - 1) + 1;
        if (q.search(random))
            return genId();
        else
            return random;
    }

    public void show() {
        showQuote(genId());
    }
}

class Display {
    static public void display() {
        int hour = LocalDateTime.now().getHour();
        int day = LocalDateTime.now().getDayOfMonth();
        int month = LocalDateTime.now().getMonthValue();

        //System.out.println(hour);
        //System.out.println(day);
        //System.out.println(month);

        if (day == 15 && month == 8) {
            Quote q = new Quote("./quotes/independenceDay");
            q.show();
        }

        else if (hour > 19 || hour < 4) {
            Quote q = new Quote("./quotes/night");
            q.show();
        }

        else {
            Quote q = new Quote("./quotes/day");
            q.show();
        }
    }
}

public class quoteOfTheDay {
    public static void main(String[] args) {
        Display.display();
    }
}