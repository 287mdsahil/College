package ass6;

import java.util.*;
import java.io.*;


class patient implements Serializable
{
    String p_name,p_id,bg,gender,ssn;
    int bpl,bph;
    Double temp;
    patient()
    {
        bpl=0;
        bph=0;
        temp=0.0;
    }
    int get_number_of_patients(int j)
    {
        try
        {
            File f=new File("ass6/patient"+Integer.toString(j)+".txt");
            Scanner s=new Scanner(f);
            int i=0;
            while(s.hasNextLine())
            {
                s.nextLine();
                i++;
            }
            return i;
        }
        catch(FileNotFoundException e)
        {
            return 0;
        }
    }
    void get_details(int j) throws IOException
    {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Name: ");
        p_name=bf.readLine();
        int i=get_number_of_patients(j);
        gen_code(i+1,j);
        System.out.print("Gender[M/F]: ");
        gender=bf.readLine();
        System.out.print("B.Group: ");
        bg= bf.readLine();
        System.out.print("Social Security Number: ");
        ssn= bf.readLine();
        try
        {
            FileWriter fw=new FileWriter("ass6/patient"+Integer.toString(j)+".txt",true);
            PrintWriter p=new PrintWriter(fw);
            p.println(p_id+"\t"+p_name+"\t"+ gender + "\t"+ bg+"\t"+ssn);
            p.close();
        }
        catch(IOException e)
        {
            System.out.println("I/O Error occured!!!");
        }
    }
    void get_readings(int j) throws IOException
    {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        //display_details(j);
        System.out.println("\nTemperature(in F): ");
        temp=Double.parseDouble(bf.readLine());
        System.out.println("Enter Blood Pressure.");
        bpl=Integer.parseInt(bf.readLine());
        bph=Integer.parseInt(bf.readLine());
        try{
            //FileOutputStream f=new FileOutputStream("ass6/patient_readings"+Integer.toString(j)+".txt",true);
            FileWriter fi=new FileWriter("ass6/patient_readings"+Integer.toString(j)+".txt");
            PrintWriter pw=new PrintWriter(fi);
            pw.println(p_id+"\t"+ssn+"\t"+p_name+"\t"+ gender + "\t"+ bg + "\t" + bpl+"/"+bph+"\t" + temp +"\u00b0F");
            pw.close();
        }
        catch(IOException e)
        {
            System.out.println("I/O Error Occured!!!");
        }
    }
    void gen_code(int i,int j)
    {
        p_id="PAT"+Integer.toString(j) + Integer.toString(i/10) + Integer.toString(i%10);
    }
    boolean readDone(int i)
    {
        try{
            File fi=new File("ass6/patient_readings"+Integer.toString(i)+".txt");
            Scanner s=new Scanner(fi);
            while(s.hasNextLine())
            {
                    patient p=new patient();
                    String str=s.nextLine();
                    StringTokenizer st=new StringTokenizer(str,"\t");
                    p.p_id=st.nextToken();
                    //System.out.println(str+" "  +p_id);
                    if(p.p_id.equals(p_id))
                    {
                        p.ssn=st.nextToken();
                        p.p_name=st.nextToken();
                        p.gender=st.nextToken();
                        p.bg=st.nextToken();
                        if(st.hasMoreTokens())
                        return true;
                        else return false;
                    }
                //e.printStackTrace();}
            }
            //System.out.println("Patient does not exist.");
        }
        catch(IOException e)
        {
            e.printStackTrace();
            System.out.println("I/O Error Occured!!!");
        }
        return false;
    }
    void display_details(int i)
    {
        try{
            File f=new File("ass6/patient"+Integer.toString(i)+".txt");
            Scanner s=new Scanner(f);
            while(s.hasNextLine())
            {
                System.out.println(s.nextLine());
            }
        }
        catch(IOException e)
        {
            System.out.println("I/O Error Occured!!!");
        }
    }
    void display_details()
    {
        System.out.println(p_id+"\t"+ssn+"\t"+p_name+"\t"+gender+"\t"+bg);
    }
    void display_readings(int i)
    {
        try{
            File fi=new File("ass6/patient_readings"+Integer.toString(i)+".txt");
            Scanner s=new Scanner(fi);
            boolean eof=false;
            
            while(s.hasNextLine())
            {
                patient p=new patient();
                String str=s.nextLine();
                StringTokenizer st=new StringTokenizer(str,"\t");
                p.p_id=st.nextToken();
                //System.out.println(str+" "  +p_id);
                if(p.p_id.equals(p_id))
                {
                    System.out.println(str);
                }   
                //System.out.println(s.nextLine());
            }
        }//e.printStackTrace();}
        catch(FileNotFoundException e)
        {
            System.out.println("File Not Found.");
        }
            System.out.println("Patient does not exist.");
    }
        
    /*void disp_read()
    {
        System.out.println(p_id+"\t"+p_name+"\t"+ gender + "\t"+ bg + "\t" + bpl+"/"+bph+"\t" + temp +"\u00b0F");
    }*/
    patient find_id(String code,int i)
    {
        int flag=0;
        try{
            File fi=new File("ass6/patient"+Integer.toString(1)+".txt");
            //System.out.println(fi.canRead());
            Scanner s=new Scanner(fi);
            /*FileOutputStream fo=new FileOutputStream("patient_readings.dat",true);
            ObjectOutputStream oo=new ObjectOutputStream(fo);*/
            while(s.hasNext())
            {
                String str=s.nextLine();
                StringTokenizer st=new StringTokenizer(str,"\t");
                p_id=st.nextToken();
                //System.out.println(str+" "  +p_id);
                if(p_id.equals(code))
                {
                    ssn=st.nextToken();
                    p_name=st.nextToken();
                    gender=st.nextToken();
                    bg=st.nextToken();
                    bpl=0;
                    bph=0;
                    temp=0.0;
                    return this;
                }
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File Not Found.");
        }
            if(flag==0)
            {
                System.out.println("Patient does not exist.");
            }
          System.err.println("I/O Error Occured");
        return null;
    }
    patient find_id_ssn(String code,int i)
    {
        int flag=0;
        try{
            File fi=new File("ass6/patient"+Integer.toString(i)+".txt");
            //System.out.println(fi.canRead());
            Scanner s=new Scanner(fi);
            /*FileOutputStream fo=new FileOutputStream("patient_readings.dat",true);
            ObjectOutputStream oo=new ObjectOutputStream(fo);*/
            while(s.hasNext())
            {
                String str=s.nextLine();
                StringTokenizer st=new StringTokenizer(str,"\t");
                p_id=st.nextToken();
                p_name=st.nextToken();
                gender=st.nextToken();
                bg=st.nextToken();
                ssn=st.nextToken();
                //System.out.println(str+" "  +p_id);
                if(ssn.equals(code))
                {
                    //p_name=st.nextToken();
                    //gender=st.nextToken();
                    //bg=st.nextToken();
                    bpl=0;
                    bph=0;
                    temp=0.0;
                    return this;
                }
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File Not Found.");
        }
            if(flag==0)
            {
                System.out.println("Patient does not exist.");
            }
          System.err.println("I/O Error Occured");
        return null;
    }
}