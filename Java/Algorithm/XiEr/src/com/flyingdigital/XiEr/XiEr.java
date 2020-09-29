package com.flyingdigital.XiEr;

// 希尔排序
public class XiEr {
	public static void sort(Comparable[] arr) {
		// 定义一个增长量
		int h = 1;
		while (h < arr.length) {
			h = 2 * h + 1;
		}

		while (h > 0) {
			for (int i = h; i < arr.length; i++) {
				for (int j = i; j > 0; j -= h) {
					if (greater(arr[j - h], arr[j])) {
						exch(arr, j - h, j);
					} else
						break;

				}
			}
			h = h / 2;
		}
	}

	public static boolean greater(Comparable a, Comparable b) {
		return a.compareTo(b) > 0;
	}

	public static void exch(Comparable[] arr, int i, int j) {
		Comparable temp;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
