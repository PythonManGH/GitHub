package com.hadoop.mapReduce.wordcount;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;


public class wordCountMapper extends Mapper<LongWritable,Text,Text,IntWritable> {
	@Override
	protected void map(LongWritable key,Text value,Context context) throws IOException, InterruptedException
	{
		// 文件里面的内容会一行一行的传进来  key是行号  value是每一行的内容
		
		// 1. 获取这一行数据
		String line = value.toString();
		
		// 2. 处理这一行数据
		String[] words = line.split(" ");
		for(String word:words)
		{
			context.write(new Text(word), new IntWritable(1)); 
			// 注意上面这一步没有到  
		}
		
		// 3. 输出单词
	}
}
