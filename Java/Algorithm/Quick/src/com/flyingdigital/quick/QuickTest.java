package com.flyingdigital.quick;

import java.util.Arrays;

public class QuickTest {
	public static void main(String[] args) {
		Integer[] arr= {6,5,4,2,3,1};
		Quick.sort(arr);
		
		System.out.println(Arrays.toString(arr));
	}
}
