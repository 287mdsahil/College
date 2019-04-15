import java.util.*;

class Item {
    String id;
    String name;
    double rate;
    int quantity;

    public Item(String nname, double rrate, int qquantity, int code) {
        name = new String(nname);
        rate = rrate;
        quantity = qquantity;
        genId(code);
    }

    public Item(Item i) {
        id = i.id;
        name = i.name;
        rate = i.rate;
        quantity = i.quantity;
    }

    private void genId(int code) {
        code = 1000 + code;
        id = name.toUpperCase().substring(0, 3) + Integer.toString(code).substring(1);
        System.out.println(id);
    }

    String getName() {
        return name;
    }

    String getId() {
        return id;
    }

    double getRate() {
        return rate;
    }

    int getQuattity() {
        return quantity;
    }

    void setRate(double r) {
        rate = r;
    }

    void setQuantity(int q) {
        quantity = q;
    }

    void display() {
        System.out.println();
        System.out.println("Id\t\t: " + id);
        System.out.println("Name\t\t: " + name);
        System.out.println("Rate\t\t: " + rate);
        System.out.println("Quantity\t: " + quantity);
    }
}

class ItemList {
    private static final int max = 100;
    int count;
    Item list[];

    ItemList() {
        count = 0;
        list = new Item[max];
    }

    int checkId(String iid) {
        for (int i = 0; i < count; i++) {
            if (list[i].getId().equals(iid))
                return i;
        }
        return -1;
    }

    boolean addItem() {
        Scanner in = new Scanner(System.in);
        System.out.println();
        System.out.print("Enter name : ");
        String name = in.nextLine();
        System.out.print("Enter rate : ");
        double rate = in.nextDouble();
        in.nextLine();
        System.out.print("Enter quantity : ");
        int quantity = in.nextInt();
        in.nextLine();
        list[count] = new Item(name, rate, quantity, count);
        count++;
        return true;
    }

    boolean addItem(Item item) {
        list[count] = new Item(item);
        count++;
        return true;
    }

    void displayAll() {
        for (int i = 0; i < count; i++)
            list[i].display();
    }

    void amountSearch(double st, double end) {
        for (int i = 0; i < count; i++)
            if (list[i].getRate() >= st && list[i].getRate() <= end)
                list[i].display();
    }

    void display() {
        System.out.print("Enter item code : ");
        Scanner in = new Scanner(System.in);
        String code = in.nextLine();
        int i = checkId(code);
        if (i == -1) {
            System.out.println("Item not found !");
            in.nextLine();
        } else {
            list[i].display();
        }
    }

    void remove() {
        System.out.print("Enter item code : ");
        Scanner in = new Scanner(System.in);
        String code = in.nextLine();
        int i = checkId(code);
        if (i == -1) {
            System.out.println("Item not found !");
            in.nextLine();
        } else {
            System.out.println("The following item will be removed !");
            list[i].display();
            System.out.print("Confirm(y/n): ");
            if (in.nextLine().charAt(0) == 'y' || in.nextLine().charAt(0) == 'Y') {
                for (; i < count - 1; i++) {
                    list[i] = new Item(list[i + 1]);
                }
                count--;
                System.out.println("Item removed !");
                in.nextLine();
            } else {
                System.out.println("Deletion aborted !");
                in.nextLine();
            }
        }
    }

    void update() {
        System.out.print("Enter item code : ");
        Scanner in = new Scanner(System.in);
        String code = in.nextLine();
        int i = checkId(code);
        if (i == -1) {
            System.out.println("Item not found !");
            in.nextLine();
        } else {
            System.out.println("Item to update : ");
            list[i].display();
            System.out.println("1. Update rate");
            System.out.println("2. Update quantity");
            System.out.print("Enter choice : ");
            int choice = in.nextInt();
            in.nextLine();
            if (choice == 1) {
                System.out.print("Enter new rate : ");
                double rate = in.nextDouble();
                in.nextLine();
                list[i].setRate(rate);

                System.out.println("Updated item :");
                list[i].display();
                in.nextLine();
            } else if (choice == 2) {
                System.out.print("Enter new quantity : ");
                int quantity = in.nextInt();
                in.nextLine();
                list[i].setQuantity(quantity);

                System.out.println("Updated item :");
                list[i].display();
                in.nextLine();
            } else {
                System.out.println("Invalid choice !");
                in.nextLine();
            }
        }
    }

    Item getItem(int i) {
        return list[i];
    }

