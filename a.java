import java.util.*;
import java.net.*;
import java.io.*;
class a
{
	public static void main(String args[]) throws Exception
	{
		Socket s=new Socket("localhost",9999);
		InputStream is=s.getInputStream();
		Scanner sc=new Scanner(is);
		File f=new File("");
		PrintWriter pw=new PrintWriter(f);
		while(sc.hasNextLine())
		{
			pw.println(sc.nextLine());
		}
		System.out.println("file recieved");
		sc.close();
		s.close();
	}
}