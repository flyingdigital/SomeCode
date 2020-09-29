package com.flyingdigital.select;
import java.util.Arrays;

public class SelectTest {
	public static void main(String[] args) {
		Integer[] arr = {5,4,3,1,2,6,7,8,6};
		Select.sort(arr);
		System.out.println(Arrays.toString(arr));
	}
}
