package training;

import java.util.*;
import java.text.CollationElementIterator;

class Main {

	public static void main(String[] args)
	{
		ArrayList<Student> students = new ArrayList<Student>();
		Student st_1 = new Student("arda", 31);
		Student st_2 = new Student("melih", 32);
		Student st_3 = new Student("salih", 33);
		students.add(st_1);
		students.add(st_2);
		students.add(st_3);

		for(Student s : students)
			System.out.println(s);

		Collections.sort(students);

		for(Student s : students)
			System.out.println(s);

	}
	
}