package com.flyingdigital.merge;

import java.util.Arrays;

public class MergeTest {
	public static void main(String[] args) {
		Integer[] arr= {6,5,4,2,3,1};
		Merge.sort(arr);
		
		System.out.println(Arrays.toString(arr));
	}
}
