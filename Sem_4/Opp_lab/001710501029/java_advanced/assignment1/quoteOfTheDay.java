import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.io.*;
import java.sql.Time;
import java.time.LocalDateTime;
import java.util.*;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;
import java.awt.event.ActionListener;

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

    public String showQuote(int quoteNumber) {
        String quote = new String();
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            for (int i = 0; i < quoteNumber; i++) {
                quote = br.readLine();
            }
            System.out.println(quote);// return quote instead
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

        return quote;

    }

    int genId() {
        int random = (int) new Random().nextInt(maxq - 1) + 1;
        if (q.search(random))
            return genId();
        else
            return random;
    }

    public String show() {
        return showQuote(genId());
    }
}

class Display {
    static public String display() {
        int hour = LocalDateTime.now().getHour();
        int day = LocalDateTime.now().getDayOfMonth();
        int month = LocalDateTime.now().getMonthValue();

        // System.out.println(hour);
        // System.out.println(day);
        // System.out.println(month);

        if (day == 15 && month == 8) {
            Quote q = new Quote("./quotes/independenceDay");
            return q.show();
        }

        else if (hour > 19 || hour < 4) {
            Quote q = new Quote("./quotes/night");
            return q.show();
        }

        else {
            Quote q = new Quote("./quotes/day");
            return q.show();
        }
    }
}

class QuoteFrame extends JFrame {

    private JTextArea quoteText;
    private JButton buttonNext;
    private JTextArea dateText;
    private JTextArea greetingText;
    int height = 500;
    int width = 800;

    public QuoteFrame() {
        setTitle("Quote of the day");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        createView();
        setSize(width, height);
        setLocationRelativeTo(null);
        setResizable(false);
        // pack();

    }

    class DisplayNextActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            nextQuote();
        }
    }

    private void createView() {

        JPanel parent = new JPanel();
        parent.setLayout(new BoxLayout(parent, BoxLayout.Y_AXIS));
        getContentPane().add(parent);

        JPanel panelTop = new JPanel();
        parent.add(panelTop);
        panelTop.setPreferredSize(new Dimension(800, 40));

        // add greeting
        greetingText = new JTextArea("Hello");
        greetingText.setLineWrap(true);
        greetingText.setWrapStyleWord(true);
        greetingText.setMargin(new Insets(10, 10, 10, 10));
        greetingText.setPreferredSize(new Dimension(600, 100));
        greetingText.setEditable(false);
        greetingText.setFont(new Font("Courier", Font.BOLD, 20));
        panelTop.add(greetingText);

        // adding date
        int day = LocalDateTime.now().getDayOfMonth();
        int month = LocalDateTime.now().getMonthValue();
        int year = LocalDateTime.now().getYear();
        dateText = new JTextArea(day + ":" + month + ":" + year);
        dateText.setLineWrap(true);
        dateText.setWrapStyleWord(true);
        dateText.setMargin(new Insets(10, 10, 10, 10));
        dateText.setPreferredSize(new Dimension(190, 100));
        dateText.setEditable(false);
        dateText.setFont(new Font("Courier", Font.BOLD, 20));
        panelTop.add(dateText);

        JPanel panelMiddle = new JPanel();
        parent.add(panelMiddle);
        panelMiddle.setPreferredSize(new Dimension(800, 340));

        // adding quote
        quoteText = new JTextArea(Display.display());
        quoteText.setLineWrap(true);
        quoteText.setWrapStyleWord(true);
        quoteText.setEditable(false);
        quoteText.setMargin(new Insets(10, 10, 10, 10));
        quoteText.setPreferredSize(new Dimension(800, 340));
        quoteText.setFont(new Font("Courier", Font.BOLD, 25));
        panelMiddle.add(quoteText);

        JPanel panelBottom = new JPanel();
        parent.add(panelBottom);
        panelBottom.setPreferredSize(new Dimension(800, 60));
        panelBottom.setBackground(Color.WHITE);
        panelBottom.setLayout(new FlowLayout(FlowLayout.RIGHT));
        panelBottom.setBorder(new EmptyBorder(10, 10, 10, 10));

        // adding button
        buttonNext = new JButton("Next");
        buttonNext.addActionListener(new DisplayNextActionListener());
        // buttonNext.setPreferredSize(new Dimension(80, 60));
        buttonNext.setMargin(new Insets(10, 15, 10, 15));
        panelBottom.add(buttonNext);

    }

    void nextQuote() {
        //quoteText.setText(Display.display());
        MyRunnable ro = new MyRunnable();
        Thread t = new Thread(ro);
        t.start();
    }

    class MyRunnable implements Runnable {
        @Override
        public void run() {
            quoteText.setText(Display.display());
        }
    }
}

public class quoteOfTheDay {
    public static void main(String[] args) {
        QuoteFrame q = new QuoteFrame();
        q.setVisible(true);
    }
}