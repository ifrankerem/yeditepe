package training;

public class Student implements Comparable<Student> {
    private String name;
    private int grade;

    public Student(String name, int grade) {
        this.name = name;
        this.grade = grade;
    }

    @Override
    public int compareTo(Student other) {
        return -(this.grade - other.grade);
    }

    @Override
    public String toString() {
        return name + " " + grade;
    }
}

