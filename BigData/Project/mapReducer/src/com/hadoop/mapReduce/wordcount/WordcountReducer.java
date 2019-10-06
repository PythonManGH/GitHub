package com.hadoop.mapReduce.wordcount;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class WordcountReducer extends Reducer<Text,IntWritable,Text,IntWritable>{
	
	@Override
	protected void reduce(Text key,Iterable<IntWritable> values,Context context) throws IOException,InterruptedException
	{
		// һ��Ҫ����� ������������˼
		
		// 1. ͳ�����е��ʵĸ���
		int count = 0;
		for(IntWritable value:values)
		{
			count += value.get();	
		}
		
		// 2. ������е��ʸ���
		context.write(key,new IntWritable(count));
	}
}