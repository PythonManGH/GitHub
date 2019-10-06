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
		// �ļ���������ݻ�һ��һ�еĴ�����  key���к�  value��ÿһ�е�����
		
		// 1. ��ȡ��һ������
		String line = value.toString();
		
		// 2. ������һ������
		String[] words = line.split(" ");
		for(String word:words)
		{
			context.write(new Text(word), new IntWritable(1)); 
			// ע��������һ��û�е�  
		}
		
		// 3. �������
	}
}
