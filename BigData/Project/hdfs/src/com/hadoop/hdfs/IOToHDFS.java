package com.hadoop.hdfs;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IOUtils;
import org.junit.Test;

// 通过IO操作

public class IOToHDFS {

	
	// 文件上传
	@SuppressWarnings("source")
	@Test
	public void putFileToHDFS() throws IOException, InterruptedException, URISyntaxException{
		// 0. 获取文件系统
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		// 1. 获取输出流 hadoop的IO
		FSDataOutputStream fos = fs.create(new Path("/user/hadoop/output/nihao.txt"));
		
		// 2. 获取输入流javaIO
		FileInputStream fis = new FileInputStream("nihao.txt");
		
		try{
			// 3. 流对接
			IOUtils.copyBytes(fis, fos, conf);
		}catch(Exception e){
			
		}finally{
			// 4. 关闭资源
			IOUtils.closeStream(fis);
			IOUtils.closeStream(fos);
		}
	}

	// 下载文件
	@Test
	public void getFileFromHDFS() throws IOException, InterruptedException, URISyntaxException{
		// 1  获取文件系统
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		// 2 获取输入流
		FSDataInputStream fis = fs.open(new Path("/user/hadoop/output/nihao.txt"));
		
		// 3 获取输出流
		FileOutputStream fos = new FileOutputStream("res/nihao.txt");
		
		try{
			// 4 流对接
			IOUtils.copyBytes(fis, fos, conf);
		}catch(Exception e)
		{
			
		}finally
		{
			// 4. 关闭资源
			IOUtils.closeStream(fis);
			IOUtils.closeStream(fos);
		}
	}
	
	// get a total block == 128MB
	@Test
	public void getABlockFromHDFS() throws IOException, InterruptedException, URISyntaxException
	{
		// 1  获取文件系统
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		// 2. 打开输入流
		FSDataInputStream fis = fs.open(new Path("/user/hadoop/input/hadoop-2.7.2.tar.gz"));  
		
		// 3. 创建输出流
		FileOutputStream fos = new FileOutputStream("res/hadoop-2.7.2.tar.gz.part1");
		
		// 4. 流对接
		byte[] bytes = new byte[1024];
		for(int i = 0; i < 128*1024; i++)
		{
			fis.read(bytes);
			fos.write(bytes);
		}
		
		// 5. 关闭流
		IOUtils.closeStream(fis);
		IOUtils.closeStream(fos);
	}
	
	
	// get a total block < 128MB
	@Test
	public void getPBlockFromHDFS() throws IOException, InterruptedException, URISyntaxException
	{
		// 1  获取文件系统
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		// 2. 打开输入流
		FSDataInputStream fis = fs.open(new Path("/user/hadoop/input/hadoop-2.7.2.tar.gz"));  
		
		// 3. 创建输出流
		FileOutputStream fos = new FileOutputStream("res/hadoop-2.7.2.tar.gz.part2");
		
		// 4. 定位偏移量，第二块的首地址
		fis.seek(1024*1024*128);
		
		// 5. 流对接
		IOUtils.copyBytes(fis, fos, conf);
		
		// 6. 关闭流
		IOUtils.closeStream(fis);
		IOUtils.closeStream(fos);
	}
}
