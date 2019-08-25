package liu.hadoop.java;

public class ArrayTest {
	public static void main(String[] args) {
		
		//静态初始化
		int[] arr1; // 声明一个数组
		arr1 = new int[]{1,2,3,4,5,6}; //初始化一个数组
//		int[] arr2 = new int[]{1,2,3,4,5,6}; //同时声明和初始化
//		int arr2[] = new int[]{1,2,3,4,5,6};
//		int arr2[] = {1,2,3,4,5,6};
		int[] arr2 = {1,2,3,4,5,6};
		
		//动态初始化
		String[] arr3 = new String[3];
		arr3[0] = "liujun";
		arr3[1] = "mingming";
		arr3[2] = "tingting";
		
		// 数组长度
		System.out.println(arr3.length);
		// 遍历数组元素
		for(int i = 0;i<arr3.length;i++)
		{
			System.out.println(arr3[i]);
		}
		
		// 整型数组的默认值 0
		int[] arr4 = new int[3];
		for(int i = 0;i<arr4.length;i++)
		{
			System.out.println(arr4[i]);
		}
		
		// 浮点型数组的默认值 0.0
		double[] arr5 = new double[3];
		for(int i = 0;i<arr5.length;i++)
		{
			System.out.println(arr5[i]);
		}
		
		// 字符型数组的默认值 '\u0000'  0  but not '0'
		char[] arr6 = new char[3];
		for(int i = 0;i<arr6.length;i++)
		{
			System.out.println(arr6[i]);
		}
		
		// 布尔数组的默认值 false
		boolean[] arr7 = new boolean[3];
		for(int i = 0;i<arr7.length;i++)
		{
			System.out.println(arr7[i]);
		}
		
		// 引用数组的默认值 null
		String[] arr8 = new String[3];
		for(int i = 0;i<arr8.length;i++)
		{
			System.out.println(arr8[i]);
		}
		
	}
}
