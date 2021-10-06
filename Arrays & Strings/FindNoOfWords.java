import java.util.Scanner;

public class FindNoOfWords
{
	public static void main(String[] args)
	{
		String s = new Scanner(System.in).nextLine();
		s = s.trim();
		int noOfWords = s.split("\\s+").length;
		System.out.println(noOfWords);
	}
}