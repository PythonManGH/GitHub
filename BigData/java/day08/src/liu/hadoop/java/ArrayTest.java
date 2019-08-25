/*
 * 二维数组
 * */
package liu.hadoop.java;

public class ArrayTest {
	public static void main(String[] args) {
		
		// 静态初始化
		int[][] arr1 = new int[][]{{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
		
		// 动态初始化
		int[][] arr2 = new int[3][2];
		int[][] arr3 = new int[3][];
		arr3[0] = new int[3];
		arr3[1] = new int[2];
		arr3[2] = new int[4];
		
		// 错误的初始化
//		int[][] arr = new int[][4];
//		int[][] arr = new int[3][]{{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
//		int[][] arr = new int[3][3]{{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
		
		// 调用数组元素
		System.out.println(arr1[1][0]);
		
		// 数组的长度  指的是几行
		System.out.println(arr1.length);
		
		// 数组的遍历
		for(int i = 0; i<arr1.length;i++)
		{
			for(int j = 0;j<arr1[i].length;j++)
			{
				System.out.println(arr1[i][j]);
			}
		}
		
		
		System.out.println(Math.random());
		System.out.println(Math.random()*30);
		System.out.println((int)(Math.random()*30));    // [0,29]
		System.out.println((int)(Math.random()*30)+1);  // [0,30]
		
		
		
	}
}
