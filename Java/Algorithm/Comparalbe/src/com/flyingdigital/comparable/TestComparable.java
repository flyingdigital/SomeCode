package com.flyingdigital.comparable;

// 测试学生类的接口方法

public class TestComparable {
	
	public static void main(String[] args) {
		Student s1 = new Student("TOM",12);
		Student s2 = new Student("JACK",20);
		
		Comparable<Student> max = getMax(s1, s2);
		
		System.out.print(max);
	}
	
	public static Comparable<Student> getMax(Student s1,Student s2) {
		int result = s1.compareTo(s2);
		
		if(result >= 0) {
			return s1;
		}else {
			return s2;
		}
	}
}