    void showBill() {
        double total = 0;
        for (int i = 0; i < count; i++) {
            double cost = list[i].getQuattity() * list[i].getRate();
            total = total + cost;
            System.out.println(list[i].getId() + "\t" + list[i].getName() + "\t" + list[i].getQuattity() + " * "
                    + list[i].getRate() + "=" + cost);
        }
        System.out.println("Total Amount : " + total);
    }

}

class Interface {

    static ItemList l = new ItemList();

    private static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    private static boolean SEO() {
        Scanner in = new Scanner(System.in);
        while (true) {
            clearScreen();
            System.out.println("SEO Menu");
            System.out.println("-----------------");
            System.out.println("1. Display all items");
            System.out.println("2. Search Item");
            System.out.println("3. Enter new item");
            System.out.println("4. Remove item");
            System.out.println("5. Update item");
            System.out.println("6. Logout");
            System.out.print("Enter choice :");
            int choice = in.nextInt();
            in.nextLine();

            switch (choice) {
            case 1:
                l.displayAll();
                in.nextLine();
                break;
            case 2:
                l.display();
                in.nextLine();
                break;
            case 3:
                l.addItem();
                break;
            case 4:
                l.remove();
                break;
            case 5:
                l.update();
                break;
            case 6:
                return true;
            default:
                System.out.println("Invalid input !");
                in.nextLine();
                break;
            }

        }
    }

    private static boolean Sk() {
        Scanner in = new Scanner(System.in);
        while (true) {
            clearScreen();
            System.out.println("SEO Menu");
            System.out.println("-----------------");
            System.out.println("1. Display all items");
            System.out.println("2. Search Item");
            System.out.println("3. Issue items");
            System.out.println("4. Search with amount");
            System.out.println("5. Logout");
            System.out.print("Enter choice :");
            int choice = in.nextInt();
            in.nextLine();

            switch (choice) {
            case 1:
                l.displayAll();
                in.nextLine();
                break;
            case 2:
                l.display();
                in.nextLine();
                break;
            case 3:
                issue();
                break;
            case 4:
                amountSearch();
                in.nextLine();
                break;
            case 5:
                return true;
            default:
                System.out.println("Invalid input !");
                in.nextLine();
                break;
            }

        }
    }

    private static void issue() {
        ItemList issue = new ItemList();
        Scanner in = new Scanner(System.in);
        while (true) {
            clearScreen();
            System.out.print("Enter item id code to buy : ");
            String code = in.nextLine();
            int i = l.checkId(code);
            if (i == -1) {
                System.out.println("Item not found !");
            } else {
                System.out.println("Item to add :- ");
                l.getItem(i).display();
                System.out.print("Enter quantity : ");
                int quantity = in.nextInt();
                in.nextLine();
                if (l.getItem(i).getQuattity() < quantity) {
                    System.out.println("Not enough stock available !");
                } else {
                    System.out.print("Confirm(y/n) : ");
                    char choice = in.nextLine().charAt(0);
                    if (choice == 'y' | choice == 'Y') {
                        Item item = l.getItem(i);
                        l.getItem(i).setQuantity(l.getItem(i).getQuattity() - quantity);
                        item.setQuantity(quantity);
                        issue.addItem(item);
                        System.out.println("Item added !");
                    } else {
                        System.out.println("Aborted !");
                    }
                }
            }
            System.out.print("Enter more items ?(y/n) : ");
            char choice = in.nextLine().charAt(0);
            if (choice != 'y' && choice != 'Y') {
                break;
            }
        }
        clearScreen();
        System.out.println("Final bill :-");
        issue.showBill();
        in.nextLine();
    }

    private static void amountSearch() {
        Scanner in = new Scanner(System.in);
        double st = 0, end = 0;
        System.out.print("Enter the starting amount :");
        st = in.nextDouble();
        in.nextLine();
        System.out.print("Enter the ending amount : ");
        end = in.nextDouble();
        in.nextLine();
        l.amountSearch(st, end);
    }

    public static boolean loginMenu() {
        Scanner in = new Scanner(System.in);
        while (true) {
            clearScreen();
            System.out.println("-------------Menu-------------");
            System.out.println("1. SEO account");
            System.out.println("2. Sk account");
            System.out.println("3. Exit");
            System.out.print("Enter choice : ");

            int choice = in.nextInt();
            in.nextLine();
            switch (choice) {
            case 1:
                SEO();
                break;
            case 2:
                Sk();
                break;
            case 3:
                in.close();
                return true;
            default:
                System.out.println("Invalid input !");
                in.nextLine();
                break;
            }

        }
    }

}

class shop {
    public static void main(String[] args) {
        Interface.loginMenu();
    }
}