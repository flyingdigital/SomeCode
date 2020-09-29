package com.flyingdigital.bubble;

import java.util.Arrays;

public class Bubble {
	public static void sort(Comparable[] arr) {
		for(int i=arr.length-1;i>0;i--)
			for(int j=0;j<i;j++) {
				if(greater(arr[j], arr[j+1])) {
					Comparable temp;
					temp = arr[j];
					arr[j]=arr[j+1];
					arr[j+1] = temp;			
				}
				System.out.println(Arrays.toString(arr));
			}
	}
	
	public static boolean greater(Comparable a,Comparable b) {
		return a.compareTo(b)>0;
	}
}
