package com.flyingdigital.quick;

public class Quick {
	public static void sort(Comparable[] arr) {
		int low = 0;
		int high = arr.length-1;
		
		
		sort(arr,low,high);
	}
	
	private static void sort(Comparable[] arr,int low,int high) {
		if(low>=high)
			return;
		
		int partition = partition(arr, low, high);
		
		sort(arr,low,partition);
		sort(arr,partition+1,high);
	}
	
	private static boolean greater(Comparable a,Comparable b) {
		return a.compareTo(b)>0;
	}
	
	private static void exch(Comparable[] arr,int i,int j) {
		Comparable temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	private static int partition(Comparable[] arr,int low,int high) {
		int left=low;
		int right=high+1;
		Comparable key = arr[low];
		
		while(true) {
			//���������ң��ҵ�һ����keyС��ͣ��
			while(greater(arr[--right], key)) {
				if(left==right) 
					break;

			}
			
			//���������ң��ҵ�һ����key���ͣ��
			while(greater(key, arr[++left])) {
				if(left==right) 
					break;

			}
			
			if(left>=right) 
				break;
			else 
				exch(arr, left, right);
		}
		
		exch(arr, low, right);
		
		return right;
	}
}