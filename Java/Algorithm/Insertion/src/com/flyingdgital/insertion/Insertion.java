package com.flyingdgital.insertion;

//≤Â»Î≈≈–Ú

public class Insertion {
	public static void sort(Comparable[] arr) {
		for(int i = 1;i<arr.length;i++) {
			for(int j = i;j>0;j--) {
				if(greater(arr[j-1], arr[j]))
					exch(arr, j-1, j);
				else
					break;
			}
		}
	}
	
	public static boolean greater(Comparable a,Comparable b){
		return a.compareTo(b)>0;
	}
	
	public static void exch(Comparable[] arr,int i,int j) {
		Comparable temp;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
