import pandas as pd
import numpy as np
import jieba

# 第一步 读取要分析的文本
df_news = pd.read_csv("./data/val.txt",sep='\t',names=['category','theme','URL','content'],encoding="utf-8")
df_news.dropna()
df_news.head()

# 第二步 从第一步读取文本的结果中提取要分析的内容(比如哪一列)
content = df_news.content.values.tolist()

# 第三步 将第二步得到的结果进行分词(使用结巴分词)
contentS = []
for line in content:
    current_segment = jieba.lcut(line)
    # print(type(current_segment))    # Returns a list
    if len(current_segment)>1 and current_segment!='\r\n':
        contentS.append(current_segment)
print(contentS[1000])

# 第四步将分词之后将数据变成 DataFrame 格式 ，仅仅是为了好用
df_content = pd.DataFrame({"contentS":contentS})
# print(df_content.head())


# 第五步 读取停用词表
stopwords = pd.read_csv("./data/stopwords.txt",index_col=False,sep='\t',quoting=3,names=['stopword'],encoding="gbk")
# print(stopwords.head(50))

# 第六步 去除停用词
sw = set(stopwords["stopword"])  # this reduces the lookup time from O(n) to O(1)
cleanContent = []
all_words = []
for line in df_content["contentS"]:
    lineContent = [item for item in line if item not in sw]
    all_words += lineContent
    # print(line)
    # print(lineContent)
    cleanContent.append(lineContent)
print(cleanContent[1000])

# 第七步
df_all_words = pd.DataFrame({"all_words":all_words})
words_count = df_all_words.groupby(by=["all_words"])["all_words"].agg(np.size)
words_count = words_count.reset_index().sort_values(ascending=False)
print(words_count.head(5))