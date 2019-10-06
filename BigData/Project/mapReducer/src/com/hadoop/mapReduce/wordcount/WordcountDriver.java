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
		// 1. ��ȡ job ������Ϣ
		Configuration configuration = new Configuration();
		Job job = Job.getInstance(configuration);
		
		// 2. ���ü��� jar ��λ��
		job.setJarByClass(WordcountDriver.class);
		
		// 3. ����mapper��reducer��class
		job.setMapperClass(wordCountMapper.class);
		job.setReducerClass(WordcountReducer.class);
		
		// 4. �������mapper����������
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(IntWritable.class);
		
		// 5. �������������������
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);
		
		// 6. �����������ݵ�·����������ݵ�·��
		FileInputFormat.setInputPaths(job,new Path(args[0]));
		FileOutputFormat.setOutputPath(job,new Path(args[1]));
		
		// 7. ����Combiner
		job.setCombinerClass(WordCountCombiner.class);	
		
		// 7. �ύ
		boolean result = job.waitForCompletion(true);
		System.exit(result?0:1);
	}
}