import java.util.Vector;
import java.util.Scanner;
import java.util.Collections;
import java.time.format.DateTimeFormatter;  
import java.time.LocalDateTime;
import java.text.DateFormat;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.io.*; 
import java.lang.*;
import java.util.*;

public class Assignment_2{
    public class Item{
        Scanner cin= new Scanner(System.in);
        String itemCode;
        String itemName;
        double itemRate;
        int itemQuantity;
        public String retItemName()
        {
            return itemName;
        }
        public void generatItemCode(String iName, int number){
            DecimalFormat formatter = new DecimalFormat("000");
		    String aFormatted = formatter.format(number);
            itemCode=iName.substring(0,3)+aFormatted;
            itemName=iName;
        }
        public void getRate()
        {
            System.out.println("Enter the rate :");
            itemRate =cin.nextDouble();
        }
         public void getQuantity()
        {
            System.out.print("Enter the quantity :");
            itemQuantity=cin.nextInt();

        }
        public double retRate(){
            return itemRate;
        }
        public void PrintDetails(){
            System.out.println("Item Code = "+itemCode);
            System.out.println("Item Name = "+itemName);
            System.out.println("Item Quantity = "+itemQuantity);
            System.out.println("Item Rate = "+itemRate);

        }
        public String retCode(){
            return itemCode;
        }
        public int retQty(){
            return itemQuantity;
        }
        public void decQty(int qty){
            itemQuantity=itemQuantity-qty;
        }



    }
    public class ItemList{
        Vector<Item> Itemlist= new Vector<Item>();
        public Vector<Item> retItemList(){
            return Itemlist;
        }
        public int EntryOrder(String iName){
            int order=0;
            for(int i=0;i<Itemlist.size();i++)
            {
                if(iName.equals(Itemlist.get(i).retItemName()))
                order++;
            }
            return (order+1);
        }
        public void printAll()
        {
            for(int i=0;i<Itemlist.size();i++)
            {
                Itemlist.get(i).PrintDetails();
             }
         }
        public void insert(Item i){
            Itemlist.add(i);
        }
        public int SearchCode(String iCode){
            int index=-1;
            for(int i=0;i<Itemlist.size();i++)
            {
                if(iCode.equals(Itemlist.get(i).retCode()))
                index=i;
            }
            return index;
        }
        public void PrintAbove(double myRate){
            int dect=0;
            System.out.println("\nHere is the list of items above your price\n");
            for(int i=0;i<Itemlist.size();i++){
                if(Itemlist.get(i).retRate()>=myRate){
                Itemlist.get(i).PrintDetails();
                System.out.println("");
                dect=1;
                }
            }
            if(dect==0){
                System.out.println("\nSorry! We found nothing :(\n");
            }

        }
        public void SearchName(String iName){
            int dect=0;
            for(int i=0;i<Itemlist.size();i++){
                if(Itemlist.get(i).retItemName().equals(iName)){
                    System.out.println("We found a valid ITEMCODE for your item :" + Itemlist.get(i).retCode());
                    dect=1;
                }
            
        }
        if(dect==0)
                System.out.println("\nSorry! We found no match for your item :(\n");

    }
    }

