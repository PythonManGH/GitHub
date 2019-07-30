import pandas as pd
from pandas import Series
import numpy as np
import matplotlib.pyplot as plt
from numpy import arange

# 绘制普通的折线图 ***********************************************************************
# unrate = pd.read_csv("data/UNRATE.csv")
# unrate["DATE"] = pd.to_datetime(unrate["DATE"])
# print(unrate.head(2))
#
# first_twelve = unrate[0:12]
# plt.plot(first_twelve["DATE"],first_twelve["VALUE"])
# plt.xticks(rotation=45)
# plt.xlabel("month")
# plt.ylabel("Unemployment Rate")
# plt.title("Employment Rate")
# plt.show()


# 添加子图 *******************************************************************************
# fig = plt.figure()
# ax1 = fig.add_subplot(4,3,1)
# ax2 = fig.add_subplot(4,3,2)
# ax3 = fig.add_subplot(4,3,6)
# plt.show()

# fig = plt.figure(figsize=(15,6)) # figsize 指明长度和宽度
# ax1 = fig.add_subplot(2,2,1)
# ax2 = fig.add_subplot(2,2,2)
# ax3 = fig.add_subplot(2,2,4)
# ax1.plot(np.random.randint(1,5,5),np.arange(5))
# plt.show()

# 一个图里面绘制两条折线*******************************************************************
# unrate["MONTH"] = unrate["DATE"].dt.month
# unrate["MONTH"] = unrate["DATE"].dt.month
# fig = plt.figure(figsize=(6,3))
# plt.plot(unrate[0:12]["MONTH"],unrate[0:12]["VALUE"],c="red")
# plt.plot(unrate[12:24]["MONTH"],unrate[12:24]["VALUE"],c="green")
# plt.show()

# unrate["MONTH"] = unrate["DATE"].dt.month
# fig = plt.figure(figsize=(10,6))
# color = ["red","green","blue","orange","black"]
# for i in range(5):
#     start = i*12
#     end = (i+1)*12
#     label = str(1948+i)
#     plt.plot(unrate[start:end]["MONTH"],unrate[start:end]["VALUE"],c=color[i],label=label)
# #plt.legend(loc="best")  # 可以显示右上角的标识
# plt.legend(loc="upper left")  # 可以显示右上角的标识
# plt.xlabel("month")
# plt.ylabel("Unemployment Rate")
# plt.title("Employment Rate")
# plt.show()



# *******************绘制柱形图**********************************************************
reviews = pd.read_csv("data/fandango_scores.csv")
cols = ["FILM","RT_user_norm","Metacritic_user_nom","IMDB_norm","Fandango_Ratingvalue","Fandango_Stars"]
norm_reviews = reviews[cols]
cols_value = ["RT_user_norm","Metacritic_user_nom","IMDB_norm","Fandango_Ratingvalue","Fandango_Stars"]
values = norm_reviews.loc[0][cols_value].values
xVec = arange(5)+1.0
fig,ax = plt.subplots()
#ax.bar(xVec,values,0.3) # 柱子的宽度 竖直的图形
ax.barh(xVec,values,0.3) # 柱子的宽度 水平的图形
ax.set_xticks(range(1,6))
ax.set_xticklabels(cols_value,rotation=45.0)
ax.set_xlabel("Rating Source")
ax.set_ylabel("Average Rating")
ax.set_title("Project Title")
plt.show()



# *******************散点图**********************************************************
