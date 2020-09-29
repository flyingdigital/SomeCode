package com.flyingdigital.merge;

//归并排序
public class Merge {
	
	private static Comparable[] assist;
	
	public static void sort(Comparable[] arr) {
		assist = new Comparable[arr.length];
		int low = 0;
		int high = arr.length-1;
		
		sort(arr,low,high);
	}

	private static void sort(Comparable[] arr, int low, int high) {
		if(low>=high)
			return;
		
		int mid = low+(high-low)/2;
		
		sort(arr,low,mid);
		sort(arr,mid+1,high);
		
		merge(arr, low, mid, high);
	}

	private static boolean greater(Comparable a, Comparable b) {
		return a.compareTo(b) > 0;
	}

	private static void merge(Comparable[] arr, int low, int mid, int high) {
		int i = low;
		int p1=low;
		int p2=mid+1;
		
		while(p1<=mid && p2<=high) {
			if(greater(arr[low], arr[mid+1])) {
				assist[i]=arr[p2];
				i++;
				p2++;
			}else {
				assist[i]=arr[p1];
				i++;
				p1++;
			}
		}
		
		if(p1<=mid) {
			for(int index=p1;index<=mid;index++,i++) {
				assist[i] = arr[index];
			}
		}
		
		if(p2<=high) {
			for(int index=p2;index<=high;index++,i++) {
				assist[i] = arr[index];
			}
		}
		
		//写入原数组
		for(int index=low;index<=high;index++) {
			arr[index]=assist[index];
		}
	}
}
