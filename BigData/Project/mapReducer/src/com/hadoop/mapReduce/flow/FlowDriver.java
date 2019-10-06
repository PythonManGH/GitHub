package com.hadoop.mapReduce.flow;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class FlowDriver {
	public static void main(String[] args) throws IOException, Exception, InterruptedException{
		
		// 1. ��ȡ job
		Configuration configuration = new Configuration();
		Job job = Job.getInstance(configuration);
		
		// 2. ��ȡjar���洢·��
		job.setJarByClass(FlowDriver.class);
		
		// 3. ���� mapper��reducer��class��
		job.setMapperClass(FlowMapper.class);
		job.setReducerClass(FlowReducer.class);
		
		// 4. ����map����׶ε�key��value����
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(FlowBean.class);
		
		// 5. �������������ݵ�key��value����
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(FlowBean.class);
		
		// 6. ����
		job.setPartitionerClass(FlowPartitioner.class);
		// 7. ����reduceNum
		job.setNumReduceTasks(6);
		
		// 7. �����������ݵ�·����������ݵ�·��
		FileInputFormat.setInputPaths(job,new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		
		// 8. �ύ
		boolean result = job.waitForCompletion(true);
		System.exit(result?0:1);
	}
}