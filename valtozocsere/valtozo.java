
public class valtozo {
	public static void main(String[] args) {
		int a = 2;
	    int b = 5;
	    System.out.println("a = " + a + " b = " + b);
	    System.out.println("Osszeadasos csere");
	    a = a + b;
	    b = a - b;
	    a = a - b;
	    System.out.println("Lassuk: a = " + a + " b = " + b);
	    System.out.println("Uj ertekek");
	    a=20; b=30;
	    System.out.println("a = " + a + " b = " + b);
	    System.out.println("Szorzasos csere");
	    a=a*b;
	    b=a/b;
	    a=a/b;
	    System.out.println("Lassuk: a = " + a + " b = " + b);
	    System.out.println("Uj ertekek");
	    a=4; b=7;
	    System.out.println("a = " + a + " b = " + b);
	    System.out.println("Exoros csere");
	    a=b^a;
	    b=b^a;
	    a=b^a;
	    System.out.println("Lassuk: a = " + a + " b = " + b);



	}
}
