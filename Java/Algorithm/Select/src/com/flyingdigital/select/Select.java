package com.flyingdigital.select;

//—°‘Ò≈≈–Ú

public class Select {
	public static void sort(Comparable[] arr) {
	
		for(int i=0;i<arr.length-1;i++) {
			int minIndex = getMinIndex(arr, i);
			exch(arr, i, minIndex);
		}
	}
	
	public static int getMinIndex(Comparable[] arr,int location) {
		Integer minIndex = location;
		for(int i=location+1;i<arr.length;i++)
			if(greater(arr[minIndex], arr[i]))
				minIndex = i;
		
		return minIndex;		
	}
	
	public static boolean greater(Comparable a,Comparable b) {
		return a.compareTo(b)>0;
	}
	
	public static void exch(Comparable[] arr,int a, int b) {
		Comparable temp;
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
}
