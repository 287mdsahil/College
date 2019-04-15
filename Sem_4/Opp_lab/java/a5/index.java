import java.util.*;
import java.io.*;

class File_index
{
    TreeMap<String,TreeSet<Integer>> t=new TreeMap<String,TreeSet<Integer>>();
    String str;
    public void index()
    {
        try
        {
            File f=new File("5.txt");
            Scanner s=new Scanner(f);
            boolean eof=false;
            int i=0;
            while(s.hasNext())
            {
                i++;
                str=s.nextLine();
                str = str.replaceAll("\\p{Punct}","");
                str=str.toLowerCase();
                StringTokenizer st=new StringTokenizer(str);
                for(int j=0;j<st.countTokens();j++)
                {
                    String token=st.nextToken();
                    if(t.containsKey(token))
                    {
                        TreeSet<Integer> ind=new TreeSet<Integer>();
                        ind=t.get(token);
                        ind.add(i);
                    }
                    else
                    {
                        TreeSet<Integer> ind=new TreeSet<Integer>();
                        ind.add(i);
                        t.put(token,ind);
                    }
                }
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File not Found.");
        }
        catch(IOException e)
        {
            System.out.println("I/O Error.");
        }
        display();
    }
    void display()
    { 
        System.out.println();
        for(Map.Entry m : t.entrySet()) 
        {
            System.out.println(m.getKey()+": " + m.getValue());
        }
        System.out.println();
    }
}
class index
{
    public static void main(String[] args)
    {
        File_index b=new File_index();
        b.index();
    }
}