package com.flyingdgital.insertion;

import java.util.Arrays;

public class InsertionTest {

	public static void main(String[] args) {
		Integer[] arr = {5,3,3,4,2,1};
		Insertion.sort(arr);
		System.out.println(Arrays.toString(arr));
	}
}
