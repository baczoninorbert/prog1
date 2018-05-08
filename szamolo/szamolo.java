
import java.io.*;
import java.util.Scanner;
public class szamolo {
	public static void main(String[] args) {
		 try {

		        Scanner input = new Scanner(new FileReader("pelda.txt"));
		        //int totalLines = lineNum(input);
		        //int wordCount = wordCount(input); 
		        //int countChar = countChar(input)

		        int lineNum = 0;
		        int wordCount = 1;
		        int charCount = 0; 
		        int letters = 0;
		        int numbers = 0;
		        int specials = 0;
		        while (input.hasNextLine()) {
		            String line;
		            line = input.nextLine();

		            //output.println(lineNum + ": " + line);

		            lineNum++;
		           // String specialChars = "/*!@#$%^&*()\"{}_[]|\\?/<>,.";
		            String str [] = line.split((" "));
		              for ( int i = 0; i <str.length ; i ++) {
		                if (str [i].length() > 0) {
		                  wordCount ++; 
		                  char[] ch = str[i].toCharArray();
		                  for (int j =0; j < ch.length; j++)
		                  {
		                	  if(Character.isLetter(ch[j])){
		          				letters ++ ;
		          				}
		          				else {if(Character.isDigit(ch[j])){
		          					numbers ++ ;
		          				}
		          				else {
		          		             specials++;
		          		        }
		          				}
		                  }
		                }
		              }
		              charCount += (line.length());

		        }
		        System.out.println("letter: " + letters);
				System.out.println("word: " + wordCount);
				System.out.println("number: " + numbers);
				System.out.println("special: " + specials);
		        System.out.println("rows: "+ lineNum); 
		        System.out.println("characters " +charCount); 
		        input.close();

		    }

		    catch (FileNotFoundException e) {
		        System.out.println("There was an error opening one of the files.");
		    }
	}
}
