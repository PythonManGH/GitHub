package com.hadoop.mapReduce.wordcount;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.io.Text;

public class WordcountDriver {

	public static void main(String[] args) throws IOException, Exception, InterruptedException{
		// 1. 获取 job 对象信息
		Configuration configuration = new Configuration();
		Job job = Job.getInstance(configuration);
		
		// 2. 设置加载 jar 的位置
		job.setJarByClass(WordcountDriver.class);
		
		// 3. 设置mapper和reducer的class
		job.setMapperClass(wordCountMapper.class);
		job.setReducerClass(WordcountReducer.class);
		
		// 4. 设置输出mapper的数据类型
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(IntWritable.class);
		
		// 5. 设置最终数据输出类型
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);
		
		// 6. 设置输入数据的路径和输出数据的路径
		FileInputFormat.setInputPaths(job,new Path(args[0]));
		FileOutputFormat.setOutputPath(job,new Path(args[1]));
		
		// 7. 关联Combiner
		job.setCombinerClass(WordCountCombiner.class);	
		
		// 7. 提交
		boolean result = job.waitForCompletion(true);
		System.exit(result?0:1);
	}
}
