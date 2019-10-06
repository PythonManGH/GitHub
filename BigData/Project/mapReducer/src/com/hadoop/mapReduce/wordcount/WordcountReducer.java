package com.hadoop.mapReduce.wordcount;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class WordcountReducer extends Reducer<Text,IntWritable,Text,IntWritable>{
	
	@Override
	protected void reduce(Text key,Iterable<IntWritable> values,Context context) throws IOException,InterruptedException
	{
		// 一定要想清楚 各个参数的意思
		
		// 1. 统计所有单词的个数
		int count = 0;
		for(IntWritable value:values)
		{
			count += value.get();	
		}
		
		// 2. 输出所有单词个数
		context.write(key,new IntWritable(count));
	}
}
