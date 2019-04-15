import java.util.*;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.plaf.basic.BasicBorders;

import com.sun.java.swing.plaf.motif.MotifBorders.ButtonBorder;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class Node {
    String word;
    Node next;

    public Node() {
        word = new String();
        next = null;
    }

    public Node(String s) {
        word = new String(s);
        next = null;
    }

    String word() {
        return word;
    }

    // for debugging
    public void show() {
        System.out.print(word + " ");
    }
}

class linkedList {
    Node head;
    Node tail;

    public linkedList() {
        head = null;
        tail = null;
    }

    void insert_back(Node cur) {
        if (head == null) {
            head = cur;
            tail = cur;
        } else {
            head.next = cur;
            head = head.next;
            head.next = null;
        }
    }

    void insert_front(Node cur) {
        if (tail == null) {
            tail = cur;
            head = cur;
        } else {
            cur.next = tail;
            tail = cur;
        }
    }

    void delete_front() {
        if (tail == head) {
            tail = null;
            head = null;
        } else if (tail != null)
            tail = tail.next;
    }

    // for debugging
    void show() {
        Node cur = tail;
        while (cur != null) {
            System.out.print(cur.word + " ");
            cur = cur.next;
        }
        System.out.println();
    }
}

class MyFrame extends JFrame {
    private static int height = 400;
    private static int width = 500;
    private JPanel controlPanel;
    private JPanel displayPanel;
    JButton buttonInsertHead;
    JButton buttonInsertTail;
    JButton buttonDeleteHead;
    JButton buttonSearch;
    JTextPane textDisplay;
    linkedList list;

    public MyFrame() {
        setTitle("Linked_list");
        setSize(width, height);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        list = new linkedList();

        createView();
        setLocationRelativeTo(null);
    }

    class insertHeadActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {

            if (!textDisplay.getText().equals("")) {
                list.insert_front(new Node(textDisplay.getText()));

            }
            createDisplayPanel(null);
            textDisplay.setText("");
        }
    }

    class insertTailActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {

            if (!textDisplay.getText().equals(""))
                list.insert_back(new Node(textDisplay.getText()));
            createDisplayPanel(null);
            textDisplay.setText("");
        }
    }

    class deleteHeadActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            list.delete_front();
            createDisplayPanel(null);
            textDisplay.setText("");
        }
    }

    class searchActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (!textDisplay.getText().equals(""))
                createDisplayPanel(textDisplay.getText());
            textDisplay.setText("");
        }
    }

    void createView() {
        // create control panel
        createControlPanel();
        // create display panel
        displayPanel = new JPanel();
        createDisplayPanel(null);

        getContentPane().add(controlPanel, BorderLayout.NORTH);
        getContentPane().add(displayPanel, BorderLayout.CENTER);
    }

    void createControlPanel() {
        controlPanel = new JPanel();
        controlPanel.setLayout(new BoxLayout(controlPanel, BoxLayout.X_AXIS));
        controlPanel.setSize(width, 100);

        buttonInsertHead = new JButton("Insert head");
        buttonInsertTail = new JButton("Insert tail");
        buttonDeleteHead = new JButton("Delete head");
        buttonSearch = new JButton("Search");
        textDisplay = new JTextPane();

        textDisplay.setText("");
        textDisplay.setEditable(true);

        buttonInsertHead.addActionListener(new insertHeadActionListener());
        buttonInsertTail.addActionListener(new insertTailActionListener());
        buttonDeleteHead.addActionListener(new deleteHeadActionListener());
        buttonSearch.addActionListener(new searchActionListener());

        buttonInsertHead.setMargin(new Insets(10, 10, 10, 10));
        buttonInsertTail.setMargin(new Insets(10, 10, 10, 10));
        buttonDeleteHead.setMargin(new Insets(10, 10, 10, 10));
        buttonSearch.setMargin(new Insets(10, 10, 10, 10));
        textDisplay.setMargin(new Insets(10, 10, 10, 10));

        controlPanel.add(buttonInsertHead);
        controlPanel.add(buttonInsertTail);
        controlPanel.add(buttonDeleteHead);
        controlPanel.add(buttonSearch);
        controlPanel.add(textDisplay);
    }

    void createDisplayPanel(String s) {
        System.out.println("updating display panel");
        displayPanel.removeAll();
        displayPanel.setBorder(new EmptyBorder(30, 30, 30, 30));
        displayPanel.setLayout(new FlowLayout(FlowLayout.LEFT));
        displayPanel.setSize(width, 300);
        displayPanel.setBackground(Color.GRAY);

        JTextPane headText = new JTextPane();
        headText.setText("Head");
        headText.setEditable(false);
        headText.setBackground(Color.GRAY);
        headText.setMargin(new Insets(10, 10, 10, 10));
        headText.setBackground(Color.DARK_GRAY);
        headText.setForeground(Color.WHITE);
        displayPanel.add(headText);
        JTextPane firstArrowText = new JTextPane();
        firstArrowText.setText(">");
        firstArrowText.setEditable(false);
        firstArrowText.setBackground(Color.GRAY);
        displayPanel.add(firstArrowText);

        Node cur = new Node();
        cur = list.tail;
        while (cur != null) {
            JTextArea nodeText = new JTextArea();
            nodeText.setText(cur.word());
            nodeText.setEditable(false);
            nodeText.setBackground(Color.WHITE);
            nodeText.setMargin(new Insets(10, 10, 10, 10));
            displayPanel.add(nodeText);
            if (s != null && cur.word.equals(s)) {
                nodeText.setBackground(Color.BLUE);
                nodeText.setForeground(Color.WHITE);
            }
            JTextPane arrowText = new JTextPane();
            arrowText.setText(">");
            arrowText.setEditable(false);
            arrowText.setBackground(Color.GRAY);
            displayPanel.add(arrowText);
            cur = cur.next;
        }

        JTextPane tailText = new JTextPane();
        tailText.setText("Tail");
        tailText.setEditable(false);
        tailText.setBackground(Color.GRAY);
        tailText.setMargin(new Insets(10, 10, 10, 10));
        tailText.setBackground(Color.DARK_GRAY);
        tailText.setForeground(Color.WHITE);
        displayPanel.add(tailText);

        displayPanel.updateUI();
    }
}

// ------------------------------------------------------------
class linkedListApplet {
    public static void main(String[] args) {
        MyFrame f = new MyFrame();
        f.setVisible(true);

        /*
         * linkedList list = new linkedList(); list.insert_front(new Node("hello"));
         * list.delete_front(); list.insert_back(new Node("hi")); list.show();
         */
    }
}