    public class MenuDrive{
        ItemList Electronics= new ItemList();
        public void Drive(){	
			Scanner cin= new Scanner(System.in);
            while(true){
                System.out.println("\nChoose the Interface :\n\n");
                System.out.println("1. Stock Entry Operator (SEO)");
                System.out.println("2. Shopkipper (SK)\n\n");
                
                int checker;
                checker= cin.nextInt();
                cin.nextLine();
                if(checker==1)
                {
                    while(true){
                    System.out.println("\n\n1. Add an Item");
                    System.out.println("2. Change Rate of an Item");
                    System.out.println("3. Issue an Item");
                    System.out.println("4. Receive an Item");
                    System.out.println("5. Check Quantity of an Item");
                    System.out.println("6. Check Items Higher than your cutoff price");
                    System.out.println("7. EXIT\n\n");
                    int g=cin.nextInt();
                    cin.nextLine();
                        if(g==1){
                            System.out.println("Enter the Item Name :");
                            String iName=cin.nextLine();
                            int entryOrder= Electronics.EntryOrder(iName);
                            Item i= new Item();
                            i.generatItemCode( iName, entryOrder);
                            i.getRate();
                            i.getQuantity();
                            Electronics.insert(i);
                            System.out.println("\n\n** One Item Added** \n\n");
                            i.PrintDetails();

                        }
                        if(g==2){
                            System.out.println("Enter the Item Code :");
                            String iCode=cin.nextLine();
                            
                            int index=Electronics.SearchCode(iCode);
                            if(index==-1)
                            System.out.println("Item not available. Item Code invalid :-( ");
                            else{
                            
                            Electronics.retItemList().get(index).getRate();
                            System.out.println("\n\n** Now the details of the item ** \n\n");
                            Electronics.retItemList().get(index).PrintDetails();
                            }

                        }
                        if(g==3){
                            System.out.println("Enter the Item Code :");
                            String iCode=cin.nextLine();
                            int index=Electronics.SearchCode(iCode);
                            if(index==-1)
                            System.out.println("Item not available. Item Code invalid :-( ");
                            else{
                            if(Electronics.retItemList().get(index).retQty()<1)
                            System.out.println("Item is out of stock! Try again later :-(");
                            else{
                            System.out.println("\n\n** Now the details of the item ** \n\n");
                            Electronics.retItemList().get(index).PrintDetails();
                            System.out.println("How much quantity you want to ISSUE ? :");
                            int qty=cin.nextInt();
                            if(qty<=Electronics.retItemList().get(index).retQty())
                            {
                                System.out.println("Issue is possible : Item issued :-)");
                                Electronics.retItemList().get(index).decQty(qty);
                                System.out.println("\n\n** Now the details of the item ** \n\n");
                                Electronics.retItemList().get(index).PrintDetails();
                            }
                            else
                            System.out.println("Issue is NOT possible :");
                            }
                            }

                        }
                        if(g==4){
                            System.out.println("Enter the Item Code :");
                            String iCode=cin.nextLine();
                            int index=Electronics.SearchCode(iCode);
                            if(index==-1)
                            System.out.println("Item not available. Item Code invalid :-( ");
                            else{
                                System.out.println("\n\n** Now the details of the item ** \n\n");
                                Electronics.retItemList().get(index).PrintDetails();
                                System.out.println("How much quantity you want to RECEIVE ? :");
                                int qty=cin.nextInt();
                                if(qty<=0)
                                {
                                    System.out.println("You entered invalid quantity to add :-(");
                                }
                                else
                                {
                                    System.out.println("Receive is possible : Item received :-)");
                                    Electronics.retItemList().get(index).decQty(-qty);
                                    System.out.println("\n\n** Now the details of the item ** \n\n");
                                    Electronics.retItemList().get(index).PrintDetails(); 
                                }
                            }

                        }
                        if(g==5){
                            System.out.println("Enter the Item Code :");
                            String iCode=cin.nextLine();
                            int index=Electronics.SearchCode(iCode);
                            if(index==-1)
                            System.out.println("Item not available. Item Code invalid :-( ");
                            else{
                              System.out.println("Item available. Existing quantity of the item = "+Electronics.retItemList().get(index).retQty());  
                            }


                        }
                        if(g==6){
                            System.out.println("Enter the Desired Rate :");
                            double myRate=cin.nextDouble();
                            Electronics.PrintAbove(myRate);

                        }
                        else if(g==7)
                        break;
                        else{}
                    }

                }
                else if(checker==2)
                {
                    while(true){
                    System.out.println("\n\n1.Check exsistence of an Item");
                    System.out.println("2. Check Quantity of an Item");
                    System.out.println("3. Issue an Item");
                    System.out.println("4. Receive an Item");
                    System.out.println("5. EXIT");
                    int g=cin.nextInt();
                    cin.nextLine();
                        if(g==1){
                            Electronics.printAll();
                            System.out.println("Enter the Item Name :");
                            String iName=cin.nextLine();
                            Electronics.SearchName(iName);

                        }
                        if(g==2){
                             System.out.println("Enter the Item Code :");
                            String iCode=cin.nextLine();
                            int index=Electronics.SearchCode(iCode);
                            if(index==-1)
                            System.out.println("Item not available. Item Code invalid :-( ");
                            else{
                              System.out.println("Item available. Existing quantity of the item = "+Electronics.retItemList().get(index).retQty());  
                            }


                        }
                        if(g==3){
                             System.out.println("Enter the Item Code :");
                            String iCode=cin.nextLine();
                            int index=Electronics.SearchCode(iCode);
                            if(index==-1)
                            System.out.println("Item not available. Item Code invalid :-( ");
                            else{
                            if(Electronics.retItemList().get(index).retQty()<1)
                            System.out.println("Item is out of stock! Try again later :-(");
                            else{
                            System.out.println("\n\n** Now the details of the item ** \n\n");
                            Electronics.retItemList().get(index).PrintDetails();
                            System.out.println("How much quantity you want to ISSUE ? :");
                            int qty=cin.nextInt();
                            if(qty<=Electronics.retItemList().get(index).retQty())
                            {
                                System.out.println("Issue is possible : Item issued :-)");
                                Electronics.retItemList().get(index).decQty(qty);
                                System.out.println("\n\n** Now the details of the item ** \n\n");
                                Electronics.retItemList().get(index).PrintDetails();
                            }
                            else
                            System.out.println("Issue is NOT possible :");
                            }
                            }

                        }
                        if(g==4){
                              System.out.println("Enter the Item Code :");
                            String iCode=cin.nextLine();
                            int index=Electronics.SearchCode(iCode);
                            if(index==-1)
                            System.out.println("Item not available. Item Code invalid :-( ");
                            else{
                                System.out.println("\n\n** Now the details of the item ** \n\n");
                                Electronics.retItemList().get(index).PrintDetails();
                                System.out.println("How much quantity you want to RECEIVE ? :");
                                int qty=cin.nextInt();
                                if(qty<=0)
                                {
                                    System.out.println("You entered invalid quantity to add :-(");
                                }
                                else
                                {
                                    System.out.println("Receive is possible : Item received :-)");
                                    Electronics.retItemList().get(index).decQty(-qty);
                                    System.out.println("\n\n** Now the details of the item ** \n\n");
                                    Electronics.retItemList().get(index).PrintDetails(); 
                                }
                            }
                            
                        }
                        else if(g==5)
                        break;
                        else{}
                    }
                }
                else break;
            }
        }
    }

	public static void main(String args[])
	{
		Assignment_2 secondAssignment= new Assignment_2();
		MenuDrive m =  secondAssignment.new MenuDrive();
		m.Drive();
		
	}
} 
