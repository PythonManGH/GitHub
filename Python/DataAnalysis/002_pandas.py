import pandas as pd
from pandas import Series
import numpy as np
# food_info = pd.read_csv("food_info.csv")
# print(type(food_info)) # <class 'pandas.core.frame.DataFrame'>
# print(food_info.dtypes) # 打印每一列的类型
# print(help(pd.read_csv))
# print(food_info)

# print(food_info.head(2)) # 显示前几行数据，默认 5 行
# print(food_info.tail(2)) # 显示后几行数据，默认 5 行
# print(food_info.columns) # 显示列名
# print(food_info.shape) # 显示多少行多少列

# 获取数据 **********************************************************************************
# print(food_info.loc[0]) # 取出行号为0的数据
# print(food_info.loc[3:6]) # 取出行号为 3~6 的数据
# print(food_info['NDB_No'])  # 取出某一列 根据列名

# colName = ['NDB_No','Shrt_Desc']
# print(food_info[colName]) # 取出指定的某几列

# 显示列名已 (g) 结尾的数据 ********************************
# showName = []
# colName = food_info.columns.tolist();
# for c in colName:
#     if c.endswith("(g)"):
#         showName.append(c)
# print(food_info[showName])

# 四则运算 ********************************************************************
# print(food_info["Iron_(mg)"].head(2))

# iron = food_info["Iron_(mg)"]/1000
# print(food_info["Iron_(mg)"].head(2))
#
# food_info["Iron_(mg)"] = iron
# print(food_info["Iron_(mg)"].head(2))
#
# iron = food_info["Iron_(mg)"]+100
# food_info["Iron_(mg)"] = iron
# print(food_info["Iron_(mg)"].head(2))

# water_energ = food_info["Water_(g)"] * food_info["Energ_Kcal"]  # 维度一样时会进行对应位置操作
# print(water_energ.head(2))

# 求最大最小值 ***********************************************************************************
# print(food_info["Water_(g)"].max())
# print(food_info["Water_(g)"].min())

# 排序 ***********************************************************************************
# print(food_info["Iron_(mg)"].head(2))
# food_info.sort_values("Iron_(mg)",inplace=True,ascending=False) # 指定按哪一列排序，指定是否生成新的
# print(food_info["Iron_(mg)"].head(2))


tianic_info = pd.read_csv("titanic_train.csv")
# print(tianic_info.head())
print(tianic_info.columns)
# age = tianic_info["Age"]
# age_null = pd.isnull(age) # 显示哪些是空值哪些不是空值 bool
# print(age_null)
#
# null_value = age[age_null] # 显示出这些空值
# print(null_value)
#
# good_ages = tianic_info["Age"][age_null==False] # 过滤掉 Age 是 Null 的
# print(good_ages)
#
# # 直接求平均值
# print(tianic_info["Age"].mean()) # 会自动过滤掉空值

# ****************************************************************
passenger_class = [1,2,3]
pClassAvg = {}
for this_class in passenger_class:
    this_class_rows = tianic_info[tianic_info["Pclass"]==this_class] # 获取指定class的数据
    this_class_Fare = this_class_rows["Fare"]
    this_class_avg = this_class_Fare.mean()
    pClassAvg[this_class] = this_class_avg
print(pClassAvg)

# 上述代码可以简化  pivot_table 的 使用
passenger_survival = tianic_info.pivot_table(index="Pclass",values="Survived",aggfunc=np.mean)
passenger_age = tianic_info.pivot_table(index="Pclass",values="Age",aggfunc=np.sum) # 求每种Pclass的Age总和
passenger_age = tianic_info.pivot_table(index="Pclass",values="Age",aggfunc=np.mean) # 求每种Pclass的Age平均值
passenger_age = tianic_info.pivot_table(index="Pclass",values=["Age","Survived"],aggfunc=np.mean)
print(passenger_age)

# dropna 的使用 -- 把有缺失值的过滤掉 ********************************************************
new_data = tianic_info.dropna(axis=0,subset=["Age","Survived","Cabin"]) # 这些字段有缺失值的 都过滤掉整行
print(new_data)

# 自定义函数 *********************************************************************
def getRow(data): # 参数就是调用对象的每一列
    rowItem = data.loc[99]
    return rowItem
# print(tianic_info.apply(getRow))
# print(tianic_info.loc[99])

# 自定义函数**统计空值的函数*************************************************************
def countNull(column): # 参数就是调用对象的每一列
    columnNullIndex = pd.isnull(column) # 这一步返回的是索引
    columnNull = column[columnNullIndex] # 这一步返回的才是真正的空值
    return len(columnNull)
# print(tianic_info.apply(countNull))

# 传入对象的每一行作为参数****************************************************************
def getClass(row): # 传入对象的每一行作为参数
    valueClass = row["Pclass"]
    if pd.isnull(valueClass):
        return "Unknow"
    elif valueClass == 1:
        return "The first class"
    elif valueClass == 2:
        return "The second class"
    else:
        return "The third class"
# print(tianic_info.apply(getClass,axis=1)) # 这里必须指定 axis = 1


def generateAgeLable(row):
    ageRow = row["Age"]
    if pd.isnull(ageRow):
        return "Unknow"
    elif ageRow < 18:
        return "minor"
    else:
        return "adult"
age_label = tianic_info.apply(generateAgeLable,axis=1)
# print(age_label)
tianic_info['AgeLable'] = age_label
age_label_survived = tianic_info.pivot_table(index = "AgeLable",values="Survived")
# print(age_label_survived)


# 这个实例要搞懂***************************************************************************
fandango = pd.read_csv("fandango_score_comparison.csv")
print(fandango.columns)
series_film = fandango["FILM"]
# print(type(series_film)) # <class 'pandas.core.series.Series'>
# print(series_film[0:5])
series_tr = fandango["RottenTomatoes"]
# print(series_tr[0:5])
series_custom = Series(series_tr.values,index=series_film.values)
# print(series_custom[["Cinderella (2015)","Ant-Man (2015)"]])
print(series_custom[5:10])
original_index = series_custom.index.tolist()
new_index = sorted(original_index)
series_custom.reindex(new_index)
print(series_custom[5:10])


print(series_custom.sort_values()[5:10])
print(series_custom[series_custom>50])


# 可以直接通过 DataFrame 设置索引
fandango_films = fandango.set_index("FILM",drop=False)
print(fandango_films.index)



