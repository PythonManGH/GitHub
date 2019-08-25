package liuj.hadoop.java1;

public class PersionTest {
	public static void main(String[] args) {
		Person p1 = new Person();
		p1.eat();  
	}
}

class Person{
	String name=null;
	int age=1;
	
	public void eat(){
		System.out.println("eat");
	}
	
	public void study(){
		System.out.println("study");
	}
	
	public void showNation(String _name){
		System.out.println(_name);
	}
}
