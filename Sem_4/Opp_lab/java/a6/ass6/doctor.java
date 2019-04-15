package ass6;

import java.util.*;
import java.io.*;

class doctor
{
    patient[] p=new patient[5];
    doctor()
    {
        for(int i=0;i<5;i++)
        {
            p[i]=new patient();
        }
    }

    void display_doctors()
    {
        try
        {
            System.out.println("Doctors List");
            File f=new File("ass6/doctors.txt");
            Scanner s=new Scanner(f);
            while(s.hasNextLine())
            {
                System.out.println(s.nextLine());
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File Not Found.");
        }
    }
    void register_pat() throws IOException
    {
        display_doctors();
        System.out.println("\nEnter your choice.");
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int x=Integer.parseInt(bf.readLine());
        p[x-1].get_details(x);
    }
    void disp_patient_list(int i)
    {
        //System.out.println("PatientId\tName\tGender\tB.Group");
        p[i].display_details(i+1);
    }
}
class Hospital
{
    public static void main(String[] args) throws IOException
    {
        doctor doc=new doctor();
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        /*System.out.println("\t\t\tSTUPID HOSPITAL\n");
        System.out.println("Register a new patient.\nPress any digit to continue.");
        doc.register_pat();
        System.out.println("\nPress any digit to continue.");
        int x=Integer.parseInt(bf.readLine());*/
        while(true)
        {
            System.out.print("\033[H\033[2J");
            System.out.println("\t\t\tHOSPITAL\n");
            System.out.println(" 1. Register a new patient.\n 2. View Patient's list\n 3. View Doctor's List.\n 4. Record test results of a patient.\n 5. View Details of a particular patient.\n 6. Find a patient with social security number.\n 7. Exit\n");
            int x=Integer.parseInt(bf.readLine());
            switch(x)
            {
                case 1:
                    doc.register_pat();
                    break;
                case 2:
                {
                    doc.display_doctors();
                    System.out.println("\nEnter your choice.");
                    x=Integer.parseInt(bf.readLine());
                    doc.disp_patient_list(x-1);
                    break;
                }
                case 3:
                    doc.display_doctors();
                    break;
                case 4:
                {
                    System.out.println("Enter Patient's ID.");
                    String id=bf.readLine();
                    int j=id.charAt(3)-48;
                    int flag=0;
                    patient pat=new patient();
                    try{
                        pat=pat.find_id(id,j);
                        if(pat!=null)
                        {
                            flag=j;
                        }
                    }
                    catch(NullPointerException e)
                    {
                        flag=0; 
                    }
                    if(flag!=0)
                    {
                        pat.get_readings(flag);
                    }
                    else
                    {
                        System.out.println("Patient Id does not exist.");
                    }
                    break;
                }
                case 5:
                {
                    patient pat=new patient();
                    int flag=0;
                    System.out.println("Enter Patient's ID.");
                    String id=bf.readLine();
                    int j=id.charAt(3)-48;
                        try{
                        pat=pat.find_id(id,j);
                        flag=1;
                        //pat.display_readings(j);
                        System.out.println(pat.readDone(j));
                        if(pat.readDone(j)) pat.display_readings(j);
                        else pat.display_details();
                        }
                        catch(NullPointerException e)
                        {
                            e.printStackTrace();
                            //System.out.println("Patient Id does not exist.");
                        }
                    break;
                }
                case 6:
                {
                    patient pat=new patient();
                    int flag=0;
                    System.out.println("Enter Social Security Number.");
                    String id=bf.readLine();
                    int j=1;//id.charAt(3)-48;
                        try{
                        pat=pat.find_id_ssn(id,j);
                        flag=1;
                        //pat.display_readings(j);
                        //System.out.println(pat.readDone(j));
                        //if(pat.readDone(j)) pat.display_readings(j);
                        pat.display_details();
                        }
                        catch(NullPointerException e)
                        {
                            e.printStackTrace();
                            System.out.println("Patient Id does not exist.");
                        }
                    break;
                }
                case 7:
                    //System.out.println("\n\n\t\t\t\tTHANK YOU :)\n");
                    return ;
        
            
            }
            System.out.println("\nPress any digit to continue.");
            x=Integer.parseInt(bf.readLine());
        }
    }
}