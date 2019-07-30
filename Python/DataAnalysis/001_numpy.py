import numpy as np


# 数据的读取、创建、初始化、数据的属性、数据的获取、切片、比较、索引、类型修改、
# 求极值、求和、加减乘除、求幂、根号、取整
# 矩阵的拼接、切分、拷贝复制、扩展、排序

# 从文本读取数据***********************************************************************
world_alcohol = np.genfromtxt("world_alcohol.txt",delimiter=',',dtype=str)
# print(type(world_alcohol))  # <class 'numpy.ndarray'>
# print(world_alcohol)  # 这个才是内容
# print(help(np.genfromtxt))

# 创建numpy.array**********************************************************************
vector = np.array([5,10,20,30])
matrix = np.array([[1,2,3],[4,5,6],[7,8,9]])
# print(vector)
# print(matrix)

# 通过arange创建array******************************************************************
# vv = np.arange(15) # 生成数据
# print(vv) # [ 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14]
# vv = vv.reshape(3,5) # 将数据变形 如果后面一个参数是 -1 则表明后面一个参数自动计算
# vv = vv.ravel() # 将矩阵变成 向量
# print(vv) # [[ 0  1  2  3  4] [ 5  6  7  8  9] [10 11 12 13 14]]
vv = np.arange(10,30,5) # 从10开始 到30结束 每次+5   [10 15 20 25]
vv = np.arange(1,5,0.3) # 从1开始 到5结束 每次+0.5   [1.  1.3 1.6 1.9 2.2 2.5 2.8 3.1 3.4 3.7 4.  4.3 4.6 4.9]
# print(vv)

# 通过random创建array******************************************************************
vv1 = np.random.random((2,3))  # 生成的数据是任意值
# print(vv1)

# 通过linespace创建array******************************************************************
vv2 = np.linspace(0,2,100)  # 指定区间的大小 并指定生成数据的个数
# print(vv2)
# print(np.sin(vv2))

# 通过zero初始化一个矩阵***************************************************************
# matrix = np.zeros((3,4)) # 全部初始化为 0
# matrix = np.ones((3,4)) # 全部初始化为 1
# print(matrix)

# 查看 numpy.array 的信息***************************************************************
# print(matrix.shape)  # shape 几行几列
# print(matrix.dtype)  # dtype 数据的类型
# print(matrix.ndim)  # ndim 2
# print(matrix.size) # 大小 9


# 获取单个数据**************************************************************************
value = world_alcohol[1,4]  #获取第二行第五列的数据

# 切片**********************************************************************************
# 在一维中切片
vector1 = vector[1:3] #获取的是第一个和第二个
# print(id(vector)) # 2395733112192
# print(id(vector1)) # 2395733112352
# print(vector1)  # [10 20]
# 在二维切片
# print(matrix[1:3 ,1:3]) # 切指定行和指定列
# print(matrix[1:3]) # 获取那几行
# print(matrix[:,1:3]) # 获取那几列
# print(matrix[:,1]) # 获取第几列
# print(matrix[1,:]) # 获取第几行

# 判断***********************************************************************************
#判断哪些值=10
# print(vector==10) # [False  True False False]
# print(matrix==5) # 输出结果如下
# [[False False False]
#  [False  True False]
#  [False False False]]


# 索引************************************************************************************
index = vector==10  # 将vector==10 的结果以索引的方式保存起来
# print(index) # [False  True False False]
# print(vector[index])  # [10]    可以通过索引直接获取值
# 切片和索引同时使用
index1 = matrix[1:3 ,1:3] == 5
# print(index1) #[[ True False] [False False]]
# print(matrix[index1]) #直接这么用会报错，现在还不知道为什么
# print(matrix[1:3 ,1:3][index1]) # 这才是正确的方法

# & | 操作*********************************************************************************
# index = (vector==5) & (vector==10) # 意思是vector中有没有某一个数即等于5又等于10
# print(index) # [False False False False]
# index = (vector==5) | (vector==10) # 意思是vector中有没有某一个数等于5或者等于10
# print(index) # [ True  True False False]


# 对array中元素的类型进行改变***************************************************************
# vector2 = vector.astype(str)
# print(vector2) # ['5' '10' '20' '30']
# print(vector) # [ 5 10 20 30]


# 求极值************************************************************************************
# print(matrix.min())
# print(matrix.max())


# 求和**************************************************************************************
print(matrix.sum()) # 求总和
# print(matrix.sum(axis=1)) # 求每一行的和   [ 6 15 24]
# print(matrix.sum(axis=0)) # 求每一列的和   [12 15 18]

# 运算**************************************************************************************
# 减法运算*******************************
a = np.array([20,30,40,50])
b = np.arange(4)
c = a - b # 对应位置的相减
# print(c)
# print(c-1) # 每个位置都减 1
# print(b**2) # 每个位置都进行平方运算
# print(a<32) # 找出哪些位置的数小于 32

A = np.array([[1,1],[0,1]])
B = np.array([[2,0],[3,4]])
# print(A*B)  # 对应位置相乘
# print(A.dot(B)) # 矩阵相乘
# print(np.dot(A,B)) # 矩阵相乘

# 求 e 的多少次幂 **********************************
# print(np.exp(A))  # 求 e 的每个数次幂
# print(np.sqrt(B)) # 求 B 中每个数开根号

# 向下取整 ******************************
A = np.floor(10*np.random.random((3,4)))
# print(A)


# 矩阵的拼接 *****************************************
A = np.floor(10*np.random.random((2,2)))
B = np.floor(10*np.random.random((2,2)))
# print(np.hstack((A,B)))
# print(np.vstack((A,B)))

# 矩阵的切分 ******************************************
# A = np.floor(10*np.random.random((2,12)))
# print(np.hsplit(A,3)) # 平均切分成 3 份
# A = np.floor(10*np.random.random((12,2)))
# print(np.vsplit(A,3)) # 平均切分成 3 份

# 拷贝和复制 ******************************************
# C = A # id 一样
# C = A.view() # 复制 id不一样 但是公用同一个数据 所以一个改变其它的也会改变
# C = A.copy()  # 复制 完全不一样

# 找最大值 *******************************************
# data = np.sin(np.arange(20).reshape(5,4))
# index = data.argmax(axis=0) # 获取每一列中最大值的位置 返回索引
# print(index)
# data_max = data[index,range(data.shape[1])] # 打印出每个最大的值
# print(data_max)


# 扩展 ************************************************************************
a = np.arange(0,40,10)  # [ 0 10 20 30]
# print(np.tile(a,(3,5)))
# [[ 0 10 20 30  0 10 20 30  0 10 20 30  0 10 20 30  0 10 20 30]
#  [ 0 10 20 30  0 10 20 30  0 10 20 30  0 10 20 30  0 10 20 30]
#  [ 0 10 20 30  0 10 20 30  0 10 20 30  0 10 20 30  0 10 20 30]]

# 排序 *************************************************************************
a = np.array([[4,3,5],[1,2,1]])
b = np.sort(a,axis=1) # 按行排序
b = np.argsort(a,axis=1) # 按行排序 只不过返回的是下标
# [[1 0 2] 下表为 1 的数值最小 然后是下表为 0 的  然后是下表为 2的
#  [0 2 1]]
print(b)






